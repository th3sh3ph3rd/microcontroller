/**
 *
 * @file hal_wt41_fc_uart.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-31
 *
 * Implementation of the WT41 HAL module.
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

/* Needed for error_t definition */
#include "wii_user.h"

//TODO change these according to real board configuration
#define CTS_PIN PJ5
#define RTS_PIN PJ4
#define RST_PIN PJ3
#define RTS_INT PCINT13

#define RBUF_SZ 32

/* Ringbuffer */
static uint8_t rbuf[RBUF_SZ];
static uint8_t rbufStart = 0;
static uint8_t rbufEnd = 0;
static uint8_t rbufLen = 0; //TODO maybe this is not needed

enum rb_state {EMPTY, LOW, NORM, HIGH, FULL};
static enum rb_state rbuf_state = EMPTY;

/* Callback functions */

static void (*sendCallback)();
static void (*recvCallback)(uint8_t);

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
    /****************
     * Setup USART3 *
     ****************/

    /* Set baudrate to 1M */
    UBRR3 = 1;
    /* Double transmission speed */
    UCSR3A |= (1<<U2XN);
    /* Enable RX & TX interrupts and enable RX & TX */
    UCSR3B |= (1<<RXCIE3)|(1<<TXCIE3)|(1<<RXEN3)|(1<<TXEN3);
    /* Frame format: 8 databits, 1 stopbit, no parity */
    UCSR3C |= (1<<UCSZ31)|(1<<UCSZ30);
 
    /*************************
     * Setup HW flow control *
     *************************/
    
    /* Enable output for CTS and RST */
    PORTJ &= ~((1<<CTS_PIN)|(1<<RST_PIN));
    DDRJ |= (1<<CTS_PIN)|(1<<RST_PIN);

    /* Configure PCint for RTS */
    /* Enable PCint 15:8 */
    PCICR |= (1<<PCIE1);
    /* Only set RTS PCint */
    PCMSK |= (1<<RTS_INT);

    //TODO reset WT41 for 5ms with timer

}

/**
 * @brief       Sends a byte to the WT41 bluetooth module.
 * @param byte  The byte to be sent.
 */
error_t halWT41FcUartSend(uint8_t byte)
{

}

ISR(USART3_RX_vect, ISR_BLOCK)
{

}

ISR(USART3_TX_vect, ISR_BLOCK)
{

}

ISR(PCINT1_vect, ISR_BLOCK)
{

}

