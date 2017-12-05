/****************************************************************************
 * Ralink Tech Inc.
 * Taiwan, R.O.C.
 *
 * (c) Copyright 2010, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************/

#include "rt_config.h"



u8 RateSwitchTable11B[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x04, 0x03,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x00,  0, 40, 101,
    0x01, 0x00,  1, 40, 50,
    0x02, 0x00,  2, 35, 45,
    0x03, 0x00,  3, 20, 45,
};

u8 RateSwitchTable11BG[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0a, 0x00,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x00,  0, 40, 101,
    0x01, 0x00,  1, 40, 50,
    0x02, 0x00,  2, 35, 45,
    0x03, 0x00,  3, 20, 45,
    0x04, 0x10,  2, 20, 35,
    0x05, 0x10,  3, 16, 35,
    0x06, 0x10,  4, 10, 25,
    0x07, 0x10,  5, 16, 25,
    0x08, 0x10,  6, 10, 25,
    0x09, 0x10,  7, 10, 13,
};

u8 RateSwitchTable11G[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x08, 0x00,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x10,  0, 20, 101,
    0x01, 0x10,  1, 20, 35,
    0x02, 0x10,  2, 20, 35,
    0x03, 0x10,  3, 16, 35,
    0x04, 0x10,  4, 10, 25,
    0x05, 0x10,  5, 16, 25,
    0x06, 0x10,  6, 10, 25,
    0x07, 0x10,  7, 10, 13,
};


u8 RateSwitchTable11N1S[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0c, 0x0a,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x00,  0, 40, 101,
    0x01, 0x00,  1, 40, 50,
    0x02, 0x00,  2, 25, 45,
    0x03, 0x21,  0, 20, 35,
    0x04, 0x21,  1, 20, 35,
    0x05, 0x21,  2, 20, 35,
    0x06, 0x21,  3, 15, 35,
    0x07, 0x21,  4, 15, 30,
    0x08, 0x21,  5, 10, 25,
    0x09, 0x21,  6,  8, 14,
    0x0a, 0x21,  7,  8, 14,
    0x0b, 0x23,  7,  8, 14,
};


u8 RateSwitchTable11N2S[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0e, 0x0c,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x00,  0, 40, 101,
    0x01, 0x00,  1, 40, 50,
    0x02, 0x00,  2, 25, 45,
    0x03, 0x21,  0, 20, 35,
    0x04, 0x21,  1, 20, 35,
    0x05, 0x21,  2, 20, 35,
    0x06, 0x21,  3, 15, 35,
    0x07, 0x21,  4, 15, 30,
    0x08, 0x20, 11, 15, 30,
    0x09, 0x20, 12, 15, 30,
    0x0a, 0x20, 13,  8, 20,
    0x0b, 0x20, 14,  8, 20,
    0x0c, 0x20, 15,  8, 25,
    0x0d, 0x22, 15,  8, 15,
};


u8 RateSwitchTable11N3S[] = {
/* Item No.	Mode	Curr-MCS	TrainUp	TrainDown	 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x11, 0x0c,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x00,  0, 40, 101,
    0x01, 0x00,  1, 40, 50,
    0x02, 0x00,  2, 25, 45,
    0x03, 0x21,  0, 20, 35,
    0x04, 0x21,  1, 20, 35,
    0x05, 0x21,  2, 20, 35,
    0x06, 0x21,  3, 15, 35,
    0x07, 0x21,  4, 15, 30,
    0x08, 0x20, 11, 15, 30,
    0x09, 0x20, 12, 15, 22,
    0x0a, 0x20, 13,  8, 20,
    0x0b, 0x20, 14,  8, 20,
    0x0c, 0x20, 20,  8, 20,
    0x0d, 0x20, 21,  8, 20,
    0x0e, 0x20, 22,  8, 20,
    0x0f, 0x20, 23,  8, 20,
    0x10, 0x22, 23,  8, 15,
};


u8 RateSwitchTable11BGN1S[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0c, 0x0a,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x00,  0, 40, 101,
    0x01, 0x00,  1, 40, 50,
    0x02, 0x00,  2, 25, 45,
    0x03, 0x21,  0, 20, 35,
    0x04, 0x21,  1, 20, 35,
    0x05, 0x21,  2, 20, 35,
    0x06, 0x21,  3, 15, 35,
    0x07, 0x21,  4, 15, 30,
    0x08, 0x21,  5, 10, 25,
    0x09, 0x21,  6,  8, 14,
    0x0a, 0x21,  7,  8, 14,
    0x0b, 0x23,  7,  8, 14,
};


u8 RateSwitchTable11BGN2S[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0e, 0x0c,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x00,  0, 40, 101,
    0x01, 0x00,  1, 40, 50,
    0x02, 0x00,  2, 25, 45,
    0x03, 0x21,  0, 20, 35,
    0x04, 0x21,  1, 20, 35,
    0x05, 0x21,  2, 20, 35,
    0x06, 0x21,  3, 15, 35,
    0x07, 0x21,  4, 15, 30,
    0x08, 0x20, 11, 15, 30,
    0x09, 0x20, 12, 15, 22,
    0x0a, 0x20, 13,  8, 20,
    0x0b, 0x20, 14,  8, 20,
    0x0c, 0x20, 15,  8, 20,
    0x0d, 0x22, 15,  8, 15,
};


u8 RateSwitchTable11BGN3S[] = { /* 3*3*/
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0e, 0x00,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x21,  0, 30,101,	/*50*/
    0x01, 0x21,  1, 20, 50,
    0x02, 0x21,  2, 20, 50,
    0x03, 0x21,  3, 20, 50,
    0x04, 0x21,  4, 15, 50,
    0x05, 0x20, 11, 15, 30,
    0x06, 0x20, 12, 15, 30,
    0x07, 0x20, 13,  8, 20,
    0x08, 0x20, 14,  8, 20,
    0x09, 0x20, 15,  8, 25,
    /*0x0a, 0x20, 20, 15, 30,*/
    0x0a, 0x20, 21,  8, 20,
    0x0b, 0x20, 22,  8, 20,
    0x0c, 0x20, 23,  8, 25,
    0x0d, 0x22, 23,  8, 25,
};


u8 RateSwitchTable11N1SForABand[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown	*/
/* Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF) */
    0x09, 0x07,  0,  0,  0,						/* Initial used item after association */
    0x00, 0x21,  0, 30, 101,
    0x01, 0x21,  1, 20, 50,
    0x02, 0x21,  2, 20, 50,
    0x03, 0x21,  3, 15, 50,
    0x04, 0x21,  4, 15, 30,
    0x05, 0x21,  5, 10, 25,
    0x06, 0x21,  6,  8, 14,
    0x07, 0x21,  7,  8, 14,
    0x08, 0x23,  7,  8, 14,
};


u8 RateSwitchTable11N2SForABand[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0b, 0x09,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x21,  0, 30, 101,
    0x01, 0x21,  1, 20, 50,
    0x02, 0x21,  2, 20, 50,
    0x03, 0x21,  3, 15, 50,
    0x04, 0x21,  4, 15, 30,
    0x05, 0x21,  5, 15, 30,
    0x06, 0x20, 12,  15, 30,
    0x07, 0x20, 13,  8, 20,
    0x08, 0x20, 14,  8, 20,
    0x09, 0x20, 15,  8, 25,
    0x0a, 0x22, 15,  8, 25,
};


u8 RateSwitchTable11BGN2SForABand[] = {
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0b, 0x09,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x21,  0, 30,101,	/*50*/
    0x01, 0x21,  1, 20, 50,
    0x02, 0x21,  2, 20, 50,
    0x03, 0x21,  3, 15, 50,
    0x04, 0x21,  4, 15, 30,
    0x05, 0x21,  5, 15, 30,
    0x06, 0x20, 12, 15, 30,
    0x07, 0x20, 13,  8, 20,
    0x08, 0x20, 14,  8, 20,
    0x09, 0x20, 15,  8, 25,
    0x0a, 0x22, 15,  8, 25,
};


u8 RateSwitchTable11N3SForABand[] = { /* 3*3*/
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0e, 0x09,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x21,  0, 30, 101,
    0x01, 0x21,  1, 20, 50,
    0x02, 0x21,  2, 20, 50,
    0x03, 0x21,  3, 15, 50,
    0x04, 0x21,  4, 15, 30,
    0x05, 0x21,  5, 15, 30,
    0x06, 0x20, 12,  15, 30,
    0x07, 0x20, 13,  8, 20,
    0x08, 0x20, 14,  8, 20,
    0x09, 0x20, 15,  8, 25,
    /*0x0a, 0x22, 15,  8, 25,*/
    /*0x0a, 0x20, 20, 15, 30,*/
    0x0a, 0x20, 21,  8, 20,
    0x0b, 0x20, 22,  8, 20,
    0x0c, 0x20, 23,  8, 25,
    0x0d, 0x22, 23,  8, 25,
};


u8 RateSwitchTable11BGN3SForABand[] = { /* 3*3*/
/* Item No.   Mode   Curr-MCS   TrainUp   TrainDown		 Mode- Bit0: STBC, Bit1: Short GI, Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)*/
    0x0e, 0x09,  0,  0,  0,						/* Initial used item after association*/
    0x00, 0x21,  0, 30,101,	/*50*/
    0x01, 0x21,  1, 20, 50,
    0x02, 0x21,  2, 20, 50,
    0x03, 0x21,  3, 15, 50,
    0x04, 0x21,  4, 15, 30,
    0x05, 0x21,  5, 15, 30,
    0x06, 0x20, 12, 15, 30,
    0x07, 0x20, 13,  8, 20,
    0x08, 0x20, 14,  8, 20,
    0x09, 0x20, 15,  8, 25,
    /*0x0a, 0x22, 15,  8, 25,*/
    /*0x0a, 0x20, 20, 15, 30,*/
    0x0a, 0x20, 21,  8, 20,
    0x0b, 0x20, 22,  8, 20,
    0x0c, 0x20, 23,  8, 25,
    0x0d, 0x22, 23,  8, 25,
};


#ifdef NEW_RATE_ADAPT_SUPPORT

#ifdef RANGE_EXTEND
#define SUPPORT_SHORT_GI_RA		/* Support switching to Short GI rates in RA */
#endif /*  RANGE_EXTEND */

/*
	Rate switch tables for New Rate Adaptation

	Each row has 10 bytes of data.
	First row contains table information:
		Byte0=the number of rate entries, Byte1=the initial rate.
	Format of Mode byte:
		Bit0: STBC,
		Bit1: Short GI,
		Bit4~6: Mode(0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF)
*/
u8 RateSwitchTableAdapt11N1S[] = {
/*  item no.   mcs   highPERThrd  upMcs3     upMcs1
           mode   lowPERThrd  downMcs     upMcs2
*/
	 12,   7,  0,  0,   0,   0,    0,     0,   0,   0,
	 0, 0x21,  0, 30,  50,  11,    1,     8,   1,   7,/* mcs0 */
	 1, 0x21,  1, 20,  50,   0,   16,     9,   2,  13,/* mcs1 */
	 2, 0x21,  2, 20,  50,   1,   17,     9,   3,  20,/* mcs2 */
	 3, 0x21,  3, 15,  50,   2,   17,    10,   4,  26,/* mcs3 */
	 4, 0x21,  4, 15,  30,   3,   18,    11,   5,  39,/* mcs4 */
	 5, 0x21,  5, 10,  25,   4,   18,    12,   6,  52,/* mcs5 */
	 6, 0x21,  6,  8,  14,   5,   19,    12,   7,  59,/* mcs6 */
	 7, 0x21,  7,  8,  14,   6,   19,    12,   8,  65,/* mcs7 */
	 8, 0x23,  7,  8,  14,   7,   19,    12,   8,  72,/* mcs7+short gi */

	 9, 0x00,  0, 40,  101,  9 ,   9,     9,   10,  1, /* cck-1M */
	10, 0x00,  1, 40,  50,   9,   10,    10,   11,  2, /* cck-2M */
	11, 0x21, 32, 30,  50,  10,    0,     8,    0,  7, /* mcs32 or 20M/mcs0 */
};

#ifdef SUPPORT_SHORT_GI_RA
/*  Indices for Short GI rates in 11N2S table */
  #define sg07	18		/*  mcs7+shortGI index */
  #define sg14	17		/*  mcs14+shortGI index */
  #define sg15	16		/*  mcs15+shortGI index */
#endif

u8 RateSwitchTableAdapt11N2S[] = {
/* item no.   mcs   highPERThrd  upMcs3    upMcs1
        mode   lowPERThrd  downMcs    upMcs2
*/
	22,   15,  0,  0,   0,   0,    0,   0,   0,   0,
     0, 0x21,  0, 30,  50,  21,    1,   8,   1,   7,/* mcs0 */
	 1, 0x21,  1, 20,  50,   0,   16,   9,   2,  13,/* mcs1 */
	 2, 0x21,  2, 20,  50,   1,   17,   9,   3,  20,/* mcs2 */
	 3, 0x21,  3, 15,  50,   2,   17,  10,   4,  26,/* mcs3 */
	 4, 0x21,  4, 15,  30,   3,   18,  11,   5,  39,/* mcs4 */
	 5, 0x21,  5, 10,  25,   4,   18,  12,   6,  52,/* mcs5 */
	 6, 0x21,  6,  8,  14,   5,   19,  12,   7,  59,/* mcs6 */
#ifdef SUPPORT_SHORT_GI_RA
	 7, 0x21,  7,  8,  14,   6,   19,  12, sg07,  65,/* mcs7 */
#else
	 7, 0x21,  7,  8,  14,   6,   19,  12,   7,  65,/* mcs7 */
#endif
	 8, 0x20,  8, 30,  50,   0,   16,   9,   2,  13,/* mcs8 */
	 9, 0x20,  9, 20,  50,   8,   17,  10,   4,  26,/* mcs9 */
	10, 0x20, 10, 20,  40,   9,   18,  11,   5,  39,/* mcs10 */
	11, 0x20, 11, 15,  30,  10,   18,  12,   6,  52,/* mcs11 */
	12, 0x20, 12, 15,  30,  11,   20,  13,  12,  78,/* mcs12 */
	13, 0x20, 13,  8,  20,  12,   20,  14,  13, 104,/* mcs13 */
#ifdef SUPPORT_SHORT_GI_RA
	14, 0x20, 14,  8,  18,  13,   21,  15,sg14, 117,/* mcs14 */
	15, 0x20, 15,  8,  25,  14,   21,sg15,sg14, 130,/* mcs15 */
	16, 0x22, 15,  8,  25,  15,   21,sg15,sg15, 144,/* mcs15+shortGI */

    17, 0x22, 14,  8,  14,  14,   21,sg15,  15, 130, /* mcs14+shortGI */
    18, 0x23,  7,  8,  14,   7,   19,  12,sg07,  72, /* mcs7+shortGI */
#else
	14, 0x20, 14,  8,  18,  13,   21,  15,  14, 117,/* mcs14 */
	15, 0x20, 15,  8,  25,  14,   21,  16,  15, 130,/* mcs15 */
	16, 0x22, 15,  8,  25,  15,   21,  16,  16, 144,/* mcs15+shortGI */
    17,    0,  0,  0,   0,   0,   0,    0,   0,   0,
    18,    0,  0,  0,   0,   0,   0,    0,   0,   0,
#endif
    19, 0x00,  0, 40,  101, 19 ,  19,    19,   20,  1, /* cck-1M */
    20, 0x00,  1, 40,  50,  19,   20,    20,   21,  2, /* cck-2M */
    21, 0x21, 32, 30,  50,  20,   0,     8,    0,   7, /* mcs32 or 20M/mcs0 */
};

#ifdef SUPPORT_SHORT_GI_RA
/*  Indices for Short GI rates in 11N3S table */
  #undef sg07
  #undef sg14
  #undef sg15
  #define sg07	29		/*  mcs7+shortGI index */
  #define sg14	27		/*  mcs14+shortGI index */
  #define sg15	28		/*  mcs15+shortGI index */
  #define sg21	25		/*  mcs21+shortGI index */
  #define sg22	26		/*  mcs22+shortGI index */
  #define sg23	24		/*  mcs23+shortGI index */
#endif

