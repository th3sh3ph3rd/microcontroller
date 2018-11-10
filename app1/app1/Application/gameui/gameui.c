/**
 *
 * @file gameui.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-30
 *
 * Implementation of the game user interface.
 *
 */

//TODO remove debug leds!!!

#include <avr/io.h>
#include <avr/pgmspace.h>

#include <math.h>
#include <stdint.h>

#include <glcd.h>
#include <Standard5x7.h>
#include <wii_user.h>
#include <rand.h>
#include <data.h>
#include <gameui.h>

#define X_WIDTH     128
#define Y_HEIGHT    64
#define RAM_SIZE    8192
#define RAM_ROWS    RAM_SIZE/Y_HEIGHT

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

/* Game parameters */
#define TICKS_PER_SCROLL    10
#define WALL_GAP            13

enum static_state {INIT, WAIT};
enum tick_state {SETUP, UPDATE, SCROLL, LEVEL};

//static const uint8_t walls[2][6] = {{0, 26, 50, 57, 82, 109},
//                              {18, 45, 70, 97, 117, 127}};

/* WIImote MAC address */
//TODO move to PROGMEM
static const uint8_t mac[6] = { 0x58, 0xbd, 0xa3, 0x54, 0xe8, 0x28 };

/* State variables */
//TODO put this in struct gameStates
static game_state_t last_game_state;
static game_state_t next_game_state;
static enum static_state start_state = INIT;
static enum static_state connect_state = INIT;
static enum tick_state play_state = SETUP;

/* Wiimote status flags */
//TODO put this in struct wiimoteStatus
static uint8_t tried_to_connect = 0;
static connection_status_t wiimote_status = DISCONNECTED;
static uint8_t accel_en = 0;
static uint8_t accel_status = 0;

/* Wiimote sensor values */
//TODO put this in struct sensorValues
static uint8_t buttons = 0;
static uint16_t accel_x;
static uint16_t accel_y;
static uint16_t accel_z;

/* Counter variables */
//TODO put this in struct ticks
//TODO rename to scrollSpeed
static uint8_t gameTicksPerScroll = TICKS_PER_SCROLL;
static uint8_t gameTicksScroll = TICKS_PER_SCROLL-1;
static uint8_t scrollTicks = WALL_GAP-1;
//TODO replace this with below defined struct
static uint8_t y_shift = 0;

/* Current screen image */
//TODO adapt this accordingly
#define WALLS_ON_SCREEN 5
struct wall
{
    uint8_t yPos;
    wall_points_t points;
};
static struct
{
    uint8_t topWall;
    xy_point ball;
    struct wall walls[WALLS_ON_SCREEN];
} screenImage;

/* Screen dynamic values */
struct ball_dyn
{
    uint8_t xAcc;
    uint8_t yAcc;
};
static struct
{
    uint8_t yShift;
    struct ball_dyn ballDynamics;
} screenDynamics;

static uint8_t toggle_wall = 0;

/* Wii callback functions */
static void buttonCB(uint8_t wii, uint16_t buttonStates);
static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z);
static void connectCB(uint8_t wii, connection_status_t status);
static void setAccelCB(uint8_t wii, error_t status);

/* Local functions */
static void displayText(PGM_P const *text, uint8_t lines, uint8_t y_top);
static void displayStartText(uint8_t y_top);
static void displayConnectText(uint8_t y_top);
static void initLevel(void);
static void displayNewWall(uint8_t y_off);
static void drawWall(uint8_t wall);
static void clearWall(uint8_t y_off);
static int8_t atan2(uint8_t x, uint8_t y);

/**
 * @brief       Initialize the game user interface.
 */
void gameui_init(void)
{
    glcdInit();

    wiiUserInit(&buttonCB, &accelCB);
    
    y_shift = glcdGetYShift();

    PORTH = 0;
    DDRH = 0xff; 
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
    //PORTL &= 0xc0;
    //PORTL = (accel_status<<7)|(accel_en<<6);
    PORTH = accel_x;

    if (INIT == start_state)
    {
        last_game_state = START;
        displayStartText(10);
        start_state = WAIT;
    }
    if (WAIT == start_state)
    {
        if (DISCONNECTED == wiimote_status)
            *game_state = CONNECT;
        else if (BUTTON_A & buttons)
            *game_state = PLAY;
        else if (BUTTON_B & buttons)
            *game_state = HIGHSCORE;

        if (START != *game_state)
        {
            glcdFillScreen(GLCD_CLEAR);
            start_state = INIT;
            buttons = 0;
        }
    }

    return 0;
}

