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
#include <string.h>

#include <glcd.h>
#include <Standard5x7.h>
#include <wii_user.h>
#include <adc.h>
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
#define SELECTOR_Y_START    6

enum static_state {INIT, WAIT};
enum tick_state {SETUP, UPDATE, SCROLL, LEVEL, NEXT};

/* WIImote MAC address */
//TODO move to PROGMEM
static const uint8_t mac[6] = { 0x58, 0xbd, 0xa3, 0xba, 0xa1, 0x32 };

/* State variables */
//TODO find out if this has to be init
static struct
{
    game_state_t last;
    game_state_t next;
    enum static_state start;
    enum static_state connect;
    enum static_state selectPlayer;
    enum static_state pause;
    enum static_state gameOver;
    enum static_state highScore;
    enum tick_state play;
} gameStates;

/* Wiimote status flags */
static struct
{
    uint8_t triedConnect;
    connection_status_t status;
    uint8_t triedSetAcc;
    uint8_t accStatus;
} wiimote;

/* Wiimote sensor values */
static struct
{
    uint8_t buttons;
    uint8_t accX;
    uint8_t accY;
    uint8_t accZ;
} input;

/* Counter variables */
static struct
{
    uint8_t scrollDiv;
    uint8_t scroll;
    uint8_t score;
    uint8_t level;
    uint16_t diffDiv;
    uint16_t diff;
} tickCnt;

/* Current screen image */
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

static void dummyCB(uint16_t n)
{}

/**
 * @brief       Initialize the game user interface.
 */
void gameui_init(void)
{
    glcdInit();
    adc_setCallbacks(&rand_feed, &dummyCB);
    wiiUserInit(&buttonCB, &accelCB);
   
    /* Initialize the structs */
    wiimote.triedConnect = 0;
    wiimote.status = DISCONNECTED;
    wiimote.triedSetAcc = 0;
    wiimote.accStatus = 0;
    screenDynamics.yShift = glcdGetYShift();;
    
    PORTK = 0;
    DDRK = 0xff; 
    PORTL = 0;
    DDRL = 0xff; 
}

uint8_t gameui_start(game_state_t *game_state)
{
    PORTK = 1;
    if (INIT == gameStates.start)
    {
        gameStates.last = START;
        glcdFillScreen(GLCD_CLEAR);
        displayStartText(10);
        gameStates.start = WAIT;
    }
    if (WAIT == gameStates.start)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_A & input.buttons)
            *game_state = SELECTPLAYER;
        else if (BUTTON_B & input.buttons)
            *game_state = HIGHSCORE;

        if (START != *game_state)
        {
            gameStates.start = INIT;
            input.buttons = 0;
        }
    }

    return 0;
}

uint8_t gameui_connect(game_state_t *game_state)
{
    PORTK = 2;
    if (INIT == gameStates.connect)
    {
        glcdFillScreen(GLCD_CLEAR);
        displayConnectText(10);
        gameStates.connect = WAIT;
    }
    if (WAIT == gameStates.connect)
    {
        if (wiimote.triedConnect == 0)
        {
            wiiUserConnect(0, mac, &connectCB);
            wiimote.triedConnect = 1;
        }

        if (CONNECTED == wiimote.status)
        {
            adc_init();
            *game_state = gameStates.last;
            gameStates.connect = INIT;
            input.buttons = 0;
        }
    }
    screenDynamics.yShift = glcdGetYShift();;

    return 0;
}

