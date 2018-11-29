
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    PORTH = 0;
    DDRH |= (1<<PH3);

    TCNT4 = 0;
    ICR4 = 100;
    OCR4A = 75;
    TCCR4A = (1<<COM4A1) | (1<<WGM41);
    TCCR4B = (1<<WGM43) | (1<<CS41);

    sei();

    while(1);

    return 0;
}

