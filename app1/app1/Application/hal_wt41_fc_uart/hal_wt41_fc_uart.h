/**
 *
 * @file hal_wt41_fc_uart.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-31
 *
 * Header file for the WT41 HAL module.
 *
 */

#ifndef __HAL_WT41_FC_UART__
#define __HAL_WT41_FC_UART__

#include <stdint.h>
#include <util.h>

/**
 * @brief               Initialize the WT41 HAL module.
 * @param sndCallback   This callback gets called when a character is sent to the WT41.
 * @param rcvCallback   This callback gets called for every character received from the WT41.
 */
error_t halWT41FcUartInit(
        void (*sndCallback)(void),
        void (*rcvCallback)(uint8_t)
    );

/**
 * @brief       Sends a byte to the WT41 bluetooth module.
 * @param byte  The byte to be sent.
 */
error_t halWT41FcUartSend(uint8_t byte);

#endif

