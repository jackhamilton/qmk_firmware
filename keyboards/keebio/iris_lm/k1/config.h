// Copyright 2024 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Defines for the split keyboard setup */
#define SERIAL_USART_DRIVER SD3         // USART 3
#define SERIAL_USART_TX_PIN B10
#define SERIAL_USART_RX_PIN B11
#define SERIAL_USART_TX_PAL_MODE 7
#define SERIAL_USART_RX_PAL_MODE 7
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_PIN_SWAP

#define USB_VBUS_PIN C6

// user
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150
#define RETRO_TAPPING
// sync rbg status to slave side
#define SPLIT_LAYER_STATE_ENABLE
// dangerous but responsive
#define RGB_TRIGGER_ON_KEYDOWN
#define RGB_MATRIX_SLEEP

/* Defines for the RGB matrix */
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 4
#define WS2812_PWM_PAL_MODE 10
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 2
#define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM3_UP
