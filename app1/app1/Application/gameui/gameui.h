/**
 *
 * @file gameui.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-30
 *
 * Header file for the game user interface.
 *
 */

#ifndef __GAMEUI__
#define __GAMEUI__

#include <stdint.h>

typedef enum game_state {START, CONNECT, PLAY, GAMEOVER, HIGHSCORE, PAUSE} game_state_t;

/**
 * @brief       Initialize the game user interface.
 */
void gameui_init(void);

uint8_t gameui_setup(game_state_t *game_state);

uint8_t gameui_start(game_state_t *game_state);

uint8_t gameui_connect(game_state_t *game_state);

/**
 * @brief               Completes one tick of the game user interface, consisting of fetching user input
 *                      and updating the picture on the screen accordingly.
 * @param game_state    The games state after calling the function is stored here. Must not be NULL.
 * @return              The function returns a non-zero value if there is still something to do and 0 if
 *                      all tasks of one tick have been completed.
 */
uint8_t gameui_play(game_state_t *game_state);

uint8_t gameui_pause(game_state_t *game_state);

uint8_t gameui_gameOver(game_state_t *game_state);

#endif

