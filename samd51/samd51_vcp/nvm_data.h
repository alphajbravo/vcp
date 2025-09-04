// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2016, Alex Taradov <alex@taradov.com>. All rights reserved.

#ifndef _NVM_DATA_H_
#define _NVM_DATA_H_

/*- Definitions -------------------------------------------------------------*/

#define NVMCTRL_OTP4                (0x00800080)

#define NVM_USB_TRANSN_POS           32
#define NVM_USB_TRANSN_SIZE          5

#define NVM_USB_TRANSP_POS           37
#define NVM_USB_TRANSP_SIZE          5

#define NVM_USB_TRIM_POS             42
#define NVM_USB_TRIM_SIZE            3

 
#define NVM_READ_CAL(cal) \
    ((*((uint32_t *)NVMCTRL_OTP4 + cal##_POS / 32)) >> (cal##_POS % 32)) & ((1 << cal##_SIZE) - 1)

#endif // _NVM_DATA_H_
