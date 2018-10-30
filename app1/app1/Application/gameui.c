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

#define WALL_GAP   12

static uint8_t walls = {{0, 26, 50, 57, 82, 109}};

/* State variables */
uint8_t yShift = 0;

/* Counter variables */
uint8_t gameTicksScroll = 0;
uint8_t gameTicksPerScroll = 10;
uint8_t scrollTicks = 0;

/* Local functions */
void displayNewWall(void);

/**
 * @brief       Initialize the game user interface.
 */
void gameui_init(void)
{
   glcdInit(); 
}

uint8_t gameui_setup(game_state_t *game_state)
{
    uint8_t y_off = WALL_GAP;

    glcdFillScreen(GLCD_CLEAR);

    for (int w = 0; w < 4; w++)
    {
        displayNewWall(y_off);
        y_off += WALL_GAP+1;
    }

    yShift = glcdSetYShift();

    *game_state = RUNNING;

    return 0;
}

/**
 * @brief               Completes one tick of the game user interface, consisting of fetching user input
 *                      and updating the picture on the screen accordingly.
 * @param game_state    The games state after calling the function is stored here. Must not be NULL.
 * @return              The function returns a non-zero value if there is still something to do and 0 if
 *                      all tasks of one tick have been completed.
 */
uint8_t gameui_tick(game_state_t *game_state)
{
    if (gameTicksScroll == gameTicksPerScroll)
    {
        if (scrollTicks == WALL_GAP)
        {
            displayNewWall(0);
            scrollTicks = 0;
        }
        else
        {
            scrollTicks++;
        }

        glcdSetYShift(++yShift);
        gameTicksScroll = 0;
    }
    else
    {
        gameTicksScroll++;
    }
}

//uint8_t gameui_pause(game_state_t *game_state);

//uint8_t gameui_reconnect(game_state_t *game_state);

void displayNewWall(uint8_t y_off)
{
    xy_point_t point0, point1;

    point0.y = WALL_DIST;
    point1.y = WALL_DIST;

    for (uint8_t i = 0; i < 6; i += 2)
    {
        point0.x = walls[0][i];
        point1.x = walls[0][i+1];
        
        glcdDrawLine(point0, point1);
    }
}

