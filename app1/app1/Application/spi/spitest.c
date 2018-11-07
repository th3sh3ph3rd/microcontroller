#include <mp3.h>
#include <spi.h>

int main(void)
{
    spiInit();
    mp3Init(NULL);
    mp3StartSineTest();
    while(1){}
}
