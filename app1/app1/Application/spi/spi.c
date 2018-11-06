/**
 *
 * @file spi.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-05
 *
 * Implementation of the SPI driver.
 *
 */

#include <avr/io.h>
#include <stdint.h>

#include <spi.h>

/* SPI pin definitions */
#define DDR_SPI DDRB
#define DD_SS   PB0
#define DD_SCK  PB1
#define DD_MOSI PB2
#define DD_MISO PB3

/**
 * @brief       Initialize the SPI driver.
 */
void spiInit(void)
{
    /* Set MOSI and SCK as output */
    DDR_SPI |= (1<<DD_MOSI)|(1<<DD_SCK);
    /* Set MISO and SS as input */
    DDR_SPI &= ~((1<<DD_MISO)|(1<<DD_SS));
    /* Enable SPI and set master mode */
    SPCR |= (1<<SPE)|(1<<MSTR);
}

/**
 * @brief       Send one byte via SPI.
 * @param data  The byte to send.
 */
void spiSend(uint8_t data)
{
    /* Start sending the byte */
    SPDR = data;
    /* Busy-wait until sending has beem finished */
    while (!(SPSR & (1<<SPIF)));
}

/**
 * @brief   Receive one byte via SPI.
 * @return  The received byte.
 */
uint8_t spiReceive(void)
{
    /* Busy-wait for reception to complete and send dummy value */
    while (!(SPSR & (1<<SPIF)))
    {
        spiSend(0xff);
    }
    /* Read received byte */
    return SPDR;
}

/**
 * @brief           Set the SPI prescaler.
 * @param prescaler The chosen prescaler.
 */
void spiSetPrescaler(spi_prescaler_t prescaler)
{
    SPCR &= ~((1<<SPR1)|(1<<SPR0));
    SPCR |= prescaler;
}

