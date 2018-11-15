/**
 *
 * @file music.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-08
 *
 * Header file for the music module.
 *
 */

#ifndef __MUSIC__
#define __MUSIC__

#include <stdint.h>
#include <task.h>

/**
 * @brief   Initialize the music module.
 */
void music_init(void (*mp3DataReqCB)(void));

/**
 * @brief   Play some music from the SD card on the mp3 module.
 * @return  Return non zero if there is still work to do and 0 if everything is done.
 */
task_state_t music_play(void);

/**
 * @brief           Pass a raw volume value (e.g from a pot) to the module.
 * @param volumeRaw The raw volume value, straight from the ADC.
 */
void music_setVolume(uint8_t volumeRaw); 

#endif

