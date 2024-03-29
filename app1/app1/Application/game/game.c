/**
 *
 * @file game.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-13
 *
 * Implementation of the falling down ball game.
 *
 */

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <glcd.h>
#include <Standard5x7.h>
#include <wii_user.h>
#include <adc.h>
#include <rand.h>
#include <timer.h>
#include <music.h>
#include <data.h>
#include <mac.h>
#include <task.h>
#include <game.h>

#define X_WIDTH     128
#define Y_HEIGHT    64
#define TOP         0
#define BOTTOM      Y_HEIGHT-1

/* Wii button encoding */
#define BUTTON_2_WII    0x01
#define BUTTON_1_WII    0x02
#define BUTTON_B_WII    0x04
#define BUTTON_A_WII    0x08
#define BUTTON_H_WII    0x80
#define BUTTON_L_WII    (0x01<<8)
#define BUTTON_R_WII    (0x02<<8)
#define BUTTON_D_WII    (0x04<<8)
#define BUTTON_U_WII    (0x08<<8)

/* Local button encoding */
#define BUTTON_1    0x01
#define BUTTON_2    0x02
#define BUTTON_A    0x04
#define BUTTON_B    0x08
#define BUTTON_H    0x10
#define BUTTON_D    0x20
#define BUTTON_U    0x40

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
#define TICK_PERIOD_MS      30
#define TICKS_PER_SCROLL    9
#define TICKS_PER_SCORE     5
#define TICKS_PER_DIFF      100
#define MAX_DIFFICULTY      2
#define WALL_GAP            15
#define BALL_RADIUS         2
#define GRAVITY             1
#define PLAYERNUM           5
#define SELECTOR_RADIUS     2
#define SELECTOR_Y_START    6
#define LINE_SPACING        10
#define LINE_MARGIN         10

typedef enum {START, CONNECT, SELECTPLAYER, PLAY, GAMEOVER, HIGHSCORE} game_state_t;
typedef enum {INIT, WAIT} static_state_t;
typedef enum {SETUP, UPDATE, SCROLL, LEVEL, NEXT} tick_state_t;

/* Interrupt flags */
static struct
{
    volatile task_state_t game;
    volatile task_state_t music;
} workLeft;

/* State variables */
static struct
{
    game_state_t next;
    static_state_t start:1;
    static_state_t connect:1;
    static_state_t selectPlayer:1;
    static_state_t gameOver:1;
    static_state_t highScore:1;
    tick_state_t play;
} gameStates;

/* Wiimote status flags */
static struct
{
    uint8_t triedConnect:1;
    connection_status_t status:1;
    uint8_t triedSetAcc:1;
    uint8_t accStatus:1;
} wiimote;

/* Wiimote sensor values */
static struct
{
    uint8_t buttons;
    uint8_t accX;
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
struct highScoreEntry
{
    int8_t player;
    uint16_t score;
};
static struct
{
    uint8_t currPlayer;
    uint16_t currScore;
    struct highScoreEntry highScore[PLAYERNUM];
} playerData;

/* Connect screen animation figure */
#define CONNECT_FRAMES 2
#define CONNECT_FRAME_MS 350
uint8_t currFrame;

/* Callback functions */
static void gameTimerCB(void);
static void musicCB(void);
static void buttonCB(uint8_t wii, uint16_t buttonStates);
static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z);
static void connectCB(uint8_t wii, connection_status_t status);
static void setAccelCB(uint8_t wii, error_t status);
static void connectAnimCB(void);

/* Local functions */
static task_state_t start(game_state_t *game_state);
static task_state_t connect(game_state_t *game_state);
static task_state_t selectPlayer(game_state_t *game_state);
static task_state_t play(game_state_t *game_state);
static task_state_t gameOver(game_state_t *game_state);
static task_state_t highScore(game_state_t *game_state);
static void displayStartText(uint8_t y_top);
static void displayConnectText(uint8_t y_top);
static void displaySelectPlayerText(uint8_t y_top);
static void displayGameOverText(uint8_t y_top);
static void displayHighScoreText(uint8_t y_top);
static void initLevel(void);
static void moveSelector(uint8_t curr, uint8_t next);
static void playUpdate(void);
static void playScroll(void);
static void displayNewWall(uint8_t yOff);
static void drawWall(uint8_t wall);
static void clearWall(uint8_t wall);
static void calcBallAcc(void);
static uint8_t updateBallPos(void);
static void drawBall(void);
static void clearBall(void);
static void enterHighScore(void);

