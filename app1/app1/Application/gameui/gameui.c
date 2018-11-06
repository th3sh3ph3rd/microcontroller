/**
 *
 * @file gameui.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-30
 *
 * Implementation of the game user interface.
 *
 */

#include <stdint.h>
#include <glcd.h>

#include <gameui.h>

#define Y_HEIGHT    64
#define RAM_SIZE    8192
#define RAM_ROWS    RAM_SIZE/Y_HEIGHT
#define WALL_GAP    13

enum gt_state {GAME, SCROLL, LEVEL};

static const uint8_t walls[2][6] = {{0, 26, 50, 57, 82, 109},
                              {18, 45, 70, 97, 117, 127}};

/* State variables */
static uint8_t y_shift = 0;
static enum gt_state gametick_state = GAME;

/* Counter variables */
static uint8_t gameTicksScroll = 0;
static uint8_t gameTicksPerScroll = 10;
static uint8_t scrollTicks = 0;

static uint8_t toggle_wall = 0;

/* Local functions */
static void displayNewWall(uint8_t y_off);
static void clearWall(uint8_t y_off);

/**
 * @brief       Initialize the game user interface.
 */
void gameui_init(void)
{
   glcdInit();
}

//TODO alt name: levelInit
uint8_t gameui_setup(game_state_t *game_state)
{
    uint8_t y_off = WALL_GAP;

    glcdFillScreen(GLCD_CLEAR);

    for (int w = 0; w < 4; w++)
    {
        displayNewWall(y_off);
        y_off += WALL_GAP;
    }

    y_shift = glcdGetYShift();

    *game_state = RUNNING;

    return 0;
}

/**
 * @brief               Completes one tick of the game user interface, consisting of fetching user input
 *                      and updating the picture on the screen accordingly.
 * @param game_state    The game state after calling the function is stored here. Must not be NULL.
 * @return              The function returns a non-zero value if there is still something to do and 0 if
 *                      all tasks of one tick have been completed.
 */
//TODO for tasking return in every block
uint8_t gameui_tick(game_state_t *game_state)
{
    if (GAME == gametick_state)
    {
        if (gameTicksScroll == gameTicksPerScroll-1)
        {
            gametick_state = SCROLL;
            gameTicksScroll = 0;
        }
        else
        {
            gameTicksScroll++;
        }
    }
    
    if (SCROLL == gametick_state)
    {
        if (scrollTicks == WALL_GAP-1)
        {
            gametick_state = LEVEL;
            scrollTicks = 0;
        }
        else
        {
            gametick_state = GAME;
            scrollTicks++;
        }

        //y_shift = (y_shift + 1) & (RAM_ROWS-1);
        if (y_shift == Y_HEIGHT)
            y_shift = 0;
        else
            y_shift++;

        glcdSetYShift(y_shift);
        //y_shift = glcdGetYShift();
    }

    if (LEVEL == gametick_state)
    {
        gametick_state = GAME;
        clearWall(y_shift);
        displayNewWall(y_shift);
        toggle_wall = !toggle_wall;
    }

    return !(GAME == gametick_state);
}

//uint8_t gameui_pause(game_state_t *game_state);

//uint8_t gameui_reconnect(game_state_t *game_state);

static void displayNewWall(uint8_t y_off)
{
    xy_point point0, point1;

    point0.y = y_off;
    point1.y = y_off;

    for (uint8_t i = 0; i < 6; i += 2)
    {
        point0.x = walls[toggle_wall][i];
        point1.x = walls[toggle_wall][i+1];
        
        glcdDrawLine(point0, point1, &glcdSetPixel);
    }
}

static void clearWall(uint8_t y_off)
{
    xy_point point0, point1;

    point0.y = y_off;
    point1.y = y_off;
    point0.x = 0;
    point1.x = 127;
    
    glcdDrawLine(point0, point1, &glcdClearPixel);
}

