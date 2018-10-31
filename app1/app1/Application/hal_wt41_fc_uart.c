/**
 *
 * @file hal_wt41_fc_uart.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-31
 *
 * Implementation of the WT41 HAL module.
 *
 */

#include <stdint.h>

/* Needed for error_t definition */
#include "wii_user.h"

#define BAUD    


/**
 * @brief               Initialize the WT41 HAL module.
 * @param sndCallback   This callback gets called when a character is sent to the WT41.
 * @param rcvCallback   This callback gets called for every character received from the WT41.
 */
error_t halWT41FcUartInit(
        void (*sndCallback)(),
        void (*rcvCallback)(uint8_t)
    )
{

}

/**
 * @brief       Sends a byte to the WT41 bluetooth module.
 * @param byte  The byte to be sent.
 */
error_t halWT41FcUartSend(uint8_t byte)
{

}

