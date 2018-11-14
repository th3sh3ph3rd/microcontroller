/**
 *
 * @file hal_glcd.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-13
 *
 * Implementation of the glcd driver.
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define GLCD_CTRL_PORT      PORTE
#define GLCD_CTRL_DDR       DDRE
#define GLCD_CTRL_RS        PE4
#define GLCD_CTRL_RW        PE5
#define GLCD_CTRL_EN        PE6
#define GLCD_CTRL_CS0       PE2
#define GLCD_CTRL_CS1       PE3
#define GLCD_CTRL_RESET     PE7

#define GLCD_DATA_PORT      PORTA
#define GLCD_DATA_DDR       DDRA
#define GLCD_DATA_PIN       PINA
#define GLCD_DATA_BUSY      PA7

#define GLCD_CONTROLLER_0   0
#define GLCD_CONTROLLER_1   1
#define GLCD_CONTROLLER_B   2

#define GLCD_CMD_ON         0x3f
#define GLCD_CMD_OFF        0x3e
#define GLCD_CMD_SET_ADDR   0x40
#define GLCD_CMD_SET_PAGE   0xb8
#define GLCD_CMD_DISP_START 0xc0

#define GCLD_RESET_US       1

#define MAX_X_CHIP  64
#define MAX_X       128
#define MAX_Y       64

#define busy_wait_enable()      \
        __asm__ __volatile__ (  \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t" ::)

#define enable() { \
        GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_EN); \
        busy_wait_enable(); \
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_EN); \
        busy_wait_enable(); } \

static struct
{
    uint8_t x;
    uint8_t y;
    uint8_t controller;
    uint8_t yShift;
} internalAddr;

//TODO if selecting both controllers is ebnabled, busyWait has to be
//called for each controller and afterwards BOTH controllers have to be selected

static void halGlcdCtrlWriteData(const uint8_t controller,
                                 const uint8_t data);
static uint8_t halGlcdCtrlReadData(const uint8_t controller);
static void halGlcdCtrlWriteCmd(const uint8_t controller,
                                const uint8_t data);
static void halGlcdCtrlSetAddress(const uint8_t controller,
                                  const uint8_t x
                                  const uint8_t y);
static void halGlcdCtrlBusyWait(const uint8_t controller);
static void halGlcdCtrlSelect(const uint8_t controller);

/**
 * @brief       Initialize the glcd driver.
 */
uint8_t halGlcdInit(void)
{
    GLCD_DATA_PORT = 0;
    GLCD_DATA_DDR = 0xff;
    GLCD_CTRL_PORT &= ~0xfc;
    GLCD_CTRL_DDR |= 0xfc;

    /* Perform reset */
    __delay_us(GLCD_RESET_US);
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RESET);

    //TODO select both controllers
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_0, GLCD_CMD_ON);
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_1, GLCD_CMD_ON);

    halGlcdSetYShift(0);

    //TODO erase ram?

    halGlcdSetAddress(0, 0);
}

/**
 * @brief       Set the internal address.
 * @param xCol  X column.
 * @param yPage Y page.
 */
uint8_t halGlcdSetAddress(const uint8_t xCol,
                          const uint8_t yPage)
{
    internalAddr.x = x;
    internalAddr.y = y;
    
    if (xCol < MAX_X_CHIP)
       internalAddr.controller = GLCD_CONTROLLER_0;
    else
       internalAddr.controller = GLCD_CONTROLLER_1;

    halGlcdCtrlSetAddress(internalAddr.y, internalAddr.x & (MAX_X_CHIP-1),
                          internalAddr.controller);
}

/**
 * @brief       Write data to the RAM at the currently set address. The x address is post-incremented.
 * @param data  The data.
 */
uint8_t halGlcdWriteData(const uint8_t data)
{
    halGlcdCtrlWriteData(internalAddr.controller, data);

    if (internalAddr.x == MAX_X_CHIP-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_1;
        halGlcdCtrlSetAddress(internalAddr.y, 0, internalAddr.controller);
    }
    else if (internalAddr.x == MAX_X-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_0;
        halGlcdCtrlSetAddress(internalAddr.y, 0, internalAddr.controller);
    }

    halGlcdCtrlSetAddress(internalAddr.y, 0, internalAddr.controller);
    internalAddr = (internalAddr+1) & (MAX_X-1);
}

/**
 * @brief       Read data from the RAM at the currently set address. The x address is post incremented.
 * @return      The data.
 */