/**
 * @brief       Initialize the game user interface.
 */
void game_init(void)
{
    glcdInit();
    music_init(&musicCB);
    adc_setCallbacks(&rand_feed, &music_setVolume);
    adc_init();
    while (wiiUserInit(&buttonCB, &accelCB) != SUCCESS); 
    
    /* Initialize the structs */
    wiimote.triedConnect = 0;
    wiimote.status = DISCONNECTED;
    wiimote.triedSetAcc = 0;
    wiimote.accStatus = 0;
    screenDynamics.yShift = glcdGetYShift();

    for (uint8_t p = 0; p < PLAYERNUM; p++)
    {
        playerData.highScore[p].player = -1;
        playerData.highScore[p].score = 0;
    }

    workLeft.game = 0;
    workLeft.music = 0;
 
    sei();
}

/*
 * @brief       Run the game. This procedure switches between the music and game tasks.
 */
void game_run(void)
{
    game_state_t game_state = START;

    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();

    timer_startTimer1(TICK_PERIOD_MS, TIMER_REPEAT, &gameTimerCB);

    for (;;)
    {
        do
        {
            if (workLeft.game != DONE)
            {
                if (START == game_state)
                    workLeft.game = start(&game_state);
                else if (CONNECT == game_state)
                    workLeft.game = connect(&game_state);
                else if (SELECTPLAYER == game_state)
                    workLeft.game = selectPlayer(&game_state);
                else if (PLAY == game_state)
                    workLeft.game = play(&game_state);
                else if (GAMEOVER == game_state)
                    workLeft.game = gameOver(&game_state);
                else if (HIGHSCORE == game_state)
                    workLeft.game = highScore(&game_state);

            }
            if (workLeft.music != DONE)
                workLeft.music = music_play();

        } while (workLeft.game != DONE || workLeft.music != DONE);

        sleep_cpu();
    }
}

/*
 * @brief               Display the start screen of the game.
 * @param game_state    Contains the next state after the procedure call.
 * @return              The task state is returned, either DONE or BUSY.
 */
static task_state_t start(game_state_t *game_state)
{
    if (INIT == gameStates.start)
    {
        glcdFillScreen(GLCD_CLEAR);
        displayStartText(LINE_SPACING);
        gameStates.start = WAIT;
        return BUSY;
    }
    if (WAIT == gameStates.start)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_1 & input.buttons)
            *game_state = SELECTPLAYER;
        else if (BUTTON_2 & input.buttons)
            *game_state = HIGHSCORE;

        if (START != *game_state)
        {
            gameStates.start = INIT;
            input.buttons = 0;
        }
    }

    return DONE;
}

/*
 * @brief               Display the connect screen of the game and waits
 *                      for a successful wiimote connection.
 * @param game_state    Contains the next state after the procedure call.
 * @return              Returns DONE.
 */
static task_state_t connect(game_state_t *game_state)
{
    if (INIT == gameStates.connect)
    {
        glcdFillScreen(GLCD_CLEAR);
        displayConnectText(LINE_SPACING);
        gameStates.connect = WAIT;
        wiimote.accStatus = 0;
        wiimote.triedSetAcc = 0;
        timer_startTimer3(CONNECT_FRAME_MS, TIMER_REPEAT, &connectAnimCB);
        return BUSY;
    }
    if (WAIT == gameStates.connect)
    {
        if (wiimote.triedConnect == 0)
        {
            if(wiiUserConnect(0, mac_address, &connectCB) == SUCCESS)
                wiimote.triedConnect = 1;
        }

        if (CONNECTED == wiimote.status)
        {
            timer_stopTimer3();
            *game_state = START;
            gameStates.connect = INIT;
            input.buttons = 0;
        }
    }

    return DONE;
}

