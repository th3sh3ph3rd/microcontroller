
#include <avr/io.h>
#include <avr/interrupt.h>

#define ICP1 PD4

uint8_t ovfCnt;
uint16_t inpCapReg;
uint32_t interval;
uint8_t seconds;
uint8_t hundreths;

int main(void)
{
    PORTA = 0;
    PORTD &= ~(1<<ICP1);
    DDRA = 0xff;
    DDRD = (DDRD | (1<<ICP1)) & ~(1<<PD0);
    PORTD |= (1<<PD0);

    PORTB = 0;
    PORTC = 0;
    DDRB = 0xff;
    DDRC = 0xff;

    EICRA = EICRA | (1<<ISC01) | (1<<ISC00);
    EIMSK = EIMSK | (1<<INT0);

    TCNT1 = 0;
    TCCR1A = TCCR1A & ~((1<<WGM11)|(1<<WGM10));
    TCCR1B = (TCCR1B | (1<<ICES1) | (1<<CS12) | (1<<CS10)) & ~((1<<WGM13) | (1<<WGM12)) ;
    TIMSK1 = TIMSK1 | (1<<ICIE1) | (1<<TOIE1);

    sei();

    uint8_t dummy = 0;
    while(1)
    {
        dummy = !dummy;
    }

    return 0;
}

ISR(INT0_vect, ISR_BLOCK)
{
    PORTD |= (1<<ICP1);
}

ISR(TIMER1_OVF_vect, ISR_BLOCK)
{
    ovfCnt++;
}

ISR(TIMER1_CAPT_vect, ISR_BLOCK)
{
    inpCapReg = ICR1;
    PORTD &= ~(1<<ICP1);
    TCNT1 = 0;
    interval = 0xffff * ovfCnt;
    ovfCnt = 0;

    interval = (interval + inpCapReg) / 1562;
    PORTB = interval;
    
    interval = (interval + inpCapReg);

    interval /= 1562;

    seconds = interval / 10;
    hundreths = interval % 10;

    if (interval > 99)
        PORTA = 0xff;
    else
        PORTA = (hundreths<<4) | seconds;
}

