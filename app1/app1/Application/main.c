#define F_CPU       (16000000UL)

#include <avr/io.h>
#include <stdio.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <lcd/lcd.h>
#include "rand.h"

#define MS_STEP         (15)            /* 15 ms, results in a display update interval of about 2Hz */
#define CONV_MS(x)      (x / MS_STEP)

static uint16_t counterMs;
static char counterChar;

int main(void)
{
    initLcd();
   
    counterChar = 0;
    counterMs  = 0;
    
    TCCR1A &= ~(_BV(COM1A1) | _BV(COM1A0) | _BV(COM1B1) | _BV(COM1B0) | _BV(COM1C1) | _BV(COM1C0) | _BV(WGM11) | _BV(WGM10));
    TCCR1B &= ~(_BV(ICNC1) | _BV(WGM13) | _BV(ICES1) | _BV(CS12) | _BV(CS11) | _BV(CS10));  /* clear prescaler */
    OCR1A = (((MS_STEP * F_CPU) / (64 * 1000U)) - 1);
    TIMSK1 |= _BV(OCIE1A);
    TCCR1B |= _BV(CS11) | _BV(CS10) | _BV(WGM12);   /* Enable prescaler, PS 64 */

    sei();

    dispString("   Hello World!", 0, 0);
    dispUint8(123, 15, 1);
    
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
       
    while(1)
    {
        sleep_cpu();
    }
    
    return 0;
}

ISR(TIMER1_COMPA_vect)
{
    syncScreen();
    
    if(counterMs == CONV_MS(500))
    {
        fprintf(lcdout, "\r%X ", (uint8_t) rand_shift(counterChar));
        
        dispUint8((uint8_t)lfsr, 2, 1);
        counterMs = 0;
        ++counterChar;
    }
    ++counterMs;
}

