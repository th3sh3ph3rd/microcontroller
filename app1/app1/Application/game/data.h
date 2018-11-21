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
const char data_disconnected[] PROGMEM = "Disconnected!";
const char data_reset[] PROGMEM = "Reset board!";
const char data_select_b[] PROGMEM = "A:Play B:Menu";
const char data_pause[] PROGMEM = "Game paused";
const char data_end_b[] PROGMEM = "A: End game";
const char data_data_resume_b[] PROGMEM = "B: Resume";
const char data_gameover[] PROGMEM = "Game over!";
const char data_score[] PROGMEM = "Score: ";

/* Connection screen animation */
struct connectFrame
{
    xy_point l0p0;
    xy_point l0p1;
    xy_point l1p0;
    xy_point l1p1;
};
const unsigned char data_connectFrames[2][4][2] PROGMEM =
{
    {{53, 40}, {73, 40}, {63, 35}, {63, 45}},
    {{53, 35}, {73, 45}, {73, 35}, {53, 45}}
};

/* A set of randomly generated walls for the game */
#define WALL_POINTS 5
typedef unsigned char wall_points_t[WALL_POINTS]; 
#define WALLS_AVAILABLE 64
#define MAX_GAP_WIDTH 12
const wall_points_t data_walls[WALLS_AVAILABLE] PROGMEM =
{
    {9,38,49,75,84},
    {43,52,78,89,118},
    {10,36,47,63,73},
    {54,64,80,91,117},
    {12,41,49,79,91},
    {36,48,78,86,115},
    {8,32,41,60,69},
    {58,67,86,95,119},
    {10,25,35,58,67},
    {60,69,92,102,117},
    {12,28,38,58,70},
    {57,69,89,99,115},
    {9,39,50,71,81},
    {46,56,77,88,118},
    {8,36,48,78,88},
    {39,49,79,91,119},
    {12,37,45,65,76},
    {51,62,82,90,115},
    {10,40,49,80,90},
    {37,47,78,87,117},
    {9,32,44,62,71},
    {56,65,83,95,118},
    {12,32,42,61,72},
    {55,66,85,95,115},
    {11,26,35,50,58},
    {69,77,92,101,116},
    {12,32,43,64,76},
    {51,63,84,95,115},
    {12,43,54,84,96},
    {31,43,73,84,115},
    {12,34,44,74,82},
    {45,53,83,93,115},
    {12,32,44,67,78},
    {49,60,83,95,115},
    {8,30,40,62,71},
    {56,65,87,97,119},
    {8,23,34,59,69},
    {58,68,93,104,119},
    {8,32,40,67,76},
    {51,60,87,95,119},
    {8,33,45,69,78},
    {49,58,82,94,119},
    {12,39,50,69,79},
    {48,58,77,88,115},
    {9,39,47,66,78},
    {49,61,80,88,118},
    {8,27,39,60,71},
    {56,67,88,100,119},
    {10,33,44,67,79},
    {48,60,83,94,117},
    {8,36,46,73,81},
    {46,54,81,91,119},
    {11,26,34,57,69},
    {58,70,93,101,116},
    {11,32,43,69,77},
    {50,58,84,95,116},
    {9,25,37,55,63},
    {64,72,90,102,118},
    {8,23,35,66,74},
    {53,61,92,104,119},
    {11,27,35,55,65},
    {62,72,92,100,116},
    {10,25,34,60,69},
    {58,67,93,102,117}
};

#endif

