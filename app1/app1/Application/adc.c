/**
 *
 * @file adc.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-27
 *
 * Implementation of the ADC driver.
 *
 */


#ifndef __ADC__
#define __ADC__

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

/* Sample ADC0 - connected to onboard potentiometer */
#define MUX_POT 0x00
/* Sample ADC3 and ADC2 in differential mode with 200x amplification */
#define MUX_DIF (1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0)

/**
 * @brief       Initialize the ADC driver.
 */
//TODO require callbacks to be called in the ISR (for PRNG and volume control)
//switch between sampling floating pins and pot with admux
//setup timer to trigger adc conversion (obviously with double the required frequency)
void adc_init(void)
{
    
}

//TODO setup ISR which alternately calls the PRNG and volume control callbacks

#endif

