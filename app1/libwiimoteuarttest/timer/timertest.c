#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

#include <timer.h>

void blink(void)
{
    PORTA = ~PORTA;
}

int main(void)
{
    timer_startTimer1(1000, TIMER_REPEAT, &blink);

    PORTA = 0;
    DDRA |= 0xff;

    sei();
    
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();

    while(1)
    {
        sleep_cpu();
    }
    
    return 0;
}

