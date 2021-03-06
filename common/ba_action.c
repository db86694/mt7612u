
#include "rt_config.h"



#define BA_ORI_INIT_SEQ		(pEntry->TxSeq[TID]) /* 1 : inital sequence number of BA session*/

#define ORI_SESSION_MAX_RETRY	8
#define ORI_BA_SESSION_TIMEOUT	(2000)	/* ms */
#define REC_BA_SESSION_IDLE_TIMEOUT	(1000)	/* ms */

#define REORDERING_PACKET_TIMEOUT		((100 * OS_HZ)/1000)	/* system ticks -- 100 ms*/
#define MAX_REORDERING_PACKET_TIMEOUT	((3000 * OS_HZ)/1000)	/* system ticks -- 100 ms*/


#define RESET_RCV_SEQ		(0xFFFF)

static void ba_mpdu_blk_free(struct rtmp_adapter *pAd, struct reordering_mpdu *mpdu_blk);

#ifdef PEER_DELBA_TX_ADAPT
static VOID Peer_DelBA_Tx_Adapt_Enable(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY pEntry);

static VOID Peer_DelBA_Tx_Adapt_Disable(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY pEntry);
#endif /* PEER_DELBA_TX_ADAPT */

BA_ORI_ENTRY *BATableAllocOriEntry(struct rtmp_adapter *pAd, unsigned short *Idx);
BA_REC_ENTRY *BATableAllocRecEntry(struct rtmp_adapter *pAd, unsigned short *Idx);

VOID BAOriSessionSetupTimeout(
    IN PVOID SystemSpecific1,
    IN PVOID FunctionContext,
    IN PVOID SystemSpecific2,
    IN PVOID SystemSpecific3);

VOID BARecSessionIdleTimeout(
    IN PVOID SystemSpecific1,
    IN PVOID FunctionContext,
    IN PVOID SystemSpecific2,
    IN PVOID SystemSpecific3);


BUILD_TIMER_FUNCTION(BAOriSessionSetupTimeout);
BUILD_TIMER_FUNCTION(BARecSessionIdleTimeout);

#define ANNOUNCE_REORDERING_PACKET(_pAd, _mpdu_blk)	\
			Announce_Reordering_Packet(_pAd, _mpdu_blk);

VOID BA_MaxWinSizeReasign(
	IN struct rtmp_adapter *pAd,
	IN MAC_TABLE_ENTRY  *pEntryPeer,
	OUT u8 		*pWinSize)
{
	u8 MaxSize;
	u8 MaxPeerRxSize;


	if (CLIENT_STATUS_TEST_FLAG(pEntryPeer, fCLIENT_STATUS_RALINK_CHIPSET))
		MaxPeerRxSize = (1 << (pEntryPeer->MaxRAmpduFactor + 3));  /* (2^(13 + exp)) / 2048 bytes */
	else
		MaxPeerRxSize = (((1 << (pEntryPeer->MaxRAmpduFactor + 3)) * 10) / 16) -1;

	if (IS_MT76x2U(pAd)) {

		if (IS_MT76x2U(pAd))
			MaxSize = 47;
		else
			MaxSize = 31;

		if (((pEntryPeer->MaxHTPhyMode.field.MODE == MODE_HTMIX) ||
			(pEntryPeer->MaxHTPhyMode.field.MODE == MODE_HTGREENFIELD)) &&
			(pEntryPeer->HTCapability.MCSSet[2] != 0xff)) {
			MaxSize = 31;
		}
	}
	else
	if (pAd->Antenna.field.TxPath == 3 &&
		(pEntryPeer->HTCapability.MCSSet[2] != 0))
		MaxSize = 31; 		/* for 3x3, MaxSize use ((48KB/1.5KB) -1) = 31 */
	else
		MaxSize = 20;			/* for not 3x3, MaxSize use ((32KB/1.5KB) -1) ~= 20 */

	DBGPRINT(RT_DEBUG_TRACE, ("ba>WinSize=%d, MaxSize=%d, MaxPeerRxSize=%d\n",
			*pWinSize, MaxSize, MaxPeerRxSize));

	MaxSize = min(MaxPeerRxSize, MaxSize);
	if ((*pWinSize) > MaxSize)
	{
		DBGPRINT(RT_DEBUG_TRACE, ("ba> reassign max win size from %d to %d\n",
				*pWinSize, MaxSize));

		*pWinSize = MaxSize;
	}
}


void Announce_Reordering_Packet(struct rtmp_adapter *pAd, struct reordering_mpdu *mpdu)
{
	struct sk_buff *pPacket;

	pPacket = mpdu->pPacket;
	if (mpdu->bAMSDU)
	{
		/*ASSERT(0);*/
		BA_Reorder_AMSDU_Annnounce(pAd, pPacket, mpdu->OpMode);
	}
	else
	{

		/* pass this 802.3 packet to upper layer or forward this packet to WM directly */
#ifdef CONFIG_AP_SUPPORT
		IF_DEV_CONFIG_OPMODE_ON_AP(pAd)
			AP_ANNOUNCE_OR_FORWARD_802_3_PACKET(pAd, pPacket, RTMP_GET_PACKET_IF(pPacket));
#endif /* CONFIG_AP_SUPPORT */

#ifdef CONFIG_STA_SUPPORT
		IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
			ANNOUNCE_OR_FORWARD_802_3_PACKET(pAd, pPacket, RTMP_GET_PACKET_IF(pPacket));
#endif /* CONFIG_STA_SUPPORT */
	}
}


/* Insert a reordering mpdu into sorted linked list by sequence no. */
bool ba_reordering_mpdu_insertsorted(struct reordering_list *list, struct reordering_mpdu *mpdu)
{

	struct reordering_mpdu **ppScan = &list->next;

	while (*ppScan != NULL)
	{
		if (SEQ_SMALLER((*ppScan)->Sequence, mpdu->Sequence, MAXSEQ))
		{
			ppScan = &(*ppScan)->next;
		}
		else if ((*ppScan)->Sequence == mpdu->Sequence)
		{
			/* give up this duplicated frame */
			return(false);
		}
		else
		{
			/* find position */
			break;
		}
	}

	mpdu->next = *ppScan;
	*ppScan = mpdu;
	list->qlen++;
	return true;
}


/* Caller lock critical section if necessary */
static inline void ba_enqueue(struct reordering_list *list, struct reordering_mpdu *mpdu_blk)
{
	list->qlen++;
	mpdu_blk->next = list->next;
	list->next = mpdu_blk;
}


/* caller lock critical section if necessary */
static inline struct reordering_mpdu * ba_dequeue(struct reordering_list *list)
{
	struct reordering_mpdu *mpdu_blk = NULL;

	ASSERT(list);

		if (list->qlen)
		{
			list->qlen--;
			mpdu_blk = list->next;
			if (mpdu_blk)
			{
				list->next = mpdu_blk->next;
				mpdu_blk->next = NULL;
			}
		}
	return mpdu_blk;
}


static inline struct reordering_mpdu  *ba_reordering_mpdu_dequeue(struct reordering_list *list)
{
	return(ba_dequeue(list));
}


static inline struct reordering_mpdu  *ba_reordering_mpdu_probe(struct reordering_list *list)
{
	ASSERT(list);

	return(list->next);
}


/* free all resource for reordering mechanism */
void ba_reordering_resource_release(struct rtmp_adapter *pAd)
{
	BA_TABLE *Tab;
	BA_REC_ENTRY *pBAEntry;
	struct reordering_mpdu *mpdu_blk;
	int i;

	Tab = &pAd->BATable;

	/* I.  release all pending reordering packet */
	spin_lock_bh(&pAd->BATabLock);
	for (i = 0; i < MAX_LEN_OF_BA_REC_TABLE; i++)
	{
		pBAEntry = &Tab->BARecEntry[i];
		if (pBAEntry->REC_BA_Status != Recipient_NONE)
		{
			while ((mpdu_blk = ba_reordering_mpdu_dequeue(&pBAEntry->list)))
			{
				ASSERT(mpdu_blk->pPacket);
				dev_kfree_skb_any(mpdu_blk->pPacket);
				ba_mpdu_blk_free(pAd, mpdu_blk);
			}
		}
	}
	spin_unlock_bh(&pAd->BATabLock);

	ASSERT(pBAEntry->list.qlen == 0);
	/* II. free memory of reordering mpdu table */
	spin_lock_bh(&pAd->mpdu_blk_pool.lock);
	kfree(pAd->mpdu_blk_pool.mem);
	spin_unlock_bh(&pAd->mpdu_blk_pool.lock);
}


/*
 * Allocate all resource for reordering mechanism
 */
bool ba_reordering_resource_init(struct rtmp_adapter *pAd, int num)
{
	int     i;
	u8 * mem;
	struct reordering_mpdu *mpdu_blk;
	struct reordering_list *freelist;

	/* allocate spinlock */
	spin_lock_init(&pAd->mpdu_blk_pool.lock);

	/* initialize freelist */
	freelist = &pAd->mpdu_blk_pool.freelist;
	freelist->next = NULL;
	freelist->qlen = 0;

	DBGPRINT(RT_DEBUG_TRACE, ("Allocate %d memory for BA reordering\n", (uint32_t)(num*sizeof(struct reordering_mpdu))));

	/* allocate number of mpdu_blk memory */
	mem = kmalloc(num*sizeof(struct reordering_mpdu), GFP_ATOMIC);

	pAd->mpdu_blk_pool.mem = mem;

	if (mem == NULL) {
		DBGPRINT(RT_DEBUG_ERROR, ("Can't Allocate Memory for BA Reordering\n"));
		return(false);
	}

	/* build mpdu_blk free list */
	for (i=0; i<num; i++)
	{
		/* get mpdu_blk */
		mpdu_blk = (struct reordering_mpdu *) mem;
		/* initial mpdu_blk */
		memset(mpdu_blk, 0, sizeof(struct reordering_mpdu));
		/* next mpdu_blk */
		mem += sizeof(struct reordering_mpdu);
		/* insert mpdu_blk into freelist */
		ba_enqueue(freelist, mpdu_blk);
	}

	return(true);
}

