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

#define F_CPU       (16000000UL)

#define COUNT_1MS   62
#define PRESC_64    3
#define PRESC_256   4
#define PRESC_1024  5

#define MAX_64      262
#define MAX_256     1048
#define MAX_1024    4194

/* Calculate the output compare register value for the desired interval */
#define OCR(T, P)   (((F_CPU/1000)*T)/(P))-1

typedef enum {AVAILABLE, NOT_AVAILABLE} timer_state_t;

typedef struct {
    volatile timer_state_t state;
    timer_mode_t mode;
    void (*callback)(void);
} timer_t;

/* Timer structs */
static timer_t timer1;
static timer_t timer3;
static timer_t timer4;
static timer_t timer5;

/**
 * @brief           Start a timer to run for the specified amount of ms.
 * @param ms        How many milliseconds the timer should run. Must not be bigger than 4194, otherwise INVAL is returned.
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

    TCNT1 = 0;

    if (ms <= MAX_64)
    {  
        OCR1A = OCR(ms, 64);
        TCCR1B = (1<<WGM12)|PRESC_64;
    }
    else if (ms <= MAX_256)
    {
        OCR1A = OCR(ms, 256);
        TCCR1B = (1<<WGM12)|PRESC_256;
    }
    else if (ms <= MAX_1024)
    {
        OCR1A = OCR(ms, 1024);
        TCCR1B = (1<<WGM12)|PRESC_1024;
    }
    else
    {
        timer1.state = AVAILABLE;
        return INVAL;
    }

    TIMSK1 |= (1<<OCIE1A);

    return SUCC;
}

timer_error_t timer_startTimer3(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void))
{
    if (NOT_AVAILABLE == timer3.state)
        return NOT_AVAIL;

    timer3.state = NOT_AVAILABLE;
    timer3.callback = _tmrCB;
    timer3.mode = mode;

    TCNT3 = 0;

    if (ms <= MAX_64)
    {  
        OCR3A = OCR(ms, 64);
        TCCR3B = (1<<WGM32)|PRESC_64;
    }
    else if (ms <= MAX_256)
    {
        OCR3A = OCR(ms, 256);
        TCCR3B = (1<<WGM32)|PRESC_256;
    }
    else if (ms <= MAX_1024)
    {
        OCR3A = OCR(ms, 1024);
        TCCR3B = (1<<WGM32)|PRESC_1024;
    }
    else
    {
        timer3.state = AVAILABLE;
        return INVAL;
    }

    TIMSK3 |= (1<<OCIE3A);

    return SUCC;
}

timer_error_t timer_startTimer4(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void))
{
    if (NOT_AVAILABLE == timer4.state)
        return NOT_AVAIL;

    timer4.state = NOT_AVAILABLE;
    timer4.callback = _tmrCB;
    timer4.mode = mode;

    TCNT4 = 0;

    if (ms <= MAX_64)
    {  
        OCR4A = OCR(ms, 64);
        TCCR4B = (1<<WGM42)|PRESC_64;
    }
    else if (ms <= MAX_256)
    {
        OCR4A = OCR(ms, 256);
        TCCR4B = (1<<WGM42)|PRESC_256;
    }
    else if (ms <= MAX_1024)
    {
        OCR4A = OCR(ms, 1024);
        TCCR4B = (1<<WGM42)|PRESC_1024;
    }
    else
    {
        timer4.state = AVAILABLE;
        return INVAL;
    }

    TIMSK4 |= (1<<OCIE4A);

    return SUCC;
}

timer_error_t timer_startTimer5(uint16_t ms, timer_mode_t mode, void (*_tmrCB)(void))
{
    if (NOT_AVAILABLE == timer5.state)
        return NOT_AVAIL;

    timer5.state = NOT_AVAILABLE;
    timer5.callback = _tmrCB;
    timer5.mode = mode;

    TCNT5 = 0;

    if (ms <= MAX_64)
    {  
        OCR5A = OCR(ms, 64);
        TCCR5B = (1<<WGM52)|PRESC_64;
    }
    else if (ms <= MAX_256)
    {
        OCR5A = OCR(ms, 256);
        TCCR5B = (1<<WGM52)|PRESC_256;
    }
    else if (ms <= MAX_1024)
    {
        OCR5A = OCR(ms, 1024);
        TCCR5B = (1<<WGM52)|PRESC_1024;
    }
    else
    {
        timer5.state = AVAILABLE;
        return INVAL;
    }

    TIMSK5 |= (1<<OCIE5A);

    return SUCC;
}

/*
 * @brief Stops the specified timer to make it available again. If the timer mode was TIMER_SINGLE, it does not have to be stopped.
 */
void timer_stopTimer1(void)
{
    TIMSK1 &= ~(1<<OCIE1A);
    timer1.state = AVAILABLE;
}

void timer_stopTimer3(void)
{
    TIMSK3 &= ~(1<<OCIE3A);
    timer3.state = AVAILABLE;
}

void timer_stopTimer4(void)
{
    TIMSK4 &= ~(1<<OCIE4A);
    timer4.state = AVAILABLE;
}

void timer_stopTimer5(void)
{
    TIMSK5 &= ~(1<<OCIE5A);
    timer5.state = AVAILABLE;
}

/*
 * @brief Decide if timer needs to be stopped an call the registered callback.
 */
ISR(TIMER1_COMPA_vect, ISR_BLOCK)
{
    if (TIMER_SINGLE == timer1.mode)
        timer_stopTimer1();

    sei();
    if (timer1.callback != NULL)
        timer1.callback();
}

ISR(TIMER3_COMPA_vect, ISR_BLOCK)
{
    if (TIMER_SINGLE == timer3.mode)
        timer_stopTimer3();

    sei();
    if (timer3.callback != NULL)
        timer3.callback();
}

ISR(TIMER4_COMPA_vect, ISR_BLOCK)
{
    if (TIMER_SINGLE == timer4.mode)
        timer_stopTimer4();

    sei();
    if (timer4.callback != NULL)
        timer4.callback();
}

ISR(TIMER5_COMPA_vect, ISR_BLOCK)
{
    if (TIMER_SINGLE == timer5.mode)
        timer_stopTimer5();

    sei();
    if (timer5.callback != NULL)
        timer5.callback();
}