/*
 * @brief               Lets the user select a player.
 * @param game_state    Contains the next state after the procedure call.
 * @return              The task state is returned, either DONE or BUSY.
 */
static task_state_t selectPlayer(game_state_t *game_state)
{
    uint8_t lastPlayer;

    if (INIT == gameStates.selectPlayer)
    {
        glcdFillScreen(GLCD_CLEAR);
        displaySelectPlayerText(LINE_SPACING);
        moveSelector(0, 0);
        playerData.currPlayer = 0;
        gameStates.selectPlayer = WAIT;
        return BUSY;
    }
    if (WAIT == gameStates.selectPlayer)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_A & input.buttons)
            *game_state = PLAY;
        else if (BUTTON_B & input.buttons)
            *game_state = START;
        /* Move cursor up */
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
        /* Move cursor down */
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

    return DONE;
}

/*
 * @brief               The main game function. Takes user input and updates
 *                      the screen accordingly.
 * @param game_state    Contains the next state after the procedure call.
 * @return              The task state is returned, either DONE or BUSY.
 */
static task_state_t play(game_state_t *game_state)
{   
    if (SETUP == gameStates.play)
    {
        gameStates.next = PLAY;
        if (wiimote.accStatus == 1)
        {
            glcdFillScreen(GLCD_CLEAR);
            initLevel();
            input.buttons = 0;
            gameStates.play = UPDATE;
        }
        /* Enable accelerometer */
        else if (wiimote.triedSetAcc == 0)
        {
            if (wiiUserSetAccel(0, 1, &setAccelCB) == SUCCESS)
                wiimote.triedSetAcc = 1;
        }
        return BUSY;
    }
    if (UPDATE == gameStates.play)
    {
        playUpdate();
        return BUSY;
    } 
    if (SCROLL == gameStates.play)
    {
        playScroll();
        return BUSY;
    }
    if (LEVEL == gameStates.play)
    {
        gameStates.play = NEXT;
        clearWall(screenImage.topWall);
        displayNewWall(BOTTOM);
        return BUSY;
    }
    if (NEXT == gameStates.play)
    {
        if (PLAY == gameStates.next)
        {
            if (DISCONNECTED == wiimote.status)
                gameStates.next = CONNECT;
            else if (BUTTON_H & input.buttons)
                gameStates.next = START;
        } 
        if (PLAY != gameStates.next)
        {
            if (wiimote.accStatus == 0 || CONNECT == gameStates.next)
            {
                /* New highscore entry */
                enterHighScore();
                
                *game_state = gameStates.next;
                gameStates.play = SETUP;
                input.buttons = 0;
            }
            /* Disable accelerometer */
            else if (wiimote.triedSetAcc == 0)
            {
                if (wiiUserSetAccel(0, 0, &setAccelCB) == SUCCESS)
                    wiimote.triedSetAcc = 1;
            }
        }
        else
            gameStates.play = UPDATE;
    }
   
    return DONE;
}

/*
 * @brief               Displays the game over message.
 * @param game_state    Contains the next state after the procedure call.
 * @return              The task state is returned, either DONE or BUSY.
 */
static task_state_t gameOver(game_state_t *game_state)
{
    if (INIT == gameStates.gameOver)
    {
        glcdFillScreen(GLCD_CLEAR);
        displayGameOverText(LINE_SPACING);
        gameStates.gameOver = WAIT;
        return BUSY;
    }
    if (WAIT == gameStates.gameOver)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_H & input.buttons)
            *game_state = START;
        else if (BUTTON_2 & input.buttons)
            *game_state = HIGHSCORE;

        if (GAMEOVER != *game_state)
        {
            gameStates.gameOver = INIT;
            input.buttons = 0;
        }
    }
    
    return DONE;
}

/*
 * @brief               Diplays the current highscore table (max. 5 entries).
 * @param game_state    Contains the next state after the procedure call.
 * @return              The task state is returned, either DONE or BUSY.
 */