/* static int blk_count=0;  sample take off, no use */

static struct reordering_mpdu *ba_mpdu_blk_alloc(struct rtmp_adapter *pAd)
{
	struct reordering_mpdu *mpdu_blk;

	spin_lock_bh(&pAd->mpdu_blk_pool.lock);
	mpdu_blk = ba_dequeue(&pAd->mpdu_blk_pool.freelist);
	if (mpdu_blk)
	{
		/* reset mpdu_blk */
		memset(mpdu_blk, 0, sizeof(struct reordering_mpdu));
	}
	spin_unlock_bh(&pAd->mpdu_blk_pool.lock);
	return mpdu_blk;
}

static void ba_mpdu_blk_free(struct rtmp_adapter *pAd, struct reordering_mpdu *mpdu_blk)
{
	ASSERT(mpdu_blk);

	spin_lock_bh(&pAd->mpdu_blk_pool.lock);
	ba_enqueue(&pAd->mpdu_blk_pool.freelist, mpdu_blk);
	spin_unlock_bh(&pAd->mpdu_blk_pool.lock);
}


static unsigned short ba_indicate_reordering_mpdus_in_order(
												   IN struct rtmp_adapter *   pAd,
												   IN PBA_REC_ENTRY    pBAEntry,
												   IN unsigned short           StartSeq)
{
	struct reordering_mpdu *mpdu_blk;
	unsigned short  LastIndSeq = RESET_RCV_SEQ;

	spin_lock_bh(&pBAEntry->RxReRingLock);

	while ((mpdu_blk = ba_reordering_mpdu_probe(&pBAEntry->list)))
	{
			/* find in-order frame */
		if (!SEQ_STEPONE(mpdu_blk->Sequence, StartSeq, MAXSEQ))
			break;

		/* dequeue in-order frame from reodering list */
		mpdu_blk = ba_reordering_mpdu_dequeue(&pBAEntry->list);
		/* pass this frame up */
		ANNOUNCE_REORDERING_PACKET(pAd, mpdu_blk);
		/* move to next sequence */
		StartSeq = mpdu_blk->Sequence;
		LastIndSeq = StartSeq;
		/* free mpdu_blk */
		ba_mpdu_blk_free(pAd, mpdu_blk);
	}

	spin_unlock_bh(&pBAEntry->RxReRingLock);

	/* update last indicated sequence */
	return LastIndSeq;
}

static void ba_indicate_reordering_mpdus_le_seq(
											   IN struct rtmp_adapter *   pAd,
											   IN PBA_REC_ENTRY    pBAEntry,
											   IN unsigned short           Sequence)
{
	struct reordering_mpdu *mpdu_blk;

	spin_lock_bh(&pBAEntry->RxReRingLock);
	while ((mpdu_blk = ba_reordering_mpdu_probe(&pBAEntry->list)))
		{
			/* find in-order frame */
		if ((mpdu_blk->Sequence == Sequence) || SEQ_SMALLER(mpdu_blk->Sequence, Sequence, MAXSEQ))
		{
			/* dequeue in-order frame from reodering list */
			mpdu_blk = ba_reordering_mpdu_dequeue(&pBAEntry->list);
			/* pass this frame up */
			ANNOUNCE_REORDERING_PACKET(pAd, mpdu_blk);
			/* free mpdu_blk */
			ba_mpdu_blk_free(pAd, mpdu_blk);
		}
		else
			{
				break;
			}
	}
	spin_unlock_bh(&pBAEntry->RxReRingLock);
}


static void ba_refresh_reordering_mpdus(struct rtmp_adapter *pAd, BA_REC_ENTRY *pBAEntry)
{
	struct reordering_mpdu *mpdu_blk;

	spin_lock_bh(&pBAEntry->RxReRingLock);

			/* dequeue in-order frame from reodering list */
	while ((mpdu_blk = ba_reordering_mpdu_dequeue(&pBAEntry->list)))
	{
			/* pass this frame up */
		ANNOUNCE_REORDERING_PACKET(pAd, mpdu_blk);

		pBAEntry->LastIndSeq = mpdu_blk->Sequence;
			ba_mpdu_blk_free(pAd, mpdu_blk);

		/* update last indicated sequence */
	}
	ASSERT(pBAEntry->list.qlen == 0);
	pBAEntry->LastIndSeq = RESET_RCV_SEQ;
	spin_unlock_bh(&pBAEntry->RxReRingLock);
}


/* static */
void ba_flush_reordering_timeout_mpdus(
									IN struct rtmp_adapter *   pAd,
									IN PBA_REC_ENTRY    pBAEntry,
									IN ULONG            Now32)

{
	unsigned short Sequence;

    if ((pBAEntry == NULL) || (pBAEntry->list.qlen <= 0))
        return;

/*	if ((RTMP_TIME_AFTER((unsigned long)Now32, (unsigned long)(pBAEntry->LastIndSeqAtTimer+REORDERING_PACKET_TIMEOUT)) &&*/
/*		 (pBAEntry->list.qlen > ((pBAEntry->BAWinSize*7)/8))) ||*/
/*		(RTMP_TIME_AFTER((unsigned long)Now32, (unsigned long)(pBAEntry->LastIndSeqAtTimer+(10*REORDERING_PACKET_TIMEOUT))) &&*/
/*		 (pBAEntry->list.qlen > (pBAEntry->BAWinSize/8)))*/
	if (RTMP_TIME_AFTER((unsigned long)Now32, (unsigned long)(pBAEntry->LastIndSeqAtTimer+(MAX_REORDERING_PACKET_TIMEOUT/6)))
		 &&(pBAEntry->list.qlen > 1)
		)
	{
		DBGPRINT(RT_DEBUG_TRACE,("timeout[%d] (%08lx-%08lx = %d > %d): %x, flush all!\n ", pBAEntry->list.qlen, Now32, (pBAEntry->LastIndSeqAtTimer),
			   (int)((long) Now32 - (long)(pBAEntry->LastIndSeqAtTimer)), MAX_REORDERING_PACKET_TIMEOUT,
			   pBAEntry->LastIndSeq));
		ba_refresh_reordering_mpdus(pAd, pBAEntry);
		pBAEntry->LastIndSeqAtTimer = Now32;
	}
	else
	if (RTMP_TIME_AFTER((unsigned long)Now32, (unsigned long)(pBAEntry->LastIndSeqAtTimer+(REORDERING_PACKET_TIMEOUT)))
		&& (pBAEntry->list.qlen > 0)
	   )
		{
/*
		DBGPRINT(RT_DEBUG_OFF, ("timeout[%d] (%lx-%lx = %d > %d): %x, ", pBAEntry->list.qlen, Now32, (pBAEntry->LastIndSeqAtTimer),
			   (int)((long) Now32 - (long)(pBAEntry->LastIndSeqAtTimer)), REORDERING_PACKET_TIMEOUT,
			   pBAEntry->LastIndSeq));
*/

		/* force LastIndSeq to shift to LastIndSeq+1*/
    		Sequence = (pBAEntry->LastIndSeq+1) & MAXSEQ;
    		ba_indicate_reordering_mpdus_le_seq(pAd, pBAEntry, Sequence);
    		pBAEntry->LastIndSeqAtTimer = Now32;
			pBAEntry->LastIndSeq = Sequence;

    		/* indicate in-order mpdus*/
    		Sequence = ba_indicate_reordering_mpdus_in_order(pAd, pBAEntry, Sequence);
    		if (Sequence != RESET_RCV_SEQ)
    		{
    			pBAEntry->LastIndSeq = Sequence;
    		}

		DBGPRINT(RT_DEBUG_OFF, ("%x, flush one!\n", pBAEntry->LastIndSeq));

	}
}


/*
 * generate ADDBA request to
 * set up BA agreement
 */
VOID BAOriSessionSetUp(
	IN struct rtmp_adapter *pAd,
	IN MAC_TABLE_ENTRY *pEntry,
	IN u8 TID,
	IN unsigned short TimeOut,
	IN ULONG DelayTime,
	IN bool isForced)
{
	BA_ORI_ENTRY *pBAEntry = NULL;
	unsigned short Idx;
	bool Cancelled;
    u8 BAWinSize = 0;

	ASSERT(TID < NUM_OF_TID);
	if (TID >= NUM_OF_TID)
	{
		DBGPRINT(RT_DEBUG_TRACE, ("Wrong TID %d!\n", TID));
		return;
	}

	if ((pAd->CommonCfg.BACapability.field.AutoBA != true)  &&  (isForced == false))
		return;

	/* if this entry is limited to use legacy tx mode, it doesn't generate BA.  */
	if (RTMPStaFixedTxMode(pAd, pEntry) != FIXED_TXMODE_HT)
		return;

	if ((pEntry->BADeclineBitmap & (1<<TID)) && (isForced == false))
	{
		DelayTime = 3000; /* try again after 3 secs*/
/*		DBGPRINT(RT_DEBUG_TRACE, ("DeCline BA from Peer\n"));*/
/*		return;*/
	}

	Idx = pEntry->BAOriWcidArray[TID];
	if (Idx == 0)
	{
		/* allocate a BA session*/
		pBAEntry = BATableAllocOriEntry(pAd, &Idx);
		if (pBAEntry == NULL)
		{
			DBGPRINT(RT_DEBUG_TRACE,("%s(): alloc BA session failed\n",
						__FUNCTION__));
			return;
		}
	}
	else
	{
		pBAEntry =&pAd->BATable.BAOriEntry[Idx];
	}

	if (pBAEntry->ORI_BA_Status >= Originator_WaitRes)
		return;

	pEntry->BAOriWcidArray[TID] = Idx;

    BAWinSize = pAd->CommonCfg.BACapability.field.TxBAWinLimit;


	/* Initialize BA session */
	pBAEntry->ORI_BA_Status = Originator_WaitRes;
	pBAEntry->Wcid = pEntry->wcid;
	pBAEntry->BAWinSize = BAWinSize;
	pBAEntry->Sequence = BA_ORI_INIT_SEQ;
	pBAEntry->Token = 1;	/* (2008-01-21) Jan Lee recommends it - this token can't be 0*/
	pBAEntry->TID = TID;
	pBAEntry->TimeOutValue = TimeOut;
	pBAEntry->pAdapter = pAd;

	if (!(pEntry->TXBAbitmap & (1<<TID)))
	{
		RTMPInitTimer(pAd, &pBAEntry->ORIBATimer, GET_TIMER_FUNCTION(BAOriSessionSetupTimeout), pBAEntry, false);
	}
	else
		RTMPCancelTimer(&pBAEntry->ORIBATimer, &Cancelled);

	/* set timer to send ADDBA request */
	RTMPSetTimer(&pBAEntry->ORIBATimer, DelayTime);
}


