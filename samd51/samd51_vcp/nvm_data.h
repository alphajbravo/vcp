// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2016, Alex Taradov <alex@taradov.com>. All rights reserved.

#ifndef _NVM_DATA_H_
#define _NVM_DATA_H_

/*- Definitions -------------------------------------------------------------*/

#define NVM_SWCAL                   (0x00800080)

#define NVM_SWCAL_USB_TRANSN_POS           32
#define NVM_SWCAL_USB_TRANSN_SIZE          5

#define NVM_SWCAL_USB_TRANSP_POS           37
#define NVM_SWCAL_USB_TRANSP_SIZE          5

#define NVM_SWCAL_USB_TRIM_POS             42
#define NVM_SWCAL_USB_TRIM_SIZE            3

#define NVM_SERIALNUM_W0            (0x008061fc)
#define NVM_SERIALNUM_W1            (0x00806010)
#define NVM_SERIALNUM_W2            (0x00806014)
#define NVM_SERIALNUM_W3            (0x00806018)

#define NVM_READ_CAL(cal) \
    ((*((uint32_t *)NVM_SWCAL + cal##_POS / 32)) >> (cal##_POS % 32)) & ((1 << cal##_SIZE) - 1)

#endif // _NVM_DATA_H_
