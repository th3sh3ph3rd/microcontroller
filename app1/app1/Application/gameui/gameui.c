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

#include <stdint.h>
#include <stdio.h>

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
#define X_MID       0x80
#define X_MAX       0x99
#define Y_MIN       0x52
#define Y_MAX       0xa7
#define Z_MIN       0x66
#define Z_MID       0x80
#define Z_MAX       0x99
#define ACC_DELTA   10

/* Game parameters */
#define TICKS_PER_SCROLL    10
#define TICKS_PER_SCORE     20
#define TICKS_PER_DIFF      20
#define WALL_GAP            15
#define BALL_RADIUS         3
#define GRAVITY             1
#define PLAYERNUM           5
#define SELECTOR_RADIUS     2

enum static_state {INIT, WAIT};
enum tick_state {SETUP, UPDATE, SCROLL, LEVEL, NEXT};

/* WIImote MAC address */
//TODO move to PROGMEM
static const uint8_t mac[6] = { 0x58, 0xbd, 0xa3, 0xba, 0xa1, 0x32 };

/* State variables */
//TODO put this in struct gameStates
static game_state_t last_game_state;
static game_state_t next_game_state;
static enum static_state start_state = INIT;
static enum static_state connect_state = INIT;
static enum static_state selectplayer_state = INIT;
static enum static_state pause_state = INIT;
static enum static_state gameover_state = INIT;
static enum static_state highscore_state = INIT;
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
static uint8_t gameTicksPerScroll = TICKS_PER_SCROLL-1;
static uint8_t gameTicksScroll = TICKS_PER_SCROLL-1;
static uint8_t gameTicksScore = 0;
static uint16_t gameTicksPerDiff = TICKS_PER_DIFF-1;
static uint16_t gameTicksDiff = 0;
static uint8_t scrollTicks = WALL_GAP;

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

/* Player data */
static struct
{
    uint8_t currPlayer;
    uint16_t currScore;
    uint16_t highScore[PLAYERNUM];
} playerData;
//TODO move to PROGMEM
static const uint8_t selectorYPosStart = 6;

/* Wii callback functions */
static void buttonCB(uint8_t wii, uint16_t buttonStates);
static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z);
static void connectCB(uint8_t wii, connection_status_t status);
static void setAccelCB(uint8_t wii, error_t status);

/* Local functions */
static void displayText(PGM_P const *text, uint8_t lines, uint8_t y_top);
static void displayStartText(uint8_t y_top);
static void displayConnectText(uint8_t y_top);
static void displaySelectPlayerText(uint8_t y_top);
static void displayPauseText(uint8_t y_top);
static void displayGameOverText(uint8_t y_top);
static void displayHighScoreText(uint8_t y_top);
static void initLevel(void);
static void moveSelector(uint8_t curr, uint8_t next);
static void scrollScreen(void);
static void displayNewWall(uint8_t yOff);
static void drawWall(uint8_t wall);
static void clearWall(uint8_t wall);
static int8_t ballAcc(uint8_t x, uint8_t z);
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
    
    PORTL = 0;
    DDRL = 0xff; 
}

uint8_t gameui_start(game_state_t *game_state)
{
    if (INIT == start_state)
    {
        last_game_state = START;
        glcdFillScreen(GLCD_CLEAR);
        displayStartText(10);
        start_state = WAIT;
    }
    if (WAIT == start_state)
    {
        if (DISCONNECTED == wiimote_status)
            *game_state = CONNECT;
        else if (BUTTON_A & buttons)
            *game_state = SELECTPLAYER;
        else if (BUTTON_B & buttons)
            *game_state = HIGHSCORE;

        if (START != *game_state)
        {
            start_state = INIT;
            buttons = 0;
        }
    }

    return 0;
}

uint8_t gameui_connect(game_state_t *game_state)
{
    if (INIT == connect_state)
    {
        glcdFillScreen(GLCD_CLEAR);
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
            *game_state = last_game_state;
            connect_state = INIT;
            buttons = 0;
        }
    }
    screenDynamics.yShift = glcdGetYShift();;

    return 0;
}