VOID BAOriSessionAdd(
	IN struct rtmp_adapter *pAd,
	IN MAC_TABLE_ENTRY *pEntry,
	IN FRAME_ADDBA_RSP *pFrame)
{
	BA_ORI_ENTRY  *pBAEntry = NULL;
	bool Cancelled;
	u8 TID;
	unsigned short Idx;
	u8 *pOutBuffer2 = NULL;
	int NStatus;
	ULONG FrameLen;
	FRAME_BAR FrameBar;
	u8 MaxPeerBufSize;
	MAC_TABLE_ENTRY *mac_entry;

	TID = pFrame->BaParm.TID;
	Idx = pEntry->BAOriWcidArray[TID];
	pBAEntry =&pAd->BATable.BAOriEntry[Idx];

	MaxPeerBufSize = 0;

	/* Start fill in parameters.*/
	if ((Idx !=0) && (pBAEntry->TID == TID) && (pBAEntry->ORI_BA_Status == Originator_WaitRes))
	{
		MaxPeerBufSize = (u8)pFrame->BaParm.BufSize;

		{
			if (MaxPeerBufSize > 0)
				MaxPeerBufSize -= 1;
			else
				MaxPeerBufSize = 0;

			pBAEntry->BAWinSize = min(pBAEntry->BAWinSize, MaxPeerBufSize);
			BA_MaxWinSizeReasign(pAd, pEntry, &pBAEntry->BAWinSize);
		}
		pBAEntry->TimeOutValue = pFrame->TimeOutValue;
		pBAEntry->amsdu_cap = pFrame->BaParm.AMSDUSupported;
		pBAEntry->ORI_BA_Status = Originator_Done;
		pAd->BATable.numDoneOriginator ++;

		/* reset sequence number */
		pBAEntry->Sequence = BA_ORI_INIT_SEQ;
		/* Set Bitmap flag.*/
		pEntry->TXBAbitmap |= (1<<TID);
		RTMPCancelTimer(&pBAEntry->ORIBATimer, &Cancelled);

		pBAEntry->ORIBATimer.TimerValue = 0;	/*pFrame->TimeOutValue;*/

		DBGPRINT(RT_DEBUG_TRACE, ("%s():TXBAbitmap=%x, AMSDUCap=%d, BAWinSize=%d, TimeOut=%ld\n",
					__FUNCTION__, pEntry->TXBAbitmap, pBAEntry->amsdu_cap,
					pBAEntry->BAWinSize, pBAEntry->ORIBATimer.TimerValue));

		/* SEND BAR */
		pOutBuffer2 = kmalloc(MGMT_DMA_BUFFER_SIZE, GFP_ATOMIC);  /*Get an unused nonpaged memory*/
		if (pOutBuffer2 == NULL) {
			DBGPRINT(RT_DEBUG_TRACE,("BA - BAOriSessionAdd() allocate memory failed \n"));
			return;
		}

		// TODO: shiang, is the mac_entry and pEntry the same one??
		mac_entry = &pAd->MacTab.Content[pBAEntry->Wcid];
		BarHeaderInit(pAd, &FrameBar, mac_entry->Addr, mac_entry->wdev->if_addr);

		FrameBar.StartingSeq.field.FragNum = 0;	/* make sure sequence not clear in DEL function.*/
		FrameBar.StartingSeq.field.StartSeq = pBAEntry->Sequence; /* make sure sequence not clear in DEL funciton.*/
		FrameBar.BarControl.TID = pBAEntry->TID; /* make sure sequence not clear in DEL funciton.*/
		MakeOutgoingFrame(pOutBuffer2, &FrameLen,
							sizeof(FRAME_BAR), &FrameBar,
							END_OF_ARGS);
		MiniportMMRequest(pAd, QID_AC_BE, pOutBuffer2, FrameLen);
		kfree(pOutBuffer2);

		if (pBAEntry->ORIBATimer.TimerValue)
			RTMPSetTimer(&pBAEntry->ORIBATimer, pBAEntry->ORIBATimer.TimerValue); /* in mSec */
	}

}


bool BARecSessionAdd(
	IN struct rtmp_adapter *pAd,
	IN MAC_TABLE_ENTRY *pEntry,
	IN FRAME_ADDBA_REQ *pFrame)
{
	BA_REC_ENTRY *pBAEntry = NULL;
	bool Status = true, Cancelled;
	unsigned short Idx;
	u8 TID, BAWinSize;


	ASSERT(pEntry);

	/* find TID*/
	TID = pFrame->BaParm.TID;

	BAWinSize = min(((u8)pFrame->BaParm.BufSize), (u8)pAd->CommonCfg.BACapability.field.RxBAWinLimit);

	/* Intel patch*/
	if (BAWinSize == 0)
		BAWinSize = 64;

	/* get software BA rec array index, Idx*/
	Idx = pEntry->BARecWcidArray[TID];


	if (Idx == 0)
	{
		/* allocate new array entry for the new session*/
		pBAEntry = BATableAllocRecEntry(pAd, &Idx);
	}
	else
	{
		pBAEntry = &pAd->BATable.BARecEntry[Idx];
		/* flush all pending reordering mpdus*/
		ba_refresh_reordering_mpdus(pAd, pBAEntry);
	}

	DBGPRINT(RT_DEBUG_TRACE,("%s(%ld): Idx = %d, BAWinSize(req %d) = %d\n",
				__FUNCTION__, pAd->BATable.numAsRecipient, Idx,
							 pFrame->BaParm.BufSize, BAWinSize));

	/* Start fill in parameters.*/
	if (pBAEntry != NULL)
	{
		ASSERT(pBAEntry->list.qlen == 0);

		pBAEntry->REC_BA_Status = Recipient_HandleRes;
		pBAEntry->BAWinSize = BAWinSize;
		pBAEntry->Wcid = pEntry->wcid;
		pBAEntry->TID = TID;
		pBAEntry->TimeOutValue = pFrame->TimeOutValue;
		pBAEntry->REC_BA_Status = Recipient_Accept;
		/* initial sequence number */
		pBAEntry->LastIndSeq = RESET_RCV_SEQ; /*pFrame->BaStartSeq.field.StartSeq;*/

		DBGPRINT(RT_DEBUG_OFF, ("Start Seq = %08x\n",  pFrame->BaStartSeq.field.StartSeq));

		if (pEntry->RXBAbitmap & (1<<TID))
			RTMPCancelTimer(&pBAEntry->RECBATimer, &Cancelled);
		else
			RTMPInitTimer(pAd, &pBAEntry->RECBATimer, GET_TIMER_FUNCTION(BARecSessionIdleTimeout), pBAEntry, true);

		/* Set Bitmap flag.*/
		pEntry->RXBAbitmap |= (1<<TID);
		pEntry->BARecWcidArray[TID] = Idx;
		pEntry->BADeclineBitmap &= ~(1<<TID);

		/* Set BA session mask in WCID table.*/
		RTMP_ADD_BA_SESSION_TO_ASIC(pAd, pEntry->wcid, TID);

		DBGPRINT(RT_DEBUG_TRACE, ("MACEntry[%d]RXBAbitmap = 0x%x. BARecWcidArray=%d\n",
				pEntry->wcid, pEntry->RXBAbitmap, pEntry->BARecWcidArray[TID]));
	}
	else
	{
		Status = false;
		DBGPRINT(RT_DEBUG_TRACE,("Can't Accept ADDBA for %02x:%02x:%02x:%02x:%02x:%02x TID = %d\n",
				PRINT_MAC(pEntry->Addr), TID));
	}
	return(Status);
}


BA_REC_ENTRY *BATableAllocRecEntry(struct rtmp_adapter *pAd, unsigned short *Idx)
{
	int i;
	BA_REC_ENTRY *pBAEntry = NULL;


	spin_lock_bh(&pAd->BATabLock);

	if (pAd->BATable.numAsRecipient >= (MAX_LEN_OF_BA_REC_TABLE - 1))
	{
		DBGPRINT(RT_DEBUG_OFF, ("BA Recipeint Session (%ld) > %d\n",
							pAd->BATable.numAsRecipient, (MAX_LEN_OF_BA_REC_TABLE - 1)));
		goto done;
	}

	/* reserve idx 0 to identify BAWcidArray[TID] as empty*/
	for (i=1; i < MAX_LEN_OF_BA_REC_TABLE; i++)
	{
		pBAEntry =&pAd->BATable.BARecEntry[i];
		if ((pBAEntry->REC_BA_Status == Recipient_NONE))
		{
			/* get one */
			pAd->BATable.numAsRecipient++;
			pBAEntry->REC_BA_Status = Recipient_USED;
			*Idx = i;
			break;
		}
	}

done:
	spin_unlock_bh(&pAd->BATabLock);
	return pBAEntry;
}