uint8_t gameui_connect(game_state_t *game_state)
{
    PORTK = 2;
    //PORTL &= 0xc0;
    PORTH = accel_x;
    
    if (INIT == connect_state)
    {
        displayConnectText(10);
        connect_state = WAIT;
    }
    if (WAIT == connect_state)
    {
        if (tried_to_connect == 0)
        {
            wiiUserConnect(0, mac, &connectCB);
            tried_to_connect = 1;
        }

        if (CONNECTED == wiimote_status)
        {
            glcdFillScreen(GLCD_CLEAR);
            *game_state = last_game_state;
            connect_state = INIT;
            buttons = 0;
        }
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
    //PORTL &= 0xc0;
    //PORTL |= accel_x>>2;

    //PORTL = (accel_status<<7)|(accel_en<<6);
    //PORTK = accel_y;
    //PORTL = accel_x;

    if (SETUP == play_state)
    {
        PORTL = 1;
        last_game_state = PLAY;
        next_game_state = PLAY;
        accel_en = 1;
        wiiUserSetAccel(0, 1, &setAccelCB);   
        if (accel_status == 1)
            play_state = UPDATE;
    }
    if (UPDATE == play_state)
    {
        PORTL = 2;

        PORTH = ((uint32_t)((atan2(accel_y, accel_z)*180.0)/M_PI)>>20);

        if (gameTicksScroll == gameTicksPerScroll-1)
        {
            play_state = SCROLL;
            gameTicksScroll = 0;
        }
        else
            gameTicksScroll++;
    } 
    if (SCROLL == play_state)
    {
        PORTL = 4;
        if (scrollTicks == WALL_GAP-1)
        {
            play_state = LEVEL;
            scrollTicks = 0;
        }
        else
        {
            play_state = UPDATE;
            scrollTicks++;
        }

        if (y_shift == Y_HEIGHT)
            y_shift = 0;
        else
            y_shift++;

        glcdSetYShift(y_shift);
    }
    if (LEVEL == play_state)
    {
        PORTL = 8;
        play_state = UPDATE;
        clearWall(Y_HEIGHT+y_shift-1);
        displayNewWall(Y_HEIGHT+y_shift-1);
        toggle_wall = !toggle_wall;
    }

    if (PLAY != next_game_state)
    {
        PORTL = 32;
        accel_en = 0;
        wiiUserSetAccel(0, 0, &setAccelCB);   
        if (accel_status == 0)
        {
            *game_state = next_game_state;
            glcdFillScreen(GLCD_CLEAR);
            play_state = SETUP;
            buttons = 0;
        }
    }
    else
    {
        PORTL = 16;
        if (DISCONNECTED == wiimote_status)
            next_game_state = CONNECT;
        else if (BUTTON_A & buttons)
            next_game_state = START;
        else if (BUTTON_B & buttons)
            next_game_state = PAUSE;
    }
    
    return 0;
}

uint8_t gameui_pause(game_state_t *game_state)
{
    PORTK = 8;
    //PORTL &= 0xc0;
    PORTH = accel_x;
    
    last_game_state = PAUSE;

    if (DISCONNECTED == wiimote_status)
        *game_state = CONNECT;
    else if (BUTTON_A & buttons)
        *game_state = START;
    else if (BUTTON_B & buttons)
        *game_state = PLAY;

    buttons = 0;

    return 0;
}

uint8_t gameui_gameOver(game_state_t *game_state)
{
    PORTK = 16;
    
    last_game_state = GAMEOVER;
 
    if (DISCONNECTED == wiimote_status)
        *game_state = CONNECT;
    else if (BUTTON_A & buttons)
        *game_state = START;
    else if (BUTTON_B & buttons)
        *game_state = HIGHSCORE;

    buttons = 0;

    return 0;
}

uint8_t gameui_highScore(game_state_t *game_state)
{
    PORTK = 32;
    //PORTL &= 0xc0;
    PORTH = accel_x;

    last_game_state = HIGHSCORE;
    
    if (DISCONNECTED == wiimote_status)
        *game_state = CONNECT;
    else if (BUTTON_A & buttons)
        *game_state = START;

    buttons = 0;

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

static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z)
{
    accel_x = x>>2;
    accel_y = y>>1;
    accel_z = z>>1;
}

static void connectCB(uint8_t wii, connection_status_t status)
{
    wiimote_status = status;
    tried_to_connect = 0;
}

static void setAccelCB(uint8_t wii, error_t status)
{
    if (accel_en == 1)
        accel_status = 1;
    if (accel_en == 0)
        accel_status = 0;
}

static void displayText(PGM_P const *text, uint8_t lines, uint8_t y_top)
{
        xy_point startPoint;
        //startPoint.y = (y_shift+y_top) & (Y_HEIGHT-1);
        startPoint.y = 10;
        startPoint.x = 10;

        for (int i = 0; i < lines; i++)
        {
            //glcdDrawTextPgm(text[i], startPoint, &Standard5x7, &glcdSetPixel);
            glcdDrawText((const char *)pgm_read_word(&text[i]), startPoint, &Standard5x7, &glcdSetPixel);
            startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
        }
}

static void displayStartText(uint8_t y_top)
{
        xy_point startPoint;
        startPoint.y = (y_shift+y_top) & (Y_HEIGHT-1);
        startPoint.x = 10;

        glcdDrawTextPgm(game_name, startPoint, &Standard5x7, &glcdSetPixel);
        startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
        glcdDrawTextPgm(play_b, startPoint, &Standard5x7, &glcdSetPixel);
        startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
        glcdDrawTextPgm(highscore_b, startPoint, &Standard5x7, &glcdSetPixel);
}

static void displayConnectText(uint8_t y_top)
{
        xy_point startPoint;
        startPoint.y = (y_shift+y_top) & (Y_HEIGHT-1);
        startPoint.x = 10;

        glcdDrawTextPgm(connecting, startPoint, &Standard5x7, &glcdSetPixel);
        startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
        glcdDrawTextPgm(towiimote, startPoint, &Standard5x7, &glcdSetPixel);
}

static void initLevel(void)
{
    xy_point point0, point1;
    uint8_t newWall;
    uint8_t yPos = screenDynamics.yShift;
    screenImage.topWall = 0;

    for (uint8_t w = 0; w < WALLS_ON_SCREEN; w++)
    {
        newWall = rand16() & (WALLS_AVAILABLE-1);
        /* Load new wall from PROGMEM */
        memcpy_P(screenImage.walls[w].points, &data_walls[newWall], WALL_POINTS);
        screenImage.walls[w].yPos = yPos;
        drawWall(w);
        yPos += WALL_GAP;
    }
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

//static void displayNewWall(uint8_t yOff)
//{
//    xy_point point0, point1;
//    uint8_t newWall = rand16() & (WALLS_AVAILABLE-1);
//
//    /* Load new wall from PROGMEM */
//    memcpy_P(screenImage.walls[screenImage.topWall].points, &data_walls[newWall], WALL_POINTS);
//    screenImage.walls[screenImage.topWall].yPos = Y_HEIGHT+screenDynamics.yShift-1;
//
//    drawWall(screenImage.topWall);
//
//    if (screenImage.topWall == WALLS_ON_SCREEN-1)
//        screenImage.topWall = 0;
//    else
//        screenImage.topWall++;
//}

static void drawWall(uint8_t wall)
{
    point0.y = screenImage.walls[wall].yPos;
    point1.y = screenImage.walls[wall].yPos;

    for (uint8_t i = 0; i < WALL_POINTS; i += 2)
    {
        if (i == WALL_POINTS-1)
        {
            if (screenImage.walls[wall].points[i] != X_WIDTH-1)
            {
                point0.x = screenImage.walls[wall].points[i];
                point1.x = X_WIDTH-1;    
                glcdDrawLine(point0, point1, &glcdSetPixel);
            }
        }
        else
        {
            point0.x = screenImage.walls[wall].points[i];
            point1.x = screenImage.walls[wall].points[i+1];    
            glcdDrawLine(point0, point1, &glcdSetPixel);
        }
    }
}

static void clearWall(uint8_t yOff)
{
    xy_point point0, point1;

    point0.y = yOff;
    point1.y = yOff;
    point0.x = 0;
    point1.x = 127;
    
    glcdDrawLine(point0, point1, &glcdClearPixel);
}

/* atan2 integer algorithm, inspired by: http://forums.parallax.com/discussion/115008/how-to-compute-atan2-with-integers-and-of-course-quickly */
static int8_t atan2(uint8_t x, uint8_t y)
{
    int32_t angle;

    if (y == 0)
    {
        if (x >= 0)
            return 0;
        return 180;
    }
    if (x == 0)
    {
        if (y > 0)
            return 90;
        return -90;
    }

    angle = (3667 * x * y) / (64 * x * x + 17 * y * y);
    
    if (abs(y) > abs(x))
        angle = 90 - angle;

    if (x < 0)
    {
        if (y < 0)
            angle = 180 + angle;
        else
            angle = 180 - angle;
    }
    else
    {
        if (y < 0)
            angle = 360 - angle;
    }

    return (int8_t) angle;
}

