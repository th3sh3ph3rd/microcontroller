/**
 *
 * @file gameui.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-30
 *
 * Implementation of the game user interface.
 *
 */

#include <avr/io.h>

#include <stdint.h>
#include <glcd.h>

#include <wii_user.h>
#include <gameui.h>

#define Y_HEIGHT    64
#define RAM_SIZE    8192
#define RAM_ROWS    RAM_SIZE/Y_HEIGHT
#define WALL_GAP    13

/* Wii button encoding */
#define BUTTON_A    0x08

enum gt_state {GAME, SCROLL, LEVEL};

static const uint8_t walls[2][6] = {{0, 26, 50, 57, 82, 109},
                              {18, 45, 70, 97, 117, 127}};

/* State variables */
static uint8_t y_shift = 0;
static enum gt_state gametick_state = GAME;
static connection_status_t wiimote_status = DISCONNECTED;

/* Counter variables */
static uint8_t gameTicksScroll = 0;
static uint8_t gameTicksPerScroll = 10;
static uint8_t scrollTicks = 0;

static uint8_t toggle_wall = 0;

/* Wii callback functions */
static void buttonCB(uint8_t wii, uint16_t buttonStates);
static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z);
static void connectCB(uint8_t wii, connection_status_t status);

static uint16_t buttons;
static uint8_t button_A = 0;

/* Local functions */
static void displayNewWall(uint8_t y_off);
static void clearWall(uint8_t y_off);

/**
 * @brief       Initialize the game user interface.
 */
void gameui_init(void)
{
    glcdInit();

    wiiUserInit(&buttonCB, &accelCB);
    
    y_shift = glcdGetYShift();

    PORTK = 0;
    DDRK = 0xff; 
    PORTL = 0;
    DDRL = 0xff; 
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

    *game_state = PLAY;

    return 0;
}


uint8_t gameui_start(game_state_t *game_state)
{
    xy_point point0, point1;
    point0.x = 0;
    point0.y = 0;
    point1.x = 127;
    point1.y = 0;
    glcdDrawLine(point0, point1, &glcdSetPixel);
   
    PORTK = 1;
    PORTL = button_A;

    if (wiimote_status == DISCONNECTED)
    {
        *game_state = CONNECT;
        glcdFillScreen(GLCD_CLEAR);
        return 0;
    }

    if (button_A)
    {
        *game_state = PLAY;
        glcdFillScreen(GLCD_CLEAR);
        button_A = 0;
    }

    return 0;
}

//TODO move to states eg. call_connect, wait_connect...
static uint8_t connect_called = 0;
uint8_t mac[6] = { 0x58, 0xbd, 0xa3, 0x54, 0xe8, 0x28 };
uint8_t gameui_connect(game_state_t *game_state)
{
    xy_point point0, point1;
    point0.x = 0;
    point0.y = 55;
    point1.x = 127;
    point1.y = 55;
    glcdDrawLine(point0, point1, &glcdSetPixel);
    
    PORTK = 2;
    PORTL = button_A;

    wiiUserConnect(0, mac, &connectCB);
    
    if (connect_called == 0)
    {
        //wiiUserConnect(0, mac, &connectCB);
        connect_called = 1;
        return 0;
    }

    if (CONNECTED == wiimote_status)
    {
        *game_state = START;
        connect_called = 0;
        glcdFillScreen(GLCD_CLEAR);
    }

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
uint8_t gameui_play(game_state_t *game_state)
{
    PORTK = 4;
    PORTL = button_A;

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

    if (button_A)
    {
        *game_state = START;
        glcdFillScreen(GLCD_CLEAR);
        button_A = 0;
    }

    return !(GAME == gametick_state);
}

//uint8_t gameui_pause(game_state_t *game_state);

//uint8_t gameui_reconnect(game_state_t *game_state);

static void buttonCB(uint8_t wii, uint16_t buttonStates)
{
    PORTK |= 64;
    buttons = buttonStates;

    if (button_A == 0)
        button_A = ((buttonStates & BUTTON_A) != 0);
}

static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z){};

static void connectCB(uint8_t wii, connection_status_t status)
{
    PORTK |= 128;
    wiimote_status = status;
}

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

