
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    PORTJ = 0;
    DDRJ = 0xff;
    PORTH &= ~(1<<PH3);
    DDRH |= (1<<PH3);
    DDRF &= ~(1<PF0);

    TCNT4 = 0;
    ICR4 = 0x3ff;
    OCR4A = 0x3ff;
    TCCR4A = (1<<COM4A1) | (1<<WGM41);
    TCCR4B = (1<<WGM43) | (1<<WGM42) | (1<<CS42) | (1<<CS40); 

    TCNT1 = 0;
    TCCR1B = (1<<CS11);

    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN) | (1<<ADATE) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCSRB = (1<<ADTS2) | (1<<ADTS1);

    sei();

    while(1);

    return 0;
}

ISR(ADC_vect, ISR_BLOCK)
{
    //OCR4A = ADC;
    PORTJ = ADC;
    TIFR1 &= ~(1<<TOV1);
}

