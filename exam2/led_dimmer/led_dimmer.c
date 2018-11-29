
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    PORTJ = 0;
    DDRJ = 0xff;
    DDRF &= ~(1<PF0);

    TCNT4 = 0;
    OCR4A = 0x0ff;
    TCCR4A = (1<<COM4A1) | (1<<WGM41) | (1<<WGM40);
    //TCCR4B = (1<<WGM43) | (1<<WGM42) | (1<<CS42) | (1<<CS40);
    TCCR4B = (1<<WGM42);

//    TCNT0 = 0;
//    TCCR0B = (1<<CS20) | (1<<CS00);
//    TIMSK0 = (1<<TOIE0);
    
    PORTH &= ~(1<<PH3);
    DDRH |= (1<<PH3);
   
    TCNT1 = 0;

    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN) | (1<<ADATE) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCSRB = (1<<ADTS2) | (1<<ADTS1);

    TCCR1B = (1<<CS21);
    TCCR4B = (1<<CS42) | (1<<CS40);
    
    TIMSK1 = (1<<TOIE1);
    
    sei();

    while(1);

    return 0;
}

ISR(ADC_vect, ISR_BLOCK)
{
    uint16_t res = ADC;
    OCR4A = res;
    PORTJ = res;
}

