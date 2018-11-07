/**
 *
 * @file timer.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-06
 *
 * Header file for the timer module.
 *
 */

#ifndef __TIMER__
#define __TIMER__

#include <stdint.h>

typedef enum timer_mode {TIMER_SINGLE, TIMER_REPEAT} timer_mode_t;
typedef enum timer_error {SUCCESS, NOT_AVAIL, INVAL} timer_error_t;

/**
 * @brief           Start a timer to run for the specified amount of ms.
 * @param ms        How many milliseconds the timer should run. Must not be bigger than 4194, otherwise INVAL is returned.
 * @param mode      The mode of the timer, wheter it should run once ore periodically.
 * @param _tmrCB    The callback function to be called in the timer ISR. Set to NULL if not needed. This callback can be interrupted at any time.
 * @return          The return value reflects if the setup was successful or if the timer is not available.
 */
timer_error_t timer_startTimer1(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void));
timer_error_t timer_startTimer3(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void));
timer_error_t timer_startTimer4(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void));
timer_error_t timer_startTimer5(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void));

/*
 * @brief Stops the specified timer to make it available again. If the timer mode was TIMER_SINGLE, it does not have to be stopped.
 */
void timer_stopTimer1(void);
void timer_stopTimer3(void);
void timer_stopTimer4(void);
void timer_stopTimer5(void);

#endif

