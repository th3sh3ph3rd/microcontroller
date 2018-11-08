
#include <avr/sleep.h>
#include <music.h>

static volatile uint8_t mp3dataReq = 1;

void musicCB(void)
{
    mp3dataReq = 1;
}

int main(void)
{
    music_init(&musicCB);

    sei();

    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();

    uint8_t done_music;

    while(1)
    {
        if (mp3dataReq == 1)
        {
            do
            {
                done_music = music_play();
            } while (done_music != 0);
            mp3dataReq = 0;
        }
        sleep_cpu();
    }

    return 0;
}