u8 RateSwitchTableAdapt11N3S[] = {
/* item no   mcs   highPERThrd   upMcs3     upMcs1
        mode   lowPERThrd  downMcs     upMcs2
*/
	33,   23,  0,  0,   0,   0,    0,    0,    0,   0,
	 0, 0x21,  0, 30,  50,  32,    1,    8,    1,   7, /* mcs0 */
     1, 0x21,  1, 20,  50,   0,   16,    9,    2,  13, /* mcs1 */
     2, 0x21,  2, 20,  50,   1,   17,    9,    3,  20, /* mcs2 */
     3, 0x21,  3, 15,  50,   2,   17,   10,    4,  26, /* mcs3 */
     4, 0x21,  4, 15,  30,   3,   18,   11,    5,  39, /* mcs4 */
     5, 0x21,  5, 10,  25,   4,   18,   12,    6,  52, /* mcs5 */
     6, 0x21,  6,  8,  14,   5,   19,   12,    7,  59, /* mcs6 */
#ifdef SUPPORT_SHORT_GI_RA
	 7, 0x21,  7,  8,  14,   6,   19,   12, sg07,  65, /* mcs7 */
#else
	 7, 0x21,  7,  8,  14,   6,   19,   12,    7,  65, /* mcs7 */
#endif /* SUPPORT_SHORT_GI_RA */
     8, 0x20,  8, 30,  50,   0,   16,    9,    2,  13, /* mcs8 */
     9, 0x20,  9, 20,  50,   8,   17,   10,    4,  26, /* mcs9 */
    10, 0x20, 10, 20,  40,   9,   18,   11,    5,  39, /* mcs10 */
    11, 0x20, 11, 15,  30,  10,   18,   12,    6,  52, /* mcs11 */
    12, 0x20, 12, 15,  30,  11,   20,   13,   12,  78, /* mcs12 */
    13, 0x20, 13,  8,  20,  12,   20,   14,   13, 104, /* mcs13 */
#ifdef SUPPORT_SHORT_GI_RA
    14, 0x20, 14,  8,  18,  13,   21,   15, sg14, 117, /* mcs14 */
    15, 0x20, 15,  8,  14,  14,   21, sg15, sg14, 130, /* mcs15 */
#else
    14, 0x20, 14,  8,  18,  13,   21,   15,   14, 117, /* mcs14 */
    15, 0x20, 15,  8,  14,  14,   21,   15,   15, 130, /* mcs15 */
#endif /* SUPPORT_SHORT_GI_RA */
    16, 0x20, 16, 30,  50,   8,   17,    9,    3,  20, /* mcs16 */
    17, 0x20, 17, 20,  50,  16,   18,   11,    5,  39, /* mcs17 */
    18, 0x20, 18, 20,  40,  17,   19,   12,    7,  59, /* mcs18 */
    19, 0x20, 19, 15,  30,  18,   20,   13,   19,  78, /* mcs19 */
    20, 0x20, 20, 15,  30,  19,   21,   15,   20, 117, /* mcs20 */
#ifdef SUPPORT_SHORT_GI_RA
    21, 0x20, 21,  8,  20,  20,   22, sg21,   21, 156, /* mcs21 */
    22, 0x20, 22,  8,  20,  21,   23, sg22, sg21, 176, /* mcs22 */
    23, 0x20, 23,  6,  18,  22, sg23,   23, sg22, 195, /* mcs23 */
    24, 0x22, 23,  6,  14,  23, sg23, sg23, sg23, 217, /* mcs23+shortGI */

    25, 0x22, 21,  6,  18,  21, sg22,   22, sg21, 173, /* mcs21+shortGI */
    26, 0x22, 22,  6,  18,  22, sg23,   23, sg22, 195, /* mcs22+shortGI */
    27, 0x22, 14,  8,  14,  14,   21, sg15,   15, 130, /* mcs14+shortGI */
    28, 0x22, 15,  8,  14,  15,   21, sg15, sg15, 144, /* mcs15+shortGI */
    29, 0x23,  7,  8,  14,   7,   19,   12,   29,  72, /* mcs7+shortGI */
#else
    21, 0x20, 21,  8,  20,  20,   22,   21,   21, 156, /* mcs21 */
    22, 0x20, 22,  8,  20,  21,   23,   22,   22, 176, /* mcs22 */
    23, 0x20, 23,  6,  18,  22,   24,   23,   23, 195, /* mcs23 */
    24, 0x22, 23,  6,  14,  23,   24,   24,   24, 217, /* mcs23+shortGI */
    25,    0,  0,  0,   0,   0,   0,     0,    0,   0,
    26,    0,  0,  0,   0,   0,   0,     0,    0,   0,
    27,    0,  0,  0,   0,   0,   0,     0,    0,   0,
    28,    0,  0,  0,   0,   0,   0,     0,    0,   0,
    29,    0,  0,  0,   0,   0,   0,     0,    0,   0,
#endif /* SUPPORT_SHORT_GI_RA */
    30, 0x00,  0, 40,  101, 30 ,  30,    30,   31,  1, /* cck-1M */
    31, 0x00,  1, 40,  50,  30,   31,    31,   32,  2, /* cck-2M */
    32, 0x21, 32, 30,  50,  31,   0,     8,    0,   7, /* mcs32 or 20M/mcs0 */
};


/*
	VHT-capable rate table

	Each row has 10 bytes of data.

	1. First row contains table info, which is initial used item after assoc:
			Byte0=the number of rate entries, Byte1=the initial rate.

	2. rest rows Format:
	[Index] [Mode] [nSS] [CurrMCS] [PERThrd Low/High] [downMCS] [upMCS3/2/1]

	[Mode]:
		bit0: STBC
		bit1: Short GI
		bit2~3: BW - (20M/40M/80M)
		bit4~bit6: Mode (0:CCK, 1:OFDM, 2:HT Mix, 3:HT GF, 4: VHT) - MODE_XXX
		bit7: Reserved
	[nSS]:
		Number of Spatial Stream

	Note: downMCS, upMCS3, upMCS2 and upMCS1 are zero-based array index.
*/
/* 1x1 VHT-capable rate table */
u8 RateTableVht1S[] =
{
	11,		9,		0,		0, 0,				0,		0, 0, 0,		0,
/*	[Idx]	[Mode]	[MCS]	[PER_Low/High]	[dMCS]	[upMCS3/2/1] [nSS]*/
	0,		0x10,	0, 		30, 101,		0,		0, 0, 1,		1,
	1,		0x25,	0, 		30, 50,			0,		0, 0, 2,		1,
	2,		0x49,	0,		30, 50,			1,		0, 0, 3,		1,
	3,		0x49,	1,		20, 50,			2,		0, 0, 4,		1,
	4,		0x49,	2,		20, 50,			3,		0, 0, 5, 		1,
	5,		0x49,	3,		15, 50,			4,		0, 0, 6, 		1,
	6,		0x49,	4,		15, 30,			5,		0, 0, 7, 		1,
	7,		0x49,	5,		10, 25,			6,		0, 0, 8, 		1,
	8,		0x49,	6,		8, 14,			7,		0, 0, 9, 		1,
	9,		0x49,	7,		8, 14,			8,		0, 0, 10, 		1,
	10,		0x4B,	7,		8, 14,			9,		0, 0, 10, 		1,
};

//S4
u8 RateTableVht1S_MCS9[] =
{
    13,     11,    0,      0,   0,      0,    0, 0,  0,     0,
/*	[Idx]	[Mode]		[MCS]	[PER_Low/High]	[dMCS]	[upMCS3/2/1] [nSS] */
	0,		0x10,		0, 		30, 101,			0,		0, 0, 1,		1, /* OFDM, MCS0, BW20 */
	1,		0x45,		0, 		30, 50,				0,		0, 0, 2,		1, /* VHT, MCS0, BW40, STBC */
     2,    0x49,    0,     30,  50,      1,    0, 0,  3,     1, /* VHT, MCS0, BW80, STBC */
     3,    0x49,    1,     20,  50,      2,    0, 0,  4,     1, /* VHT, MCS1, BW80, STBC */
     4,    0x49,    2,     20,  50,      3,    0, 0,  5,     1, /* VHT, MCS2, BW80, STBC */
     5,    0x49,    3,     15,  50,      4,    0, 0,  6,     1, /* VHT, MCS3, BW80, STBC */
     6,    0x49,    4,     15,  30,      5,    0, 0,  7,     1, /* VHT, MCS4, BW80, STBC */
     7,    0x49,    5,     12,  25,      6,    0, 0,  8,     1, /* VHT, MCS5, BW80, STBC */
     8,    0x49,    6,     12,  15,      7,    0, 0,  9,     1, /* VHT, MCS6, BW80, STBC */
     9,    0x49,    7,     12,  15,      8,    0, 0, 10,     1, /* VHT, MCS7, BW80, STBC */
    10,    0x49,    8,     12,  15,      9,    0, 0, 11,     1, /* VHT, MCS8, BW80, STBC */
    11,    0x49,    9,     12,  15,     10,    0, 0, 12,     1, /* VHT, MCS9, BW80, STBC */
    12,    0x4A,    9,     12,  15,     11,    0, 0, 12,     1, /* VHT, MCS9, BW80, SGI */
};
//S4

/* 2x2 VHT-capable rate table */
// TODO: shiang-usw, refine this!!
u8 RateTableVht2S_old[] =
{
	22,		21,		0,		0, 0,				0,		0, 0,0,		0,
/*	[Idx]	[Mode]	[MCS]	[PER_Low/High]	[dMCS]	[upMCS3/2/1] [nSS]*/
	0,		0x10,	0,		30, 101,		0,		0, 1, 1,		1, /* OFDM 1x1 MCS0 BW20 */
	1,		0x25,	0,		30, 50,			0,		0, 2, 2,		1, /* HT 1x1 MCS0 BW40 */
	2,		0x49,	0,		30, 50,			1,		0, 10, 3,		1, /* VHT 1x1 MCS0 BW80 LGI */
	3,		0x49,	1,		20, 50,			2,		0, 11, 4,		1, /* VHT 1x1 MCS1 BW80 LGI */
	4,		0x49,	2,		20, 50,			3,		0, 11, 5,		1, /* VHT 1x1 MCS2 BW80 LGI */
	5,		0x49,	3,		15, 50,			4,		0, 12, 6,		1, /* VHT 1x1 MCS3 BW80 LGI */
	6,		0x49,	4,		15, 30,			5,		0, 13, 7,		1, /* VHT 1x1 MCS4 BW80 LGI */
	7,		0x49,	5,		10, 25,			6,		0, 14, 8,		1, /* VHT 1x1 MCS5 BW80 LGI */
	8,		0x49,	6,		8, 14,			7,		0, 14, 9,		1, /* VHT 1x1 MCS6 BW80 LGI */
	9,		0x49,	7,		8, 14,			8,		0, 14, 9,		1, /* VHT 1x1 MCS7 BW80 LGI */
	10,		0x48,	0,		30, 50,			2,		0, 11, 4,		2, /* VHT 2x2 MCS0 BW80 LGI */
	11,		0x48,	1,		20, 50,			10,		0, 12, 6,		2, /* VHT 2x2 MCS1 BW80 LGI */
	12,		0x48,	2,		20, 50,			11,		0, 13, 7,		2, /* VHT 2x2 MCS2 BW80 LGI */
	13,		0x48,	3,		15, 30,			12,		0, 14, 8,		2, /* VHT 2x2 MCS3 BW80 LGI */
	14,		0x48,	4,		15, 30,			13,		0, 15, 14,		2, /* VHT 2x2 MCS4 BW80 LGI */
	15,		0x48,	5,		8, 20,			14,		0, 16, 15, 		2, /* VHT 2x2 MCS5 BW80 LGI */
	16,		0x48,	6,		8, 18,			15,		0, 17, 16, 		2, /* VHT 2x2 MCS6 BW80 LGI */
	17,		0x48,	7,		8, 25,			16,		0, 18, 17, 		2, /* VHT 2x2 MCS7 BW80 LGI */
	18,		0x4A,	7,		8, 25,			17,		0, 19, 18, 		2, /* VHT 2x2 MCS7 BW80 SGI */
	19,		0x48,	8,		8, 25,			18,		0, 20, 19, 		2, /* VHT 2x2 MCS8 BW80 LGI */
	20, 	0x48,	9,		8, 25,			19,		0, 21, 20,		2, /* VHT 2x2 MCS9 BW80 LGI */
	21,		0x4A, 	9,		8, 25,			20,		0, 21, 21,  	2, /* VHT 2x2 MCS9 BW80 SGI */
};

u8 RateTableVht2S_MCS7[] =
{
  31,   30,   0,      0,   0,    0,   0,  0,  0,  0,
/*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */
  /* reserved */
  0,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  1,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  2,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20, 101,    3,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
   4,   0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
   5,   0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 10, 10,  1,/* OFDM 1x1 MCS3 BW20 */

  /* The Data Rate of VHT BW 20/40 */
  7,    0x41, 0,     15,  25,    3,   0,  8,  8,  1,/* VHT 1x1 MCS0 BW20 */
  8,    0x45, 0,     25,  50,    7,   0, 10, 10,  1,/* VHT 1x1 MCS0 BW40 */
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,

  /* The Group Data Rate of 1SS with VHT BW80 */
  10,   0x49, 0,     25,  50,    8,   0, 20, 11,  1,/* VHT 1x1 MCS0 BW80 LGI */
  11,   0x49, 1,     20,  35,   10,   0, 21, 12,  1,/* VHT 1x1 MCS1 BW80 LGI */
  12,   0x49, 2,     20,  35,   11,   0, 21, 13,  1,/* VHT 1x1 MCS2 BW80 LGI */
  13,   0x49, 3,     15,  30,   12,   0, 22, 14,  1,/* VHT 1x1 MCS3 BW80 LGI */
  14,   0x49, 4,     15,  30,   13,   0, 23, 15,  1,/* VHT 1x1 MCS4 BW80 LGI */
  15,   0x49, 5,     10,  25,   14,   0, 24, 16,  1,/* VHT 1x1 MCS5 BW80 LGI */
  16,   0x49, 6,      8,  15,   15,   0, 24, 17,  1,/* VHT 1x1 MCS6 BW80 LGI */
  17,   0x49, 7,      8,  15,   16,   0, 24, 24,  1,/* VHT 1x1 MCS7 BW80 LGI */
  18,   0x49, 8,      8,  15,   16,   0, 24, 24,  1,/* VHT 1x1 MCS8 BW80 LGI */
  19,   0x49, 9,      8,  15,   16,   0, 24, 24,  1,/* VHT 1x1 MCS9 BW80 LGI */

  /* The Group Data Rate of 2SS with VHT BW80 */
  20,   0x48, 0,     30,  50,   10,   0, 21, 12,  2,/* VHT 2x2 MCS0 BW80 LGI */
  21,   0x48, 1,     30,  50,   20,   0, 22, 14,  2,/* VHT 2x2 MCS1 BW80 LGI */
  22,   0x48, 2,     15,  30,   21,   0, 23, 15,  2,/* VHT 2x2 MCS2 BW80 LGI */
  23,   0x48, 3,     15,  30,   22,   0, 24, 16,  2,/* VHT 2x2 MCS3 BW80 LGI */
  24,   0x48, 4,     15,  30,   23,   0, 25, 25,  2,/* VHT 2x2 MCS4 BW80 LGI */
  25,   0x48, 5,      8,  20,   24,   0, 26, 26,  2,/* VHT 2x2 MCS5 BW80 LGI */
  26,   0x48, 6,      8,  20,   25,   0, 27, 27,  2,/* VHT 2x2 MCS6 BW80 LGI */
  27,   0x48, 7,      8,  20,   26,   0, 28, 28,  2,/* VHT 2x2 MCS7 BW80 LGI */
  28,   0x4A, 7,      5,  15,   27,   0, 28, 28,  2,/* VHT 2x2 MCS7 BW80 SGI */
  29,   0x48, 9,      5,  15,   28,   0, 28, 28,  2,/* VHT 2x2 MCS9 BW80 LGI */
  30,   0x4A, 9,      5,  15,   28,   0, 28, 28,  2,/* VHT 2x2 MCS9 BW80 SGI */
};

