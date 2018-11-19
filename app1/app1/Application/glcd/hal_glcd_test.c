
#include <avr/io.h>
//#include <util/delay.h>
#include <hal_glcd.h>

//#define F_CPU (16000000UL)

int main(void)
{

    PORTK = 0;
    DDRK = 0xff;
    PORTL = 0;
    DDRL = 0xff;
    
    halGlcdInit();

//    halGlcdSetAddress(0x3f, 0x03);
//    halGlcdWriteData(0xaa);
//    halGlcdWriteData(0x55);
//    halGlcdSetAddress(0x3f, 0x03);
//    PORTK = halGlcdReadData();
//    PORTL = halGlcdReadData();
//    halGlcdWriteData(0xaa);
//    halGlcdWriteData(0x55);


    uint8_t pattern = 0xaa;

    for (uint8_t y = 0; y < 8; y++)
    {
        halGlcdSetAddress(0x00, y);
        for (uint8_t x = 0; x < 128; x++)
        {
            halGlcdWriteData(pattern);
            pattern ^= 0xff;
        }
    }

    while(1);

    return 0;
}

