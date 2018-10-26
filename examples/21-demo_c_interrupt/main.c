/**
    This is the C interrupt callback demo.
    
    Enable the LEDs for port A.
    Whenever INT7 or INT6 is pressed the counting
    mode changes from increasing to decreasing and vice versa.
*/

#define F_CPU       (16000000UL)

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

#ifndef NULL
#define NULL    ((void *) 0)
#endif
#ifndef TRUE
#define TRUE    (0 == 0)
#endif
#ifndef FALSE
#define FALSE   (!TRUE)
#endif

/* prototypes */
static uint8_t increment(const uint8_t counter);
static uint8_t decrement(const uint8_t counter);
static void setCallback(uint8_t (*_interrupt)(const uint8_t counter));
static void callCallback(volatile uint8_t *counter);

/* variables */
static uint8_t (*interrupt)(const uint8_t counter);
static volatile uint8_t isFallingEdge, click;

int main(void)
{
    /* initialize variables */
    setCallback(&increment);
    isFallingEdge = TRUE;
    click = FALSE;
    
    /* Initialize LEDs. */
    DDRA = 0xFF;
    PORTA = 0x00;
    
    /* Set up interrupts */
    DDRE  &= ~((1<<PE6) | (1<<PE7));
    PORTE |= (1<<PE6)   | (1<<PE7);
    EICRB = (EICRB & ~((1<<ISC60) | (1<<ISC70))) | (1<<ISC61) | (1<<ISC71);
    EIMSK |= (1<<INT6)  | (1<<INT7);
    
    /* Set up timer interrupt */
    TCCR1A &= ~(_BV(COM1A1) | _BV(COM1A0) | _BV(COM1B1) | _BV(COM1B0) | _BV(COM1C1) | _BV(COM1C0) | _BV(WGM11) | _BV(WGM10));
    TCCR1B &= ~(_BV(ICNC1) | _BV(WGM13) | _BV(ICES1) | _BV(CS12) | _BV(CS11) | _BV(CS10));
    OCR1A = ((250 * F_CPU) / (64 * 1000U)) - 1;
    TIMSK1 |= _BV(OCIE1A);
    TCCR1B |= _BV(CS11) | _BV(CS10) | _BV(WGM12);
    
    sei();
    
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    
    while(TRUE)
    {
        /* Set CPU to sleep mode. */
        sleep_cpu();
    }
    return 0;
}

/* helper functions */
static uint8_t decrement(const uint8_t counter)
{
    return counter - 1;
}

static uint8_t increment(const uint8_t counter)
{
    return counter + 1;
}

static void setCallback(uint8_t (*_interrupt)(const uint8_t counter))
{
    interrupt = _interrupt;
}

static void callCallback(volatile uint8_t *counter)
{
    if(interrupt != NULL)
    {
        *counter = (*interrupt)(*counter);
    }
}

/* interrupts */
ISR(TIMER1_COMPA_vect, ISR_BLOCK)           /* Blocking timer interrupt */
{
    static volatile uint8_t counter = 0;
    
    click = FALSE;
    callCallback(&counter);
    PORTA = counter;
}

ISR(INT7_vect, ISR_NOBLOCK)                 /* Non blocking interrupt on PE7 */
{
    if(!click)
    {
        if(isFallingEdge)
            setCallback(&decrement);
        else
            setCallback(&increment);
        
        isFallingEdge = !isFallingEdge;
    }
    click = TRUE;
}

ISR(INT6_vect, ISR_ALIASOF(INT7_vect));       /* Alias for PE6 to do the same as on PE7 */
