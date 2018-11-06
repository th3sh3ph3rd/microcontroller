/**
 *
 * @file adc.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-27
 *
 * Implementation of the ADC driver.
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include <adc.h>

/* Sample ADC3 and ADC2 in differential mode with 200x amplification */
#define ADMUX_DIF   (1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0)
/* Set timer frequency to ~200Hz if used with a prescaler of 1024, so every channel gets read every ~10ms */
#define OCV         38

enum adc_state {DIF, POT};
static volatile enum adc_state state;

static void (*difCB)(uint16_t adc);
static void (*potCB)(uint16_t adc);

/**
 * @brief       Initialize the ADC driver.
 */
void adc_init(void)
{ 
    /*******************
     * Setup timer 0 A *
     *******************/
 
    OCR0A = OCV;
    TCNT0 = 0;
    /* Enable output compare interrupt B */
    TIMSK0 |= (1<<OCIE0A);
    /* Set timer to CTC mode and set prescaler to 1024 */
    TCCR0A |= (1<<WGM01);
    TCCR0B |= (1<<CS02)|(1<<CS00);
 
    /*****************
     * Setup the ADC *
     *****************/

    /* Set voltage reference to AVCC */
    ADMUX |= (1<<REFS0);
    /* Enable auto triggering, enable ADC interrupt and use 128 as prescaler */
    ADCSRA |= (1<<ADATE)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
    /* Select timer0 compare match A as auto trigger source  */
    ADCSRB |= (1<<ADTS1)|(1<<ADTS0);

    state = DIF;
}

/**
 * @brief           Set the callback functions for the ADC ISR.
 * @param _difCB    The callback function processing the adc value from the differential channel.
 * @param _potCB    The callback function processing the adc value from the potentiometer.
 */
void adc_setCallbacks(void (*_difCB)(uint16_t adc), void (*_potCB)(uint16_t adc))
{
    difCB = _difCB;
    potCB = _potCB;
}

/**
 * @brief   Read the ADC value, pass it to the appropriate callback, disable the ADC and switch to the next channel.
 */
ISR(ADC_vect, ISR_BLOCK)
{
    uint16_t adc_res = ADC;
    ADCSRA &= ~(1<<ADEN);

    if (DIF == state)
    {
        ADMUX &= ~(ADMUX_DIF);
        state = POT;
        sei();
        difCB(adc_res);
    }
    else if (POT == state)
    {
        ADMUX |= ADMUX_DIF;
        state = DIF;
        sei();
        potCB(adc_res);
    }
}

/**
 * @brief   Enable the ADC.
 */
ISR(TIMER0_COMPA_vect, ISR_BLOCK)
{
    ADCSRA |= (1<<ADEN);
}