BA_ORI_ENTRY *BATableAllocOriEntry(struct rtmp_adapter *pAd, unsigned short *Idx)
{
	int i;
	BA_ORI_ENTRY *pBAEntry = NULL;

	spin_lock_bh(&pAd->BATabLock);
	if (pAd->BATable.numAsOriginator >= (MAX_LEN_OF_BA_ORI_TABLE - 1))
		goto done;

	/* reserve idx 0 to identify BAWcidArray[TID] as empty*/
	for (i=1; i<MAX_LEN_OF_BA_ORI_TABLE; i++)
	{
		pBAEntry =&pAd->BATable.BAOriEntry[i];
		if ((pBAEntry->ORI_BA_Status == Originator_NONE))
		{
			/* get one */
			pAd->BATable.numAsOriginator++;
			pBAEntry->ORI_BA_Status = Originator_USED;
			pBAEntry->pAdapter = pAd;
			*Idx = i;
			break;
		}
	}

done:
	spin_unlock_bh(&pAd->BATabLock);
	return pBAEntry;
}


VOID BATableFreeOriEntry(struct rtmp_adapter *pAd, ULONG Idx)
{
	BA_ORI_ENTRY *pBAEntry = NULL;
	MAC_TABLE_ENTRY *pEntry;

	if ((Idx == 0) || (Idx >= MAX_LEN_OF_BA_ORI_TABLE))
		return;

	pBAEntry =&pAd->BATable.BAOriEntry[Idx];

	if (pBAEntry->ORI_BA_Status != Originator_NONE)
	{
		pEntry = &pAd->MacTab.Content[pBAEntry->Wcid];
		pEntry->BAOriWcidArray[pBAEntry->TID] = 0;
		DBGPRINT(RT_DEBUG_TRACE, ("%s: Wcid = %d, TID = %d\n", __FUNCTION__, pBAEntry->Wcid, pBAEntry->TID));


		spin_lock_bh(&pAd->BATabLock);
		if (pBAEntry->ORI_BA_Status == Originator_Done)
		{
			pAd->BATable.numDoneOriginator -= 1;
		 	pEntry->TXBAbitmap &= (~(1<<(pBAEntry->TID) ));
			DBGPRINT(RT_DEBUG_TRACE, ("BATableFreeOriEntry numAsOriginator= %ld\n", pAd->BATable.numAsRecipient));
			/* Erase Bitmap flag.*/
		}

		ASSERT(pAd->BATable.numAsOriginator != 0);

		pAd->BATable.numAsOriginator -= 1;

		pBAEntry->ORI_BA_Status = Originator_NONE;
		pBAEntry->Token = 0;
		spin_unlock_bh(&pAd->BATabLock);
	}
}


VOID BATableFreeRecEntry(struct rtmp_adapter *pAd, ULONG Idx)
{
	BA_REC_ENTRY    *pBAEntry = NULL;
	MAC_TABLE_ENTRY *pEntry;


	if ((Idx == 0) || (Idx >= MAX_LEN_OF_BA_REC_TABLE))
		return;

	pBAEntry =&pAd->BATable.BARecEntry[Idx];

	if (pBAEntry->REC_BA_Status != Recipient_NONE)
	{
		pEntry = &pAd->MacTab.Content[pBAEntry->Wcid];
		pEntry->BARecWcidArray[pBAEntry->TID] = 0;

		spin_lock_bh(&pAd->BATabLock);

		ASSERT(pAd->BATable.numAsRecipient != 0);

		pAd->BATable.numAsRecipient -= 1;

		pBAEntry->REC_BA_Status = Recipient_NONE;
		spin_unlock_bh(&pAd->BATabLock);
	}
}


VOID BAOriSessionTearDown(
	INOUT struct rtmp_adapter *pAd,
	IN u8 Wcid,
	IN u8 TID,
	IN bool bPassive,
	IN bool bForceSend)
{
	UINT Idx = 0;
	BA_ORI_ENTRY *pBAEntry;
	bool Cancelled;

	if (Wcid >= MAX_LEN_OF_MAC_TABLE)
		return;

	/* Locate corresponding BA Originator Entry in BA Table with the (pAddr,TID).*/
	Idx = pAd->MacTab.Content[Wcid].BAOriWcidArray[TID];
	if ((Idx == 0) || (Idx >= MAX_LEN_OF_BA_ORI_TABLE))
	{
		if (bForceSend == true)
		{
			/* force send specified TID DelBA*/
			MLME_DELBA_REQ_STRUCT   DelbaReq;
			MLME_QUEUE_ELEM *Elem;
			Elem = kmalloc(sizeof(MLME_QUEUE_ELEM), GFP_ATOMIC);
			if (Elem != NULL) {
				memset(&DelbaReq, 0, sizeof(DelbaReq));
				memset(Elem, 0, sizeof(MLME_QUEUE_ELEM));

				COPY_MAC_ADDR(DelbaReq.Addr, pAd->MacTab.Content[Wcid].Addr);
				DelbaReq.Wcid = Wcid;
				DelbaReq.TID = TID;
				DelbaReq.Initiator = ORIGINATOR;
				Elem->MsgLen  = sizeof(DelbaReq);
				memmove(Elem->Msg, &DelbaReq, sizeof(DelbaReq));
				MlmeDELBAAction(pAd, Elem);
				kfree(Elem);
			}
			else
			{
				DBGPRINT(RT_DEBUG_ERROR, ("%s(bForceSend):alloc memory failed!\n", __FUNCTION__));
			}
		}

		return;
	}

	DBGPRINT(RT_DEBUG_TRACE,("%s===>Wcid=%d.TID=%d \n", __FUNCTION__, Wcid, TID));

	pBAEntry = &pAd->BATable.BAOriEntry[Idx];
	DBGPRINT(RT_DEBUG_TRACE,("\t===>Idx = %d, Wcid=%d.TID=%d, ORI_BA_Status = %d \n", Idx, Wcid, TID, pBAEntry->ORI_BA_Status));

	/* Prepare DelBA action frame and send to the peer.*/
	if ((bPassive == false) && (TID == pBAEntry->TID) && (pBAEntry->ORI_BA_Status == Originator_Done))
	{
		MLME_DELBA_REQ_STRUCT   DelbaReq;
		MLME_QUEUE_ELEM *Elem;
		Elem = kmalloc(sizeof(MLME_QUEUE_ELEM), GFP_ATOMIC);
		if (Elem != NULL) {
			memset(&DelbaReq, 0, sizeof(DelbaReq));
			memset(Elem, 0, sizeof(MLME_QUEUE_ELEM));

			COPY_MAC_ADDR(DelbaReq.Addr, pAd->MacTab.Content[Wcid].Addr);
			DelbaReq.Wcid = Wcid;
			DelbaReq.TID = pBAEntry->TID;
			DelbaReq.Initiator = ORIGINATOR;
			Elem->MsgLen  = sizeof(DelbaReq);
			memmove(Elem->Msg, &DelbaReq, sizeof(DelbaReq));
			MlmeDELBAAction(pAd, Elem);
			kfree(Elem);
		}
		else
		{
			DBGPRINT(RT_DEBUG_ERROR, ("%s():alloc memory failed!\n", __FUNCTION__));
			return;
		}
	}
	RTMPCancelTimer(&pBAEntry->ORIBATimer, &Cancelled);
	BATableFreeOriEntry(pAd, Idx);

	if (bPassive)
	{
		/*BAOriSessionSetUp(pAd, &pAd->MacTab.Content[Wcid], TID, 0, 10000, true);*/
	}
}

VOID BARecSessionTearDown(
						 IN OUT  struct rtmp_adapter *  pAd,
						 IN      u8           Wcid,
						 IN      u8           TID,
						 IN      bool         bPassive)
{
	ULONG Idx = 0;
	BA_REC_ENTRY *pBAEntry;

	if (Wcid >= MAX_LEN_OF_MAC_TABLE)
		return;

	/*  Locate corresponding BA Originator Entry in BA Table with the (pAddr,TID).*/
	Idx = pAd->MacTab.Content[Wcid].BARecWcidArray[TID];
	if (Idx == 0)
		return;

	DBGPRINT(RT_DEBUG_TRACE,("%s===>Wcid=%d.TID=%d \n", __FUNCTION__, Wcid, TID));


	pBAEntry = &pAd->BATable.BARecEntry[Idx];
	DBGPRINT(RT_DEBUG_TRACE,("\t===>Idx = %ld, Wcid=%d.TID=%d, REC_BA_Status = %d \n", Idx, Wcid, TID, pBAEntry->REC_BA_Status));

	/* Prepare DelBA action frame and send to the peer.*/
	if ((TID == pBAEntry->TID) && (pBAEntry->REC_BA_Status == Recipient_Accept))
	{
		MLME_DELBA_REQ_STRUCT DelbaReq;
		bool Cancelled;

		RTMPCancelTimer(&pBAEntry->RECBATimer, &Cancelled);


		/* 1. Send DELBA Action Frame*/
		if (bPassive == false)
		{
			MLME_QUEUE_ELEM *Elem;
			Elem = kmalloc(sizeof(MLME_QUEUE_ELEM), GFP_ATOMIC);
			if (Elem != NULL) {
				memset(&DelbaReq, 0, sizeof(DelbaReq));
				memset(Elem, 0, sizeof(MLME_QUEUE_ELEM));

				COPY_MAC_ADDR(DelbaReq.Addr, pAd->MacTab.Content[Wcid].Addr);
				DelbaReq.Wcid = Wcid;
				DelbaReq.TID = TID;
				DelbaReq.Initiator = RECIPIENT;
				Elem->MsgLen  = sizeof(DelbaReq);
				memmove(Elem->Msg, &DelbaReq, sizeof(DelbaReq));
				MlmeDELBAAction(pAd, Elem);
				kfree(Elem);
			}
			else
			{
				DBGPRINT(RT_DEBUG_ERROR, ("%s():alloc memory failed!\n", __FUNCTION__));
				return;
			}
		}



		/* 2. Free resource of BA session*/
		/* flush all pending reordering mpdus */
		ba_refresh_reordering_mpdus(pAd, pBAEntry);

		spin_lock_bh(&pAd->BATabLock);

		/* Erase Bitmap flag.*/
		pBAEntry->LastIndSeq = RESET_RCV_SEQ;
		pBAEntry->BAWinSize = 0;
		/* Erase Bitmap flag at software mactable*/
		pAd->MacTab.Content[Wcid].RXBAbitmap &= (~(1<<(pBAEntry->TID)));
		pAd->MacTab.Content[Wcid].BARecWcidArray[TID] = 0;

		RTMP_DEL_BA_SESSION_FROM_ASIC(pAd, Wcid, TID);

		spin_unlock_bh(&pAd->BATabLock);

	}

	BATableFreeRecEntry(pAd, Idx);
}