u8 RateTableVht2S[] =
{
  31,   30,   0,      0,   0,    0,   0,  0,  0,  0,
/*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */

  /* reserved */
  0,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  1,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  2,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20, 101,    3,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
  4,    0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
  5,    0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 10, 10,  1,/* OFDM 1x1 MCS3 BW20 */

  /* The Data Rate of VHT BW 20/40 */
  7,    0x41, 0,     15,  25,    3,   0,  8,  8,  1,/* VHT 1x1 MCS0 BW20 */
  8,    0x45, 0,     25,  50,    7,   0, 10, 10,  1,/* VHT 1x1 MCS0 BW40 */
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,

  /* The Group Data Rate of 1SS with VHT BW80 */
  10,   0x49, 0,     25,  50,    8,   0, 20, 11,  1,/* VHT 1x1 MCS0 BW80 LGI */
  11,   0x49, 1,     20,  35,   10,   0, 21, 12,  1,/* VHT 1x1 MCS1 BW80 LGI */
  12,   0x49, 2,     20,  35,   11,   0, 21, 13,  1,/* VHT 1x1 MCS2 BW80 LGI */
  13,   0x49, 3,     15,  30,   12,   0, 22, 14,  1,/* VHT 1x1 MCS3 BW80 LGI */
  14,   0x49, 4,     15,  30,   13,   0, 23, 15,  1,/* VHT 1x1 MCS4 BW80 LGI */
  15,   0x49, 5,     10,  25,   14,   0, 24, 16,  1,/* VHT 1x1 MCS5 BW80 LGI */
  16,   0x49, 6,      8,  15,   15,   0, 24, 17,  1,/* VHT 1x1 MCS6 BW80 LGI */
  17,   0x49, 7,      8,  15,   16,   0, 24, 18,  1,/* VHT 1x1 MCS7 BW80 LGI */
  18,   0x49, 8,      8,  15,   17,   0, 25, 19,  1,/* VHT 1x1 MCS8 BW80 LGI */
  19,   0x49, 9,      8,  15,   18,   0, 25, 25,  1,/* VHT 1x1 MCS9 BW80 LGI */

  /* The Group Data Rate of 2SS with VHT BW 80 */
  20,   0x48, 0,     30,  50,   10,   0, 21, 12,  2,/* VHT 2x2 MCS0 BW80 LGI */
  21,   0x48, 1,     30,  50,   20,   0, 22, 14,  2,/* VHT 2x2 MCS1 BW80 LGI */
  22,   0x48, 2,     15,  30,   21,   0, 23, 15,  2,/* VHT 2x2 MCS2 BW80 LGI */
  23,   0x48, 3,     15,  30,   22,   0, 24, 16,  2,/* VHT 2x2 MCS3 BW80 LGI */
  24,   0x48, 4,     15,  30,   23,   0, 25, 19,  2,/* VHT 2x2 MCS4 BW80 LGI */
  25,   0x48, 5,      8,  20,   24,   0, 26, 26,  2,/* VHT 2x2 MCS5 BW80 LGI */
  26,   0x48, 6,      8,  20,   25,   0, 27, 27,  2,/* VHT 2x2 MCS6 BW80 LGI */
  27,   0x48, 7,      8,  20,   26,   0, 28, 28,  2,/* VHT 2x2 MCS7 BW80 LGI */
  28,   0x48, 8,      5,  15,   27,   0, 29, 29,  2,/* VHT 2x2 MCS8 BW80 LGI */
  29,   0x48, 9,      5,  15,   28,   0, 30, 30,  2,/* VHT 2x2 MCS9 BW80 LGI */
  30,   0x4A, 9,      5,  15,   29,   0, 30, 30,  2,/* VHT 2x2 MCS9 BW80 SGI */
};

u8 RateTableVht2S_BW40[] =
{
  31,   30,   0,      0,   0,    0,   0,  0,  0,  0,
/*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */
  /* reserved */
  0,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  1,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  2,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20, 101,    3,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
  4,    0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
  5,    0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 11, 11,  1,/* OFDM 1x1 MCS3 BW20 */

  /* The Data Rate of VHT BW 20/40 */
  7,    0x41, 0,     15,  25,    3,   0, 10, 10,  1,/* VHT 1x1 MCS0 BW20 LGI*/
  8,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,

  /* The Group Data Rate of 1SS with VHT BW40 */
  10,   0x45, 0,     25,  50,    7,   0, 20, 11,  1,/* VHT 1x1 MCS0 BW40 LGI */
  11,   0x45, 1,     20,  35,   10,   0, 21, 12,  1,/* VHT 1x1 MCS1 BW40 LGI */
  12,   0x45, 2,     20,  35,   11,   0, 21, 13,  1,/* VHT 1x1 MCS2 BW40 LGI */
  13,   0x45, 3,     15,  30,   12,   0, 22, 14,  1,/* VHT 1x1 MCS3 BW40 LGI */
  14,   0x45, 4,     15,  30,   13,   0, 23, 15,  1,/* VHT 1x1 MCS4 BW40 LGI */
  15,   0x45, 5,     10,  25,   14,   0, 24, 16,  1,/* VHT 1x1 MCS5 BW40 LGI */
  16,   0x45, 6,      8,  15,   15,   0, 24, 17,  1,/* VHT 1x1 MCS6 BW40 LGI */
  17,   0x45, 7,      8,  15,   16,   0, 24, 18,  1,/* VHT 1x1 MCS7 BW40 LGI */
  18,   0x45, 8,      8,  15,   17,   0, 25, 19,  1,/* VHT 1x1 MCS8 BW40 LGI */
  19,   0x45, 9,      8,  15,   18,   0, 25, 25,  1,/* VHT 1x1 MCS9 BW40 LGI */

  /* The Group Data Rate of 2SS with VHT BW40 */

  20,   0x44, 0,     30,  50,   10,   0, 21, 12,  2,/* VHT 2x2 MCS0 BW40 LGI */
  21,   0x44, 1,     30,  50,   20,   0, 22, 14,  2,/* VHT 2x2 MCS1 BW40 LGI */
  22,   0x44, 2,     15,  30,   21,   0, 23, 15,  2,/* VHT 2x2 MCS2 BW40 LGI */
  23,   0x44, 3,     15,  30,   22,   0, 24, 16,  2,/* VHT 2x2 MCS3 BW40 LGI */
  24,   0x44, 4,     15,  30,   23,   0, 25, 19,  2,/* VHT 2x2 MCS4 BW40 LGI */
  25,   0x44, 5,      8,  20,   24,   0, 26, 26,  2,/* VHT 2x2 MCS5 BW40 LGI */
  26,   0x44, 6,      8,  20,   25,   0, 27, 27,  2,/* VHT 2x2 MCS6 BW40 LGI */
  27,   0x44, 7,      8,  20,   26,   0, 28, 28,  2,/* VHT 2x2 MCS7 BW40 LGI */
  28,   0x44, 8,      5,  15,   27,   0, 29, 29,  2,/* VHT 2x2 MCS8 BW40 LGI */
  29,   0x44, 9,      5,  15,   28,   0, 30, 30,  2,/* VHT 2x2 MCS9 BW40 LGI */
  30,   0x46, 9,      5,  15,   29,   0, 30, 30,  2,/* VHT 2x2 MCS9 BW40 SGI */
};

u8 RateTableVht2S_BW20[] =

{
  30,   28,   0,      0,   0,    0,   0,  0,  0,  0,
/*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */
  /* reserved */
  0,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  1,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,
  2,    0x11, 0,    100, 101,    3,   0,  4,  4,  1,

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20, 101,    3,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
  4,    0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
  5,    0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 13, 13,  1,/* OFDM 1x1 MCS3 BW20 */

  7,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,
  8,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,

  /* The Group Data Rate of 1SS with VHT BW80 */
  10,   0x41, 0,     15,  25,    3,   0, 20, 11,  1,/* VHT 1x1 MCS0 BW20 LGI */
  11,   0x41, 1,     20,  35,   10,   0, 21, 12,  1,/* VHT 1x1 MCS1 BW20 LGI */
  12,   0x41, 2,     20,  35,   11,   0, 21, 13,  1,/* VHT 1x1 MCS2 BW20 LGI */
  13,   0x41, 3,     15,  30,   12,   0, 22, 14,  1,/* VHT 1x1 MCS3 BW20 LGI */
  14,   0x41, 4,     15,  30,   13,   0, 23, 15,  1,/* VHT 1x1 MCS4 BW20 LGI */
  15,   0x41, 5,     10,  25,   14,   0, 24, 16,  1,/* VHT 1x1 MCS5 BW20 LGI */
  16,   0x41, 6,      8,  15,   15,   0, 24, 17,  1,/* VHT 1x1 MCS6 BW20 LGI */
  17,   0x41, 7,      8,  15,   16,   0, 24, 18,  1,/* VHT 1x1 MCS7 BW20 LGI */
  18,   0x41, 8,      8,  15,   17,   0, 25, 25,  1,/* VHT 1x1 MCS8 BW20 LGI */
  19,   0x00, 0,      0,   0,    0,   0,  0,  0,  0,

  /* The Group Data Rate of 2SS with VHT BW 80 */
  20,   0x40, 0,     30,  50,   10,   0, 21, 12,  2,/* VHT 2x2 MCS0 BW20 LGI */
  21,   0x40, 1,     30,  50,   20,   0, 22, 14,  2,/* VHT 2x2 MCS1 BW20 LGI */
  22,   0x40, 2,     15,  30,   21,   0, 23, 15,  2,/* VHT 2x2 MCS2 BW20 LGI */
  23,   0x40, 3,     15,  30,   22,   0, 24, 16,  2,/* VHT 2x2 MCS3 BW20 LGI */
  24,   0x40, 4,     15,  30,   23,   0, 25, 25,  2,/* VHT 2x2 MCS4 BW20 LGI */
  25,   0x40, 5,      8,  20,   24,   0, 26, 26,  2,/* VHT 2x2 MCS5 BW20 LGI */
  26,   0x40, 6,      8,  20,   25,   0, 27, 27,  2,/* VHT 2x2 MCS6 BW20 LGI */
  27,   0x40, 7,      8,  20,   26,   0, 28, 29,  2,/* VHT 2x2 MCS7 BW20 LGI */
  28,   0x40, 8,      5,  15,   27,   0, 29, 29,  2,/* VHT 2x2 MCS8 BW20 LGI */
  29,   0x42, 8,      5,  15,   28,   0, 29, 29,  2,/* VHT 2x2 MCS8 BW20 SGI */
};


u8 RateTableVht1S_2G_BW40[] =
{
  21,   20,   0,      0,   0,    0,   0,  0,  0,  0,
  /*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */
  /* The Data Rate of CCK for long distance */
  0,    0x00, 0,     40, 101,    0,   0,  1,  1,  1,/* CCK 1x1 MCS0 BW20 */
  1,    0x00, 1,     40,  50,    0,   0,  2,  2,  1,/* CCK 1x1 MCS1 BW20 */
  2,    0x00, 2,     25,  45,    1,   0,  4,  4,  1,/* CCK 1x1 MCS2 BW20 */

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20,  50,    2,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
  4,    0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
  5,    0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 11, 11,  1,/* OFDM 1x1 MCS3 BW20 */

  /* The Data Rate of VHT BW 20/40 */
  7,    0x41, 0,     15,  25,    3,   0, 10, 10,  1,/* VHT 1x1 MCS0 BW20 LGI*/
  8,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,

  /* The Group Data Rate of 1SS with VHT BW40 */
  10,   0x45, 0,     25,  50,    7,   0, 20, 11,  1,/* VHT 1x1 MCS0 BW40 LGI */
  11,   0x45, 1,     20,  35,   10,   0, 12, 12,  1,/* VHT 1x1 MCS1 BW40 LGI */
  12,   0x45, 2,     20,  35,   11,   0, 13, 13,  1,/* VHT 1x1 MCS2 BW40 LGI */
  13,   0x45, 3,     15,  30,   12,   0, 14, 14,  1,/* VHT 1x1 MCS3 BW40 LGI */
  14,   0x45, 4,     15,  30,   13,   0, 15, 15,  1,/* VHT 1x1 MCS4 BW40 LGI */
  15,   0x45, 5,     10,  25,   14,   0, 16, 16,  1,/* VHT 1x1 MCS5 BW40 LGI */
  16,   0x45, 6,      8,  15,   15,   0, 17, 17,  1,/* VHT 1x1 MCS6 BW40 LGI */
  17,   0x45, 7,      8,  15,   16,   0, 18, 18,  1,/* VHT 1x1 MCS7 BW40 LGI */
  18,   0x45, 8,      8,  15,   17,   0, 19, 19,  1,/* VHT 1x1 MCS8 BW40 LGI */
  19,   0x45, 9,      8,  15,   18,   0, 20, 20,  1,/* VHT 1x1 MCS9 BW40 LGI */
  20,   0x47, 9,      8,  15,   19,   0, 20, 20,  1,/* VHT 1x1 MCS9 BW40 SGI */
};

u8 RateTableVht1S_2G_BW20[] =
{
  20,   19,   0,      0,   0,    0,   0,  0,  0,  0,
  /*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */
  /* reserved */
  /* The Data Rate of CCK for long distance */
  0,    0x00, 0,     40, 101,    0,   0,  1,  1,  1,/* CCK 1x1 MCS0 BW20 */
  1,    0x00, 1,     40,  50,    0,   0,  2,  2,  1,/* CCK 1x1 MCS1 BW20 */
  2,    0x00, 2,     25,  45,    1,   0,  4,  4,  1,/* CCK 1x1 MCS2 BW20 */

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20,  50,    2,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
  4,    0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
  5,    0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 13, 13,  1,/* OFDM 1x1 MCS3 BW20 */

  /* The Data Rate of VHT BW 20/40 */
  7,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,
  8,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,

  /* The Group Data Rate of 1SS with VHT BW20 */
  10,   0x41, 0,     15,  25,    3,   0, 11, 11,  1,/* VHT 1x1 MCS0 BW20 LGI */
  11,   0x41, 1,     20,  35,   10,   0, 12, 12,  1,/* VHT 1x1 MCS1 BW20 LGI */
  12,   0x41, 2,     20,  35,   11,   0, 13, 13,  1,/* VHT 1x1 MCS2 BW20 LGI */
  13,   0x41, 3,     15,  30,   12,   0, 14, 14,  1,/* VHT 1x1 MCS3 BW20 LGI */
  14,   0x41, 4,     15,  30,   13,   0, 15, 15,  1,/* VHT 1x1 MCS4 BW20 LGI */
  15,   0x41, 5,     10,  25,   14,   0, 16, 16,  1,/* VHT 1x1 MCS5 BW20 LGI */
  16,   0x41, 6,      8,  15,   15,   0, 17, 17,  1,/* VHT 1x1 MCS6 BW20 LGI */
  17,   0x41, 7,      8,  15,   16,   0, 18, 18,  1,/* VHT 1x1 MCS7 BW20 LGI */
  18,   0x41, 8,      8,  15,   17,   0, 19, 19,  1,/* VHT 1x1 MCS8 BW20 LGI */
  19,   0x43, 8,      8,  15,   18,   0, 19, 19,  1,/* VHT 1x1 MCS8 BW20 SGI */
};

