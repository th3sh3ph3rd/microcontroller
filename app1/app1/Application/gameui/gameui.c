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
#include <data.h>
#include <gameui.h>

#define Y_HEIGHT    64
#define RAM_SIZE    8192
#define RAM_ROWS    RAM_SIZE/Y_HEIGHT
#define WALL_GAP    13

/* Wii button encoding */
#define BUTTON_2_WII    0x01
#define BUTTON_1_WII    0x02
#define BUTTON_B_WII    0x04
#define BUTTON_A_WII    0x08
#define BUTTON_L_WII    (0x01<<8)
#define BUTTON_R_WII    (0x02<<8)
#define BUTTON_D_WII    (0x04<<8)
#define BUTTON_U_WII    (0x08<<8)

/* Local button encoding */
#define BUTTON_1    0x01
#define BUTTON_2    0x02
#define BUTTON_A    0x04
#define BUTTON_B    0x08
#define BUTTON_L    0x10
#define BUTTON_R    0x20
#define BUTTON_D    0x40
#define BUTTON_U    0x80

enum gt_state {GAME, SCROLL, LEVEL};

static const uint8_t walls[2][6] = {{0, 26, 50, 57, 82, 109},
                              {18, 45, 70, 97, 117, 127}};

/* State variables */
static game_state_t last_game_state;
static uint8_t y_shift = 0;
static enum gt_state gametick_state = GAME;
static connection_status_t wiimote_status = DISCONNECTED;
static uint8_t buttons = 0;

/* Counter variables */
static uint8_t gameTicksScroll = 0;
static uint8_t gameTicksPerScroll = 10;
static uint8_t scrollTicks = 0;

static uint8_t toggle_wall = 0;

/* Wii callback functions */
static void buttonCB(uint8_t wii, uint16_t buttonStates);
static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z);
static void connectCB(uint8_t wii, connection_status_t status);

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
    PORTK = 1;

    last_game_state = START;

    if (DISCONNECTED == wiimote_status)
    {
        *game_state = CONNECT;
        return 0;
    }
    else if (BUTTON_A & buttons)
    {
        *game_state = PLAY;
        glcdFillScreen(GLCD_CLEAR);
        buttons &= ~BUTTON_A;
    }
    else if (BUTTON_B & buttons)
    {
        *game_state = HIGHSCORE;
        glcdFillScreen(GLCD_CLEAR);
        buttons &= ~BUTTON_B;
    }

    return 0;
}

//TODO move to states eg. call_connect, wait_connect...
static uint8_t tried_to_connect = 0;
uint8_t mac[6] = { 0x58, 0xbd, 0xa3, 0x54, 0xe8, 0x28 };
uint8_t gameui_connect(game_state_t *game_state)
{
    PORTK = 2;
    
    if (tried_to_connect == 0)
    {
        wiiUserConnect(0, mac, &connectCB);
        tried_to_connect = 1;
    }

    if (CONNECTED == wiimote_status)
        *game_state = last_game_state;

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
   
    last_game_state = PLAY;
    
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

    if (DISCONNECTED == wiimote_status)
    {
        *game_state = CONNECT;
        return 0;
    }
    else if (BUTTON_A & buttons)
    {
        *game_state = START;
        buttons &= ~BUTTON_A;
    }
    else if (BUTTON_B & buttons)
    {
        *game_state = PAUSE;
        buttons &= ~BUTTON_B;
    }

    return !(GAME == gametick_state);
}

uint8_t gameui_pause(game_state_t *game_state)
{
    PORTK = 8;
    
    last_game_state = PAUSE;

    if (DISCONNECTED == wiimote_status)
    {
        *game_state = CONNECT;
        return 0;
    }
    else if (BUTTON_A & buttons)
    {
        *game_state = PLAY;
        buttons &= ~BUTTON_A;
    }

    return 0;
}

uint8_t gameui_gameOver(game_state_t *game_state)
{
    PORTK = 16;
    
    last_game_state = GAMEOVER;
 
    if (DISCONNECTED == wiimote_status)
    {
        *game_state = CONNECT;
    }
    else if (BUTTON_A & buttons)
    {
        *game_state = PLAY;
        buttons &= ~BUTTON_A;
    }
    else if (BUTTON_B & buttons)
    {
        *game_state = HIGHSCORE;
        buttons &= ~BUTTON_B;
    }

    return 0;
}

static void buttonCB(uint8_t wii, uint16_t buttonStates)
{
    if ((buttonStates & BUTTON_1_WII) && !(buttons & BUTTON_1))
        buttons |= BUTTON_1;
    if ((buttonStates & BUTTON_2_WII) && !(buttons & BUTTON_2))
        buttons |= BUTTON_2;
    if ((buttonStates & BUTTON_A_WII) && !(buttons & BUTTON_A))
        buttons |= BUTTON_A;
    if ((buttonStates & BUTTON_B_WII) && !(buttons & BUTTON_B))
        buttons |= BUTTON_B;
    if ((buttonStates & BUTTON_L_WII) && !(buttons & BUTTON_L))
        buttons |= BUTTON_L;
    if ((buttonStates & BUTTON_R_WII) && !(buttons & BUTTON_R))
        buttons |= BUTTON_R;
    if ((buttonStates & BUTTON_D_WII) && !(buttons & BUTTON_D))
        buttons |= BUTTON_D;
    if ((buttonStates & BUTTON_U_WII) && !(buttons & BUTTON_U))
        buttons |= BUTTON_U;
}

static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z){};

static void connectCB(uint8_t wii, connection_status_t status)
{
    wiimote_status = status;
    tried_to_connect = 0;
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