VOID BASessionTearDownALL(struct rtmp_adapter *pAd, u8 Wcid)
{
	int i;

	for (i=0; i<NUM_OF_TID; i++)
	{
		BAOriSessionTearDown(pAd, Wcid, i, false, false);
		BARecSessionTearDown(pAd, Wcid, i, false);
	}
}


/*
	==========================================================================
	Description:
		Retry sending ADDBA Reqest.

	IRQL = DISPATCH_LEVEL

	Parametrs:
	p8023Header: if this is already 802.3 format, p8023Header is NULL

	Return	: true if put into rx reordering buffer, shouldn't indicaterxhere.
				false , then continue indicaterx at this moment.
	==========================================================================
 */
VOID BAOriSessionSetupTimeout(
    IN PVOID SystemSpecific1,
    IN PVOID FunctionContext,
    IN PVOID SystemSpecific2,
    IN PVOID SystemSpecific3)
{
	BA_ORI_ENTRY *pBAEntry = (BA_ORI_ENTRY *)FunctionContext;
	MAC_TABLE_ENTRY *pEntry;
	struct rtmp_adapter *pAd;

	if (pBAEntry == NULL)
		return;

	pAd = pBAEntry->pAdapter;

#ifdef CONFIG_STA_SUPPORT
	IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
	{
		/* Do nothing if monitor mode is on*/
		if (MONITOR_ON(pAd))
			return;
	}
#endif /* CONFIG_STA_SUPPORT */

	pEntry = &pAd->MacTab.Content[pBAEntry->Wcid];

	if ((pBAEntry->ORI_BA_Status == Originator_WaitRes) && (pBAEntry->Token < ORI_SESSION_MAX_RETRY))
	{
		MLME_ADDBA_REQ_STRUCT AddbaReq;

#ifdef CONFIG_STA_SUPPORT
		IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
		{
			if (INFRA_ON(pAd) &&
				RTMP_TEST_FLAG(pAd, fRTMP_ADAPTER_BSS_SCAN_IN_PROGRESS) &&
				(OPSTATUS_TEST_FLAG(pAd, fOP_STATUS_MEDIA_STATE_CONNECTED)))
			{
				/* In scan progress and have no chance to send out, just re-schedule to another time period */
				RTMPSetTimer(&pBAEntry->ORIBATimer, ORI_BA_SESSION_TIMEOUT);
				return;
			}
		}
#endif /* CONFIG_STA_SUPPORT */

		memset(&AddbaReq, 0, sizeof(AddbaReq));
		COPY_MAC_ADDR(AddbaReq.pAddr, pEntry->Addr);
		AddbaReq.Wcid = pEntry->wcid;
		AddbaReq.TID = pBAEntry->TID;
		AddbaReq.BaBufSize = pAd->CommonCfg.BACapability.field.RxBAWinLimit;
		AddbaReq.TimeOutValue = 0;
		AddbaReq.Token = pBAEntry->Token;
		MlmeEnqueue(pAd, ACTION_STATE_MACHINE, MT2_MLME_ADD_BA_CATE, sizeof(MLME_ADDBA_REQ_STRUCT), (PVOID)&AddbaReq, 0);
		RTMP_MLME_HANDLER(pAd);
		DBGPRINT(RT_DEBUG_TRACE,("BA Ori Session Timeout(%d) : Send ADD BA again\n", pBAEntry->Token));

		pBAEntry->Token++;
		RTMPSetTimer(&pBAEntry->ORIBATimer, ORI_BA_SESSION_TIMEOUT);
	}
	else
	{
		BATableFreeOriEntry(pAd, pEntry->BAOriWcidArray[pBAEntry->TID]);
	}
}


/*
	==========================================================================
	Description:
		Retry sending ADDBA Reqest.

	IRQL = DISPATCH_LEVEL

	Parametrs:
	p8023Header: if this is already 802.3 format, p8023Header is NULL

	Return	: true if put into rx reordering buffer, shouldn't indicaterxhere.
				false , then continue indicaterx at this moment.
	==========================================================================
 */
VOID BARecSessionIdleTimeout(
    IN PVOID SystemSpecific1,
    IN PVOID FunctionContext,
    IN PVOID SystemSpecific2,
    IN PVOID SystemSpecific3)
{

	BA_REC_ENTRY    *pBAEntry = (BA_REC_ENTRY *)FunctionContext;
	struct rtmp_adapter *  pAd;
	ULONG           Now32;

	if (pBAEntry == NULL)
		return;

	if ((pBAEntry->REC_BA_Status == Recipient_Accept))
	{
		NdisGetSystemUpTime(&Now32);

		if (RTMP_TIME_AFTER((unsigned long)Now32, (unsigned long)(pBAEntry->LastIndSeqAtTimer + REC_BA_SESSION_IDLE_TIMEOUT)))
		{
			pAd = pBAEntry->pAdapter;
			/* flush all pending reordering mpdus */
			ba_refresh_reordering_mpdus(pAd, pBAEntry);
			DBGPRINT(RT_DEBUG_OFF, ("%ld: REC BA session Timeout\n", Now32));
		}
	}
}


VOID PeerAddBAReqAction(struct rtmp_adapter *pAd, MLME_QUEUE_ELEM *Elem)
{
	u8 Status = 1;
	u8 pAddr[6];
	FRAME_ADDBA_RSP ADDframe;
	u8 *pOutBuffer = NULL;
	int NStatus;
	PFRAME_ADDBA_REQ pAddreqFrame = NULL;
	ULONG FrameLen, *ptemp;
	MAC_TABLE_ENTRY *pMacEntry;
#ifdef CONFIG_AP_SUPPORT
	INT apidx;
#endif /* CONFIG_AP_SUPPORT */

	DBGPRINT(RT_DEBUG_TRACE, ("%s ==> (Wcid = %d)\n", __FUNCTION__, Elem->Wcid));

	/*ADDBA Request from unknown peer, ignore this.*/

	if (Elem->Wcid >= MAX_LEN_OF_MAC_TABLE)
		return;

	pMacEntry = &pAd->MacTab.Content[Elem->Wcid];
	DBGPRINT(RT_DEBUG_TRACE,("BA - PeerAddBAReqAction----> \n"));
	ptemp = (unsigned long *)Elem->Msg;

	if (PeerAddBAReqActionSanity(pAd, Elem->Msg, Elem->MsgLen, pAddr))
	{

		if ((pAd->CommonCfg.bBADecline == false) && IS_HT_STA(pMacEntry))
		{
			pAddreqFrame = (PFRAME_ADDBA_REQ)(&Elem->Msg[0]);
			DBGPRINT(RT_DEBUG_OFF, ("Rcv Wcid(%d) AddBAReq\n", Elem->Wcid));
			if (BARecSessionAdd(pAd, &pAd->MacTab.Content[Elem->Wcid], pAddreqFrame))
			{
#ifdef PEER_DELBA_TX_ADAPT
				Peer_DelBA_Tx_Adapt_Disable(pAd, &pAd->MacTab.Content[Elem->Wcid]);
#endif /* PEER_DELBA_TX_ADAPT */
				Status = 0;
			}
			else
				Status = 38; /* more parameters have invalid values*/
		}
		else
		{
			Status = 37; /* the request has been declined.*/
		}
	}

	if (IS_ENTRY_CLIENT(pMacEntry))
		ASSERT(pMacEntry->Sst == SST_ASSOC);

	pAddreqFrame = (PFRAME_ADDBA_REQ)(&Elem->Msg[0]);
	/* 2. Always send back ADDBA Response */
	pOutBuffer = kmalloc(MGMT_DMA_BUFFER_SIZE, GFP_ATOMIC);	 /*Get an unused nonpaged memory*/
	if (pOutBuffer == NULL) {
		DBGPRINT(RT_DEBUG_TRACE,("ACTION - PeerBAAction() allocate memory failed \n"));
		return;
	}

	memset(&ADDframe, 0, sizeof(FRAME_ADDBA_RSP));
	/* 2-1. Prepare ADDBA Response frame.*/
#ifdef CONFIG_AP_SUPPORT
	IF_DEV_CONFIG_OPMODE_ON_AP(pAd)
	{
		{
			apidx = pMacEntry->apidx;
			ActHeaderInit(pAd, &ADDframe.Hdr, pAddr, pAd->ApCfg.MBSSID[apidx].wdev.if_addr, pAd->ApCfg.MBSSID[apidx].wdev.bssid);
		}
	}
#endif /* CONFIG_AP_SUPPORT */
#ifdef CONFIG_STA_SUPPORT
	IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
	{
		if (ADHOC_ON(pAd)
			)
			ActHeaderInit(pAd, &ADDframe.Hdr, pAddr, pAd->StaCfg.wdev.if_addr, pAd->CommonCfg.Bssid);
		else
			ActHeaderInit(pAd, &ADDframe.Hdr, pAd->CommonCfg.Bssid, pAd->StaCfg.wdev.if_addr, pAddr);
	}
#endif /* CONFIG_STA_SUPPORT */
	ADDframe.Category = CATEGORY_BA;
	ADDframe.Action = ADDBA_RESP;
	ADDframe.Token = pAddreqFrame->Token;
	/* What is the Status code??  need to check.*/
	ADDframe.StatusCode = Status;
	ADDframe.BaParm.BAPolicy = IMMED_BA;
	if (pMacEntry && IS_VHT_STA(pMacEntry) && (Status == 0))
		ADDframe.BaParm.AMSDUSupported = pAddreqFrame->BaParm.AMSDUSupported;
	else
		ADDframe.BaParm.AMSDUSupported = 0;

#ifdef WFA_VHT_PF
	if (pAd->CommonCfg.DesiredHtPhy.AmsduEnable)
		ADDframe.BaParm.AMSDUSupported = 1;
#endif /* WFA_VHT_PF */
	ADDframe.BaParm.TID = pAddreqFrame->BaParm.TID;
	ADDframe.BaParm.BufSize = min(((u8)pAddreqFrame->BaParm.BufSize), (u8)pAd->CommonCfg.BACapability.field.RxBAWinLimit);
	if (ADDframe.BaParm.BufSize == 0)
		ADDframe.BaParm.BufSize = 64;
	ADDframe.TimeOutValue = 0; /* pAddreqFrame->TimeOutValue; */

#ifdef UNALIGNMENT_SUPPORT
	{
		BA_PARM tmpBaParm;

		memmove(&tmpBaParm, &ADDframe.BaParm, sizeof(BA_PARM));
		*(unsigned short *)(&tmpBaParm) = cpu2le16(*(unsigned short *)(&tmpBaParm));
		memmove(&ADDframe.BaParm, &tmpBaParm, sizeof(BA_PARM));
	}
#else
	*(unsigned short *)(&ADDframe.BaParm) = cpu2le16(*(unsigned short *)(&ADDframe.BaParm));
#endif /* UNALIGNMENT_SUPPORT */

	ADDframe.StatusCode = cpu2le16(ADDframe.StatusCode);
	ADDframe.TimeOutValue = cpu2le16(ADDframe.TimeOutValue);

	MakeOutgoingFrame(pOutBuffer,               &FrameLen,
					  sizeof(FRAME_ADDBA_RSP),  &ADDframe,
			  END_OF_ARGS);
	MiniportMMRequest(pAd, QID_AC_BE, pOutBuffer, FrameLen);
	kfree(pOutBuffer);

	DBGPRINT(RT_DEBUG_TRACE, ("%s(%d): TID(%d), BufSize(%d) <== \n", __FUNCTION__, Elem->Wcid, ADDframe.BaParm.TID,
							  ADDframe.BaParm.BufSize));
}


