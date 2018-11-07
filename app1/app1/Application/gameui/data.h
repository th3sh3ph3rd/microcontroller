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
const char menu[] PROGMEM = "A: Menu";
const char highscore[] PROGMEM = "B: Highscore";
const char player_1[] PROGMEM = "Player 1";
const char player_2[] PROGMEM = "Player 2";
const char player_3[] PROGMEM = "Player 3";
const char player_4[] PROGMEM = "Player 4";
const char player_5[] PROGMEM = "Player 5";

/* Start screen */
#define START_LINES 7
const char play[] PROGMEM = "A: Play";
PGM_P const data_startText[] PROGMEM =
{
    player_1,
    player_2,
    player_3,
    player_4,
    player_5,
    play,
    highscore
};

/* Connect screen */
const char data_connectText[] PROGMEM = "Connecting to wiimote...";

/* Pause screen */
#define PAUSE_LINES 3
const char pause[] PROGMEM = "Game paused";
const char resume[] PROGMEM = "A: Resume";
const char end[] PROGMEM = "B: End game";
PGM_P const data_pauseText[] PROGMEM =
{
    pause,
    resume,
    end
};

/* Game over screen */
#define GAMEOVER_LINES 3
const char gameover[] PROGMEM = "Game over!";
PGM_P const data_gameoverText[] PROGMEM =
{
    gameover,
    menu,
    highscore
};

/* Highscore screen */
#define HIGHSCORE_LINES 7
PGM_P const data_highscoreText[] PROGMEM =
{
    player_1,
    player_2,
    player_3,
    player_4,
    player_5,
    menu,
    highscore
};

#endif

