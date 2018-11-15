
#include <avr/io.h>
#include <util/delay.h>
#include <hal_glcd.h>

#define F_CPU (16000000UL)

int main(void)
{
    halGlcdInit();

    halGlcdSetAddress(0x04, 0x00);
    halGlcdWriteData(0xaa);
    halGlcdWriteData(0xaa);
//    halGlcdWriteData(0xaa);
//    halGlcdWriteData(0xaa);
//    halGlcdWriteData(0xaa);
    //halGlcdWriteData(0x55);
    
    //halGlcdSetAddress(0x3f, 0x01);
    //halGlcdWriteData(0xaa);
    //halGlcdWriteData(0x55);

    while(1);

    return 0;
}