VOID PeerAddBARspAction(struct rtmp_adapter *pAd, MLME_QUEUE_ELEM *Elem)
{
	PFRAME_ADDBA_RSP pFrame = NULL;

	/*ADDBA Response from unknown peer, ignore this.*/
	if (Elem->Wcid >= MAX_LEN_OF_MAC_TABLE)
		return;

	DBGPRINT(RT_DEBUG_TRACE, ("%s ==> Wcid(%d)\n", __FUNCTION__, Elem->Wcid));

	/*hex_dump("PeerAddBARspAction()", Elem->Msg, Elem->MsgLen);*/

	if (PeerAddBARspActionSanity(pAd, Elem->Msg, Elem->MsgLen))
	{
		pFrame = (PFRAME_ADDBA_RSP)(&Elem->Msg[0]);

		DBGPRINT(RT_DEBUG_TRACE, ("\t\t StatusCode = %d\n", pFrame->StatusCode));
		switch (pFrame->StatusCode)
		{
			case 0:
				/* I want a BAsession with this peer as an originator. */
				BAOriSessionAdd(pAd, &pAd->MacTab.Content[Elem->Wcid], pFrame);
#ifdef PEER_DELBA_TX_ADAPT
				Peer_DelBA_Tx_Adapt_Disable(pAd, &pAd->MacTab.Content[Elem->Wcid]);
#endif /* PEER_DELBA_TX_ADAPT */
				break;
			default:
				/* check status == USED ??? */
				BAOriSessionTearDown(pAd, Elem->Wcid, pFrame->BaParm.TID, true, false);
				break;
		}
		/* Rcv Decline StatusCode*/
		if ((pFrame->StatusCode == 37)
#ifdef CONFIG_STA_SUPPORT
            || ((pAd->OpMode == OPMODE_STA) && STA_TGN_WIFI_ON(pAd) && (pFrame->StatusCode != 0))
#endif /* CONFIG_STA_SUPPORT */
            )
		{
			pAd->MacTab.Content[Elem->Wcid].BADeclineBitmap |= 1<<pFrame->BaParm.TID;
		}
	}
}

VOID PeerDelBAAction(
	IN struct rtmp_adapter *pAd,
	IN MLME_QUEUE_ELEM *Elem)

{
	PFRAME_DELBA_REQ    pDelFrame = NULL;

	DBGPRINT(RT_DEBUG_TRACE,("%s ==>\n", __FUNCTION__));
	/*DELBA Request from unknown peer, ignore this.*/
	if (PeerDelBAActionSanity(pAd, Elem->Wcid, Elem->Msg, Elem->MsgLen))
	{
		pDelFrame = (PFRAME_DELBA_REQ)(&Elem->Msg[0]);

#ifdef PEER_DELBA_TX_ADAPT
		if (pDelFrame->DelbaParm.TID == 0)
			Peer_DelBA_Tx_Adapt_Enable(pAd, &pAd->MacTab.Content[Elem->Wcid]);
#endif /* PEER_DELBA_TX_ADAPT */

		if (pDelFrame->DelbaParm.Initiator == ORIGINATOR)
		{
			DBGPRINT(RT_DEBUG_TRACE,("BA - PeerDelBAAction----> ORIGINATOR\n"));
			BARecSessionTearDown(pAd, Elem->Wcid, pDelFrame->DelbaParm.TID, true);
		}
		else
		{
			DBGPRINT(RT_DEBUG_TRACE,("BA - PeerDelBAAction----> RECIPIENT, Reason = %d\n",  pDelFrame->ReasonCode));
			/*hex_dump("DelBA Frame", pDelFrame, Elem->MsgLen);*/
			BAOriSessionTearDown(pAd, Elem->Wcid, pDelFrame->DelbaParm.TID, true, false);
		}
	}
}


bool CntlEnqueueForRecv(
						  IN struct rtmp_adapter *pAd,
						  IN ULONG Wcid,
						  IN ULONG MsgLen,
						  IN PFRAME_BA_REQ pMsg)
{
	PFRAME_BA_REQ pFrame = pMsg;
	PBA_REC_ENTRY pBAEntry;
	ULONG Idx;
	u8 TID;

	TID = (u8)pFrame->BARControl.TID;

	DBGPRINT(RT_DEBUG_TRACE, ("%s(): BAR-Wcid(%ld), Tid (%d)\n", __FUNCTION__, Wcid, TID));
	/*hex_dump("BAR", (PCHAR) pFrame, MsgLen);*/
	/* Do nothing if the driver is starting halt state.*/
	/* This might happen when timer already been fired before cancel timer with mlmehalt*/
	if (RTMP_TEST_FLAG(pAd, fRTMP_ADAPTER_HALT_IN_PROGRESS | fRTMP_ADAPTER_NIC_NOT_EXIST))
		return false;

	/* First check the size, it MUST not exceed the mlme queue size*/
	if (MsgLen > MGMT_DMA_BUFFER_SIZE) /* 1600B */
	{
		DBGPRINT_ERR(("CntlEnqueueForRecv: frame too large, size = %ld \n", MsgLen));
		return false;
	}
	else if (MsgLen != sizeof(FRAME_BA_REQ))
	{
		DBGPRINT_ERR(("CntlEnqueueForRecv: BlockAck Request frame length size = %ld incorrect\n", MsgLen));
		return false;
	}
	else if (MsgLen != sizeof(FRAME_BA_REQ))
	{
		DBGPRINT_ERR(("CntlEnqueueForRecv: BlockAck Request frame length size = %ld incorrect\n", MsgLen));
		return false;
	}

	if ((Wcid < MAX_LEN_OF_MAC_TABLE) && (TID < 8))
	{
		/* if this receiving packet is from SA that is in our OriEntry. Since WCID <9 has direct mapping. no need search.*/
		Idx = pAd->MacTab.Content[Wcid].BARecWcidArray[TID];
		pBAEntry = &pAd->BATable.BARecEntry[Idx];
	}
	else
	{
		return false;
	}

	DBGPRINT(RT_DEBUG_TRACE, ("BAR(%ld) : Tid (%d) - %04x:%04x\n", Wcid, TID, pFrame->BAStartingSeq.field.StartSeq, pBAEntry->LastIndSeq ));

	if (SEQ_SMALLER(pBAEntry->LastIndSeq, pFrame->BAStartingSeq.field.StartSeq, MAXSEQ))
	{
		/*DBGPRINT(RT_DEBUG_TRACE, ("BAR Seq = %x, LastIndSeq = %x\n", pFrame->BAStartingSeq.field.StartSeq, pBAEntry->LastIndSeq));*/
		ba_indicate_reordering_mpdus_le_seq(pAd, pBAEntry, pFrame->BAStartingSeq.field.StartSeq);
		pBAEntry->LastIndSeq = (pFrame->BAStartingSeq.field.StartSeq == 0) ? MAXSEQ :(pFrame->BAStartingSeq.field.StartSeq -1);
	}
	/*ba_refresh_reordering_mpdus(pAd, pBAEntry);*/
	return true;
}