u8 RateTableVht2S_2G_BW40[] =
{
  31,   30,   0,      0,   0,    0,   0,  0,  0,  0,
  /*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */
  /* The Data Rate of CCK for long distance */
  0,    0x00, 0,     40, 101,    0,   0,  1,  1,  1,/* CCK 1x1 MCS0 BW20 */
  1,    0x00, 1,     40,  50,    0,   0,  2,  2,  1,/* CCK 1x1 MCS1 BW20 */
  2,    0x00, 2,     25,  45,    1,   0,  4,  4,  1,/* CCK 1x1 MCS2 BW20 */

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20,  50,    2,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
  4,    0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
  5,    0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 11, 11,  1,/* OFDM 1x1 MCS3 BW20 */

  /* The Data Rate of VHT BW 20/40 */
  7,    0x41, 0,     15,  25,    3,   0, 10, 10,  1,/* VHT 1x1 MCS0 BW20 LGI*/
  8,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  1,

  /* The Group Data Rate of 1SS with VHT BW40 */
  10,   0x45, 0,     25,  50,    7,   0, 20, 11,  1,/* VHT 1x1 MCS0 BW40 LGI */
  11,   0x45, 1,     20,  35,   10,   0, 21, 12,  1,/* VHT 1x1 MCS1 BW40 LGI */
  12,   0x45, 2,     20,  35,   11,   0, 21, 13,  1,/* VHT 1x1 MCS2 BW40 LGI */
  13,   0x45, 3,     15,  30,   12,   0, 22, 14,  1,/* VHT 1x1 MCS3 BW40 LGI */
  14,   0x45, 4,     15,  30,   13,   0, 23, 15,  1,/* VHT 1x1 MCS4 BW40 LGI */
  15,   0x45, 5,     10,  25,   14,   0, 24, 16,  1,/* VHT 1x1 MCS5 BW40 LGI */
  16,   0x45, 6,      8,  15,   15,   0, 24, 17,  1,/* VHT 1x1 MCS6 BW40 LGI */
  17,   0x45, 7,      8,  15,   16,   0, 24, 18,  1,/* VHT 1x1 MCS7 BW40 LGI */
  18,   0x45, 8,      8,  15,   17,   0, 25, 19,  1,/* VHT 1x1 MCS8 BW40 LGI */
  19,   0x45, 9,      8,  15,   18,   0, 25, 25,  1,/* VHT 1x1 MCS9 BW40 LGI */

  /* The Group Data Rate of 2SS with VHT BW40 */
  20,   0x44, 0,     30,  50,   10,   0, 21, 12,  2,/* VHT 2x2 MCS0 BW40 LGI */
  21,   0x44, 1,     30,  50,   20,   0, 22, 14,  2,/* VHT 2x2 MCS1 BW40 LGI */
  22,   0x44, 2,     15,  30,   21,   0, 23, 15,  2,/* VHT 2x2 MCS2 BW40 LGI */
  23,   0x44, 3,     15,  30,   22,   0, 24, 16,  2,/* VHT 2x2 MCS3 BW40 LGI */
  24,   0x44, 4,     15,  30,   23,   0, 25, 19,  2,/* VHT 2x2 MCS4 BW40 LGI */
  25,   0x44, 5,      8,  20,   24,   0, 26, 26,  2,/* VHT 2x2 MCS5 BW40 LGI */
  26,   0x44, 6,      8,  20,   25,   0, 27, 27,  2,/* VHT 2x2 MCS6 BW40 LGI */
  27,   0x44, 7,      8,  20,   26,   0, 28, 28,  2,/* VHT 2x2 MCS7 BW40 LGI */
  28,   0x44, 8,      5,  15,   27,   0, 29, 29,  2,/* VHT 2x2 MCS8 BW40 LGI */
  29,   0x44, 9,      5,  15,   28,   0, 30, 30,  2,/* VHT 2x2 MCS9 BW40 LGI */
  30,   0x46, 9,      5,  15,   29,   0, 30, 30,  2,/* VHT 2x2 MCS9 BW40 SGI */
};

u8 RateTableVht2S_2G_BW20[] =
{
  30,   29,   0,      0,   0,    0,   0,  0,  0,  0,
  /*  [Idx] [Mode]  [MCS] [PER_down/up] [dMCS]  [upMCS3/2/1] [nSS] */
  /* reserved */
  /* The Data Rate of CCK for long distance */
  0,    0x00, 0,     40, 101,    0,   0,  1,  1,  1,/* CCK 1x1 MCS0 BW20 */
  1,    0x00, 1,     40,  50,    0,   0,  2,  2,  1,/* CCK 1x1 MCS1 BW20 */
  2,    0x00, 2,     25,  45,    1,   0,  4,  4,  1,/* CCK 1x1 MCS2 BW20 */

  /* The Data Rate of OFDM for long distance */
  3,    0x11, 0,     20,  50,    2,   0,  4,  4,  1,/* OFDM 1x1 MCS0 BW20 */
  4,    0x11, 1,     20,  40,    3,   0,  5,  5,  1,/* OFDM 1x1 MCS1 BW20 */
  5,    0x11, 2,     20,  35,    4,   0,  6,  6,  1,/* OFDM 1x1 MCS2 BW20 */
  6,    0x11, 3,     15,  35,    5,   0, 13, 13,  1,/* OFDM 1x1 MCS3 BW20 */

  7,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,
  8,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,
  9,    0x00, 0,      0,   0,    0,   0,  0,  0,  0,

  /* The Group Data Rate of 1SS with VHT BW20 */
  10,   0x41, 0,     15,  25,    3,   0, 20, 11,  1,/* VHT 1x1 MCS0 BW20 LGI */
  11,   0x41, 1,     20,  35,   10,   0, 21, 12,  1,/* VHT 1x1 MCS1 BW20 LGI */
  12,   0x41, 2,     20,  35,   11,   0, 21, 13,  1,/* VHT 1x1 MCS2 BW20 LGI */
  13,   0x41, 3,     15,  30,   12,   0, 22, 14,  1,/* VHT 1x1 MCS3 BW20 LGI */
  14,   0x41, 4,     15,  30,   13,   0, 23, 15,  1,/* VHT 1x1 MCS4 BW20 LGI */
  15,   0x41, 5,     10,  25,   14,   0, 24, 16,  1,/* VHT 1x1 MCS5 BW20 LGI */
  16,   0x41, 6,      8,  15,   15,   0, 24, 17,  1,/* VHT 1x1 MCS6 BW20 LGI */
  17,   0x41, 7,      8,  15,   16,   0, 24, 18,  1,/* VHT 1x1 MCS7 BW20 LGI */
  18,   0x41, 8,      8,  15,   17,   0, 25, 25,  1,/* VHT 1x1 MCS8 BW20 LGI */
  19,   0x00, 0,      0,   0,    0,   0,  0,  0,  0,

  /* The Group Data Rate of 2SS with VHT BW20 */
  20,   0x40, 0,     30,  50,   10,   0, 21, 12,  2,/* VHT 2x2 MCS0 BW20 LGI */
  21,   0x40, 1,     30,  50,   20,   0, 22, 14,  2,/* VHT 2x2 MCS1 BW20 LGI */
  22,   0x40, 2,     15,  30,   21,   0, 23, 15,  2,/* VHT 2x2 MCS2 BW20 LGI */
  23,   0x40, 3,     15,  30,   22,   0, 24, 16,  2,/* VHT 2x2 MCS3 BW20 LGI */
  24,   0x40, 4,     15,  30,   23,   0, 25, 25,  2,/* VHT 2x2 MCS4 BW20 LGI */
  25,   0x40, 5,      8,  20,   24,   0, 26, 26,  2,/* VHT 2x2 MCS5 BW20 LGI */
  26,   0x40, 6,      8,  20,   25,   0, 27, 27,  2,/* VHT 2x2 MCS6 BW20 LGI */
  27,   0x40, 7,      8,  20,   26,   0, 28, 29,  2,/* VHT 2x2 MCS7 BW20 LGI */
  28,   0x40, 8,      5,  15,   27,   0, 29, 29,  2,/* VHT 2x2 MCS8 BW20 LGI */
  29,   0x42, 8,      5,  15,   28,   0, 29, 29,  2,/* VHT 2x2 MCS8 BW20 SGI */
};


#endif /*  NEW_RATE_ADAPT_SUPPORT */


/* MlmeGetSupportedMcs - fills in the table of mcs with index into the pTable
		pAd - pointer to adapter
		pTable - pointer to the Rate Table. Assumed to be a table without mcsGroup values
		mcs - table of MCS index into the Rate Table. -1 => not supported
*/
VOID MlmeGetSupportedMcs(
	IN struct rtmp_adapter *pAd,
	IN u8 *pTable,
	OUT CHAR 	mcs[])
{
	CHAR	idx;
	RTMP_RA_LEGACY_TB *pCurrTxRate;

	for (idx = 0; idx < 24; idx++)
		mcs[idx] = -1;

	/*  check the existence and index of each needed MCS */
	for (idx=0; idx<RATE_TABLE_SIZE(pTable); idx++)
	{
		pCurrTxRate = PTX_RA_LEGACY_ENTRY(pTable, idx);

		/*  Rate Table may contain CCK and MCS rates. Give HT/Legacy priority over CCK */
		if (pCurrTxRate->CurrMCS==MCS_0 && (mcs[0]==-1 || pCurrTxRate->Mode!=MODE_CCK))
			mcs[0] = idx;
		else if (pCurrTxRate->CurrMCS==MCS_1 && (mcs[1]==-1 || pCurrTxRate->Mode!=MODE_CCK))
			mcs[1] = idx;
		else if (pCurrTxRate->CurrMCS==MCS_2 && (mcs[2]==-1 || pCurrTxRate->Mode!=MODE_CCK))
			mcs[2] = idx;
		else if (pCurrTxRate->CurrMCS == MCS_3)
			mcs[3] = idx;
		else if (pCurrTxRate->CurrMCS == MCS_4)
			mcs[4] = idx;
		else if (pCurrTxRate->CurrMCS == MCS_5)
			mcs[5] = idx;
		else if (pCurrTxRate->CurrMCS == MCS_6)
			mcs[6] = idx;
		else if ((pCurrTxRate->CurrMCS == MCS_7) && (pCurrTxRate->ShortGI == GI_800))
			mcs[7] = idx;
		else if (pCurrTxRate->CurrMCS == MCS_12)
			mcs[12] = idx;
		else if (pCurrTxRate->CurrMCS == MCS_13)
			mcs[13] = idx;
		else if (pCurrTxRate->CurrMCS == MCS_14)
			mcs[14] = idx;
		else if ((pCurrTxRate->CurrMCS == MCS_15) && (pCurrTxRate->ShortGI == GI_800))
		{
			mcs[15] = idx;
		}
	}

#ifdef DBG_CTRL_SUPPORT
	/*  Debug Option: Disable highest MCSs when picking initial MCS based on RSSI */
	if (pAd->CommonCfg.DebugFlags & DBF_INIT_MCS_DIS1)
		mcs[23] = mcs[15] = mcs[7] = mcs[22] = mcs[14] = mcs[6] = 0;
#endif /* DBG_CTRL_SUPPORT */
}


/*  MlmeClearTxQuality - Clear TxQuality history only for the active BF state */
VOID MlmeClearTxQuality(MAC_TABLE_ENTRY *pEntry)
{
#ifdef TXBF_AWARE
	if (pEntry->phyETxBf || pEntry->phyITxBf)
		memset(pEntry->BfTxQuality, 0, sizeof(pEntry->BfTxQuality));
	else
#endif /*  TXBF_AWARD */
		memset(pEntry->TxQuality, 0, sizeof(pEntry->TxQuality));

	memset(pEntry->PER, 0, sizeof(pEntry->PER));
}


/*  MlmeClearAllTxQuality - Clear both BF and non-BF TxQuality history */
VOID MlmeClearAllTxQuality(MAC_TABLE_ENTRY *pEntry)
{
#ifdef TXBF_AWARE
	memset(pEntry->BfTxQuality, 0, sizeof(pEntry->BfTxQuality));
#endif /*  TXBF_AWARD */
	memset(pEntry->TxQuality, 0, sizeof(pEntry->TxQuality));

	memset(pEntry->PER, 0, sizeof(pEntry->PER));
}


/*  MlmeDecTxQuality - Decrement TxQuality of specified rate table entry */
VOID MlmeDecTxQuality(MAC_TABLE_ENTRY *pEntry, u8 rateIndex)
{
#ifdef TXBF_AWARE
	if (pEntry->phyETxBf || pEntry->phyITxBf) {
		if (pEntry->BfTxQuality[rateIndex])
			pEntry->BfTxQuality[rateIndex]--;
	}
	else
#endif /*  TXBF_AWARD */
	if (pEntry->TxQuality[rateIndex])
		pEntry->TxQuality[rateIndex]--;
}


VOID MlmeSetTxQuality(MAC_TABLE_ENTRY *pEntry, u8 rate_idx, unsigned short quality)
{
#ifdef TXBF_AWARE
	if (pEntry->phyETxBf || pEntry->phyITxBf)
		pEntry->BfTxQuality[rate_idx] = quality;
	else
#endif /*  TXBF_AWARD */
		pEntry->TxQuality[rate_idx] = quality;
}


unsigned short MlmeGetTxQuality(MAC_TABLE_ENTRY *pEntry, u8 rateIndex)
{
#ifdef TXBF_AWARE
	if (pEntry->phyETxBf || pEntry->phyITxBf)
		return pEntry->BfTxQuality[rateIndex];
#endif /*  TXBF_AWARD */
	return pEntry->TxQuality[rateIndex];
}



#ifdef CONFIG_AP_SUPPORT
VOID APMlmeSetTxRate(
	IN struct rtmp_adapter *pAd,
	IN MAC_TABLE_ENTRY *pEntry,
	IN RTMP_RA_LEGACY_TB *pTxRate)
{
	u8 tx_mode = pTxRate->Mode;
	u8 tx_bw = pTxRate->BW;

	if ((pAd->chipCap.phy_caps & fPHY_CAP_VHT) &&
		((pEntry->pTable == RateTableVht2S) || (pEntry->pTable == RateTableVht1S) ||
		 (pEntry->pTable == RateTableVht1S_MCS9) ||
		 (pEntry->pTable == RateTableVht2S_BW20) ||
		 (pEntry->pTable == RateTableVht2S_BW40) ||
		 (pEntry->pTable == RateTableVht2S_MCS7) ||
		 (pEntry->pTable == RateTableVht1S_2G_BW20) ||
		 (pEntry->pTable == RateTableVht1S_2G_BW40) ||
		 (pEntry->pTable == RateTableVht2S_2G_BW20) ||
		 (pEntry->pTable == RateTableVht2S_2G_BW40)))
	{
		RTMP_RA_GRP_TB *pAdaptTbEntry = (RTMP_RA_GRP_TB *)pTxRate;
		u8 bw_cap = BW_20;

		if (pEntry->MaxHTPhyMode.field.BW != pAdaptTbEntry->BW)
		{
			switch (pEntry->MaxHTPhyMode.field.BW)
			{
				case BW_80:
					bw_cap = pAdaptTbEntry->BW;
					break;
				case BW_40:
					if (pAdaptTbEntry->BW == BW_80)
						bw_cap = BW_40;
					else
						bw_cap = pAdaptTbEntry->BW;
					break;
#if 0	/* ULLI : BW_10 is 4 in a 2 bit bitfield */
				case BW_10:
					bw_cap = BW_10;
					break;
#endif
				case BW_20:
				default:
					if (pAdaptTbEntry->BW == BW_80 || pAdaptTbEntry->BW == BW_40)
						bw_cap = BW_20;
					else
						bw_cap = pAdaptTbEntry->BW;
					break;
			}
			tx_bw = bw_cap;
		}
		else
			tx_bw = pAdaptTbEntry->BW;

		if ((pEntry->force_op_mode == true))
		{
			switch (pEntry->operating_mode.ch_width) {
				case 1:
					bw_cap = BW_40;
					break;
				case 2:
					bw_cap = BW_80;
					break;
				case 0:
				default:
					bw_cap = BW_20;
					break;
			}
			if ((tx_bw != BW_10) && (tx_bw >= bw_cap))
				tx_bw = bw_cap;
		}

#ifdef WFA_VHT_PF
		if (pAd->CommonCfg.vht_bw_signal && tx_bw == BW_40 &&
			pAdaptTbEntry->Mode == MODE_VHT &&
			(pAd->MacTab.fAnyStation20Only == false))
		{
			// try to use BW_40 for VHT mode!
			tx_mode = pAdaptTbEntry->Mode;
		}
#endif /* WFA_VHT_PF */
DBGPRINT(RT_DEBUG_INFO, ("%s(): txbw=%d, txmode=%d\n", __FUNCTION__, tx_bw, tx_mode));
	}

	if (tx_mode == MODE_HTMIX || tx_mode == MODE_HTGREENFIELD)
	{
		if ((pTxRate->STBC) && (pEntry->MaxHTPhyMode.field.STBC))
			pEntry->HTPhyMode.field.STBC = STBC_USE;
		else
			pEntry->HTPhyMode.field.STBC = STBC_NONE;

		if ((pTxRate->ShortGI || pAd->WIFItestbed.bShortGI) && (pEntry->MaxHTPhyMode.field.ShortGI))
			pEntry->HTPhyMode.field.ShortGI = GI_400;
		else
			pEntry->HTPhyMode.field.ShortGI = GI_800;
	}

	/* TODO: will check ldpc if related to rate table */
	if (CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_VHT_RX_LDPC_CAPABLE) ||
		CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_HT_RX_LDPC_CAPABLE)) {
		pEntry->HTPhyMode.field.ldpc = true;
	} else {
		pEntry->HTPhyMode.field.ldpc = false;
	}

	if (tx_mode == MODE_VHT)
	{
		if (((CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_SGI80_CAPABLE)) ||
			CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_2G_256QAM_CAPABLE)) &&
			(pTxRate->ShortGI
#ifdef WFA_VHT_PF
			|| pAd->vht_force_sgi
#endif /* WFA_VHT_PF */
			)
		)
			pEntry->HTPhyMode.field.ShortGI = GI_400;
		else
			pEntry->HTPhyMode.field.ShortGI = GI_800;

		if (pTxRate->STBC && (CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_VHT_RXSTBC_CAPABLE)))
			pEntry->HTPhyMode.field.STBC = STBC_USE;
		else
			pEntry->HTPhyMode.field.STBC = STBC_NONE;
	}

	if (pTxRate->CurrMCS < MCS_AUTO)
		pEntry->HTPhyMode.field.MCS = pTxRate->CurrMCS;

	pEntry->HTPhyMode.field.MODE = tx_mode;

	if ((pAd->WIFItestbed.bGreenField & pEntry->HTCapability.HtCapInfo.GF) && (pEntry->HTPhyMode.field.MODE == MODE_HTMIX))
	{
		/* force Tx GreenField */
		pEntry->HTPhyMode.field.MODE = MODE_HTGREENFIELD;
	}

	/* BW depends on BSSWidthTrigger and Negotiated BW */
	if (pAd->CommonCfg.bRcvBSSWidthTriggerEvents ||
		(pEntry->MaxHTPhyMode.field.BW==BW_20) ||
		(pAd->CommonCfg.BBPCurrentBW==BW_20))
		pEntry->HTPhyMode.field.BW = BW_20;
	else
		pEntry->HTPhyMode.field.BW = BW_40;

	if (pAd->CommonCfg.BBPCurrentBW==BW_80 &&
		pEntry->MaxHTPhyMode.field.BW == BW_80 &&
		pEntry->MaxHTPhyMode.field.MODE == MODE_VHT)
		pEntry->HTPhyMode.field.BW = BW_80;

