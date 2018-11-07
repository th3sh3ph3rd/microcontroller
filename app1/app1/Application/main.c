#define F_CPU       (16000000UL)

#include <avr/io.h>
#include <stdio.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <timer.h>
#include <gameui.h>

#define MS_STEP         (15)            /* 15 ms, results in a display update interval of about 2Hz */
#define CONV_MS(x)      (x / MS_STEP)
//OCR1A = (((MS_STEP * F_CPU) / (64 * 1000U)) - 1);

static game_state_t game_state = START;

static uint8_t tmr_int = 0;

void gametickCallback(void)
{
    tmr_int = 1;
}

int main(void)
{
    gameui_init();

    timer_startTimer1(50, TIMER_REPEAT, &gametickCallback);

    sei();
     
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();

    while (1)
    {
        if (tmr_int == 1)
        {
            if (START == game_state)
                gameui_start(&game_state);
            else if (CONNECT == game_state)
                gameui_connect(&game_state);
            else if (PLAY == game_state)
                gameui_play(&game_state);
            
            tmr_int = 0;
        }
        sleep_cpu();
    }
    
    return 0;
}