uint8_t gameui_selectPlayer(game_state_t *game_state)
{
    uint8_t lastPlayer;
    PORTK = 4;

    if (INIT == gameStates.selectPlayer)
    {
        gameStates.last = SELECTPLAYER;
        glcdFillScreen(GLCD_CLEAR);
        displaySelectPlayerText(10);
        moveSelector(0, 0);
        playerData.currPlayer = 0;
        gameStates.selectPlayer = WAIT;
    }
    if (WAIT == gameStates.selectPlayer)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_A & input.buttons)
            *game_state = PLAY;
        else if (BUTTON_U & input.buttons)
        {
            lastPlayer = playerData.currPlayer;
            if (playerData.currPlayer == 0)
                playerData.currPlayer = PLAYERNUM-1;
            else
                playerData.currPlayer--;
            moveSelector(lastPlayer, playerData.currPlayer);
            input.buttons &= ~BUTTON_U;
        }
        else if (BUTTON_D & input.buttons)
        {
            lastPlayer = playerData.currPlayer;
            if (playerData.currPlayer == PLAYERNUM-1)
                playerData.currPlayer = 0;
            else
                playerData.currPlayer++;
            moveSelector(lastPlayer, playerData.currPlayer);
            input.buttons &= ~BUTTON_D;
        }

        if (SELECTPLAYER != *game_state)
        {
            gameStates.selectPlayer = INIT;
            input.buttons = 0;
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
//TODO make function shorter!!! max 100 lines
uint8_t gameui_play(game_state_t *game_state)
{   
    PORTK = 8;
    if (SETUP == gameStates.play)
    {
        //TODO fsm sometimes gets stuck here
        PORTL ^= 1;
        gameStates.last = PLAY;
        gameStates.next = PLAY;
        if (wiimote.accStatus == 1)
        {
            glcdFillScreen(GLCD_CLEAR);
            initLevel();
            input.buttons = 0;
            gameStates.play = UPDATE;
        }
        else
        {
            wiimote.triedSetAcc = 1;
            wiiUserSetAccel(0, 1, &setAccelCB);   
        }
    }
    if (UPDATE == gameStates.play)
    {
        PORTL = 2;
        if (tickCnt.scroll >= tickCnt.scrollDiv)
        {
            gameStates.play = SCROLL;
            tickCnt.scroll = 0;
        }
        else
            tickCnt.scroll++;
        
        if (tickCnt.score == TICKS_PER_SCORE-1)
        {
            playerData.currScore++;
            tickCnt.score = 0;
        }
        else
            tickCnt.score++;
        
        if (tickCnt.diff == tickCnt.diffDiv && tickCnt.scrollDiv > 1)
        {
            tickCnt.scrollDiv--;
            tickCnt.diffDiv += TICKS_PER_DIFF;
            tickCnt.diff = 0;
        }
        else
            tickCnt.diff++;

        clearBall();
        screenDynamics.ballDynamics.xAcc = ballAcc(input.accX, input.accY);
        if (updateBallPos() == 1)
        {
            gameStates.play = NEXT;
            gameStates.next = GAMEOVER;
        }
        drawBall();
    } 
    if (SCROLL == gameStates.play)
    {
        PORTL = 4;
        if (tickCnt.level == WALL_GAP)
        {
            gameStates.play = LEVEL;
            tickCnt.level = 0;
        }
        else
        {
            gameStates.play = NEXT;
            tickCnt.level++;
        }

        scrollScreen();
    }
    if (LEVEL == gameStates.play)
    {
        PORTL = 8;
        gameStates.play = NEXT;
        clearWall(screenImage.topWall);
        displayNewWall(BOTTOM);
    }
    if (NEXT == gameStates.play)
    {
        if (PLAY == gameStates.next)
        {
            PORTL = 16;
            if (DISCONNECTED == wiimote.status)
                gameStates.next = CONNECT;
            else if (BUTTON_A & input.buttons)
                gameStates.next = START;
            else if (BUTTON_B & input.buttons)
                gameStates.next = PAUSE;
        } 
        if (PLAY != gameStates.next)
        {
            //TODO app gets stuck here sometimes
            PORTL ^= 32;
            if (wiimote.accStatus == 0)
            {
                /* New highscore entry */
                if ((GAMEOVER == gameStates.next ||
                     START == gameStates.next) &&
                    playerData.currScore > playerData.highScore[playerData.currPlayer])
                    playerData.highScore[playerData.currPlayer] = playerData.currScore;
                
                *game_state = gameStates.next;
                gameStates.play = SETUP;
                input.buttons = 0;
            }
            else
            {
                wiimote.triedSetAcc = 1;
                wiiUserSetAccel(0, 0, &setAccelCB);   
            }
        }
        else
            gameStates.play = UPDATE;
    }
    
    return 0;
}

uint8_t gameui_pause(game_state_t *game_state)
{
    PORTK = 16;
    if (INIT == gameStates.pause)
    {
        gameStates.last = PAUSE;
        glcdFillScreen(GLCD_CLEAR);
        displayPauseText(10);
        gameStates.pause = WAIT;
    }
    if (WAIT == gameStates.pause)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_A & input.buttons)
            *game_state = START;
        else if (BUTTON_B & input.buttons)
            *game_state = PLAY;

        if (PAUSE != *game_state)
        {
            gameStates.pause = INIT;
            input.buttons = 0;
        }
    }

    return 0;
}