/* Description : Send SMPS Action frame If SMPS mode switches. */
VOID SendSMPSAction(struct rtmp_adapter *pAd, u8 Wcid, u8 smps)
{
	struct rtmp_wifi_dev *wdev;
	MAC_TABLE_ENTRY *pEntry;
	u8 *pOutBuffer = NULL;
	int NStatus;
	FRAME_SMPS_ACTION Frame;
	ULONG FrameLen;


	pOutBuffer = kmalloc(MGMT_DMA_BUFFER_SIZE, GFP_ATOMIC);	 /*Get an unused nonpaged memory*/
	if (pOutBuffer == NULL) {
		DBGPRINT(RT_DEBUG_ERROR,("BA - MlmeADDBAAction() allocate memory failed \n"));
		return;
	}

	if (!VALID_WCID(Wcid))
	{
		kfree(pOutBuffer);
		DBGPRINT(RT_DEBUG_ERROR,("BA - Invalid WCID(%d)\n",  Wcid));
		return;
	}

	pEntry = &pAd->MacTab.Content[Wcid];
	wdev = pEntry->wdev;
	if (!wdev)
	{
		kfree(pOutBuffer);
		DBGPRINT(RT_DEBUG_ERROR, ("BA - wdev is null\n"));
		return;
	}

	ActHeaderInit(pAd, &Frame.Hdr, pEntry->Addr, wdev->if_addr, wdev->bssid);
	Frame.Category = CATEGORY_HT;
	Frame.Action = SMPS_ACTION;
	switch (smps)
	{
		case MMPS_DISABLE:
			Frame.smps = 0;
			break;
		case MMPS_DYNAMIC:
			Frame.smps = 3;
			break;
		case MMPS_STATIC:
			Frame.smps = 1;
			break;
	}


	MakeOutgoingFrame(pOutBuffer, &FrameLen,
					  sizeof(FRAME_SMPS_ACTION), &Frame,
					  END_OF_ARGS);
	MiniportMMRequest(pAd, QID_AC_BE, pOutBuffer, FrameLen);
	kfree(pOutBuffer);
	DBGPRINT(RT_DEBUG_ERROR,("HT - %s( %d )  \n", __FUNCTION__, Frame.smps));
}


#define RADIO_MEASUREMENT_REQUEST_ACTION	0

typedef struct GNU_PACKED _BEACON_REQUEST {
	u8 RegulatoryClass;
	u8 ChannelNumber;
	unsigned short RandomInterval;
	unsigned short MeasurementDuration;
	u8 MeasurementMode;
	u8   BSSID[MAC_ADDR_LEN];
	u8 ReportingCondition;
	u8 Threshold;
	u8   SSIDIE[2];			/* 2 byte*/
} BEACON_REQUEST;

typedef struct GNU_PACKED _MEASUREMENT_REQ
{
	u8 ID;
	u8 Length;
	u8 Token;
	u8 RequestMode;
	u8 Type;
} MEASUREMENT_REQ;


#ifdef CONFIG_AP_SUPPORT
VOID SendBeaconRequest(struct rtmp_adapter *pAd, u8 Wcid)
{
	u8 *pOutBuffer = NULL;
	int NStatus;
	FRAME_RM_REQ_ACTION Frame;
	ULONG FrameLen;
	BEACON_REQUEST BeaconReq;
	MEASUREMENT_REQ MeasureReg;
	u8 apidx;

	if (IS_ENTRY_APCLI(&pAd->MacTab.Content[Wcid]))
		return;

	pOutBuffer = kmalloc(MGMT_DMA_BUFFER_SIZE, GFP_ATOMIC);	 /*Get an unused nonpaged memory*/
	if (pOutBuffer == NULL) {
		DBGPRINT(RT_DEBUG_ERROR,("Radio - SendBeaconRequest() allocate memory failed \n"));
		return;
	}
	apidx = pAd->MacTab.Content[Wcid].apidx;
	ActHeaderInit(pAd, &Frame.Hdr, pAd->MacTab.Content[Wcid].Addr, pAd->ApCfg.MBSSID[apidx].wdev.if_addr, pAd->ApCfg.MBSSID[apidx].wdev.bssid);

	Frame.Category = CATEGORY_RM;
	Frame.Action = RADIO_MEASUREMENT_REQUEST_ACTION;
	Frame.Token = 1;
	Frame.Repetition = 0;	/* executed once*/

	BeaconReq.RegulatoryClass = 32;		/* ?????*/
	BeaconReq.ChannelNumber = 255;		/* all channels*/
	BeaconReq.RandomInterval = 0;
	BeaconReq.MeasurementDuration = 10;	/* 10 TU*/
	BeaconReq.MeasurementMode = 1; 		/* Active mode */
	COPY_MAC_ADDR(BeaconReq.BSSID, 	BROADCAST_ADDR);
	BeaconReq.ReportingCondition = 254;	/* report not necesssary*/
	BeaconReq.Threshold = 0;			/* minimum RCPI*/
	BeaconReq.SSIDIE[0] = 0;
	BeaconReq.SSIDIE[1] = 0; 			/* wildcard SSID zero length */


	MeasureReg.ID = IE_MEASUREMENT_REQUEST;
	MeasureReg.Token = 0;
	MeasureReg.RequestMode = 0;
	MeasureReg.Type = 5;				/* Beacon Request*/
	MeasureReg.Length = sizeof(MEASUREMENT_REQ)+sizeof(BEACON_REQUEST)-2;

	MakeOutgoingFrame(pOutBuffer,               &FrameLen,
					  sizeof(FRAME_RM_REQ_ACTION),      &Frame,
					  sizeof(MEASUREMENT_REQ),			&MeasureReg,
					  sizeof(BEACON_REQUEST),			&BeaconReq,
					  END_OF_ARGS);
	MiniportMMRequest(pAd, QID_AC_BE, pOutBuffer, FrameLen);
	kfree(pOutBuffer);
	DBGPRINT(RT_DEBUG_TRACE,("Radio - SendBeaconRequest\n"));
}
#endif /* CONFIG_AP_SUPPORT */


void convert_reordering_packet_to_preAMSDU_or_802_3_packet(
	IN	struct rtmp_adapter *pAd,
	IN	RX_BLK			*pRxBlk,
	IN  u8 		FromWhichBSSID)
{
	struct sk_buff *pRxPkt;
	u8 		Header802_3[LENGTH_802_3];

/*
	1. get 802.3 Header
	2. remove LLC
		a. pointer pRxBlk->pData to payload
		b. modify pRxBlk->DataSize
*/
#ifdef CONFIG_AP_SUPPORT
	IF_DEV_CONFIG_OPMODE_ON_AP(pAd)
		RTMP_AP_802_11_REMOVE_LLC_AND_CONVERT_TO_802_3(pRxBlk, Header802_3);
#endif /* CONFIG_AP_SUPPORT */

#ifdef CONFIG_STA_SUPPORT
	IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
		RTMP_802_11_REMOVE_LLC_AND_CONVERT_TO_802_3(pRxBlk, Header802_3);
#endif /* CONFIG_STA_SUPPORT */

	ASSERT(pRxBlk->pRxPacket);

	pRxPkt = pRxBlk->pRxPacket;

	pRxPkt->dev = get_netdev_from_bssid(pAd, FromWhichBSSID);
	pRxPkt->data = pRxBlk->pData;
	pRxPkt->len = pRxBlk->DataSize;
	skb_set_tail_pointer(pRxPkt , pRxBlk->DataSize);

	/* copy 802.3 header, if necessary*/
	if (!RX_BLK_TEST_FLAG(pRxBlk, fRX_AMSDU))
	{
#ifdef CONFIG_AP_SUPPORT
		IF_DEV_CONFIG_OPMODE_ON_AP(pAd)
		{
			/* maybe insert VLAN tag to the received packet */
			u8 VLAN_Size = 0;
			u8 *data_p;
			unsigned short VLAN_VID = 0, VLAN_Priority = 0;

			/* VLAN related */
			MBSS_VLAN_INFO_GET(pAd, VLAN_VID, VLAN_Priority, FromWhichBSSID);

#ifdef WDS_VLAN_SUPPORT
			if (VLAN_VID == 0) /* maybe WDS packet */
				WDS_VLAN_INFO_GET(pAd, VLAN_VID, VLAN_Priority, FromWhichBSSID);
#endif /* WDS_VLAN_SUPPORT */

			if (VLAN_VID != 0)
				VLAN_Size = LENGTH_802_1Q;

			data_p = skb_push(pRxPkt, LENGTH_802_3+VLAN_Size);
			RT_VLAN_8023_HEADER_COPY(pAd, VLAN_VID, VLAN_Priority,
									Header802_3, LENGTH_802_3,
									data_p, FromWhichBSSID, TPID);
		}
#endif /* CONFIG_AP_SUPPORT */

#ifdef CONFIG_STA_SUPPORT
		IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
		{
#ifdef LINUX
			u8 *data_p;
			data_p = skb_push(pRxPkt, LENGTH_802_3);
			memmove(data_p, Header802_3, LENGTH_802_3);
#endif
		}
#endif /* CONFIG_STA_SUPPORT */
	}
}


#define INDICATE_LEGACY_OR_AMSDU(_pAd, _pRxBlk, _fromWhichBSSID)		\
	do																	\
	{																	\
    	if (RX_BLK_TEST_FLAG(_pRxBlk, fRX_AMSDU))						\
    	{																\
    		Indicate_AMSDU_Packet(_pAd, _pRxBlk, _fromWhichBSSID);		\
    	}																\
		else if (RX_BLK_TEST_FLAG(_pRxBlk, fRX_EAP))					\
		{																\
			Indicate_EAPOL_Packet(_pAd, _pRxBlk, _fromWhichBSSID);		\
		}																\
    	else															\
    	{																\
    		Indicate_Legacy_Packet(_pAd, _pRxBlk, _fromWhichBSSID);		\
    	}																\
	} while (0);