#ifdef NEW_RATE_ADAPT_SUPPORT
	if ((pEntry->pTable == RateTableVht2S) ||
		(pEntry->pTable == RateTableVht2S_BW20) ||
		(pEntry->pTable == RateTableVht2S_BW40) ||
		(pEntry->pTable == RateTableVht1S) ||
		(pEntry->pTable == RateTableVht1S_MCS9) ||
		(pEntry->pTable == RateTableVht2S_MCS7) ||
		(pEntry->pTable == RateTableVht1S_2G_BW20) ||
		(pEntry->pTable == RateTableVht1S_2G_BW40) ||
		(pEntry->pTable == RateTableVht2S_2G_BW20) ||
		(pEntry->pTable == RateTableVht2S_2G_BW40))
	{
		RTMP_RA_GRP_TB *pAdaptTbEntry = (RTMP_RA_GRP_TB *)pTxRate;
		pEntry->HTPhyMode.field.MCS = pAdaptTbEntry->CurrMCS | ((pAdaptTbEntry->dataRate -1) <<4);
		pEntry->HTPhyMode.field.BW = tx_bw;

#ifdef WFA_VHT_PF
		if ((pAd->vht_force_tx_stbc)
			&& (pEntry->HTPhyMode.field.MODE == MODE_VHT)
			&& (CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_VHT_RXSTBC_CAPABLE))
			&& (pEntry->HTPhyMode.field.STBC == STBC_NONE)
		)
		{
			pEntry->HTPhyMode.field.MCS = pAdaptTbEntry->CurrMCS;
			pEntry->HTPhyMode.field.STBC = STBC_USE;
		}
#endif /* WFA_VHT_PF */
	}
	else if (IS_VHT_STA(pEntry))
	{
		u8 bw_max = pEntry->MaxHTPhyMode.field.BW;
		if (pEntry->force_op_mode == true)
		{
			switch (pEntry->operating_mode.ch_width) {
				case 1:
					bw_max = BW_40;
					break;
				case 2: /* not support for BW_80 for other rate table */
				case 0:
				default:
					bw_max = BW_20;
					break;
			}
		}

		if ( (bw_max != BW_10) &&
			(bw_max > pAd->CommonCfg.BBPCurrentBW))
		{
			bw_max = pAd->CommonCfg.BBPCurrentBW;
		}
		pEntry->HTPhyMode.field.BW = bw_max;
	}
#endif /* NEW_RATE_ADAPT_SUPPORT */


#ifdef RANGE_EXTEND
#ifdef NEW_RATE_ADAPT_SUPPORT
	/* 20 MHz Fallback */
	if ((tx_mode == MODE_HTMIX || tx_mode == MODE_HTGREENFIELD) &&
	    pEntry->HTPhyMode.field.BW == BW_40 &&
	    ADAPT_RATE_TABLE(pEntry->pTable))
	{
		if (pEntry->HTPhyMode.field.MCS == 32
#ifdef DBG_CTRL_SUPPORT
			&& (pAd->CommonCfg.DebugFlags & DBF_DISABLE_20MHZ_MCS0) == 0
#endif /* DBG_CTRL_SUPPORT */
		)
		{
			/* Map HT Duplicate to 20MHz MCS0 */
			pEntry->HTPhyMode.field.BW = BW_20;
			pEntry->HTPhyMode.field.MCS = 0;
		}
		else if (pEntry->HTPhyMode.field.MCS == 0 &&
				(pAd->CommonCfg.DebugFlags & DBF_FORCE_20MHZ) == 0
#ifdef DBG_CTRL_SUPPORT
				&& (pAd->CommonCfg.DebugFlags & DBF_DISABLE_20MHZ_MCS1) == 0
#endif /* DBG_CTRL_SUPPORT */
		)
		{
			/* Map 40MHz MCS0 to 20MHz MCS1 */
			pEntry->HTPhyMode.field.BW = BW_20;
			pEntry->HTPhyMode.field.MCS = 1;
		}
		else if (pEntry->HTPhyMode.field.MCS == 8
#ifdef DBG_CTRL_SUPPORT
			&& (pAd->CommonCfg.DebugFlags & DBF_ENABLE_20MHZ_MCS8)
#endif /* DBG_CTRL_SUPPORT */
			)
		{
			/* Map 40MHz MCS8 to 20MHz MCS8 */
			pEntry->HTPhyMode.field.BW = BW_20;
		}
	}
#endif /* NEW_RATE_ADAPT_SUPPORT */

#ifdef DBG_CTRL_SUPPORT
	/* Debug Option: Force BW */
	if (pAd->CommonCfg.DebugFlags & DBF_FORCE_40MHZ)
	{
		pEntry->HTPhyMode.field.BW = BW_40;
	}
	else if (pAd->CommonCfg.DebugFlags & DBF_FORCE_20MHZ)
	{
		pEntry->HTPhyMode.field.BW = BW_20;
	}
#endif /* DBG_CTRL_SUPPORT */
#endif /* RANGE_EXTEND */

	/* Reexam each bandwidth's SGI support. */
	if ((pEntry->HTPhyMode.field.BW==BW_20 && !CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_SGI20_CAPABLE)) ||
		(pEntry->HTPhyMode.field.BW==BW_40 && !CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_SGI40_CAPABLE)) )
		pEntry->HTPhyMode.field.ShortGI = GI_800;

#ifdef DBG_CTRL_SUPPORT
	/* Debug option: Force Short GI */
	if (pAd->CommonCfg.DebugFlags & DBF_FORCE_SGI)
		pEntry->HTPhyMode.field.ShortGI = GI_400;
#endif /* DBG_CTRL_SUPPORT */

	pAd->LastTxRate = (unsigned short)(pEntry->HTPhyMode.word);

#ifdef FIFO_EXT_SUPPORT
	AsicFifoExtEntryClean(pAd, pEntry);
#endif /* FIFO_EXT_SUPPORT */



}
#endif /* CONFIG_AP_SUPPORT */


#ifdef CONFIG_STA_SUPPORT
VOID MlmeSetTxRate(
	IN struct rtmp_adapter *pAd,
	IN MAC_TABLE_ENTRY *pEntry,
	IN RTMP_RA_LEGACY_TB *pTxRate)
{
	struct rtmp_wifi_dev *wdev = &pAd->StaCfg.wdev;
	u8 MaxMode = MODE_OFDM;
	u8 tx_mode = pTxRate->Mode;
	u8 tx_bw = pTxRate->BW;
	HTTRANSMIT_SETTING *tx_setting = &pAd->StaCfg.wdev.HTPhyMode;

	MaxMode = MODE_HTGREENFIELD;

	MaxMode = MODE_VHT;

	if (pTxRate->STBC &&
		(((pAd->StaCfg.wdev.MaxHTPhyMode.field.STBC) && (tx_mode == MODE_HTMIX || tx_mode == MODE_HTGREENFIELD))
			||((CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_VHT_RXSTBC_CAPABLE)) && (tx_mode == MODE_VHT))
		)
		/* Fix Miracast Connection failed issue with S4 phone if STBC was enabled */
		&& pEntry->MaxHTPhyMode.field.STBC
	)
		wdev->HTPhyMode.field.STBC = STBC_USE;
	else
		wdev->HTPhyMode.field.STBC = STBC_NONE;

	if (pTxRate->CurrMCS < MCS_AUTO)
		wdev->HTPhyMode.field.MCS = pTxRate->CurrMCS;

	/* TODO: will check ldpc if related to rate table */
	if (CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_VHT_RX_LDPC_CAPABLE) ||
		CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_HT_RX_LDPC_CAPABLE)) {
		wdev->HTPhyMode.field.ldpc = true;
	} else {
		wdev->HTPhyMode.field.ldpc = false;
	}

#ifdef NEW_RATE_ADAPT_SUPPORT
	if ((pEntry->pTable == RateTableVht2S) || (pEntry->pTable == RateTableVht2S_BW20) ||
				(pEntry->pTable == RateTableVht2S_BW40) ||
				(pEntry->pTable == RateTableVht1S) || (pEntry->pTable == RateTableVht1S_MCS9)
				|| (pEntry->pTable == RateTableVht2S_MCS7)
				|| (pEntry->pTable == RateTableVht1S_2G_BW20) || (pEntry->pTable == RateTableVht1S_2G_BW40)
				|| (pEntry->pTable == RateTableVht2S_2G_BW20) || (pEntry->pTable == RateTableVht2S_2G_BW40))
	{
		RTMP_RA_GRP_TB *pAdaptTbEntry = (RTMP_RA_GRP_TB *)pTxRate;
		// TODO: shiang-usw, fix me for STA mode, original code use following code
		pAd->StaCfg.wdev.HTPhyMode.field.MCS = pAdaptTbEntry->CurrMCS | ((pAdaptTbEntry->dataRate -1) <<4);
    	pAd->StaCfg.wdev.HTPhyMode.field.BW = pAdaptTbEntry->BW;
		// TODO: shiang-usw, we should use this method!
		wdev->HTPhyMode.field.MCS = pAdaptTbEntry->CurrMCS | ((pAdaptTbEntry->dataRate -1) <<4);
    	wdev->HTPhyMode.field.BW = pAdaptTbEntry->BW;
	}
#endif /* NEW_RATE_ADAPT_SUPPORT */


	if (wdev->HTPhyMode.field.MCS > 7)
		wdev->HTPhyMode.field.STBC = STBC_NONE;

   	if (ADHOC_ON(pAd))
	{
		/*  If peer adhoc is b-only mode, we can't send 11g rate. */
		wdev->HTPhyMode.field.ShortGI = GI_800;
		pEntry->HTPhyMode.field.STBC	= STBC_NONE;

		/* For Adhoc MODE_CCK, driver will use AdhocBOnlyJoined flag to roll back to B only if necessary */
		pEntry->HTPhyMode.field.MODE	= tx_mode;
		pEntry->HTPhyMode.field.ShortGI = wdev->HTPhyMode.field.ShortGI;
		pEntry->HTPhyMode.field.MCS = wdev->HTPhyMode.field.MCS;

		/*  Patch speed error in status page */
		wdev->HTPhyMode.field.MODE = pEntry->HTPhyMode.field.MODE;
	}
	else
	{
		unsigned short OperationMode =0xffff;

		if ((pAd->CommonCfg.RegTransmitSetting.field.HTMODE == HTMODE_GF) &&
			(pAd->MlmeAux.HtCapability.HtCapInfo.GF == HTMODE_GF))
			wdev->HTPhyMode.field.MODE = MODE_HTGREENFIELD;
		else
		if (tx_mode <= MaxMode)
			wdev->HTPhyMode.field.MODE = tx_mode;

		if (pTxRate->ShortGI && (wdev->MaxHTPhyMode.field.ShortGI))
			wdev->HTPhyMode.field.ShortGI = GI_400;
		else
			wdev->HTPhyMode.field.ShortGI = GI_800;

		/*  BW depends on Negotiated BW */
		if (pEntry->MaxHTPhyMode.field.BW==BW_20 || pAd->CommonCfg.BBPCurrentBW==BW_20)
			pEntry->HTPhyMode.field.BW = BW_20;
		else
			pEntry->HTPhyMode.field.BW = BW_40;

		if (pEntry->MaxHTPhyMode.field.BW==BW_80 || pAd->CommonCfg.BBPCurrentBW==BW_80)
			pEntry->HTPhyMode.field.BW = BW_80;

		if ((pEntry->force_op_mode == true))
		{
			u8 bw_cap = BW_20;

			switch (pEntry->operating_mode.ch_width) {
				case 1:
					bw_cap = BW_40;
					break;
				case 2:
					bw_cap = BW_80;
					break;
				case 0:
				default:
					bw_cap = BW_20;
					break;
			}
			if ((pEntry->HTPhyMode.field.BW != BW_10) && (pEntry->HTPhyMode.field.BW >= bw_cap))
				pEntry->HTPhyMode.field.BW = bw_cap;
		}

#ifdef RANGE_EXTEND
#ifdef NEW_RATE_ADAPT_SUPPORT
		/*  20 MHz Fallback */
		if (tx_mode >=MODE_HTMIX && pEntry->HTPhyMode.field.BW==BW_40 &&
			ADAPT_RATE_TABLE(pEntry->pTable)
		)
		{
			if ((wdev->HTPhyMode.field.MCS==32)
#ifdef DBG_CTRL_SUPPORT
			&& (pAd->CommonCfg.DebugFlags & DBF_DISABLE_20MHZ_MCS0)==0
#endif /* DBG_CTRL_SUPPORT */
			)
			{
				/*  Map HT Duplicate to 20MHz MCS0 */
				pEntry->HTPhyMode.field.BW = BW_20;
				wdev->HTPhyMode.field.MCS = 0;
				if (pTxRate->STBC && wdev->MaxHTPhyMode.field.STBC)
					wdev->HTPhyMode.field.STBC = STBC_USE;
			}
			else if (wdev->HTPhyMode.field.MCS==0
#ifdef DBG_CTRL_SUPPORT
				&& (pAd->CommonCfg.DebugFlags & DBF_FORCE_20MHZ)==0
				&& (pAd->CommonCfg.DebugFlags & DBF_DISABLE_20MHZ_MCS1)==0
#endif /* DBG_CTRL_SUPPORT */
			)
			{
				/*  Map 40MHz MCS0 to 20MHz MCS1 */
				pEntry->HTPhyMode.field.BW = BW_20;
				wdev->HTPhyMode.field.MCS = 1;
			}
			else if (wdev->HTPhyMode.field.MCS==8
#ifdef DBG_CTRL_SUPPORT
				&& (pAd->CommonCfg.DebugFlags & DBF_ENABLE_20MHZ_MCS8)
#endif /* DBG_CTRL_SUPPORT */
			)
			{
				/*  Map 40MHz MCS8 to 20MHz MCS8 */
				pEntry->HTPhyMode.field.BW = BW_20;
			}
		}
#endif /* NEW_RATE_ADAPT_SUPPORT */

#ifdef DBG_CTRL_SUPPORT
		/*  Debug Option: Force BW */
		if (pAd->CommonCfg.DebugFlags & DBF_FORCE_40MHZ)
			pEntry->HTPhyMode.field.BW = BW_40;
		else if (pAd->CommonCfg.DebugFlags & DBF_FORCE_20MHZ)
			pEntry->HTPhyMode.field.BW = BW_20;
#endif /* DBG_CTRL_SUPPORT */
#endif /*  RANGE_EXTEND */

		/*  Reexam each bandwidth's SGI support. */
		if ((pEntry->HTPhyMode.field.BW==BW_20 && !CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_SGI20_CAPABLE)) ||
			(pEntry->HTPhyMode.field.BW==BW_40 && !CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_SGI40_CAPABLE)) )
			wdev->HTPhyMode.field.ShortGI = GI_800;

