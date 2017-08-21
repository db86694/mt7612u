/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

	Module Name:

	Abstract:

	Revision History:
	Who 		When			What
	--------	----------		----------------------------------------------
*/

#ifndef __FCE_H__
#define __FCE_H__

#include "rt_config.h"

#define FCE_PSE_CTRL	0x0800
#define FCE_PARAMETERS	0x0804
#define FCE_CSO			0x0808
#define MT_FCE_L2_STUFF	0x080c
#define TX_CPU_PORT_FROM_FCE_BASE_PTR		0x09A0
#define TX_CPU_PORT_FROM_FCE_MAX_COUNT		0x09A4
#define FCE_PDMA_GLOBAL_CONF				0x09C4
#define TX_CPU_PORT_FROM_FCE_CPU_DESC_INDEX 0x09A8
#define FCE_SKIP_FS							0x0A6C
#define PER_PORT_PAUSE_ENABLE_CONTROL1		0x0A38

#define MT_FCE_L2_STUFF_HT_L2_EN	BIT(0)
#define MT_FCE_L2_STUFF_QOS_L2_EN	BIT(1)
#define MT_FCE_L2_STUFF_RX_STUFF_EN	BIT(2)
#define MT_FCE_L2_STUFF_TX_STUFF_EN	BIT(3)
#define MT_FCE_L2_STUFF_WR_MPDU_LEN_EN	BIT(4)
#define MT_FCE_L2_STUFF_MVINV_BSWAP	BIT(5)
#define MT_FCE_L2_STUFF_TS_CMD_QSEL_EN	GENMASK(15, 8)
#define MT_FCE_L2_STUFF_TS_LEN_EN	GENMASK(23, 16)
#define MT_FCE_L2_STUFF_OTHER_PORT	GENMASK(25, 24)


#define NORMAL_PKT				0x0
#define CMD_PKT					0x1

#define FCE_WLAN_PORT			0x0
#define FCE_CPU_RX_PORT			0x1
#define FCE_CPU_TX_PORT			0x2
#define FCE_HOST_PORT			0x3
#define FCE_VIRTUAL_CPU_RX_PORT	0x4
#define FCE_VIRTUAL_CPU_TX_PORT	0x5
#define FCE_DISCARD				0x6
#endif /*__FCE_H__ */