uint8_t gameui_selectPlayer(game_state_t *game_state)
{
    uint8_t lastPlayer;

    if (INIT == selectplayer_state)
    {
        last_game_state = SELECTPLAYER;
        glcdFillScreen(GLCD_CLEAR);
        displaySelectPlayerText(10);
        moveSelector(0, 0);
        playerData.currPlayer = 0;
        selectplayer_state = WAIT;
    }
    if (WAIT == selectplayer_state)
    {
        if (DISCONNECTED == wiimote_status)
            *game_state = CONNECT;
        else if (BUTTON_A & buttons)
            *game_state = PLAY;
        else if (BUTTON_U & buttons)
        {
            lastPlayer = playerData.currPlayer;
            if (playerData.currPlayer == 0)
                playerData.currPlayer = PLAYERNUM-1;
            else
                playerData.currPlayer--;
            moveSelector(lastPlayer, playerData.currPlayer);
            buttons &= ~BUTTON_U;
        }
        else if (BUTTON_D & buttons)
        {
            lastPlayer = playerData.currPlayer;
            if (playerData.currPlayer == PLAYERNUM-1)
                playerData.currPlayer = 0;
            else
                playerData.currPlayer++;
            moveSelector(lastPlayer, playerData.currPlayer);
            buttons &= ~BUTTON_D;
        }

        if (SELECTPLAYER != *game_state)
        {
            selectplayer_state = INIT;
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
    if (SETUP == play_state)
    {
        //TODO fsm sometimes gets stuck here
        PORTL = 1;
        last_game_state = PLAY;
        next_game_state = PLAY;
        accel_en = 1;
        wiiUserSetAccel(0, 1, &setAccelCB);   
        if (accel_status == 1)
        {
            glcdFillScreen(GLCD_CLEAR);
            initLevel();
            buttons = 0;
            play_state = UPDATE;
        }
    }
    if (UPDATE == play_state)
    {
        PORTL = 2;
        if (gameTicksScroll >= gameTicksPerScroll)
        {
            play_state = SCROLL;
            gameTicksScroll = 0;
        }
        else
            gameTicksScroll++;
        
        if (gameTicksScore == TICKS_PER_SCORE-1)
        {
            playerData.currScore++;
            gameTicksScore = 0;
        }
        else
            gameTicksScore++;
        
        if (gameTicksDiff == gameTicksPerDiff && gameTicksPerScroll > 1)
        {
            gameTicksPerScroll--;
            gameTicksPerDiff += TICKS_PER_DIFF;
            gameTicksDiff = 0;
        }
        else
            gameTicksDiff++;

        clearBall();
        screenDynamics.ballDynamics.xAcc = ballAcc(accel_x, accel_y);
        if (updateBallPos() == 1)
        {
            play_state = NEXT;
            next_game_state = GAMEOVER;
        }
        drawBall();
    } 
    if (SCROLL == play_state)
    {
        PORTL = 4;
        if (scrollTicks == WALL_GAP)
        {
            play_state = LEVEL;
            scrollTicks = 0;
        }
        else
        {
            play_state = NEXT;
            scrollTicks++;
        }

        scrollScreen();
    }
    if (LEVEL == play_state)
    {
        PORTL = 8;
        play_state = NEXT;
        clearWall(screenImage.topWall);
        displayNewWall(BOTTOM);
    }
    if (NEXT == play_state)
    {
        if (PLAY == next_game_state)
        {
            PORTL = 16;
            if (DISCONNECTED == wiimote_status)
                next_game_state = CONNECT;
            else if (BUTTON_A & buttons)
                next_game_state = START;
            else if (BUTTON_B & buttons)
                next_game_state = PAUSE;
        } 
        if (PLAY != next_game_state)
        {
            //TODO app gets stuck here sometimes
            PORTL = 32;
            accel_en = 0;
            wiiUserSetAccel(0, 0, &setAccelCB);   
            if (accel_status == 0)
            {
                /* New highscore entry */
                if ((GAMEOVER == next_game_state ||
                     START == next_game_state) &&
                    playerData.currScore > playerData.highScore[playerData.currPlayer])
                    playerData.highScore[playerData.currPlayer] = playerData.currScore;
                *game_state = next_game_state;
                play_state = SETUP;
                buttons = 0;
            }
        }
        else
            play_state = UPDATE;
    }
    
    return 0;
}

uint8_t gameui_pause(game_state_t *game_state)
{
    if (INIT == pause_state)
    {
        last_game_state = PAUSE;
        glcdFillScreen(GLCD_CLEAR);
        displayPauseText(10);
        pause_state = WAIT;
    }
    if (WAIT == pause_state)
    {
        if (DISCONNECTED == wiimote_status)
            *game_state = CONNECT;
        else if (BUTTON_A & buttons)
            *game_state = START;
        else if (BUTTON_B & buttons)
            *game_state = PLAY;

        if (PAUSE != *game_state)
        {
            pause_state = INIT;
            buttons = 0;
        }
    }

    return 0;
}

uint8_t gameui_gameOver(game_state_t *game_state)
{
    if (INIT == gameover_state)
    {
        last_game_state = GAMEOVER;
        glcdFillScreen(GLCD_CLEAR);
        displayGameOverText(10);
        gameover_state = WAIT;
    }
    if (WAIT == gameover_state)
    {
        if (DISCONNECTED == wiimote_status)
            *game_state = CONNECT;
        else if (BUTTON_A & buttons)
            *game_state = START;
        else if (BUTTON_B & buttons)
            *game_state = HIGHSCORE;

        if (GAMEOVER != *game_state)
        {
            gameover_state = INIT;
            buttons = 0;
        }
    }
    
    return 0;
}

uint8_t gameui_highScore(game_state_t *game_state)
{
    if (INIT == highscore_state)
    {
        last_game_state = HIGHSCORE;
        glcdFillScreen(GLCD_CLEAR);
        displayHighScoreText(10);
        highscore_state = WAIT;
    }
    if (WAIT == highscore_state)
    {
        if (DISCONNECTED == wiimote_status)
            *game_state = CONNECT;
        else if (BUTTON_A & buttons)
            *game_state = START;

        if (HIGHSCORE != *game_state)
        {
            highscore_state = INIT;
            buttons = 0;
        }
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

static void displaySelectPlayerText(uint8_t yTop)
{
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = 10;

    glcdDrawTextPgm(player_1, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(player_2, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(player_3, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(player_4, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(player_5, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(play_b, startPoint, &Standard5x7, &glcdSetPixel);
}

static void displayPauseText(uint8_t yTop)
{
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = 10;

    glcdDrawTextPgm(pause, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(end_b, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(resume_b, startPoint, &Standard5x7, &glcdSetPixel);
}

static void displayGameOverText(uint8_t yTop)
{
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = 10;

    glcdDrawTextPgm(gameover, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(menu_b, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(highscore_b, startPoint, &Standard5x7, &glcdSetPixel);
}

static void displayHighScoreText(uint8_t yTop)
{
    char hsStr[15];
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = 10;
    
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_1);
    sprintf(hsStr+8, " %d", playerData.highScore[0]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_2);
    sprintf(hsStr+8, " %d", playerData.highScore[1]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_3);
    sprintf(hsStr+8, " %d", playerData.highScore[1]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_4);
    sprintf(hsStr+8, " %d", playerData.highScore[3]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_5);
    sprintf(hsStr+8, " %d", playerData.highScore[4]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    glcdDrawTextPgm(menu_b, startPoint, &Standard5x7, &glcdSetPixel);
}

static void initLevel(void)
{
    uint8_t newWall;
    uint8_t yPos = 0;
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
    screenImage.ball.y = BOTTOM-BALL_RADIUS;
    drawBall();

    gameTicksPerScroll = TICKS_PER_SCROLL-1;
    gameTicksScroll = TICKS_PER_SCROLL-1;
    gameTicksPerDiff = TICKS_PER_DIFF-1;
    gameTicksDiff = 0;
    gameTicksScore = TICKS_PER_SCROLL-1;
    scrollTicks = WALL_GAP;

    playerData.currScore = 0;
}

static void moveSelector(uint8_t curr, uint8_t next)
{
    xy_point selector;
    
    selector.x = 4;
    selector.y = selectorYPosStart+screenDynamics.yShift+10*curr; 
    glcdDrawCircle(selector, SELECTOR_RADIUS, &glcdClearPixel);
    selector.y = selectorYPosStart+screenDynamics.yShift+10*next; 
    glcdDrawCircle(selector, SELECTOR_RADIUS, &glcdSetPixel); 
}

static void scrollScreen(void)
{
    if (screenDynamics.yShift == Y_HEIGHT-1)
        screenDynamics.yShift = 0;
    else
        screenDynamics.yShift++;

    for (uint8_t w = 0; w < WALLS_ON_SCREEN; w++)
    {
        if (screenImage.walls[w].yPos == 0)
            screenImage.walls[w].yPos = BOTTOM;
        else
            screenImage.walls[w].yPos--;
    }

    if (screenImage.ball.y == 0)
        screenImage.ball.y = BOTTOM;
    else
        screenImage.ball.y--;
    
    glcdSetYShift(screenDynamics.yShift);
}

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
    
    point0.y = screenImage.walls[wall].yPos+screenDynamics.yShift;
    point1.y = screenImage.walls[wall].yPos+screenDynamics.yShift;

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

static void clearWall(uint8_t wall)
{
    xy_point point0, point1;

    point0.y = screenImage.walls[wall].yPos+screenDynamics.yShift;
    point1.y = screenImage.walls[wall].yPos+screenDynamics.yShift;
    point0.x = 0;
    point1.x = 127;
    
    glcdDrawLine(point0, point1, &glcdClearPixel);
}

static int8_t ballAcc(uint8_t x, uint8_t z)
{
    if (x >= X_MID-ACC_DELTA && 
        x <= X_MID+ACC_DELTA)
        return 0;

    if (x > 0x81 && z > Z_MIN)
        return 1;

    return -1;
}

static uint8_t updateBallPos(void)
{
    uint8_t xCollisionL = 0;
    uint8_t xCollisionR = 0;
    uint8_t yCollision = 0;
    /* GAME OVER */
    if (screenImage.ball.y-BALL_RADIUS-1 == TOP)
        return 1;

    /* Wall collision detection */
    for (uint8_t w = 0; w < WALLS_ON_SCREEN; w++)
    {
        /* Check if wall is on ball level */
        if (screenImage.walls[w].yPos >= screenImage.ball.y-BALL_RADIUS &&
            screenImage.walls[w].yPos <= screenImage.ball.y+BALL_RADIUS+1)
        {
            for (uint8_t p = 0; p < WALL_POINTS; p += 2)
            {
                if (screenImage.walls[w].yPos == screenImage.ball.y+BALL_RADIUS+1)
                {
                    if (p == WALL_POINTS-1 &&
                        screenImage.walls[w].points[p] != X_WIDTH-1 &&
                        screenImage.walls[w].points[p] <= screenImage.ball.x+BALL_RADIUS)
                    {
                        yCollision = 1;
                        break;
                    }
                    else if ((screenImage.walls[w].points[p] < screenImage.ball.x-BALL_RADIUS &&
                              screenImage.walls[w].points[p+1] > screenImage.ball.x+BALL_RADIUS) ||
                             (screenImage.walls[w].points[p] >= screenImage.ball.x-BALL_RADIUS &&
                              screenImage.walls[w].points[p] <= screenImage.ball.x+BALL_RADIUS) ||
                             (screenImage.walls[w].points[p+1] >= screenImage.ball.x-BALL_RADIUS &&
                              screenImage.walls[w].points[p+1] <= screenImage.ball.x+BALL_RADIUS))
                    {
                        yCollision = 1;
                        break;
                    }
                }
                else
                {
                    if (p == WALL_POINTS-1 &&
                        screenImage.walls[w].points[p] != X_WIDTH-1 &&
                        screenImage.walls[w].points[p] == screenImage.ball.x+BALL_RADIUS+1)
                    {
                        xCollisionR = 1;
                        break;
                    }
                    else if (screenImage.walls[w].points[p] == screenImage.ball.x+BALL_RADIUS+1)
                    {
                        xCollisionR = 1;
                        break;
                    }
                    else if (screenImage.walls[w].points[p+1] == screenImage.ball.x-BALL_RADIUS-1)
                    {
                        xCollisionL = 1;
                        break;
                    }
                }
            }

            break;
        }
    }

    if (screenImage.ball.x-BALL_RADIUS-1 == 0)
        xCollisionL = 1;
    else if (screenImage.ball.x+BALL_RADIUS+1 == X_WIDTH-1)
        xCollisionR = 1;

    if ((!xCollisionL && !xCollisionR) ||
        (xCollisionL && screenDynamics.ballDynamics.xAcc > 0) ||
        (xCollisionR && screenDynamics.ballDynamics.xAcc < 0))
        screenImage.ball.x += screenDynamics.ballDynamics.xAcc;

    if (!yCollision &&
        screenImage.ball.y+BALL_RADIUS+1 < BOTTOM)
        screenImage.ball.y += screenDynamics.ballDynamics.yAcc;

    return 0;
}

static void drawBall(void)
{
    xy_point ball;
    ball.x = screenImage.ball.x;
    ball.y = screenImage.ball.y+screenDynamics.yShift;
    glcdDrawCircle(ball, BALL_RADIUS, &glcdSetPixel);
}

static void clearBall(void)
{
    xy_point ball;
    ball.x = screenImage.ball.x;
    ball.y = screenImage.ball.y+screenDynamics.yShift;
    glcdDrawCircle(ball, BALL_RADIUS, &glcdClearPixel);
}