#ifdef DBG_CTRL_SUPPORT
		/*  Debug option: Force Short GI */
		if (pAd->CommonCfg.DebugFlags & DBF_FORCE_SGI)
			wdev->HTPhyMode.field.ShortGI = GI_400;
#endif /*  DBG_CTRL_SUPPORT */

		/*  Turn RTS/CTS rate to 6Mbps. */
		if (((pEntry->HTPhyMode.field.MCS == 0) && (wdev->HTPhyMode.field.MCS != 0)) ||
			((pEntry->HTPhyMode.field.MCS == 8) && (wdev->HTPhyMode.field.MCS != 8)))
		{
			pEntry->HTPhyMode.field.MCS = wdev->HTPhyMode.field.MCS;
			if (pAd->MacTab.fAnyBASession)
				OperationMode = HT_FORCERTSCTS;
			else
				OperationMode = pAd->MlmeAux.AddHtInfo.AddHtInfo2.OperaionMode;
		}
		else if ((pEntry->HTPhyMode.field.MCS != 0) && (wdev->HTPhyMode.field.MCS == 0))
			OperationMode = HT_RTSCTS_6M;
		else if ((pEntry->HTPhyMode.field.MCS != 8) && (wdev->HTPhyMode.field.MCS == 8))
			OperationMode = HT_RTSCTS_6M;

		if (OperationMode != 0xffff)
			AsicUpdateProtect(pAd, OperationMode , ALLN_SETPROTECT, true,
							(bool)pAd->MlmeAux.AddHtInfo.AddHtInfo2.NonGfPresent);

		pEntry->HTPhyMode.field.STBC	= wdev->HTPhyMode.field.STBC;
		pEntry->HTPhyMode.field.ShortGI = wdev->HTPhyMode.field.ShortGI;
		pEntry->HTPhyMode.field.ldpc = wdev->HTPhyMode.field.ldpc;
		pEntry->HTPhyMode.field.MCS = wdev->HTPhyMode.field.MCS;
		pEntry->HTPhyMode.field.MODE = wdev->HTPhyMode.field.MODE;
	}


}
#endif /* CONFIG_STA_SUPPORT */


VOID MlmeSelectTxRateTable(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY pEntry,
	IN u8 **ppTable,
	IN u8 *pTableSize,
	IN u8 *pInitTxRateIdx)
{
	do
	{
		INT mcs_idx, ss = 0, bw = pEntry->MaxHTPhyMode.field.BW;

		if (WMODE_CAP_AC(pAd->CommonCfg.PhyMode) &&
			(pEntry->SupportRateMode & SUPPORT_VHT_MODE))
		{
			for (mcs_idx = 0; mcs_idx < MAX_LEN_OF_VHT_RATES; mcs_idx++)
			{
				if (pEntry->SupportVHTMCS[mcs_idx])
				{
					if (mcs_idx <= 9)
						ss =1;
					if (mcs_idx >= 10)
						ss = 2;
				}
			}

#ifdef WFA_VHT_PF
			if ((pAd->CommonCfg.vht_nss_cap > 0) &&
				(ss > pAd->CommonCfg.vht_nss_cap))
				ss = pAd->CommonCfg.vht_nss_cap;
#endif /* WFA_VHT_PF */

			if ((pEntry->force_op_mode == true) &&
			    (pEntry->operating_mode.rx_nss_type == 0))
			{
				if (pEntry->operating_mode.rx_nss < pAd->CommonCfg.TxStream)
					ss = pEntry->operating_mode.rx_nss + 1;

				switch (pEntry->operating_mode.ch_width)
				{
					case 0:
						bw = BW_20;
						break;
					case 1:
						bw = BW_40;
						break;
					case 2:
					default:
						bw = BW_80;
						break;
				}
			}

#ifdef NEW_RATE_ADAPT_SUPPORT
			if (pAd->rateAlg == RATE_ALG_GRP) {
				if (ss == 2) {
					if (pEntry->MaxHTPhyMode.field.BW == BW_20) {
						*ppTable = RateTableVht2S_BW20;
					} else if (pEntry->MaxHTPhyMode.field.BW == BW_40) {
						*ppTable = RateTableVht2S_BW40;
					} else if ((pEntry->SupportVHTMCS[MCS_8] == 1) &&
						(pEntry->SupportVHTMCS[MCS_9] == 1)) {
						*ppTable = RateTableVht2S;
					} else {
						*ppTable = RateTableVht2S_MCS7;
					}
				} else if (ss == 1) {
					if ((pEntry->SupportVHTMCS[MCS_8] == 1) &&
						(pEntry->SupportVHTMCS[MCS_9] == 1))
						*ppTable = RateTableVht1S_MCS9;
					else
						*ppTable = RateTableVht1S;
					DBGPRINT(RT_DEBUG_INFO | DBG_FUNC_RA, ("%s(): Select RateTableVht%dS%s\n",
							__FUNCTION__, (ss == 2 ? 2 : 1),
							((*ppTable == RateTableVht1S_MCS9) ? "_MCS9" : "")));
				} else {
					DBGPRINT(RT_DEBUG_ERROR, ("%s:unknow ss(%d)\n", __FUNCTION__, ss));
				}
			}
#endif /* NEW_RATE_ADAPT_SUPPORT */

#ifdef WFA_VHT_PF
			// TODO: shiang, add for Realtek behavior when run in BW signaling mode test and we are the testbed!
			// TODO: add at 11/15!
			if ((pAd->CommonCfg.vht_bw_signal == BW_SIGNALING_DYNAMIC) &&
				(bw == BW_40) &&
				(pAd->MacTab.fAnyStation20Only == false))
				break;
#endif /* WFA_VHT_PF */
		}

#ifdef CONFIG_STA_SUPPORT
		if ((pAd->OpMode == OPMODE_STA) && ADHOC_ON(pAd))
		{
			/* for ADHOC mode */
			if (WMODE_CAP_N(pAd->CommonCfg.PhyMode) &&
				(pEntry->HTCapability.MCSSet[0] != 0x00) &&
				((pEntry->HTCapability.MCSSet[1] == 0x00) || (pAd->Antenna.field.TxPath == 1)))
			{/* 11N 1S Adhoc*/

				{
					if (pAd->LatchRfRegs.Channel <= 14)
						*ppTable = RateSwitchTable11N1S;
					else
						*ppTable = RateSwitchTable11N1SForABand;
				}
			}
			else if (WMODE_CAP_N(pAd->CommonCfg.PhyMode) &&
					(pEntry->HTCapability.MCSSet[0] != 0x00) &&
					(pEntry->HTCapability.MCSSet[1] != 0x00) &&
					(((pAd->Antenna.field.TxPath == 3) && (pEntry->HTCapability.MCSSet[2] == 0x00)) || (pAd->Antenna.field.TxPath == 2)))
			{/* 11N 2S Adhoc*/
				{
					if (pAd->LatchRfRegs.Channel <= 14)
						*ppTable = RateSwitchTable11N2S;
					else
						*ppTable = RateSwitchTable11N2SForABand;
				}
			}
			else
			if ((pEntry->RateLen == 4)
				&& (pEntry->HTCapability.MCSSet[0] == 0) && (pEntry->HTCapability.MCSSet[1] == 0)
			)
				*ppTable = RateSwitchTable11B;
			else if (pAd->LatchRfRegs.Channel <= 14)
				*ppTable = RateSwitchTable11BG;
			else
				*ppTable = RateSwitchTable11G;
			break;
		}
#endif /* CONFIG_STA_SUPPORT */

		/*if ((pAd->StaActive.SupRateLen + pAd->StaActive.ExtRateLen == 12) && (pAd->StaActive.SupportedPhyInfo.MCSSet[0] == 0xff) &&*/
		/*	((pAd->StaActive.SupportedPhyInfo.MCSSet[1] == 0x00) || (pAd->Antenna.field.TxPath == 1)))*/
		if ((pEntry->SupportRateMode & (SUPPORT_OFDM_MODE)) &&
			(pEntry->HTCapability.MCSSet[0] != 0x00) &&
			((pEntry->HTCapability.MCSSet[1] == 0x00) || (pAd->CommonCfg.TxStream == 1)))
		{/* 11BGN 1S AP*/

			if (CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_2G_256QAM_CAPABLE)
				&& (pAd->LatchRfRegs.Channel <= 14))
			{
				if (pEntry->MaxHTPhyMode.field.BW == BW_20) {
					*ppTable = RateTableVht1S_2G_BW20;
				} else if (pEntry->MaxHTPhyMode.field.BW == BW_40) {
					*ppTable = RateTableVht1S_2G_BW40;
				}

				break;
			}

#ifdef NEW_RATE_ADAPT_SUPPORT
			if (pAd->rateAlg == RATE_ALG_GRP)
				*ppTable = RateSwitchTableAdapt11N1S;
			else
#endif
			if ((pAd->LatchRfRegs.Channel <= 14) && (pEntry->SupportRateMode & (SUPPORT_CCK_MODE)))
				*ppTable = RateSwitchTable11BGN1S;
			else
				*ppTable = RateSwitchTable11N1SForABand;

			break;
		}

		/*else if ((pAd->StaActive.SupRateLen + pAd->StaActive.ExtRateLen == 12) && (pAd->StaActive.SupportedPhyInfo.MCSSet[0] == 0xff) &&*/
		/*	(pAd->StaActive.SupportedPhyInfo.MCSSet[1] == 0xff) && (pAd->Antenna.field.TxPath == 2))*/
		if ((pEntry->SupportRateMode & (SUPPORT_OFDM_MODE)) &&
			(pEntry->HTCapability.MCSSet[0] != 0x00) &&
			(pEntry->HTCapability.MCSSet[1] != 0x00) &&
			(((pAd->Antenna.field.TxPath == 3) && (pEntry->HTCapability.MCSSet[2] == 0x00)) || (pAd->CommonCfg.TxStream == 2)))
		{/* 11BGN 2S AP*/
			if (CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_2G_256QAM_CAPABLE)
				&& (pAd->LatchRfRegs.Channel <= 14))
			{
				if (pEntry->MaxHTPhyMode.field.BW == BW_20) {
					*ppTable = RateTableVht2S_2G_BW20;
				} else if (pEntry->MaxHTPhyMode.field.BW == BW_40) {
					*ppTable = RateTableVht2S_2G_BW40;
				}

				break;
			}

#ifdef NEW_RATE_ADAPT_SUPPORT
				if (pAd->rateAlg == RATE_ALG_GRP) {
					*ppTable = RateSwitchTableAdapt11N2S;
				} else
#endif /* NEW_RATE_ADAPT_SUPPORT */
			if ((pAd->LatchRfRegs.Channel <= 14) && (pEntry->SupportRateMode & (SUPPORT_CCK_MODE)))
					*ppTable = RateSwitchTable11BGN2S;
				else
					*ppTable = RateSwitchTable11BGN2SForABand;

			break;
		}


		/*else if ((pAd->StaActive.SupportedPhyInfo.MCSSet[0] == 0xff) && ((pAd->StaActive.SupportedPhyInfo.MCSSet[1] == 0x00) || (pAd->Antenna.field.TxPath == 1)))*/
		if ((pEntry->HTCapability.MCSSet[0] != 0x00) &&
			((pEntry->HTCapability.MCSSet[1] == 0x00) || (pAd->CommonCfg.TxStream == 1)
			))
		{/* 11N 1S AP*/
			{
#ifdef NEW_RATE_ADAPT_SUPPORT
				if (pAd->rateAlg == RATE_ALG_GRP)
					*ppTable = RateSwitchTableAdapt11N1S;
				else
#endif /* NEW_RATE_ADAPT_SUPPORT */
				if (pAd->LatchRfRegs.Channel <= 14)
					*ppTable = RateSwitchTable11N1S;
				else
					*ppTable = RateSwitchTable11N1SForABand;
			}
			break;
		}

		/*else if ((pAd->StaActive.SupportedPhyInfo.MCSSet[0] == 0xff) && (pAd->StaActive.SupportedPhyInfo.MCSSet[1] == 0xff) && (pAd->Antenna.field.TxPath == 2))*/
		if ((pEntry->HTCapability.MCSSet[0] != 0x00) &&
			(pEntry->HTCapability.MCSSet[1] != 0x00) &&
			(pAd->CommonCfg.TxStream == 2)
			)
		{/* 11N 2S AP*/
			{
#ifdef NEW_RATE_ADAPT_SUPPORT
				if (pAd->rateAlg == RATE_ALG_GRP) {
					*ppTable = RateSwitchTableAdapt11N2S;
				} else
#endif /* NEW_RATE_ADAPT_SUPPORT */
				if (pAd->LatchRfRegs.Channel <= 14)
					*ppTable = RateSwitchTable11N2S;
				else
					*ppTable = RateSwitchTable11N2SForABand;
			}
			break;
		}



		if (((pEntry->SupportRateMode == SUPPORT_CCK_MODE) ||
			WMODE_EQUAL(pAd->CommonCfg.PhyMode, WMODE_B))
		/*Iverson mark for Adhoc b mode,sta will use rate 54  Mbps when connect with sta b/g/n mode */
		/* && (pEntry->HTCapability.MCSSet[0] == 0) && (pEntry->HTCapability.MCSSet[1] == 0)*/
			)
		{/* B only AP*/
			*ppTable = RateSwitchTable11B;
			break;
		}

		/*else if ((pAd->StaActive.SupRateLen + pAd->StaActive.ExtRateLen > 8) && (pAd->StaActive.SupportedPhyInfo.MCSSet[0] == 0) && (pAd->StaActive.SupportedPhyInfo.MCSSet[1] == 0))*/
		if ((pEntry->SupportRateMode & (SUPPORT_CCK_MODE)) &&
			(pEntry->SupportRateMode & (SUPPORT_OFDM_MODE))
			&& (pEntry->HTCapability.MCSSet[0] == 0) && (pEntry->HTCapability.MCSSet[1] == 0)
			)
		{/* B/G  mixed AP*/
			*ppTable = RateSwitchTable11BG;
			break;
		}

		/*else if ((pAd->StaActive.SupRateLen + pAd->StaActive.ExtRateLen == 8) && (pAd->StaActive.SupportedPhyInfo.MCSSet[0] == 0) && (pAd->StaActive.SupportedPhyInfo.MCSSet[1] == 0))*/
		if ((pEntry->SupportRateMode & (SUPPORT_OFDM_MODE))
			&& (pEntry->HTCapability.MCSSet[0] == 0) && (pEntry->HTCapability.MCSSet[1] == 0)
			)
		{/* G only AP*/
			*ppTable = RateSwitchTable11G;
			break;
		}
#ifdef CONFIG_AP_SUPPORT
		IF_DEV_CONFIG_OPMODE_ON_AP(pAd)
		{
			{
				/*
					Temp solution for:
					EX: when the extend rate only supports 6, 12, 24 in
					the association req frame. So the pEntry->RateLen is 7.
				*/
				if (pAd->LatchRfRegs.Channel <= 14)
					*ppTable = RateSwitchTable11BG;
				else
					*ppTable = RateSwitchTable11G;
			}
			break;
		}
#endif /* CONFIG_AP_SUPPORT */

#ifdef CONFIG_STA_SUPPORT
		IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
		{
			/*else if ((pAd->StaActive.SupportedPhyInfo.MCSSet[0] == 0) && (pAd->StaActive.SupportedPhyInfo.MCSSet[1] == 0))*/
			if ((pEntry->HTCapability.MCSSet[0] == 0) && (pEntry->HTCapability.MCSSet[1] == 0))
			{	/* Legacy mode*/
				if (pAd->CommonCfg.MaxTxRate <= RATE_11)
				{
					*ppTable = RateSwitchTable11B;
				}
				else if ((pAd->CommonCfg.MaxTxRate > RATE_11) && (pAd->CommonCfg.MinTxRate > RATE_11))
				{
					*ppTable = RateSwitchTable11G;
				}
				else
				{
					*ppTable = RateSwitchTable11BG;
				}
				break;
			}
			{
				if (pAd->LatchRfRegs.Channel <= 14)
				{
					if (pAd->CommonCfg.TxStream == 1)
					{
						*ppTable = RateSwitchTable11N1S;
						DBGPRINT_RAW(RT_DEBUG_ERROR,("DRS: unkown mode,default use 11N 1S AP \n"));
					}
					else if (pAd->CommonCfg.TxStream == 2)
					{
						*ppTable = RateSwitchTable11N2S;
						DBGPRINT_RAW(RT_DEBUG_ERROR,("DRS: unkown mode,default use 11N 2S AP \n"));
					}
					else
					{
						*ppTable = RateSwitchTable11N2S;
					}
				}
				else
				{
					if (pAd->CommonCfg.TxStream == 1)
					{
						*ppTable = RateSwitchTable11N1S;
						DBGPRINT_RAW(RT_DEBUG_ERROR,("DRS: unkown mode,default use 11N 1S AP \n"));
					}
					else if (pAd->CommonCfg.TxStream == 2)
					{
						*ppTable = RateSwitchTable11N2S;
						DBGPRINT_RAW(RT_DEBUG_ERROR,("DRS: unkown mode,default use 11N 2S AP \n"));
					}
					else
					{
						*ppTable = RateSwitchTable11N2SForABand;
					}
				}
			}
			DBGPRINT_RAW(RT_DEBUG_ERROR,("DRS: unkown mode (SupRateLen=%d, ExtRateLen=%d, MCSSet[0]=0x%x, MCSSet[1]=0x%x)\n",
						pAd->StaActive.SupRateLen,
						pAd->StaActive.ExtRateLen,
						pAd->StaActive.SupportedPhyInfo.MCSSet[0],
						pAd->StaActive.SupportedPhyInfo.MCSSet[1]));
		}
