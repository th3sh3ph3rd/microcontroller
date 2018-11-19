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

#include <spi.h>
#include <mp3.h>
#include <sdcard.h>
#include <task.h>

/* dt_himalayas.mp3 */
#define SONG_START  4385760
#define SONG_LENGTH 289872

#define DELTA_VOLUME    50

static uint32_t sdcardBlockAddress = SONG_START;
static uint8_t spiLock = 0;

static uint8_t scaleVolume(uint8_t volume); 

/**
 * @brief   Initialize the music module.
 */
void music_init(void (*mp3DataReqCB)(void))
{
    spiInit();
    while (sdcardInit() != SUCCESS);
    mp3Init(mp3DataReqCB);
}

/**
 * @brief   Play some music from the SD card on the mp3 module.
 * @return  Return non zero if there is still work to do and 0 if everything is done.
 */
task_state_t music_play(void)
{
    sdcard_block_t musicBuffer;

    //if (!mp3Busy() && sdcardBlockAddress < (SONG_START + SONG_LENGTH))
    if (!mp3Busy())
    {
        spiLock = 1;
        if (sdcardReadBlock(sdcardBlockAddress, musicBuffer) == SUCCESS)
        {
            mp3SendMusic(musicBuffer);
            spiLock = 0;
            if (sdcardBlockAddress < SONG_START + SONG_LENGTH)
                sdcardBlockAddress += BLOCK_SIZE;
            else
                sdcardBlockAddress = SONG_START;
        }
        spiLock = 0;
        return BUSY;
    }
    return DONE;
}

/**
 * @brief           Pass a raw volume value (e.g from a pot) to the module.
 * @param volumeRaw The raw volume value, straight from the ADC.
 */
void music_setVolume(uint8_t volumeRaw)
{
    uint8_t newVolume = scaleVolume(volumeRaw);
    /* Only set the volume if the spi is not used by other functions */
    if (spiLock == 0)
        mp3SetVolume(newVolume);
}

/**
 * @brief           Scale the volume value to an approximate logarithmic scale.
 * @param volume    The raw volume value to scale.
 * @return          The scaled volume value.
 */
static uint8_t scaleVolume(uint8_t volume)
{
    /* Implementation of the log-approximation 1-(1-x)^4 */
    volume = 0xff - volume;
    volume = (volume * volume) >> 8;
    volume = (volume * volume) >> 8;
    return 0xff - volume;
}

