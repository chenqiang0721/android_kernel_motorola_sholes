/*
 * Copyright (C) 2005 - 2008 ServerEngines
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.  The full GNU General
 * Public License is included in this distribution in the file called COPYING.
 *
 * Contact Information:
 * linux-drivers@serverengines.com
 *
 * ServerEngines
 * 209 N. Fair Oaks Ave
 * Sunnyvale, CA 94085
 */
/*
 * Autogenerated by srcgen version: 0127
 */
#ifndef __fwcmd_mcc_amap_h__
#define __fwcmd_mcc_amap_h__
#include "fwcmd_opcodes.h"
/*
 * Where applicable, a WRB, may contain a list of Scatter-gather elements.
 * Each element supports a 64 bit address and a 32bit length field.
 */
struct BE_MCC_SGE_AMAP {
	u8 pa_lo[32];	/* DWORD 0 */
	u8 pa_hi[32];	/* DWORD 1 */
	u8 length[32];	/* DWORD 2 */
} __packed;
struct MCC_SGE_AMAP {
	u32 dw[3];
};
/*
 * The design of an MCC_SGE allows up to 19 elements to be embedded
 * in a WRB, supporting 64KB data transfers (assuming a 4KB page size).
 */
struct BE_MCC_WRB_PAYLOAD_AMAP {
	union {
		struct BE_MCC_SGE_AMAP sgl[19];
		u8 embedded[59][32];	/* DWORD 0 */
	};
} __packed;
struct MCC_WRB_PAYLOAD_AMAP {
	u32 dw[59];
};

/*
 * This is the structure of the MCC Command WRB for commands
 * sent to the Management Processing Unit (MPU). See section
 * for usage in embedded and non-embedded modes.
 */
struct BE_MCC_WRB_AMAP {
	u8 embedded;	/* DWORD 0 */
	u8 rsvd0[2];	/* DWORD 0 */
	u8 sge_count[5];	/* DWORD 0 */
	u8 rsvd1[16];	/* DWORD 0 */
	u8 special[8];	/* DWORD 0 */
	u8 payload_length[32];	/* DWORD 1 */
	u8 tag[2][32];	/* DWORD 2 */
	u8 rsvd2[32];	/* DWORD 4 */
	struct BE_MCC_WRB_PAYLOAD_AMAP payload;
} __packed;
struct MCC_WRB_AMAP {
	u32 dw[64];
};

/*  This is the structure of the MCC Completion queue entry  */
struct BE_MCC_CQ_ENTRY_AMAP {
	u8 completion_status[16];	/* DWORD 0 */
	u8 extended_status[16];	/* DWORD 0 */
	u8 mcc_tag[2][32];	/* DWORD 1 */
	u8 rsvd0[27];	/* DWORD 3 */
	u8 consumed;	/* DWORD 3 */
	u8 completed;	/* DWORD 3 */
	u8 hpi_buffer_completion;	/* DWORD 3 */
	u8 async_event;	/* DWORD 3 */
	u8 valid;		/* DWORD 3 */
} __packed;
struct MCC_CQ_ENTRY_AMAP {
	u32 dw[4];
};

/* Mailbox structures used by the MPU during bootstrap */
struct BE_MCC_MAILBOX_AMAP {
	struct BE_MCC_WRB_AMAP wrb;
	struct BE_MCC_CQ_ENTRY_AMAP cq;
} __packed;
struct MCC_MAILBOX_AMAP {
	u32 dw[68];
};

#endif /* __fwcmd_mcc_amap_h__ */