static VOID ba_enqueue_reordering_packet(
	IN struct rtmp_adapter *pAd,
	IN BA_REC_ENTRY *pBAEntry,
	IN	RX_BLK			*pRxBlk,
	IN	u8 		FromWhichBSSID)
{
	struct reordering_mpdu *mpdu_blk;
	uint16_t Sequence = (uint16_t) pRxBlk->pHeader->Sequence;

	mpdu_blk = ba_mpdu_blk_alloc(pAd);
	if ((mpdu_blk != NULL) &&
		(!RX_BLK_TEST_FLAG(pRxBlk, fRX_EAP)))
	{
		/* Write RxD buffer address & allocated buffer length */
		spin_lock_bh(&pBAEntry->RxReRingLock);

		mpdu_blk->Sequence = Sequence;
		mpdu_blk->OpMode = pRxBlk->OpMode;

		mpdu_blk->bAMSDU = RX_BLK_TEST_FLAG(pRxBlk, fRX_AMSDU);

		convert_reordering_packet_to_preAMSDU_or_802_3_packet(pAd, pRxBlk, FromWhichBSSID);

		STATS_INC_RX_PACKETS(pAd, FromWhichBSSID);


		/* it is necessary for reordering packet to record
			which BSS it come from
		*/
		RTMP_SET_PACKET_IF(pRxBlk->pRxPacket, FromWhichBSSID);

		mpdu_blk->pPacket = pRxBlk->pRxPacket;

		if (ba_reordering_mpdu_insertsorted(&pBAEntry->list, mpdu_blk) == false)
		{
			/* had been already within reordering list don't indicate */
			dev_kfree_skb_any(pRxBlk->pRxPacket);
			ba_mpdu_blk_free(pAd, mpdu_blk);
		}

		ASSERT((0<= pBAEntry->list.qlen)  && (pBAEntry->list.qlen <= pBAEntry->BAWinSize));
		spin_unlock_bh(&pBAEntry->RxReRingLock);
	}
	else
	{
		DBGPRINT(RT_DEBUG_ERROR,  ("!!! (%d) Can't allocate reordering mpdu blk\n",
								   pBAEntry->list.qlen));
		/*
		 * flush all pending reordering mpdus
		 * and receving mpdu to upper layer
		 * make tcp/ip to take care reordering mechanism
		 */
		/*ba_refresh_reordering_mpdus(pAd, pBAEntry);*/
		ba_indicate_reordering_mpdus_le_seq(pAd, pBAEntry, Sequence);

		pBAEntry->LastIndSeq = Sequence;
		INDICATE_LEGACY_OR_AMSDU(pAd, pRxBlk, FromWhichBSSID);
	}
}




/*
	==========================================================================
	Description:
		Indicate this packet to upper layer or put it into reordering buffer

	Parametrs:
		pRxBlk         : carry necessary packet info 802.11 format
		FromWhichBSSID : the packet received from which BSS

	Return	:
			  none

	Note    :
	          the packet queued into reordering buffer need to cover to 802.3 format
			  or pre_AMSDU format
	==========================================================================
*/
VOID Indicate_AMPDU_Packet(struct rtmp_adapter *pAd, RX_BLK *pRxBlk, u8 FromWhichBSSID)
{
	unsigned short Idx;
	PBA_REC_ENTRY pBAEntry = NULL;
	uint16_t Sequence = pRxBlk->pHeader->Sequence;
	ULONG Now32;

	if (!RX_BLK_TEST_FLAG(pRxBlk, fRX_AMSDU) &&  (pRxBlk->DataSize > MAX_RX_PKT_LEN))
	{
		static int err_size;

		err_size++;
		if (err_size > 20) {
			 DBGPRINT(RT_DEBUG_TRACE, ("AMPDU DataSize = %d\n", pRxBlk->DataSize));
			 hex_dump("802.11 Header", (u8 *)pRxBlk->pHeader, 24);
			 hex_dump("Payload", pRxBlk->pData, 64);
			 err_size = 0;
		}

		dev_kfree_skb_any(pRxBlk->pRxPacket);
		return;
	}

	if (pRxBlk->wcid < MAX_LEN_OF_MAC_TABLE)
	{
		Idx = pAd->MacTab.Content[pRxBlk->wcid].BARecWcidArray[pRxBlk->TID];
		if (Idx == 0)
		{
			/* Rec BA Session had been torn down */
			INDICATE_LEGACY_OR_AMSDU(pAd, pRxBlk, FromWhichBSSID);
			return;
		}
		pBAEntry = &pAd->BATable.BARecEntry[Idx];
	}
	else
	{
		/* impossible !!! release packet*/
		ASSERT(0);
		dev_kfree_skb_any(pRxBlk->pRxPacket);
		return;
	}

	ASSERT(pBAEntry);

	/* update last rx time*/
	NdisGetSystemUpTime(&Now32);

	pBAEntry->rcvSeq = Sequence;


	ba_flush_reordering_timeout_mpdus(pAd, pBAEntry, Now32);
	pBAEntry->LastIndSeqAtTimer = Now32;


	/* Reset Last Indicate Sequence*/
	if (pBAEntry->LastIndSeq == RESET_RCV_SEQ)
	{
		ASSERT((pBAEntry->list.qlen == 0) && (pBAEntry->list.next == NULL));

		/* reset rcv sequence of BA session */
		pBAEntry->LastIndSeq = Sequence;
		pBAEntry->LastIndSeqAtTimer = Now32;
		INDICATE_LEGACY_OR_AMSDU(pAd, pRxBlk, FromWhichBSSID);
		return;
	}


	/* I. Check if in order.*/
	if (SEQ_STEPONE(Sequence, pBAEntry->LastIndSeq, MAXSEQ))
	{
		unsigned short  LastIndSeq;

		pBAEntry->LastIndSeq = Sequence;
		INDICATE_LEGACY_OR_AMSDU(pAd, pRxBlk, FromWhichBSSID);
 		LastIndSeq = ba_indicate_reordering_mpdus_in_order(pAd, pBAEntry, pBAEntry->LastIndSeq);
		if (LastIndSeq != RESET_RCV_SEQ)
			pBAEntry->LastIndSeq = LastIndSeq;

		pBAEntry->LastIndSeqAtTimer = Now32;
	}

	/* II. Drop Duplicated Packet*/
	else if (Sequence == pBAEntry->LastIndSeq)
	{

		pBAEntry->nDropPacket++;
		dev_kfree_skb_any(pRxBlk->pRxPacket);
	}

	/* III. Drop Old Received Packet*/
	else if (SEQ_SMALLER(Sequence, pBAEntry->LastIndSeq, MAXSEQ))
	{

		pBAEntry->nDropPacket++;
		dev_kfree_skb_any(pRxBlk->pRxPacket);
	}

	/* IV. Receive Sequence within Window Size*/
	else if (SEQ_SMALLER(Sequence, (((pBAEntry->LastIndSeq+pBAEntry->BAWinSize+1)) & MAXSEQ), MAXSEQ))
	{
		ba_enqueue_reordering_packet(pAd, pBAEntry, pRxBlk, FromWhichBSSID);
	}

	/* V. Receive seq surpasses Win(lastseq + nMSDU). So refresh all reorder buffer*/
	else
	{
		LONG WinStartSeq, TmpSeq;


		TmpSeq = Sequence - (pBAEntry->BAWinSize) -1;
		if (TmpSeq < 0)
			TmpSeq = (MAXSEQ+1) + TmpSeq;

		WinStartSeq = (TmpSeq+1) & MAXSEQ;
		ba_indicate_reordering_mpdus_le_seq(pAd, pBAEntry, WinStartSeq);
		pBAEntry->LastIndSeq = WinStartSeq; /*TmpSeq;          */

		pBAEntry->LastIndSeqAtTimer = Now32;

		ba_enqueue_reordering_packet(pAd, pBAEntry, pRxBlk, FromWhichBSSID);

		TmpSeq = ba_indicate_reordering_mpdus_in_order(pAd, pBAEntry, pBAEntry->LastIndSeq);
		if (TmpSeq != RESET_RCV_SEQ)
			pBAEntry->LastIndSeq = TmpSeq;
	}
}




VOID BaReOrderingBufferMaintain(struct rtmp_adapter *pAd)
{
    ULONG Now32;
    u8 Wcid;
    unsigned short Idx;
    u8 TID;
    PBA_REC_ENTRY pBAEntry = NULL;
    PMAC_TABLE_ENTRY pEntry = NULL;

    /* update last rx time*/
    NdisGetSystemUpTime(&Now32);

    for (Wcid = 1; Wcid < MAX_LEN_OF_MAC_TABLE; Wcid++)
    {
        pEntry = &pAd->MacTab.Content[Wcid];
        if (IS_ENTRY_NONE(pEntry))
            continue;

        for (TID= 0; TID < NUM_OF_TID; TID++)
        {
            Idx = pAd->MacTab.Content[Wcid].BARecWcidArray[TID];
            pBAEntry = &pAd->BATable.BARecEntry[Idx];
            ba_flush_reordering_timeout_mpdus(pAd, pBAEntry, Now32);
        }
    }
}


#ifdef PEER_DELBA_TX_ADAPT
VOID Peer_DelBA_Tx_Adapt_Init(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY pEntry)
{
	pEntry->bPeerDelBaTxAdaptEn = 0;
	RTMPInitTimer(pAd, &pEntry->DelBA_tx_AdaptTimer, GET_TIMER_FUNCTION(PeerDelBATxAdaptTimeOut), pEntry, false);
}

static VOID Peer_DelBA_Tx_Adapt_Enable(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY pEntry)
{
}

static VOID Peer_DelBA_Tx_Adapt_Disable(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY pEntry)
{
}

VOID PeerDelBATxAdaptTimeOut(
	IN PVOID SystemSpecific1,
	IN PVOID FunctionContext,
	IN PVOID SystemSpecific2,
	IN PVOID SystemSpecific3)
{
	PMAC_TABLE_ENTRY pEntry = (PMAC_TABLE_ENTRY) FunctionContext;

	DBGPRINT(RT_DEBUG_OFF, ("%s()\n", __FUNCTION__));

	/* Disable Tx Mac look up table (Ressume original setting) */
	Peer_DelBA_Tx_Adapt_Disable(pEntry->pAd, pEntry);
}
#endif /* PEER_DELBA_TX_ADAPT */