#endif /* CONFIG_STA_SUPPORT */
	} while(false);

	*pTableSize = RATE_TABLE_SIZE(*ppTable);
	*pInitTxRateIdx = RATE_TABLE_INIT_INDEX(*ppTable);

}



/*
	MlmeSelectTxRate - select the MCS based on the RSSI and the available MCSs
		pAd - pointer to adapter
		pEntry - pointer to MAC table entry
		mcs - table of MCS index into the Rate Table. -1 => not supported
		Rssi - the Rssi value
		RssiOffset - offset to apply to the Rssi
*/
u8 MlmeSelectTxRate(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY	pEntry,
	IN CHAR		mcs[],
	IN CHAR		Rssi,
	IN CHAR		RssiOffset)
{
	u8 TxRateIdx = 0;
	u8 *pTable = pEntry->pTable;

#ifdef NEW_RATE_ADAPT_SUPPORT
	if (pTable == RateTableVht2S || pTable == RateTableVht2S_BW20 || pTable == RateTableVht2S_BW40
		|| (pTable == RateTableVht2S_MCS7)
		|| (pTable == RateTableVht2S_2G_BW20) || (pTable == RateTableVht2S_2G_BW40))
	{
		/*  VHT mode with 2SS */
		if (mcs[15]>=0 && (Rssi >= (-70+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_15]))
			TxRateIdx = mcs[15];
		else if (mcs[14]>=0 && (Rssi >= (-72+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_14]))
			TxRateIdx = mcs[14];
		else if (mcs[13]>=0 && (Rssi >= (-76+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_13]))
			TxRateIdx = mcs[13];
		else if (mcs[12]>=0 && (Rssi >= (-78+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_12]))
			TxRateIdx = mcs[12];
		else if (mcs[4]>=0 && (Rssi >= (-82+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_4]))
			TxRateIdx = mcs[4];
		else if (mcs[3]>=0 && (Rssi >= (-84+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_3]))
			TxRateIdx = mcs[3];
		else if (mcs[2]>=0 && (Rssi >= (-86+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_2]))
			TxRateIdx = mcs[2];
		else if (mcs[1]>=0 && (Rssi >= (-88+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_1]))
			TxRateIdx = mcs[1];
		else
			TxRateIdx = mcs[0];
	}
	else if ((pTable == RateTableVht1S_MCS9)
		|| (pTable == RateTableVht1S_2G_BW20) || (pTable == RateTableVht1S_2G_BW40))
	{	/*  VHT mode with 1SS */
		if (mcs[9]>=0 && (Rssi > (-72+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_9]))
			TxRateIdx = mcs[8];
		else if (mcs[8]>=0 && (Rssi > (-72+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_8]))
			TxRateIdx = mcs[8];
		else if (mcs[7]>=0 && (Rssi > (-72+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_7]))
			TxRateIdx = mcs[7];
		else if (mcs[6]>=0 && (Rssi > (-74+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_6]))
			TxRateIdx = mcs[6];
		else if (mcs[5]>=0 && (Rssi > (-77+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_5]))
			TxRateIdx = mcs[5];
		else if (mcs[4]>=0 && (Rssi > (-79+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_4]))
			TxRateIdx = mcs[4];
		else if (mcs[3]>=0 && (Rssi > (-81+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_3]))
			TxRateIdx = mcs[3];
		else if (mcs[2]>=0 && (Rssi > (-83+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_2]))
			TxRateIdx = mcs[2];
		else if (mcs[1]>=0 && (Rssi > (-86+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_1]))
			TxRateIdx = mcs[1];
		else
			TxRateIdx = mcs[0];
	}
	else if (pTable == RateTableVht1S)
	{	/*  VHT mode with 1SS */
		if (mcs[7]>=0 && (Rssi > (-72+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_7]))
			TxRateIdx = mcs[7];
		else if (mcs[6]>=0 && (Rssi > (-74+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_6]))
			TxRateIdx = mcs[6];
		else if (mcs[5]>=0 && (Rssi > (-77+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_5]))
			TxRateIdx = mcs[5];
		else if (mcs[4]>=0 && (Rssi > (-79+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_4]))
			TxRateIdx = mcs[4];
		else if (mcs[3]>=0 && (Rssi > (-81+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_3]))
			TxRateIdx = mcs[3];
		else if (mcs[2]>=0 && (Rssi > (-83+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_2]))
			TxRateIdx = mcs[2];
		else if (mcs[1]>=0 && (Rssi > (-86+RssiOffset)) && (pEntry->SupportVHTMCS[MCS_1]))
			TxRateIdx = mcs[1];
		else
			TxRateIdx = mcs[0];
	}
	else
#endif /* NEW_RATE_ADAPT_SUPPORT */
	if ((pTable == RateSwitchTable11BGN2S) || (pTable == RateSwitchTable11BGN2SForABand) ||
		(pTable == RateSwitchTable11N2S) || (pTable == RateSwitchTable11N2SForABand)
#ifdef NEW_RATE_ADAPT_SUPPORT
		|| (pTable == RateSwitchTableAdapt11N2S)
#endif /* NEW_RATE_ADAPT_SUPPORT */
	)
	{/*  N mode with 2 stream */
		if (mcs[15]>=0 && (Rssi >= (-70+RssiOffset)) && (pEntry->SupportHTMCS[MCS_15]))
			TxRateIdx = mcs[15];
		else if (mcs[14]>=0 && (Rssi >= (-72+RssiOffset)) && (pEntry->SupportHTMCS[MCS_14]))
			TxRateIdx = mcs[14];
		else if (mcs[13]>=0 && (Rssi >= (-76+RssiOffset)) && (pEntry->SupportHTMCS[MCS_13]))
			TxRateIdx = mcs[13];
		else if (mcs[12]>=0 && (Rssi >= (-78+RssiOffset)) && (pEntry->SupportHTMCS[MCS_12]))
			TxRateIdx = mcs[12];
		else if (mcs[4]>=0 && (Rssi >= (-82+RssiOffset)) && (pEntry->SupportHTMCS[MCS_4]))
			TxRateIdx = mcs[4];
		else if (mcs[3]>=0 && (Rssi >= (-84+RssiOffset)) && (pEntry->SupportHTMCS[MCS_3]))
			TxRateIdx = mcs[3];
		else if (mcs[2]>=0 && (Rssi >= (-86+RssiOffset)) && (pEntry->SupportHTMCS[MCS_2]))
			TxRateIdx = mcs[2];
		else if (mcs[1]>=0 && (Rssi >= (-88+RssiOffset)) && (pEntry->SupportHTMCS[MCS_1]))
			TxRateIdx = mcs[1];
		else
			TxRateIdx = mcs[0];
	}
	else if ((pTable == RateSwitchTable11BGN1S) ||
			 (pTable == RateSwitchTable11N1S) ||
			 (pTable == RateSwitchTable11N1SForABand)
#ifdef NEW_RATE_ADAPT_SUPPORT
			|| (pTable == RateSwitchTableAdapt11N1S)
#endif /* NEW_RATE_ADAPT_SUPPORT */
	)
	{/*  N mode with 1 stream */
		{
			if (mcs[7]>=0 && (Rssi > (-72+RssiOffset)) && (pEntry->SupportHTMCS[MCS_7]))
				TxRateIdx = mcs[7];
			else if (mcs[6]>=0 && (Rssi > (-74+RssiOffset)) && (pEntry->SupportHTMCS[MCS_6]))
				TxRateIdx = mcs[6];
			else if (mcs[5]>=0 && (Rssi > (-77+RssiOffset)) && (pEntry->SupportHTMCS[MCS_5]))
				TxRateIdx = mcs[5];
			else if (mcs[4]>=0 && (Rssi > (-79+RssiOffset)) && (pEntry->SupportHTMCS[MCS_4]))
				TxRateIdx = mcs[4];
			else if (mcs[3]>=0 && (Rssi > (-81+RssiOffset)) && (pEntry->SupportHTMCS[MCS_3]))
				TxRateIdx = mcs[3];
			else if (mcs[2]>=0 && (Rssi > (-83+RssiOffset)) && (pEntry->SupportHTMCS[MCS_2]))
				TxRateIdx = mcs[2];
			else if (mcs[1]>=0 && (Rssi > (-86+RssiOffset)) && (pEntry->SupportHTMCS[MCS_1]))
				TxRateIdx = mcs[1];
			else
				TxRateIdx = mcs[0];
		}
	}
	else
	{/*  Legacy mode */
		if (mcs[7]>=0 && (Rssi > -70) && (pEntry->SupportOFDMMCS[MCS_7]))
		TxRateIdx = mcs[7];
		else if (mcs[6]>=0 && (Rssi > -74) && (pEntry->SupportOFDMMCS[MCS_7]))
			TxRateIdx = mcs[6];
		else if (mcs[5]>=0 && (Rssi > -78) && (pEntry->SupportOFDMMCS[MCS_7]))
			TxRateIdx = mcs[5];
		else if (mcs[4]>=0 && (Rssi > -82) && (pEntry->SupportOFDMMCS[MCS_7]))
			TxRateIdx = mcs[4];
		else if (mcs[4] == -1)							/*  for B-only mode */
		{
			if (mcs[3]>=0 && (Rssi > -85) && (pEntry->SupportCCKMCS[MCS_3]))
				TxRateIdx = mcs[3];
			else if (mcs[2]>=0 && (Rssi > -87) && (pEntry->SupportCCKMCS[MCS_2]))
				TxRateIdx = mcs[2];
			else if (mcs[1]>=0 && (Rssi > -90) && (pEntry->SupportCCKMCS[MCS_1]))
				TxRateIdx = mcs[1];
			else if (pEntry->SupportCCKMCS[MCS_0])
				TxRateIdx = mcs[0];
			else
			TxRateIdx = mcs[3];
		}
		else if (mcs[3]>=0 && (Rssi > -85) && (pEntry->SupportOFDMMCS[MCS_3]))
			TxRateIdx = mcs[3];
		else if (mcs[2]>=0 && (Rssi > -87) && (pEntry->SupportOFDMMCS[MCS_2]))
			TxRateIdx = mcs[2];
		else if (mcs[1]>=0 && (Rssi > -90) && (pEntry->SupportOFDMMCS[MCS_1]))
			TxRateIdx = mcs[1];
		else
			TxRateIdx = mcs[0];
	}


	return TxRateIdx;
}


/*  MlmeRAInit - Initialize Rate Adaptation for this entry */
VOID MlmeRAInit(struct rtmp_adapter *pAd, MAC_TABLE_ENTRY *pEntry)
{
#ifdef NEW_RATE_ADAPT_SUPPORT
	MlmeSetMcsGroup(pAd, pEntry);

	pEntry->lastRateIdx = 1;
	pEntry->lowTrafficCount = 0;
	pEntry->perThrdAdj = PER_THRD_ADJ;
#endif /* NEW_RATE_ADAPT_SUPPORT */
	pEntry->lowTrafficCount = 0;

	pEntry->phyETxBf = pEntry->phyITxBf = false;
	pEntry->lastRatePhyTxBf = false;
	pEntry->lastNonBfRate = 0;

	pEntry->fLastSecAccordingRSSI = false;
	pEntry->LastSecTxRateChangeAction = RATE_NO_CHANGE;
	pEntry->CurrTxRateIndex = 0;
	pEntry->CurrTxRateStableTime = 0;
	pEntry->TxRateUpPenalty = 0;
	pEntry->LowPacket = false;
    pEntry->LastSaveRateIdx = 0;
    memset(pEntry->DownTxMCSRate, 0, sizeof(pEntry->DownTxMCSRate));

	MlmeClearAllTxQuality(pEntry);
}


/* #define TIMESTAMP_RA_LOG	*/ /* Include timestamp in RA Log */

/*
	MlmeRALog - Prints concise Rate Adaptation log entry
		The BF percentage counters are also updated
*/
VOID MlmeRALog(
	IN struct rtmp_adapter *pAd,
	IN PMAC_TABLE_ENTRY	pEntry,
	IN RA_LOG_TYPE		raLogType,
	IN ULONG			TxErrorRatio,
	IN ULONG			TxTotalCnt)
{
	UINT ETxCount = pEntry->TxBFCounters.ETxSuccessCount + pEntry->TxBFCounters.ETxFailCount;
	UINT ITxCount = pEntry->TxBFCounters.ITxSuccessCount + pEntry->TxBFCounters.ITxFailCount;
	UINT TxCount = pEntry->TxBFCounters.TxSuccessCount + pEntry->TxBFCounters.TxFailCount + ETxCount + ITxCount;
	ULONG bfRatio = 0;
#ifdef TIMESTAMP_RA_LOG
	ULONG newTime;
	static ULONG saveRATime;
	struct timeval tval;

	do_gettimeofday(&tval);
	newTime = (tval.tv_sec*1000000L + tval.tv_usec);
#endif

	if (TxTotalCnt !=0 || raLogType==RAL_QUICK_DRS
#ifdef DBG_CTRL_SUPPORT
		|| (pAd->CommonCfg.DebugFlags & DBF_SHOW_ZERO_RA_LOG)
#endif /* DBG_CTRL_SUPPORT */
	)
	{
		bool stbc, csd=false;
		ULONG tp;

		/*  Get STBC and StreamMode state */
		stbc = (pEntry->HTPhyMode.field.STBC && pEntry->HTPhyMode.field.MCS<8);


		/*  Normalized throughput - packets per RA Interval */
		if (raLogType==RAL_QUICK_DRS)
			tp = (100-TxErrorRatio)*TxTotalCnt*RA_INTERVAL/(100*pAd->ra_fast_interval);
		else if (pEntry->LastSecTxRateChangeAction==RATE_NO_CHANGE
#ifdef DBG_CTRL_SUPPORT
				&& (pAd->CommonCfg.DebugFlags & DBF_FORCE_QUICK_DRS)==0
#endif /* DBG_CTRL_SUPPORT */
		)
			tp = (100-TxErrorRatio)*TxTotalCnt/100;
		else
			tp = (100-TxErrorRatio)*TxTotalCnt*RA_INTERVAL/(100*(RA_INTERVAL-pAd->ra_fast_interval));

		/*  Compute BF ratio in the last interval */
		if ((TxCount - pEntry->LastTxCount)>0)
		{
			if (pEntry->HTPhyMode.field.eTxBF)
				bfRatio = 100*(ETxCount-pEntry->LastETxCount)/(TxCount - pEntry->LastTxCount);
			else if (pEntry->HTPhyMode.field.iTxBF)
				bfRatio = 100*(ITxCount-pEntry->LastITxCount)/(TxCount - pEntry->LastTxCount);
		}

		if ((pEntry->HTPhyMode.field.eTxBF || pEntry->HTPhyMode.field.iTxBF)
#ifdef DBG_CTRL_SUPPORT
			&& (pAd->CommonCfg.DebugFlags & DBF_DBQ_RA_LOG)==0
#endif /* DBG_CTRL_SUPPORT */
		)
		{
			DBGPRINT_RAW(RT_DEBUG_ERROR,("%s[%d]: M=%d %c%c%c%c%c PER=%ld%% TP=%ld BF=%ld%% ",
				raLogType==RAL_QUICK_DRS? " Q": (raLogType==RAL_NEW_DRS? "\nRA": "\nra"),
				pEntry->wcid, pEntry->HTPhyMode.field.MCS,
				pEntry->HTPhyMode.field.MODE==MODE_CCK? 'C': (pEntry->HTPhyMode.field.ShortGI? 'S': 'L'),
				pEntry->HTPhyMode.field.BW? '4': '2',
				stbc? 'S': 's',
				csd? 'C': 'c',
				pEntry->HTPhyMode.field.eTxBF? 'E': (pEntry->HTPhyMode.field.iTxBF? 'I': '-'),
				TxErrorRatio, tp, bfRatio) );
		}
		else
#ifdef DBG_CTRL_SUPPORT
#ifdef INCLUDE_DEBUG_QUEUE
		if (pAd->CommonCfg.DebugFlags & DBF_DBQ_RA_LOG)
		{
			struct {
				unsigned short phyMode;
				unsigned short per;
				unsigned short tp;
				unsigned short bfRatio;
			} raLogInfo;

			raLogInfo.phyMode = pEntry->HTPhyMode.word;
			raLogInfo.per = TxErrorRatio;
			raLogInfo.tp = tp;
			raLogInfo.bfRatio = bfRatio;
			dbQueueEnqueue(0x7e, (u8 *)&raLogInfo);
		}
		else
#endif /*  INCLUDE_DEBUG_QUEUE */
#endif /*  DBG_CTRL_SUPPORT */
		{
			DBGPRINT_RAW(RT_DEBUG_ERROR,("%s[%d]: M=%d %c%c%c%c- PER=%ld%% TP=%ld ",
				raLogType==RAL_QUICK_DRS? " Q": (raLogType==RAL_NEW_DRS? "\nRA": "\nra"),
				pEntry->wcid, pEntry->HTPhyMode.field.MCS,
				pEntry->HTPhyMode.field.MODE==MODE_CCK? 'C': (pEntry->HTPhyMode.field.ShortGI? 'S': 'L'),
				pEntry->HTPhyMode.field.BW? '4': '2',
				stbc? 'S': 's',
				csd? 'C': 'c',
				TxErrorRatio, tp) );
		}
	}

	/*  Remember previous counts */
	pEntry->LastETxCount = ETxCount;
	pEntry->LastITxCount = ITxCount;
	pEntry->LastTxCount = TxCount;
#ifdef TIMESTAMP_RA_LOG
	saveRATime = newTime;
#endif
}


