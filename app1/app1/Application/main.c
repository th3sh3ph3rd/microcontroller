#define F_CPU       (16000000UL)

#include <avr/io.h>
#include <stdio.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "gameui.h"

#define MS_STEP         (15)            /* 15 ms, results in a display update interval of about 2Hz */
#define CONV_MS(x)      (x / MS_STEP)
//OCR1A = (((MS_STEP * F_CPU) / (64 * 1000U)) - 1);

static uint8_t tmr_int = 0;

int main(void)
{
    gameui_init();

    TCCR1B |= (1<<WGM12)|(1<<CS12)|(1<<CS10);
    OCR1A = 780;
    TCNT1 = 0;
    TIMSK1 |= (1<<OCIE1A);

    sei();
    
    gameui_setup();
    
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();

    while (1)
    {
        if (tmr_int == 1)
        {
            gameui_tick(NULL);
            tmr_int = 0;
        }
        sleep_cpu();
    }
    
    return 0;
}

ISR(TIMER1_COMPA_vect, ISR_BLOCK)
{
    tmr_int = 1;
}

