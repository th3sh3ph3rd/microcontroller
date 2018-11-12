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
#define TOP         0
#define BOTTOM      Y_HEIGHT-1
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

/* Accelerometer corner values */
//TODO finf out the real values
#define X_MIN       0x66
#define X_MAX       0x99
#define Y_MIN       0x52
#define Y_MAX       0xa7
#define Z_MIN       0x66
#define Z_MAX       0x99
#define ACC_DELTA   10

/* Game parameters */
#define TICKS_PER_SCROLL    10
#define WALL_GAP            15
#define BALL_RADIUS         3
#define GRAVITY             2

enum static_state {INIT, WAIT};
enum tick_state {SETUP, UPDATE, SCROLL, LEVEL};

/* WIImote MAC address */
//TODO move to PROGMEM
static const uint8_t mac[6] = { 0x58, 0xbd, 0xa3, 0x54, 0xfb, 0xf8 };

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
static uint8_t accel_x;
static uint8_t accel_y;
static uint8_t accel_z;
static uint8_t acc_min = 255;
static uint8_t acc_max = 0;

/* Counter variables */
//TODO put this in struct ticks
//TODO rename to scrollSpeed
static uint8_t gameTicksPerScroll = TICKS_PER_SCROLL;
static uint8_t gameTicksScroll = TICKS_PER_SCROLL-1;
static uint8_t scrollTicks = WALL_GAP-1;

/* Current screen image */
//TODO adapt this accordingly
#define WALLS_ON_SCREEN 4
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
    int8_t xAcc;
    int8_t yAcc;
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
static int8_t ballDir(uint8_t x, uint8_t z);
static uint8_t updateBallPos(void);
static void drawBall(void);
static void clearBall(void);
//static int8_t atan2(uint8_t x, uint8_t y);

/**
 * @brief       Initialize the game user interface.
 */
void gameui_init(void)
{
    glcdInit();

    wiiUserInit(&buttonCB, &accelCB);
    
    screenDynamics.yShift = glcdGetYShift();;

    PORTH = 0;
    DDRH = 0xff; 
    PORTK = 0;
    DDRK = 0xff; 
    PORTL = 0;
    DDRL = 0xff; 
}