static task_state_t highScore(game_state_t *game_state)
{
    if (INIT == gameStates.highScore)
    {
        glcdFillScreen(GLCD_CLEAR);
        displayHighScoreText(LINE_SPACING);
        gameStates.highScore = WAIT;
        return BUSY;
    }
    if (WAIT == gameStates.highScore)
    {
        if (DISCONNECTED == wiimote.status)
            *game_state = CONNECT;
        else if (BUTTON_H & input.buttons)
            *game_state = START;

        if (HIGHSCORE != *game_state)
        {
            gameStates.highScore = INIT;
            input.buttons = 0;
        }
    }

    return DONE;
}

/*
 * @brief   Callback function for the main game timer. Set a flag on interrupt.
 */
static void gameTimerCB(void)
{
    workLeft.game = 1;
}

/*
 * @brief   Callback function for the mp3 module. Set a flag on interrupt.
 */
static void musicCB(void)
{
    workLeft.music = 1;
}

/*
 * @brief   Callback function for the wiimote buttons.
 */
static void buttonCB(uint8_t wii, uint16_t buttonStates)
{
    (void) wii;

    if (buttonStates & BUTTON_A_WII)
        input.buttons |= BUTTON_A;
    if (buttonStates & BUTTON_B_WII)
        input.buttons |= BUTTON_B;
    if (buttonStates & BUTTON_1_WII)
        input.buttons |= BUTTON_1;
    if (buttonStates & BUTTON_2_WII)
        input.buttons |= BUTTON_2;
    if (buttonStates & BUTTON_H_WII)
        input.buttons |= BUTTON_H;
    if (buttonStates & BUTTON_D_WII)
        input.buttons |= BUTTON_D;
    if (buttonStates & BUTTON_U_WII)
        input.buttons |= BUTTON_U;
}

/*
 * @brief   Callback function for the wiimote accelerometer.
 */
static void accelCB(uint8_t wii, uint16_t x, uint16_t y, uint16_t z)
{
    (void) wii;
    (void) y;
    (void) z;

    input.accX = x>>2;
}

/*
 * @brief   Callback function for enabling/disabling the wiimote accelerometer.
 */
static void connectCB(uint8_t wii, connection_status_t status)
{
    (void) wii;
    
    wiimote.status = status;
    wiimote.triedConnect = 0;
}

/*
 * @brief   Callback function for enabling/disabling the wiimote accelerometer.
 */
static void setAccelCB(uint8_t wii, error_t status)
{
    (void) wii;
    (void) status;
    
    wiimote.accStatus = !wiimote.accStatus;
    wiimote.triedSetAcc = 0;
}

/*
 * @brief   Display a little animation on the connect screen.
 */
static void connectAnimCB(void)
{
    struct connectFrame frame;
    memcpy_P(&frame, &data_connectFrames[currFrame], sizeof(struct connectFrame));
    glcdDrawLine(frame.l0p0,
                 frame.l0p1,
                 &glcdClearPixel);
    glcdDrawLine(frame.l1p0,
                 frame.l1p1,
                 &glcdClearPixel);
    currFrame = !currFrame;
    memcpy_P(&frame, &data_connectFrames[currFrame], sizeof(struct connectFrame));
    glcdDrawLine(frame.l0p0,
                 frame.l0p1,
                 &glcdSetPixel);
    glcdDrawLine(frame.l1p0,
                 frame.l1p1,
                 &glcdSetPixel);
}

/*
 * @brief   Display the text for the start screen.
 * @param y The y coordinate of the top line.
 */
