
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

int main(void)
{
    OCR4A = 0;
    TCCR4A = (1<<COM4A1) | (1<<WGM41) | (1<<WGM40);
    TCCR4B = (1<<WGM42) | (1<<CS41) | (1<<CS40);

    DDRF &= ~(1<PF0);
    PORTH &= ~(1<<PH3);
    DDRH |= (1<<PH3);

    TCNT0 = 0;
    TCCR0A = 0;
    TCCR0B = (1<<CS02);
    TIMSK0 = (1<<TOIE0);

    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN) | (1<<ADATE) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCSRB = (1<<ADTS2); 
    
    sei();

    while(1) sleep_mode();

    return 0;
}

ISR(ADC_vect, ISR_BLOCK)
{
    OCR4A = ADC;
}