uint8_t halGlcdReadData(void)
{
    uint8_t data = halGlcdCtrlReadData(internalAddr.controller);

    if (internalAddr.x == MAX_X_CHIP-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_1;
        halGlcdCtrlSetAddress(internalAddr.y, 0, internalAddr.controller);
    }
    else if (internalAddr.x == MAX_X-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_0;
        halGlcdCtrlSetAddress(internalAddr.y, 0, internalAddr.controller);
    }

    internalAddr = (internalAddr+1) & (MAX_X-1);
    
    return data;
}

/**
 * @brief           Set the display row address displayed at the top of the screen.
 * @param yShift    The y-shift address.
 */
uint8_t halGlcdSetYShift(uint8_t yShift)
{
    //TODO select both controllers
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_0, GLCD_CMD_DISP_START | (yShift & (MAX_Y-1)));
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_1, GLCD_CMD_DISP_START | (yShift & (MAX_Y-1)));

    internalAddr.yShift = yShift & (MAX_Y-1);
}

/**
 * @brief       Get the display row address displayed at the top of the screen.
 * @return      The y-shift address.
 */
uint8_t halGlcdGetYShift(void)
{
    return internalAddr.yShift;
}

/*
 * @brief               Writes one byte of data to the selected RAM controller(s).
 * @param controller    The selected controller(s).
 * @param data          The data byte to write.
 */
static void halGlcdCtrlWriteData(const uint8_t controller,
                                 const uint8_t data)
{
    /* Prepare for write access */
    halGlcdCtrlBusyWait(controller); //Chip is already selected in this function
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RS);
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_RW);
    
    GLCD_DATA_PORT = data;
    enable(); 
}

/*
 * @brief               Read one byte of data.
 * @param controller    The selected controller(s).
 * @return              The read byte.
 */
static uint8_t halGlcdCtrlReadData(const uint8_t controller)
{
    uint8_t data;
    
    /* Prepare for read access */
    halGlcdCtrlBusyWait(controller); //Chip is already selected in this function
    GLCD_DATA_DDR = 0;
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RS)|(1<<GLCD_CTRL_RW);
    enable();
    
    data = GLCD_DATA_PIN;

    GLCD_DATA_DDR = 0xff;

    return data;
}

static void halGlcdCtrlWriteCmd(const uint8_t controller,
                                const uint8_t data)
{
    /* Prepare for writing a command */
    halGlcdCtrlBusyWait(controller); //Chip is already selected in this function
    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_RS)|(1<<GLCD_CTRL_RW));
    
    GLCD_DATA_PORT = data;
    enable(); 
}

/*
 * @brief               Set x and y RAM address on the selected controller(s).
 * @param controller    The controller(s) to check.
 * @param x             The page number.
 * @param y             The address.
 */
static void halGlcdCtrlSetAddress(const uint8_t controller,
                                  const uint8_t x,
                                  const uint8_t y)
{
    halGlcdCtrlWriteCmd(GLCD_CMD_SET_PAGE | x);
    halGlcdCtrlWriteCmd(GLCD_CMD_SET_ADDR | y);
}

/*
 * @brief               Check if the controller is busy and wait until it is ready.
 * @param controller    The controller(s) to check.
 */
static void halGlcdCtrlBusyWait(const uint8_t controller)
{
    halGlcdCtrlSelect(controller);

    /* Set busy pin to input */
    GLCD_DATA_DDR &= ~(1<<GLCD_DATA_BUSY);
    /* Prepare for read access */
    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_EN)|(1<<GLCD_CTRL_RS));
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RW);

    busy_wait_enable();

    /* Wait until busy line is low */
    uint8_t busy;
    do
    {
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_EN);
        busy_wait_enable();

        busy = GLCD_DATA_PIN & (1<<GLCD_DATA_BUSY);

        GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_EN);
        busy_wait_enable();
    }
    while(busy != 0);

    /* Restore initial pin states */
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RS);
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_RW);
    GLCD_DATA_DDR |= (1<<GLCD_DATA_BUSY);
}

/*
 * @brief               Select the desired RAM controller(s).
 * @param controller    The desired controller(s) (_0, _1, or _B for both).
 */
//TODO enable both controllers
static void halGlcdCtrlSelect(const uint8_t controller)
{
    if (GLCD_CONTROLLER_0 == controller)
    {
        GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_CS1);
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_CS0);
    }
    else if (GLCD_CONTROLLER_1 == controller)
    {
        GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_CS0);
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_CS1);
    }
    /*else if (GLCD_CONTROLLER_B == controller)
    {
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_CS0);
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_CS1);
    }*/
}