static void displayStartText(uint8_t yTop)
{
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = LINE_MARGIN;

    glcdDrawTextPgm(data_game_name, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    glcdDrawTextPgm(data_play_b, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    glcdDrawTextPgm(data_highscore_b, startPoint, &Standard5x7, &glcdSetPixel);
}

/*
 * @brief   Display the text for the connect screen.
 * @param y The y coordinate of the top line.
 */
static void displayConnectText(uint8_t yTop)
{
    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = LINE_MARGIN;

    glcdDrawTextPgm(data_connecting, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    glcdDrawTextPgm(data_towiimote, startPoint, &Standard5x7, &glcdSetPixel);
}

/*
 * @brief   Display the text for the select player screen.
 * @param y The y coordinate of the top line.
 */
static void displaySelectPlayerText(uint8_t yTop)
{
    uint8_t slen = strlen_P(data_player);
    char plStr[slen+2];

    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = LINE_MARGIN;

    for (uint8_t p = 0; p < PLAYERNUM; p++)
    {
        memset(plStr, 0, slen+2);
        strcpy_P(plStr, data_player);
        sprintf(plStr+slen, "%u", p+1);
        glcdDrawText(plStr, startPoint, &Standard5x7, &glcdSetPixel);
        startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    }
    
    glcdDrawTextPgm(data_select_b, startPoint, &Standard5x7, &glcdSetPixel);
}

/*
 * @brief   Display the text for the game over screen.
 * @param y The y coordinate of the top line.
 */
static void displayGameOverText(uint8_t yTop)
{
    uint8_t slen = strlen_P(data_score);
    char goStr[slen+6];

    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = LINE_MARGIN;

    glcdDrawTextPgm(data_gameover, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    memset(goStr, 0, slen+6);
    strcpy_P(goStr, data_score);
    sprintf(goStr+slen, "%u", playerData.currScore);
    glcdDrawText(goStr, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    glcdDrawTextPgm(data_menu_b, startPoint, &Standard5x7, &glcdSetPixel);
    startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    glcdDrawTextPgm(data_highscore_b, startPoint, &Standard5x7, &glcdSetPixel);
}

/*
 * @brief   Display the current highscore table.
 * @param y The y coordinate of the top line.
 */
static void displayHighScoreText(uint8_t yTop)
{
    uint8_t slen = strlen_P(data_player);
    char hsStr[slen+9];

    xy_point startPoint;
    startPoint.y = (screenDynamics.yShift+yTop) & (Y_HEIGHT-1);
    startPoint.x = LINE_MARGIN;

    for (uint8_t p = 0; p < PLAYERNUM; p++)
    {
        if (playerData.highScore[p].player < 0)
            break;

        memset(hsStr, 0, slen+9);
        strcpy_P(hsStr, data_player);
        sprintf(hsStr+slen, "%d: %u", playerData.highScore[p].player+1, playerData.highScore[p].score);
        glcdDrawText(hsStr, startPoint, &Standard5x7, &glcdSetPixel);
        startPoint.y = (startPoint.y+LINE_SPACING) & (Y_HEIGHT-1);
    }
   
    startPoint.y = ((screenDynamics.yShift+yTop) & (Y_HEIGHT-1)) + LINE_SPACING*PLAYERNUM;
    glcdDrawTextPgm(data_menu_b, startPoint, &Standard5x7, &glcdSetPixel);
}

/*
 * @brief   Procedure to initialise the screen with the ball and a new random level.
 */
static void initLevel(void)
{
    uint8_t newWall;
    uint8_t yPos = 0;
    screenImage.topWall = 0;

    for (uint8_t w = 0; w < WALLS_ON_SCREEN; w++)
    {
        newWall = rand16() & (WALLS_AVAILABLE-1);
        /* Load new wall from PROGMEM */
        memcpy_P(&screenImage.walls[w].points,
                 &data_walls[newWall], WALL_POINTS);
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
    tickCnt.score = TICKS_PER_SCORE-1;
    tickCnt.level = WALL_GAP;

    playerData.currScore = 0;
}

/*
 * @brief       This function moves the selector on the select player screen.
 * @param curr  Currently selected player.
 * @param next  Next selected player.
 */
static void moveSelector(uint8_t curr, uint8_t next)
{
    xy_point selector;
    
    selector.x = 4;
    selector.y = SELECTOR_Y_START+screenDynamics.yShift+LINE_SPACING*curr; 
    glcdDrawCircle(selector, SELECTOR_RADIUS, &glcdClearPixel);
    selector.y = SELECTOR_Y_START+screenDynamics.yShift+LINE_SPACING*next; 
    glcdDrawCircle(selector, SELECTOR_RADIUS, &glcdSetPixel); 
}

/*
 * @brief   This procedure performs the necessary updates of a game tick.
 *          The scroll, score and difficulty counters are updated and the
 *          ball is moved to its new position.
 */
static void playUpdate(void)
{
    if (tickCnt.scroll >= tickCnt.scrollDiv)
    {
        gameStates.play = SCROLL;
        tickCnt.scroll = 0;
    }
    else
    {
        gameStates.play = NEXT;
        tickCnt.scroll++;
    }
    
    /* Update player score */
    if (tickCnt.score == TICKS_PER_SCORE-1)
    {
        playerData.currScore++;
        tickCnt.score = 0;
    }
    else
        tickCnt.score++;
    
    /* Increase game difficulty */
    if (tickCnt.diff == tickCnt.diffDiv && tickCnt.scrollDiv >= MAX_DIFFICULTY)
    {
        tickCnt.scrollDiv--;
        tickCnt.diffDiv = TICKS_PER_DIFF;
        tickCnt.diff = 0;
    }
    else
        tickCnt.diff++;

    calcBallAcc();
    clearBall();
    if (updateBallPos() == 1)
    {
        gameStates.play = NEXT;
        gameStates.next = GAMEOVER;
    }
    drawBall();
}

/*
 * @brief   This procedure performs the scrolling of the screen. The
 *          internally stored ball an wall positions are updated accordingly.
 */
static void playScroll(void)
{
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

    if (screenDynamics.yShift == Y_HEIGHT-1)
        screenDynamics.yShift = 0;
    else
        screenDynamics.yShift++;

    /* Adapt y position of walls and ball on shift */
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
    memcpy_P(&screenImage.walls[screenImage.topWall].points,
             &data_walls[newWall], WALL_POINTS);
    screenImage.walls[screenImage.topWall].yPos = yOff;

    drawWall(screenImage.topWall);

    if (screenImage.topWall == WALLS_ON_SCREEN-1)
        screenImage.topWall = 0;
    else
        screenImage.topWall++;
}

/*
 * @brief       Draws a level wall on the screen.
 * @param wall  The index of the wall in the screenImage.
 */
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

/*
 * @brief       Draws a level wall on the screen.
 * @param wall  The index of the wall in the screenImage.
 */
static void clearWall(uint8_t wall)
{
    xy_point point0, point1;

    point0.y = screenImage.walls[wall].yPos+screenDynamics.yShift;
    point1.y = screenImage.walls[wall].yPos+screenDynamics.yShift;
    point0.x = 0;
    point1.x = X_WIDTH-1;
    
    glcdDrawLine(point0, point1, &glcdClearPixel);
}

/*
 * @brief   Calculate the ball acceleration according to the accelerometer data.
 */
static void calcBallAcc(void)
{
    if (input.accX >= X_MID-ACC_DELTA && 
        input.accX <= X_MID+ACC_DELTA)
    {
       screenDynamics.ballDynamics.xAcc = 0;
       return;
    }

    if (input.accX > 0x81)
    {
        screenDynamics.ballDynamics.xAcc = 1;
        return;
    }

    screenDynamics.ballDynamics.xAcc = -1;
}

/*
 * @brief   This function performs collision detection for the ball and
 *          sets the balls next position accordingly.
 * @return  On game over 1 is returned, else 0.
 */
static uint8_t updateBallPos(void)
{
    uint8_t xCollisionL = 0;
    uint8_t xCollisionR = 0;
    uint8_t yCollision = 0;

    /* GAME OVER */
    if (screenImage.ball.y-BALL_RADIUS == TOP)
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
                /* Detect if a wall is being hit from the top */
                if (screenImage.walls[w].yPos == screenImage.ball.y+BALL_RADIUS+1)
                {
                    if (p == WALL_POINTS-1)
                    {
                        if (screenImage.walls[w].points[p] != X_WIDTH-1 &&
                            screenImage.walls[w].points[p] <= screenImage.ball.x+BALL_RADIUS)
                        {
                            yCollision = 1;
                            break;
                        }
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
                /* Detect if a wall is being hit from the side */
                if (p == WALL_POINTS-1)
                {
                    if (screenImage.walls[w].points[p] != X_WIDTH-1 &&
                        screenImage.walls[w].points[p] == screenImage.ball.x+BALL_RADIUS+1)
                    {
                        xCollisionR = 1;
                        break;
                    }
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

            break;
        }
    }

    if (screenImage.ball.x-BALL_RADIUS == 0)
        xCollisionL = 1;
    else if (screenImage.ball.x+BALL_RADIUS == X_WIDTH-1)
        xCollisionR = 1;

    if ((!xCollisionL && !xCollisionR) ||
        (xCollisionL && screenDynamics.ballDynamics.xAcc > 0) ||
        (xCollisionR && screenDynamics.ballDynamics.xAcc < 0))
        screenImage.ball.x += screenDynamics.ballDynamics.xAcc;

    if (!yCollision &&
        screenImage.ball.y+BALL_RADIUS < BOTTOM)
        screenImage.ball.y += screenDynamics.ballDynamics.yAcc;

    return 0;
}

/*
 * @brief   Draw the ball to the screen on its current position.
 */
static void drawBall(void)
{
    xy_point ball;
    ball.x = screenImage.ball.x;
    ball.y = screenImage.ball.y+screenDynamics.yShift;

    xy_point p0 = {ball.x-BALL_RADIUS, ball.y};
    xy_point p1 = {ball.x+BALL_RADIUS, ball.y}; 
    glcdDrawLine(p0, p1, &glcdSetPixel);

    for (uint8_t l = 1; l <= BALL_RADIUS; l++)
    {
        glcdDrawLine((xy_point) {ball.x+l-BALL_RADIUS-1, ball.y-l},
                     (xy_point) {ball.x-l+BALL_RADIUS+1, ball.y-l}, &glcdSetPixel);
        glcdDrawLine((xy_point) {ball.x+l-BALL_RADIUS-1, ball.y+l},
                     (xy_point) {ball.x-l+BALL_RADIUS+1, ball.y+l}, &glcdSetPixel);
    }
}

/*
 * @brief   Erase the ball from the screen.
 */
static void clearBall(void)
{
    xy_point ball;
    ball.x = screenImage.ball.x;
    ball.y = screenImage.ball.y+screenDynamics.yShift;
   
    xy_point p0 = {ball.x-BALL_RADIUS, ball.y};
    xy_point p1 = {ball.x+BALL_RADIUS, ball.y}; 
    glcdDrawLine(p0, p1, &glcdClearPixel);

    for (uint8_t l = 1; l <= BALL_RADIUS; l++)
    {
        glcdDrawLine((xy_point) {ball.x+l-BALL_RADIUS-1, ball.y-l},
                     (xy_point) {ball.x-l+BALL_RADIUS+1, ball.y-l}, &glcdClearPixel);
        glcdDrawLine((xy_point) {ball.x+l-BALL_RADIUS-1, ball.y+l},
                     (xy_point) {ball.x-l+BALL_RADIUS+1, ball.y+l}, &glcdClearPixel);
    }
}

/*
 * @brief   Check if the current score belongs in the highscore
 *          table and place it on the appropriate position.
 */
static void enterHighScore(void)
{
    int8_t p = PLAYERNUM-1;

    while (p >= 0 && playerData.currScore > playerData.highScore[p].score)
    {
        if (p == PLAYERNUM-1)
        {
            playerData.highScore[PLAYERNUM-1].player = playerData.currPlayer;
            playerData.highScore[PLAYERNUM-1].score = playerData.currScore;
        }
        else
        {
            playerData.highScore[p+1].player = playerData.highScore[p].player;
            playerData.highScore[p+1].score = playerData.highScore[p].score;
            playerData.highScore[p].player = playerData.currPlayer;
            playerData.highScore[p].score = playerData.currScore;
        }
        p--;
    }
}

