
#define F_CPU       (16000000UL)
#define TRUE        (0 == 0)
#define FALSE       (!TRUE)

#include <avr/io.h>
#include <util/delay.h>

/* If you compile it with -ffreestanding you could use void main(void)
   but the functions from <util/delay.h> don't work with -ffreestanding. */
int main(void)
{
    /* Initialize LEDs. */
    DDRA  = DDRB  = DDRC  = DDRD  = 0xFF;
    PORTA = PORTB = PORTC = PORTD = 0x01;
    
    while(TRUE)
    {
        /* Some action. */
        PORTA <<= 1;
        
        if(PORTA == 0x00)
        {
            PORTB <<= 1;
            PORTA = 0x01;
        }
        if(PORTB == 0x00)
        {
            PORTC <<= 1;
            PORTB = 0x01;
        }
        if(PORTC == 0x00)
        {
            PORTD <<= 1;
            PORTC = 0x01;
        }
        if(PORTD == 0x00)
        {
            PORTA = PORTB = PORTC = PORTD = 0x01;
        }
        _delay_ms(100);
    }
}

