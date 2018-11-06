/**
 *
 * @file timer.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-06
 *
 * Implementation of the timer module.
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdint.h>
#include <stdio.h>

#include <timer.h>

#define COUNT_1MS   62
#define PRESCALER   3

//TODO add some sort of error correction for the ms value, as exactly 1ms would ne 62.5 counts

typedef enum timer_state {AVAILABLE, NOT_AVAILABLE} timer_state_t;

typedef struct timer {
    volatile timer_state_t state;
    timer_mode_t mode;
    uint16_t period;
    volatile uint16_t ms;
    void (*callback)(void);
} timer_t;

/* Timer structs */
static timer_t timer1;
static timer_t timer3;
static timer_t timer4;
static timer_t timer5;

/**
 * @brief           Start a timer to run for the specified amount of ms.
 * @param ms        How many milliseconds the timer should run.
 * @param mode      The mode of the timer, wheter it should run once ore periodically.
 * @param _tmrCB    The callback function to be called in the timer ISR. Set to NULL if not needed. This callback can be interrupted at any time.
 * @return          The return value reflects if the setup was successful or if the timer is not available.
 */
timer_error_t timer_startTimer1(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void))
{
    if (NOT_AVAILABLE == timer1.state)
        return NOT_AVAIL;

    timer1.state = NOT_AVAILABLE;
    timer1.callback = _tmrCB;
    timer1.mode = mode;
    timer1.period = ms;
    timer1.ms = 0;

    TCNT1 = 0;
    OCR1A = COUNT_1MS;
    TCCR1B = (1<<WGM12)|PRESCALER;
    TIMSK1 |= (1<<OCIE1A);

    return SUCCESS;
}

timer_error_t timer_startTimer3(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void)){}
timer_error_t timer_startTimer4(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void)){}
timer_error_t timer_startTimer5(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void)){}

/*
 * @brief Stops the specified timer to make it available again. If the timer mode was TIMER_SINGLE, it does not have to be stopped.
 */
void timer_stopTimer1(void)
{
    TIMSK1 &= ~(1<<OCIE1A);
    timer1.state = AVAILABLE;
}

void timer_stopTimer3(void){}
void timer_stopTimer4(void){}
void timer_stopTimer5(void){}

ISR(TIMER1_COMPA_vect, ISR_BLOCK)
{
    timer1.ms++;
    if (timer1.ms == timer1.period)
    {
        timer1.ms = 0;
        if (TIMER_SINGLE == timer1.mode)
            timer_stopTimer1();

        sei();
        if (timer1.callback != NULL)
            timer1.callback();
    }
}

