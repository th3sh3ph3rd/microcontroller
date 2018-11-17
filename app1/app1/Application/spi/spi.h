/**
 *
 * @file spi.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-05
 *
 * Header file for the SPI driver.
 *
 */

#ifndef __SPI__
#define __SPI__

#include <stdint.h>

/* Typedef as in the SD card library */
typedef enum {
    SPI_PRESCALER_128   = 3,
    SPI_PRESCALER_4     = 0,
} spi_prescaler_t;

/**
 * @brief       Initialize the SPI driver.
 */
void spiInit(void);

/**
 * @brief       Send one byte via SPI.
 * @param data  The byte to send.
 */
void spiSend(uint8_t data);

/**
 * @brief   Receive one byte via SPI.
 * @return  The received byte.
 */
uint8_t spiReceive(void);

/**
 * @brief           Set the SPI prescaler.
 * @param prescaler The chosen prescaler.
 */
void spiSetPrescaler(spi_prescaler_t prescaler);

#endif

