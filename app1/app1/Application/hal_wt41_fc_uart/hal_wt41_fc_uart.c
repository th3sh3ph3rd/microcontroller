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
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdint.h>

/* Needed for error_t definition */
#include <util.h>
#include <hal_wt41_fc_uart.h>

#define CTS_PIN PJ3
#define RTS_PIN PJ2
#define RST_PIN PJ5
#define RTS_INT PCINT11

#define RBUF_SZ     32  //must be a power of 2!!!
#define RBUF_HIGH   5
#define RBUF_LOW    RBUF_SZ/2

/* Ringbuffer */
struct ringbuffer
{
    uint8_t start;
    uint8_t end;
    uint8_t len;
    uint8_t data[RBUF_SZ];
};
static volatile struct ringbuffer rbuf = { .start = 0, .end = 0, .len = 0 };

/* Transmission buffer */
static uint8_t tx_byte_buf;

/* Callback functions */
static void (*sendCallback)(void);
static void (*recvCallback)(uint8_t);

/* State variables */
enum sendstate {INIT, SEND, BLOCK};

//TODO optimization: put in bitfield
static volatile uint8_t wt41_reset_complete = 0;
static volatile uint8_t ringbuffer_being_processed = 0;
static volatile uint8_t CTS_state = 0;
//TODO volatile needed?
static volatile enum sendstate send_state = INIT;

/* Local functions */
static void processRingbuffer(void);

/**
 * @brief               Initialize the WT41 HAL module.
 * @param sndCallback   This callback gets called when a character is sent to the WT41.
 * @param rcvCallback   This callback gets called for every character received from the WT41.
 */
//TODO enable some sort of error handling
error_t halWT41FcUartInit(
        void (*sndCallback)(void),
        void (*rcvCallback)(uint8_t)
    )
{
    sendCallback = sndCallback;
    recvCallback = rcvCallback;

    /****************
     * Setup USART3 *
     ****************/

    /* Set baudrate to 1M */
    UBRR3 = 1;
    /* Double transmission speed */
    UCSR3A |= (1<<U2X3);
    /* Enable RX & TX interrupts and enable RX & TX */
    UCSR3B |= (1<<RXCIE3)|(1<<TXCIE3)|(1<<RXEN3)|(1<<TXEN3);
    /* Disable user data register interrupt */
    UCSR3B &= ~(1<<UDRIE3);
    /* Frame format: 8 databits, 1 stopbit, no parity */
    UCSR3C |= (1<<UCSZ31)|(1<<UCSZ30);
 
    /*************************
     * Setup HW flow control *
     *************************/
    
    /* Enable output for CTS and RST and input for RTS */
    PORTJ &= ~((1<<CTS_PIN)|(1<<RST_PIN));
    DDRJ |= (1<<CTS_PIN)|(1<<RST_PIN);
    DDRJ &= ~(1<<RTS_PIN);

    /* Configure PCint for RTS */
    /* Enable PCint 15:8 */
    PCICR |= (1<<PCIE1);
    /* Disable RTS PCint */
    PCMSK1 &= ~(1<<RTS_INT);
 
    /******************
     * Reset the WT41 *
     *****************/

    /* Configure timer 5A to wait for 5 ms */
    OCR5A = 780;
    TCNT5 = 0;
    TCCR5B |= (1<<WGM52)|(1<<CS52)|(1<<CS50);
    TIMSK5 |= (1<<OCIE5A);

    NONATOMIC_BLOCK(NONATOMIC_RESTORESTATE)
    {
        set_sleep_mode(SLEEP_MODE_IDLE);
        sleep_enable();
        while (wt41_reset_complete != 1)
        {
            sleep_cpu();
        }
    }
    TIMSK5 &= ~(1<<OCIE5A);

    /* Pull RST high */
    PORTJ |= (1<<RST_PIN);

    return SUCCESS;
}

/**
 * @brief       Sends a byte to the WT41 bluetooth module.
 * @param byte  The byte to be sent.
 */
error_t halWT41FcUartSend(uint8_t byte)
{
    if (BLOCK != send_state)
        tx_byte_buf = byte;

    /* Buffer the byte until the wt41 reset has finished */
    if (wt41_reset_complete == 0)
    {
        send_state = BLOCK;
        return ERROR;
    }
    /* High RTS inidcates flow control by WT41 */
    if ((PINJ & (1<<RTS_PIN)) != 0)
    {
        /* Enable pin change interrupt for RTS */
        send_state = BLOCK;
        PCMSK1 |= (1<<RTS_INT);
        return ERROR;
    }
    /* TX buffer not empty */
    if ((UCSR3A & (1<<UDRE3)) == 0)
    {
        /* Enable user data register interrupt */
        send_state = BLOCK;
        UCSR3B |= (1<<UDRIE3);
        return ERROR;
    }

    UDR3 = tx_byte_buf;
    send_state = SEND;

    return SUCCESS;
}

/**
 * @brief   Empty the ringbuffer by calling the specified callback on every byte.
 */
static void processRingbuffer(void)
{
    ringbuffer_being_processed = 1;

    while (rbuf.len > 0)
    {
        recvCallback(rbuf.data[rbuf.end]);
        rbuf.end = (rbuf.end + 1) & (RBUF_SZ - 1);
        
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            rbuf.len--;
            if (CTS_state == 1 &&
                rbuf.len < RBUF_LOW)
            {
                PORTJ &= ~(1<<CTS_PIN);
                CTS_state = 0;
            }
        }
    }

    ringbuffer_being_processed = 0;
}

/**
 * @brief   Handle an incoming byte on the UART by putting it in the ringbuffer.
 */
ISR(USART3_RX_vect, ISR_BLOCK)
{
    rbuf.data[rbuf.start] = UDR3;
    /* Increment the start pointer mod buffer size */
    rbuf.start = (rbuf.start + 1) & (RBUF_SZ - 1);
    rbuf.len++;
    /* Set CTS if buffer capacity low */
    if (CTS_state == 0 && 
        RBUF_SZ - rbuf.len < RBUF_HIGH)
    {
        PORTJ |= (1<<CTS_PIN);
        CTS_state = 1;
    }

    sei();

    if (ringbuffer_being_processed == 0)
        processRingbuffer();
}

/**
 * @brief   After transmitting a byte, call the send callback.
 */
ISR(USART3_TX_vect, ISR_BLOCK)
{
    if (SEND == send_state)
    {
        sei();
        sendCallback();
    }
}

/**
 * @brief   Try sending the byte which has been held back by a full buffer.
 */
ISR(USART3_UDRE_vect, ISR_BLOCK)
{
    /* Disable the interrupt */
    UCSR3B &= ~(1<<UDRIE3);
    sei();
    halWT41FcUartSend(0);
}

/**
 * @brief   Try sending the byte which has been held back by HW flow control.
 */
ISR(PCINT1_vect, ISR_BLOCK)
{
    /* Disable the interrupt */
    PCMSK1 &= ~(1<<RTS_INT);
    sei();
    halWT41FcUartSend(0);
}

/**
 * @brief   Signify the end of the wt41 reset period and send one byte via
 *          if the send function has been called during reset.
 */
ISR(TIMER5_COMPA_vect, ISR_BLOCK)
{
    wt41_reset_complete = 1;
    if (BLOCK == send_state)
    {
        sei();
        halWT41FcUartSend(0);
    }
}