/*  MlmeRestoreLastRate - restore last saved rate */
VOID MlmeRestoreLastRate(
	IN PMAC_TABLE_ENTRY	pEntry)
{
	pEntry->CurrTxRateIndex = pEntry->lastRateIdx;
	if (pEntry->eTxBfEnCond>0)
		pEntry->phyETxBf = pEntry->lastRatePhyTxBf;
	else
		pEntry->phyITxBf = pEntry->lastRatePhyTxBf;
}




VOID txbf_rate_adjust(struct rtmp_adapter *pAd, MAC_TABLE_ENTRY *pEntry)
{
	RTMP_RA_LEGACY_TB *pNextTxRate;
	u8 *pTable = pEntry->pTable;


	/*  Get pointer to CurrTxRate entry */
#ifdef NEW_RATE_ADAPT_SUPPORT
	if (ADAPT_RATE_TABLE(pTable))
		pNextTxRate = (RTMP_RA_LEGACY_TB *)PTX_RA_GRP_ENTRY(pTable, pEntry->CurrTxRateIndex);
	else
#endif /*  NEW_RATE_ADAPT_SUPPORT */
		pNextTxRate = PTX_RA_LEGACY_ENTRY(pTable, pEntry->CurrTxRateIndex);

	/*  If BF has been disabled then force a non-BF rate */
	pEntry->phyETxBf = (pEntry->eTxBfEnCond > 0) ? true : false;
	pEntry->iTxBfEn  = (pEntry->iTxBfEn > 0) ? true : false;


   	/*  Set BF options */
	pEntry->HTPhyMode.field.eTxBF = pEntry->phyETxBf;
	pEntry->HTPhyMode.field.iTxBF = pEntry->phyITxBf;

	/*  Give ETxBF priority over ITxBF */
	if (pEntry->HTPhyMode.field.eTxBF)
		pEntry->HTPhyMode.field.iTxBF = 0;

	/*  In ITxBF mode force GI if we have no choice */
	if (pEntry->HTPhyMode.field.iTxBF &&
		(pEntry->OneSecRxLGICount + pEntry->OneSecRxSGICount) > 10)
	{
		if (pEntry->OneSecRxSGICount==0)
			pEntry->HTPhyMode.field.ShortGI = GI_800;

		if (pEntry->OneSecRxLGICount==0)
		{
			if ((pEntry->HTPhyMode.field.BW==BW_20 && CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_SGI20_CAPABLE)) ||
		    	(pEntry->HTPhyMode.field.BW==BW_40 && CLIENT_STATUS_TEST_FLAG(pEntry, fCLIENT_STATUS_SGI40_CAPABLE)))
					pEntry->HTPhyMode.field.ShortGI = GI_400;
		}
	}

	/*  Disable STBC if BF is enabled */
	if (pEntry->HTPhyMode.field.eTxBF || pEntry->HTPhyMode.field.iTxBF)
		pEntry->HTPhyMode.field.STBC = STBC_NONE;
}


INT rtmp_get_rate_from_rate_tb(u8 *table, INT idx, RTMP_TX_RATE *tx_rate)
{
#ifdef NEW_RATE_ADAPT_SUPPORT
	if (ADAPT_RATE_TABLE(table)) {
		RTMP_RA_GRP_TB *rate_entry;

		rate_entry = PTX_RA_GRP_ENTRY(table, idx);
		tx_rate->mode = rate_entry->Mode;
		tx_rate->bw = rate_entry->BW;
		tx_rate->mcs = rate_entry->CurrMCS;
		tx_rate->sgi = rate_entry->ShortGI;
		tx_rate->stbc = rate_entry->STBC;
		if (table == RateTableVht1S || table == RateTableVht2S ||
					table == RateTableVht2S_BW40 ||
					table == RateTableVht2S_BW20 || table == RateTableVht1S_MCS9
					|| (table == RateTableVht2S_MCS7)
					|| (table == RateTableVht1S_2G_BW20)
					|| (table == RateTableVht1S_2G_BW40)
					|| (table == RateTableVht2S_2G_BW20)
					|| (table == RateTableVht2S_2G_BW40))
			tx_rate->nss = rate_entry->dataRate;
		else
			tx_rate->nss = 0;
	}
	else
#endif /* NEW_RATE_ADAPT_SUPPORT */
	{
		RTMP_RA_LEGACY_TB *rate_entry;

		rate_entry = PTX_RA_LEGACY_ENTRY(table, idx);
		tx_rate->mode = rate_entry->Mode;
		tx_rate->bw = rate_entry->BW;
		tx_rate->mcs = rate_entry->CurrMCS;
		tx_rate->sgi = rate_entry->ShortGI;
		tx_rate->stbc = rate_entry->STBC;
		tx_rate->nss = 0;
	}

	return true;
}


/*
	MlmeNewTxRate - called when a new TX rate was selected. Sets TX PHY to
		rate selected by pEntry->CurrTxRateIndex in pTable;
*/
VOID MlmeNewTxRate(struct rtmp_adapter *pAd, MAC_TABLE_ENTRY *pEntry)
{
	RTMP_RA_LEGACY_TB *pNextTxRate;
	u8 *pTable = pEntry->pTable;
	RTMP_TX_RATE tx_rate;


	rtmp_get_rate_from_rate_tb(pEntry->pTable, pEntry->CurrTxRateIndex, &tx_rate);
	/*  Get pointer to CurrTxRate entry */
#ifdef NEW_RATE_ADAPT_SUPPORT
	if (ADAPT_RATE_TABLE(pTable))
		pNextTxRate = (RTMP_RA_LEGACY_TB *)PTX_RA_GRP_ENTRY(pTable, pEntry->CurrTxRateIndex);
	else
#endif /* NEW_RATE_ADAPT_SUPPORT */
		pNextTxRate = PTX_RA_LEGACY_ENTRY(pTable, pEntry->CurrTxRateIndex);

	/*  Set new rate */
#ifdef CONFIG_AP_SUPPORT
	IF_DEV_CONFIG_OPMODE_ON_AP(pAd)
	{
		APMlmeSetTxRate(pAd, pEntry, pNextTxRate);
	}
#endif /*  CONFIG_AP_SUPPORT */
#ifdef CONFIG_STA_SUPPORT
	IF_DEV_CONFIG_OPMODE_ON_STA(pAd)
	{
		if(IS_ENTRY_TDLS(pEntry))
			;
		else
			MlmeSetTxRate(pAd, pEntry, pNextTxRate);
	}
#endif /*  CONFIG_STA_SUPPORT */

	/*  Disable invalid HT Duplicate modes to prevent PHY error */
	if (pEntry->HTPhyMode.field.MCS==32)
	{
		if ((pEntry->HTPhyMode.field.BW!=BW_40) && (pEntry->HTPhyMode.field.BW!=BW_80))
			pEntry->HTPhyMode.field.MCS = 0;
		else
			pEntry->HTPhyMode.field.STBC = 0;
	}

	if (pAd->chipCap.FlgHwTxBfCap)
		txbf_rate_adjust(pAd, pEntry);

	pAd->LastTxRate = (unsigned short)(pEntry->HTPhyMode.word);

}


VOID RTMPSetSupportMCS(
	IN struct rtmp_adapter *pAd,
	IN u8 OpMode,
	IN PMAC_TABLE_ENTRY	pEntry,
	IN u8 SupRate[],
	IN u8 SupRateLen,
	IN u8 ExtRate[],
	IN u8 ExtRateLen,
	IN u8 vht_cap_len,
	IN VHT_CAP_IE *vht_cap,
	IN HT_CAPABILITY_IE *pHtCapability,
	IN u8 HtCapabilityLen)
{
	u8 idx, SupportedRatesLen = 0;
	u8 SupportedRates[MAX_LEN_OF_SUPPORTED_RATES];

	if (SupRateLen > 0)
	{
		if (SupRateLen <= MAX_LEN_OF_SUPPORTED_RATES)
		{
			memmove(SupportedRates, SupRate, SupRateLen);
			SupportedRatesLen = SupRateLen;
		}
		else
		{
			u8 RateDefault[8] = {0x82, 0x84, 0x8b, 0x96, 0x12, 0x24, 0x48, 0x6c};

			memmove(SupportedRates, RateDefault, 8);
			SupportedRatesLen = 8;

			DBGPRINT(RT_DEBUG_TRACE,("%s():wrong SUPP RATES., Len=%d\n",
							__FUNCTION__, SupRateLen));
		}
	}

	if (ExtRateLen > 0)
	{
		if ((SupRateLen + ExtRateLen) <= MAX_LEN_OF_SUPPORTED_RATES)
		{
			memmove(&SupportedRates[SupRateLen], ExtRate, ExtRateLen);
			SupportedRatesLen += ExtRateLen;
		}
		else
		{
			memmove(&SupportedRates[SupRateLen], ExtRate, MAX_LEN_OF_SUPPORTED_RATES - ExtRateLen);
			SupportedRatesLen = MAX_LEN_OF_SUPPORTED_RATES;

		}
	}

	/* Clear Supported MCS Table */
	memset(pEntry->SupportCCKMCS, 0, MAX_LEN_OF_CCK_RATES);
	memset(pEntry->SupportOFDMMCS, 0, MAX_LEN_OF_OFDM_RATES);
	memset(pEntry->SupportHTMCS, 0, MAX_LEN_OF_HT_RATES);
	memset(pEntry->SupportVHTMCS, 0, MAX_LEN_OF_VHT_RATES);

	pEntry->SupportRateMode = 0;

	for(idx = 0; idx < SupportedRatesLen; idx ++)
	{
		switch((SupportedRates[idx] & 0x7F)*5)
		{
			case 10:
				pEntry->SupportCCKMCS[MCS_0] = true;
				pEntry->SupportRateMode |= SUPPORT_CCK_MODE;
				break;

			case 20:
				pEntry->SupportCCKMCS[MCS_1] = true;
				pEntry->SupportRateMode |= SUPPORT_CCK_MODE;
				break;

			case 55:
				pEntry->SupportCCKMCS[MCS_2] = true;
				pEntry->SupportRateMode |= SUPPORT_CCK_MODE;
				break;

			case 110:
				pEntry->SupportCCKMCS[MCS_3] = true;
				pEntry->SupportRateMode |= SUPPORT_CCK_MODE;
				break;

			case 60:
				pEntry->SupportOFDMMCS[MCS_0] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;

			case 90:
				pEntry->SupportOFDMMCS[MCS_1] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;

			case 120:
				pEntry->SupportOFDMMCS[MCS_2] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;

			case 180:
				pEntry->SupportOFDMMCS[MCS_3] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;

			case 240:
				pEntry->SupportOFDMMCS[MCS_4] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;

			case 360:
				pEntry->SupportOFDMMCS[MCS_5] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;

			case 480:
				pEntry->SupportOFDMMCS[MCS_6] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;

			case 540:
				pEntry->SupportOFDMMCS[MCS_7] = true;
				pEntry->SupportRateMode |= SUPPORT_OFDM_MODE;
				break;
		}
	}

	if (HtCapabilityLen)
	{
		RT_PHY_INFO *pDesired_ht_phy = NULL;
		u8 j, bitmask;
		CHAR i;

#ifdef CONFIG_STA_SUPPORT
		if (OpMode == OPMODE_STA)
			pDesired_ht_phy = &pAd->StaCfg.wdev.DesiredHtPhyInfo;
#endif /* CONFIG_STA_SUPPORT */

#ifdef CONFIG_AP_SUPPORT
		if (OpMode == OPMODE_AP)
		{
				pDesired_ht_phy = &pAd->ApCfg.MBSSID[pEntry->apidx].wdev.DesiredHtPhyInfo;
		}
#endif /* CONFIG_AP_SUPPORT */

		if (pDesired_ht_phy == NULL)
			return;

		for (i = 23; i >= 0; i--)
		{
			j = i / 8;
			bitmask = (1 << (i - (j * 8)));

			if ((pDesired_ht_phy->MCSSet[j] & bitmask)
				&& (pHtCapability->MCSSet[j] & bitmask))
			{
				pEntry->SupportHTMCS[i] = true;
				pEntry->SupportRateMode |= SUPPORT_HT_MODE;
			}
		}

		if ((vht_cap_len > 0)&& (vht_cap != NULL) && pDesired_ht_phy->bVhtEnable)
		{
			/* Currently we only support for MCS0~MCS7, so don't check mcs_map */
			memset(&pEntry->SupportVHTMCS[0], 0, sizeof(pEntry->SupportVHTMCS));
			switch (pAd->CommonCfg.TxStream)
			{
				case 2:
					if (vht_cap->mcs_set.rx_mcs_map.mcs_ss2 < VHT_MCS_CAP_NA)
					{
						for (i = 10; i <= 17; i++)
							pEntry->SupportVHTMCS[i] = true;

						if (vht_cap->mcs_set.rx_mcs_map.mcs_ss2 == VHT_MCS_CAP_8) {
							pEntry->SupportVHTMCS[18] = true;
						} else if (vht_cap->mcs_set.rx_mcs_map.mcs_ss2 == VHT_MCS_CAP_9) {
							pEntry->SupportVHTMCS[18] = true;
							pEntry->SupportVHTMCS[19] = true;
						}

						pEntry->SupportRateMode |= SUPPORT_VHT_MODE;
					}
				case 1:
					if (vht_cap->mcs_set.rx_mcs_map.mcs_ss1 < VHT_MCS_CAP_NA)
					{
						for (i = 0; i <= 7; i++)
							pEntry->SupportVHTMCS[i] = true;

						if (vht_cap->mcs_set.rx_mcs_map.mcs_ss1 == VHT_MCS_CAP_8) {
							pEntry->SupportVHTMCS[8] = true;
						} else if (vht_cap->mcs_set.rx_mcs_map.mcs_ss1 == VHT_MCS_CAP_9) {
							pEntry->SupportVHTMCS[8] = true;
							pEntry->SupportVHTMCS[9] = true;
						}

						pEntry->SupportRateMode |= SUPPORT_VHT_MODE;
					}
				default:
					break;
			}
		}
	}
}