uint8_t gameui_start(game_state_t *game_state)
{
    PORTK = 1;

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
    //PORTK = 4;
    //PORTH = ballDir(accel_x, accel_z);
    //PORTK = acc_min;
    //PORTH = accel_z;

    if (SETUP == play_state)
    {
        PORTL = 1;
        last_game_state = PLAY;
        next_game_state = PLAY;
        accel_en = 1;
        wiiUserSetAccel(0, 1, &setAccelCB);   
        if (accel_status == 1)
            play_state = UPDATE;
        initLevel();
    }
    if (UPDATE == play_state)
    {
        PORTL = 2;

        if (gameTicksScroll == gameTicksPerScroll-1)
        {
            play_state = SCROLL;
            gameTicksScroll = 0;
        }
        else
            gameTicksScroll++;

        clearBall();
        screenDynamics.ballDynamics.xAcc = ballDir(accel_x, accel_y);
        updateBallPos();
        drawBall();
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

        if (screenDynamics.yShift == Y_HEIGHT)
            screenDynamics.yShift = 0;
        else
            screenDynamics.yShift++;

        glcdSetYShift(screenDynamics.yShift);
    }
    if (LEVEL == play_state)
    {
        PORTL = 8;
        play_state = UPDATE;
        //clearWall(screenDynamics.yShift);
        //displayNewWall(screenDynamics.yShift+BOTTOM);
    }

    if (PLAY != next_game_state)
    {
        //TODO app gets stuck here sometimes
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

   // if (accel_z < acc_min)
   //     acc_min = accel_z;
   // if (accel_z > acc_max)
   //     acc_max = accel_z;
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

static void displayStartText(uint8_t yTop)
{
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = 10;

    glcdDrawTextPgm(game_name, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(play_b, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(highscore_b, startPoint, &Standard5x7, &glcdSetPixel);
}

static void displayConnectText(uint8_t yTop)
{
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = 10;

    glcdDrawTextPgm(connecting, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(towiimote, startPoint, &Standard5x7, &glcdSetPixel);
}

static void initLevel(void)
{
    uint8_t newWall;
    uint8_t yPos = screenDynamics.yShift;
    screenImage.topWall = 0;

    for (uint8_t w = 0; w < WALLS_ON_SCREEN; w++)
    {
        newWall = rand16() & (WALLS_AVAILABLE-1);
        /* Load new wall from PROGMEM */
        memcpy_P((void *)screenImage.walls[w].points, &data_walls[newWall], WALL_POINTS);
        screenImage.walls[w].yPos = yPos;
        drawWall(w);
        yPos += WALL_GAP+1;
    }
    
    screenDynamics.ballDynamics.xAcc = 0;
    screenDynamics.ballDynamics.yAcc = GRAVITY;
    screenImage.ball.x = (X_WIDTH/2)-1;
    screenImage.ball.y = (screenDynamics.yShift+BOTTOM-BALL_RADIUS);
    drawBall();
}

//static void displayNewWall(uint8_t y_off)
//{
//    xy_point point0, point1;
//
//    point0.y = y_off;
//    point1.y = y_off;
//
//    for (uint8_t i = 0; i < 6; i += 2)
//    {
//        point0.x = walls[toggle_wall][i];
//        point1.x = walls[toggle_wall][i+1];
//        
//        glcdDrawLine(point0, point1, &glcdSetPixel);
//    }
//}

static void displayNewWall(uint8_t yOff)
{
    uint8_t newWall = rand16() & (WALLS_AVAILABLE-1);

    /* Load new wall from PROGMEM */
    memcpy_P((void *)screenImage.walls[screenImage.topWall].points, &data_walls[newWall], WALL_POINTS);
    screenImage.walls[screenImage.topWall].yPos = yOff;

    drawWall(screenImage.topWall);

    if (screenImage.topWall == WALLS_ON_SCREEN-1)
        screenImage.topWall = 0;
    else
        screenImage.topWall++;
}

static void drawWall(uint8_t wall)
{
    xy_point point0, point1;
    
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

static int8_t ballDir(uint8_t x, uint8_t z)
{
    if (x >= 0x81-ACC_DELTA && 
        x <= 0x81+ACC_DELTA &&
        z >= Z_MAX-ACC_DELTA &&
        z <= Z_MAX+ACC_DELTA)
        return 0;

    if (x > 0x81 && z < Z_MAX)
        return 1;

    return -1;
}

static uint8_t updateBallPos(void)
{
//    /* GAME OVER */
//    if (screenImage.ball.y + screenDynamics.ballDynamics.yAcc + BALL_RADIUS >= TOP)
//        return 1;

    /* Hit left wall */
    if (screenImage.ball.x + screenDynamics.ballDynamics.xAcc - BALL_RADIUS == 0)
        screenImage.ball.x = BALL_RADIUS;
    /* Hit right wall */
    else if (screenImage.ball.x + screenDynamics.ballDynamics.xAcc + BALL_RADIUS >= X_WIDTH-1)
        screenImage.ball.x = X_WIDTH-BALL_RADIUS-1;
    /* Update ball position according to user input */
    else
        screenImage.ball.x += screenDynamics.ballDynamics.xAcc;
//
//    /* Wall collision detection */
//    for (uint8_t w = 0; w < WALLS_ON_SCREEN; w++)
//    {
//        //TODO detect collision with wall in x direction
//        // if (screenImage.walls[w].yPos >= screenImage.ball.y-BALL_RADIUS &&
//        //     screenImage.walls[w].yPos <= screenImage.ball.y+BALL_RADIUS)
//        /* Check if wall is on ball level */
//        if (screenImage.walls[w].yPos == screenImage.ball.y+BALL_RADIUS)
//        {
//            for (uint8_t p = 0; p < WALL_POINTS; p++)
//            {
//                if (p == WALL_POINTS-1 &&
//                    screenImage.walls[w].points[p] != X_WIDTH-1 &&
//                    screenImage.walls[w].points[p] <= screenImage.ball.x+BALL_RADIUS)
//                {
//                    //TODO set some flag
//                     break;
//                }
//                else if ((screenImage.walls[w].points[p] <= screenImage.ball.x-BALL_RADIUS &&
//                          screenImage.walls[w].points[p+1] >= screenImage.ball.x+BALL_RADIUS) ||
//                         (screenImage.walls[w].points[p] >= screenImage.ball.x-BALL_RADIUS &&
//                          screenImage.walls[w].points[p] <= screenImage.ball.x+BALL_RADIUS) ||
//                         (screenImage.walls[w].points[p+1] >= screenImage.ball.x-BALL_RADIUS &&
//                          screenImage.walls[w].points[p+1] <= screenImage.ball.x+BALL_RADIUS))
//                {
//                    //TODO set some flag
//                    break;
//                }
//            }
//        }
//    }
//
//    /* Compensate for scroll */
//    //TODO determine interference with collision detection
//    if (gameTicksScroll == gameTicksPerScroll)
//        screenImage.ball.y--;

    return 0;
}

static void drawBall(void)
{
    glcdDrawCircle(screenImage.ball, BALL_RADIUS, &glcdSetPixel);
}

static void clearBall(void)
{
    glcdDrawCircle(screenImage.ball, BALL_RADIUS, &glcdClearPixel);
}

/* atan2 integer algorithm, inspired by: http://forums.parallax.com/discussion/115008/how-to-compute-atan2-with-integers-and-of-course-quickly */
//static int8_t atan2(uint8_t x, uint8_t y)
//{
//    int32_t angle;
//
//    if (y == 0)
//    {
//        if (x >= 0)
//            return 0;
//        return 180;
//    }
//    if (x == 0)
//    {
//        if (y > 0)
//            return 90;
//        return -90;
//    }
//
//    angle = (3667 * x * y) / (64 * x * x + 17 * y * y);
//    
//    if (abs(y) > abs(x))
//        angle = 90 - angle;
//
//    if (x < 0)
//    {
//        if (y < 0)
//            angle = 180 + angle;
//        else
//            angle = 180 - angle;
//    }
//    else
//    {
//        if (y < 0)
//            angle = 360 - angle;
//    }
//
//    return (int8_t) angle;
//}

