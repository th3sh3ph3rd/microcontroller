/**
 *
 * @file music.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-08
 *
 * Implementation of the music module.
 *
 */

#include <stdint.h>

#include <mp3.h>
#include <sdcard.h>

static uint8_t volumeRaw = 0;
static uint32_t sdcardBlockAddress = 0;

uint8_t scaleVolume(uint8_t volume); 

/**
 * @brief   Initialize the music module.
 */
void music_init(void (*mp3DataReqCB)(void))
{
    sdcardInit(); //TODO check for error?
    mp3Init(&mp3DataReqCB);
    mp3SetVolume(50);
}

/**
 * @brief   Play some music from the SD card on the mp3 module.
 * @return  Return non zero if there is still work to do and 0 if everything is done.
 */
uint8_t music_play(void)
{
    uint8_t musicBuffer[BLOCK_SIZE];

    if (!mp3Busy())
    {
        if (sdcardReadBlock(sdcardBlockAddress, music_buffer) == SUCCESS)
        {
            mp3SendMusic(musicBuffer);
            sdcardBlockAddress += BLOCK_SIZE; //TODO make atomic?
        }
        return 1;
    }
    return 0;
}

/**
 * @brief           Pass a raw volume value (e.g from a pot) to the module.
 * @param volumeRaw The raw volume value, straight from the ADC.
 */
void music_setVolumeRaw(uint8_t _volumeRaw)
{
    volumeRaw = _volumeRaw;
}

//TODO decide whether volume is updatet when a new value is received or autonomously
uint8_t scaleVolume(uint8_t volume)
{
    /* Implementation of the log-approximation 1-(1-x)^4 */
    volume = 255 - volume;
    volume = (volume * volume) >> 8;
    volume = (volume * volume) >> 8;
    return 255 - volume;
}

