/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 *
 */

#ifndef __GH_ERRNO_H
#define __GH_ERRNO_H

#include <linux/errno.h>
#include <linux/gunyah.h>

static inline int gh_remap_error(int gh_error)
{
	switch (gh_error) {
	case GH_ERROR_OK:
		return 0;
	case GH_ERROR_NOMEM:
		return -ENOMEM;
	case GH_ERROR_DENIED:
	case GH_ERROR_CSPACE_CAP_NULL:
	case GH_ERROR_CSPACE_CAP_REVOKED:
	case GH_ERROR_CSPACE_WRONG_OBJ_TYPE:
	case GH_ERROR_CSPACE_INSUF_RIGHTS:
	case GH_ERROR_CSPACE_FULL:
		return -EACCES;
	case GH_ERROR_BUSY:
	case GH_ERROR_IDLE:
		return -EBUSY;
	case GH_ERROR_IRQ_BOUND:
	case GH_ERROR_IRQ_UNBOUND:
	case GH_ERROR_MSGQUEUE_FULL:
	case GH_ERROR_MSGQUEUE_EMPTY:
		return -EPERM;
	case GH_ERROR_UNIMPLEMENTED:
		return -EOPNOTSUPP;
	case GH_ERROR_ARG_INVAL:
	case GH_ERROR_ARG_SIZE:
	case GH_ERROR_ARG_ALIGN:
	case GH_ERROR_ADDR_OVFL:
	case GH_ERROR_ADDR_UNFL:
	case GH_ERROR_ADDR_INVAL:
	default:
		return -EINVAL;
	}
}

#endif
