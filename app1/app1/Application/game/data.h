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
const char data_menu_b[] PROGMEM = "A: Menu";
const char data_player[] PROGMEM = "Player ";
const char data_game_name[] PROGMEM = "Falling down ball";
const char data_play_b[] PROGMEM = "A: Play";
const char data_highscore_b[] PROGMEM = "B: Highscore";
const char data_start_b[] PROGMEM = "A:Play B:Highscore";
const char data_connecting[] PROGMEM = "Connecting";
const char data_towiimote[] PROGMEM = "to wiimote...";
const char data_select_b[] PROGMEM = "A:Play B:Menu";
const char data_pause[] PROGMEM = "Game paused";
const char data_end_b[] PROGMEM = "A: End game";
const char data_data_resume_b[] PROGMEM = "B: Resume";
const char data_gameover[] PROGMEM = "Game over!";

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
};

#endif

