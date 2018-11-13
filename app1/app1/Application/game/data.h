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

/* Select player screen */
const char select_b[] PROGMEM = "A:Play B:Menu";

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

/* A set of randomly generated walls for the game */
#define WALL_POINTS 5
typedef const unsigned char wall_points_t[WALL_POINTS]; 
#define WALLS_AVAILABLE 32
wall_points_t data_walls[WALLS_AVAILABLE] PROGMEM =
{
	{8,40,69,110,127},
	{0,17,58,87,119},
	{15,32,42,84,127},
	{0,43,85,95,112},
	{14,45,57,104,127},
	{0,23,70,82,113},
	{21,40,50,65,127},
	{0,62,77,87,106},
	{17,38,62,116,127},
	{0,11,65,89,110},
	{9,46,59,77,127},
	{0,50,68,81,118},
	{19,47,67,111,127},
	{0,16,60,80,108},
	{2,13,26,103,127},
	{0,24,101,114,125},
	{16,43,52,64,127},
	{0,63,75,84,111},
	{1,35,46,103,127},
	{0,24,81,92,126},
	{13,23,48,61,127},
	{0,66,79,104,114},
	{15,48,80,113,127},
	{0,14,47,79,112},
	{9,23,34,80,127},
	{0,47,93,104,118},
	{1,27,63,79,127},
	{0,48,64,100,126},
	{18,31,66,89,127},
	{0,38,61,96,109},
	{12,23,34,96,127},
	{0,31,93,104,115}
}

#endif

