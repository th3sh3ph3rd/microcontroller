#define F_CPU       (16000000UL)

#include <avr/io.h>
#include <stdio.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "adc.h"
#include "rand.h"

#define MS_STEP         (15)            /* 15 ms, results in a display update interval of about 2Hz */
#define CONV_MS(x)      (x / MS_STEP)
//OCR1A = (((MS_STEP * F_CPU) / (64 * 1000U)) - 1);

static uint16_t volume;
static uint8_t adc_dif;

void feedRand(uint16_t n)
{
    rand_feed((uint8_t)n);
    adc_dif = (uint8_t)n;
}

uint8_t scaleVolume16(uint16_t n)
{
    /* Implementation of the log-approximation 1-(1-x)^4 */
    n = 255 - n;
    n = (n * n) >> 8;
    n = (n * n) >> 8;
    return 255 - n;
}

uint8_t scaleVolume8(uint8_t n)
{
    /* Implementation of the log-approximation 1-(1-x)^4 */
    n = 255 - n;
    n = (n * n) >> 8;
    n = (n * n) >> 8;
    return 255 - n;
}

void setVolume(uint16_t n)
{
    volume = (uint8_t) n;
    //volume = scaleVolume(n);
}

int main(void)
{
    adc_init();
    adc_setCallbacks(&feedRand, &setVolume);

    PORTA = 0;
    DDRA |= 0xff;
    PORTB = 0;
    DDRB |= 0xff;
    PORTC = 0;
    DDRC |= 0xff;

    sei();

    while(1)
    {
        PORTA = (uint8_t)rand16();
        //PORTA = adc_dif;
        PORTB = scaleVolume16(volume);
        PORTC = scaleVolume8(volume);
        _delay_ms(50);
    }
    
    return 0;
}

