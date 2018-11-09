
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <adc.h>
#include <rand.h>
#include <music.h>

static volatile uint8_t mp3dataReq = 1;

void musicCB(void)
{
    mp3dataReq = 1;
}

void difCB(uint16_t n)
{
    //rand_feed((uint8_t) n);
}

void potCB(uint16_t n)
{
    n >>= 2;
    music_setVolume((uint8_t) n);
}

int main(void)
{
    music_init(&musicCB);
    adc_init();
    adc_setCallbacks(&difCB, &potCB);

    sei();

    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();

    volatile uint8_t done_music;

    while(1)
    {
        if (mp3dataReq == 1)
        {
            mp3dataReq = 0;
            do
            {
                done_music = music_play();
            } while (done_music != 0);
        }
        sleep_cpu();
    }

    return 0;
}

