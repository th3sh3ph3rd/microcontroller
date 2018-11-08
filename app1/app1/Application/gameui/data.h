/**
 *
 * @file data.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-08
 *
 * Game data stored in the program memory (flash).
 *
 */

#ifndef __DATA__
#define __DATA__

#include <avr/pgmspace.h>
#include <stdint.h>

/* Common strings*/
const char menu_b[] PROGMEM = "A: Menu";
//const char highscore_b[] PROGMEM = "B: Highscore";
const char player_1[] PROGMEM = "Player 1";
const char player_2[] PROGMEM = "Player 2";
const char player_3[] PROGMEM = "Player 3";
const char player_4[] PROGMEM = "Player 4";
const char player_5[] PROGMEM = "Player 5";

/* Start screen */
#define START_LINES 3
const char game_name[] PROGMEM = "Falling down ball";
const char play_b[] PROGMEM = "A: Play";
const char highscore_b[] PROGMEM = "B: Highscore";
const char start_b[] PROGMEM = "A:Play B:Highscore";
PGM_P const data_startText[] PROGMEM =
{
    game_name,
    play_b,
    highscore_b
};

/* Connect screen */
#define CONNECT_LINES 2
const char connecting[] PROGMEM = "Connecting";
const char towiimote[] PROGMEM = "to wiimote...";
PGM_P const data_connectText[] PROGMEM =
{
    connecting,
    towiimote,
};

/* Pause screen */
#define PAUSE_LINES 3
const char pause[] PROGMEM = "Game paused";
const char end_b[] PROGMEM = "A: End game";
const char resume_b[] PROGMEM = "B: Resume";
PGM_P const data_pauseText[] PROGMEM =
{
    pause,
    resume_b,
    end_b
};

/* Game over screen */
#define GAMEOVER_LINES 3
const char gameover[] PROGMEM = "Game over!";
PGM_P const data_gameoverText[] PROGMEM =
{
    gameover,
    menu_b,
    highscore_b
};

/* Highscore screen */
#define HIGHSCORE_LINES 6
PGM_P const data_highscoreText[] PROGMEM =
{
    player_1,
    player_2,
    player_3,
    player_4,
    player_5,
    menu_b,
};

#endif