uint8_t gameui_gameOver(game_state_t *game_state)
{
    PORTK = 32;
    if (INIT == gameStates.gameOver)
    {
        gameStates.last = GAMEOVER;
        glcdFillScreen(GLCD_CLEAR);
        displayGameOverText(10);
        gameStates.gameOver = WAIT;
    }
    if (WAIT == gameStates.gameOver)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_A & input.buttons)
            *game_state = START;
        else if (BUTTON_B & input.buttons)
            *game_state = HIGHSCORE;

        if (GAMEOVER != *game_state)
        {
            gameStates.gameOver = INIT;
            input.buttons = 0;
        }
    }
    
    return 0;
}

uint8_t gameui_highScore(game_state_t *game_state)
{
    PORTK = 64;
    if (INIT == gameStates.highScore)
    {
        gameStates.last = HIGHSCORE;
        glcdFillScreen(GLCD_CLEAR);
        displayHighScoreText(10);
        gameStates.highScore = WAIT;
    }
    if (WAIT == gameStates.highScore)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_A & input.buttons)
            *game_state = START;

        if (HIGHSCORE != *game_state)
        {
            gameStates.highScore = INIT;
            input.buttons = 0;
        }
    }

    return 0;
}

static void buttonCB(uint8_t wii, uint16_t buttonStates)
{
    if ((buttonStates & BUTTON_1_WII) && !(input.buttons & BUTTON_1))
        input.buttons |= BUTTON_1;
    if ((buttonStates & BUTTON_2_WII) && !(input.buttons & BUTTON_2))
        input.buttons |= BUTTON_2;
    if ((buttonStates & BUTTON_A_WII) && !(input.buttons & BUTTON_A))
        input.buttons |= BUTTON_A;
    if ((buttonStates & BUTTON_B_WII) && !(input.buttons & BUTTON_B))
        input.buttons |= BUTTON_B;
    if ((buttonStates & BUTTON_L_WII) && !(input.buttons & BUTTON_L))
        input.buttons |= BUTTON_L;
    if ((buttonStates & BUTTON_R_WII) && !(input.buttons & BUTTON_R))
        input.buttons |= BUTTON_R;
    if ((buttonStates & BUTTON_D_WII) && !(input.buttons & BUTTON_D))
        input.buttons |= BUTTON_D;
    if ((buttonStates & BUTTON_U_WII) && !(input.buttons & BUTTON_U))
        input.buttons |= BUTTON_U;
}

static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z)
{
    input.accX = x>>2;
    input.accY = y>>1;
    input.accZ = z>>1;
}

static void connectCB(uint8_t wii, connection_status_t status)
{
    wiimote.status = status;
    wiimote.triedConnect = 0;
}

static void setAccelCB(uint8_t wii, error_t status)
{
//    if (wiimote.accEn == 1)
//        wiimote.accStatus = 1;
//    if (wiimote.accEn == 0)
//        wiimote.accStatus = 0;

    wiimote.accStatus = !wiimote.accStatus;
    wiimote.triedSetAcc = 0;
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
    sprintf(hsStr+8, " %ul", playerData.highScore[0]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_2);
    sprintf(hsStr+8, " %ul", playerData.highScore[1]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_3);
    sprintf(hsStr+8, " %ul", playerData.highScore[1]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_4);
    sprintf(hsStr+8, " %ul", playerData.highScore[3]);
    glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+10) & (Y_HEIGHT-1);
    memset(hsStr, 0, 15);
    strcpy_P(hsStr, player_5);
    sprintf(hsStr+8, " %ul", playerData.highScore[4]);
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

    tickCnt.scrollDiv = TICKS_PER_SCROLL-1;
    tickCnt.scroll = TICKS_PER_SCROLL-1;
    tickCnt.diffDiv = TICKS_PER_DIFF-1;
    tickCnt.diff = 0;
    tickCnt.score = TICKS_PER_SCROLL-1;
    tickCnt.level = WALL_GAP;

    playerData.currScore = 0;
}

static void moveSelector(uint8_t curr, uint8_t next)
{
    xy_point selector;
    
    selector.x = 4;
    selector.y = SELECTOR_Y_START+screenDynamics.yShift+10*curr; 
    glcdDrawCircle(selector, SELECTOR_RADIUS, &glcdClearPixel);
    selector.y = SELECTOR_Y_START+screenDynamics.yShift+10*next; 
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

