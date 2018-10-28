/**
 *
 * @file adc.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-27
 *
 * Header file for the ADC driver.
 *
 */

#ifndef __ADC__
#define __ADC__

#include <stdint.h>

/**
 * @brief       Initialize the ADC driver.
 */
void adc_init(void);

/**
 * @brief           Set the callback functions for the ADC ISR.
 * @param _difCB    The callback function processing the adc value from the differential channel.
 * @param _potCB    The callback function processing the adc value from the potentiometer.
 */
void adc_setCallbacks(void (*_difCB)(uint16_t adc), void (*_potCB)(uint16_t adc));

#endif

