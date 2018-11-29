
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//#define F_CPU (16000000UL)

int main(void)
{
    PORTA = 0;
    DDRA = 0xff;

    UCSR0A &= ~((1<<U2X0) | (1<<MPCM0));
    UCSR0B = (UCSR0B | (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0)) & ~(1<<UCSZ02);
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
    UBRR0 = 103;

    sei();

    uint8_t c = 'a';
    while(1)
    {
        while (!(UCSR0A & (1<<UDRE0)));
        UDR0 = c;
        
        if (c == 'z')
            c = 'a';
        else
            c++;
        
        _delay_ms(1000);
    }

    return 0;
}

ISR(USART0_RX_vect, ISR_BLOCK)
{
    PORTA = UDR0;
}

