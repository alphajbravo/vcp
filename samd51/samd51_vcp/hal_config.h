// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2017-2022, Alex Taradov <alex@taradov.com>. All rights reserved.

#ifndef _HAL_CONFIG_H_
#define _HAL_CONFIG_H_

/*- Includes ----------------------------------------------------------------*/
#include "sam.h"
#include "hal_gpio.h"

/*- Definitions -------------------------------------------------------------*/
HAL_GPIO_PIN(VCP_STATUS,         A, 28);
HAL_GPIO_PIN(BOOT_ENTER,         A, 31);
HAL_GPIO_PIN(UART_TX,            B, 22);
HAL_GPIO_PIN(UART_RX,            B, 23);

#define UART_SERCOM              SERCOM5
#define UART_SERCOM_PMUX_RX      PORT_PMUX_PMUXE_D_Val
#define UART_SERCOM_PMUX_TX      PORT_PMUX_PMUXE_D_Val
#define UART_SERCOM_GCLK_ID      35 //SERCOM5_GCLK_ID_CORE
#define UART_SERCOM_APBCMASK     PM_APBCMASK_SERCOM5
#define UART_SERCOM_IRQ_INDEX    SERCOM5_IRQn
#define UART_SERCOM_IRQ_HANDLER  irq_handler_sercom5
#define UART_SERCOM_TXPO         1
#define UART_SERCOM_RXPO         3

#endif // _HAL_CONFIG_H_
