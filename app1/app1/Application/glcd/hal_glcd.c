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
#include <stdint.h>

#include <hal_glcd.h>

#define GLCD_CTRL_PORT      PORTE
#define GLCD_CTRL_DDR       DDRE
#define GLCD_CTRL_RS        PE4
#define GLCD_CTRL_RW        PE5
#define GLCD_CTRL_EN        PE6
#define GLCD_CTRL_CS0       PE3
#define GLCD_CTRL_CS1       PE2
#define GLCD_CTRL_RESET     PE7

#define GLCD_DATA_PORT      PORTA
#define GLCD_DATA_DDR       DDRA
#define GLCD_DATA_PIN       PINA

#define GLCD_STATUS_BUSY    PA7
#define GLCD_STATUS_DISP    PA5
#define GLCD_STATUS_RESET   PA4

#define GLCD_CONTROLLER_0   0
#define GLCD_CONTROLLER_1   1
#define GLCD_CONTROLLER_B   2

#define GLCD_CMD_ON         0x3f
#define GLCD_CMD_OFF        0x3e
#define GLCD_CMD_SET_ADDR   0x40
#define GLCD_CMD_SET_PAGE   0xb8
#define GLCD_CMD_DISP_START 0xc0

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

static void halGlcdCtrlWriteData(const uint8_t controller,
                                 const uint8_t data);
static uint8_t halGlcdCtrlReadData(const uint8_t controller);
static void halGlcdCtrlWriteCmd(const uint8_t controller,
                                const uint8_t data);
static void halGlcdCtrlSetAddress(const uint8_t controller,
                                  const uint8_t x,
                                  const uint8_t y);
static void halGlcdCtrlBusyWait(const uint8_t controller);
static void halGlcdCtrlSelect(const uint8_t controller);
static void halGlcdCtrlClearRAM(void);

/**
 * @brief       Initialize the glcd driver.
 */
uint8_t halGlcdInit(void)
{
    GLCD_DATA_PORT = 0;
    GLCD_DATA_DDR = 0xff;
    GLCD_CTRL_PORT &= ~0xfc;
    GLCD_CTRL_DDR |= 0xfc;

    PORTK = 0;
    DDRK = 0xff;

    /* Perform reset */
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RESET);

    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_B, GLCD_CMD_ON);
    halGlcdCtrlClearRAM();
    halGlcdSetYShift(0);
    halGlcdSetAddress(0, 0);

    return 0;
}

/**
 * @brief       Set the internal address.
 * @param xCol  X column.
 * @param yPage Y page.
 */
uint8_t halGlcdSetAddress(const uint8_t xCol,
                          const uint8_t yPage)
{
    internalAddr.x = xCol & (MAX_X_CHIP);
    internalAddr.y = yPage & 7;
    
    if (xCol < MAX_X_CHIP)
       internalAddr.controller = GLCD_CONTROLLER_0;
    else
       internalAddr.controller = GLCD_CONTROLLER_1;

    halGlcdCtrlSetAddress(internalAddr.x, internalAddr.y,
                          internalAddr.controller);

    return 0;
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
        halGlcdCtrlSetAddress(0, internalAddr.y, internalAddr.controller);
    }
    else if (internalAddr.x == MAX_X-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_0;
        halGlcdCtrlSetAddress(0, internalAddr.y, internalAddr.controller);
    }

    internalAddr.x = (internalAddr.x+1) & (MAX_X-1);

    return 0;
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
        halGlcdCtrlSetAddress(0, internalAddr.y, internalAddr.controller);
    }
    else if (internalAddr.x == MAX_X-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_0;
        halGlcdCtrlSetAddress(0, internalAddr.y, internalAddr.controller);
    }

    internalAddr.x = (internalAddr.x+1) & (MAX_X-1);
    
    return data;
}

/**
 * @brief           Set the display row address displayed at the top of the screen.
 * @param yShift    The y-shift address.
 */
uint8_t halGlcdSetYShift(uint8_t yShift)
{
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_B, GLCD_CMD_DISP_START | (yShift & (MAX_Y-1)));
    internalAddr.yShift = yShift & (MAX_Y-1);

    return 0;
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
    if (GLCD_CONTROLLER_B == controller)
    {
        halGlcdCtrlBusyWait(GLCD_CONTROLLER_0);
        halGlcdCtrlBusyWait(GLCD_CONTROLLER_1);
        halGlcdCtrlSelect(GLCD_CONTROLLER_B);
    }
    else 
        halGlcdCtrlBusyWait(controller);
    
    /* Prepare for write access */ 
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RS);
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_RW);
    
    GLCD_DATA_PORT = data;
    enable(); 
}

/*
 * @brief               Read one byte of data.
 * @param controller    The selected controller.
 * @return              The read byte.
 */
static uint8_t halGlcdCtrlReadData(const uint8_t controller)
{
    uint8_t data;
    
    /* Prepare for read access */
    halGlcdCtrlBusyWait(controller);
    GLCD_DATA_DDR = 0;
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RS)|(1<<GLCD_CTRL_RW);
    
    /* To read data, two read accesses are required */
    enable();
    data = GLCD_DATA_PIN;
    enable();
    data = GLCD_DATA_PIN;

    GLCD_DATA_DDR = 0xff;

    return data;
}

static void halGlcdCtrlWriteCmd(const uint8_t controller,
                                const uint8_t data)
{
    if (GLCD_CONTROLLER_B == controller)
    {
        halGlcdCtrlBusyWait(GLCD_CONTROLLER_0);
        halGlcdCtrlBusyWait(GLCD_CONTROLLER_1);
        halGlcdCtrlSelect(GLCD_CONTROLLER_B);
    }
    else 
        halGlcdCtrlBusyWait(controller);

    /* Prepare for writing a command */
    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_RS)|(1<<GLCD_CTRL_RW));
    
    GLCD_DATA_PORT = data;
    enable();
}

/*
 * @brief               Set x and y RAM address on the selected controller(s).
 * @param controller    The controller(s) to check.
 * @param x             The column adress.
 * @param y             The page number.
 */
static void halGlcdCtrlSetAddress(const uint8_t controller,
                                  const uint8_t x,
                                  const uint8_t y)
{
    halGlcdCtrlWriteCmd(controller, GLCD_CMD_SET_PAGE | y);
    halGlcdCtrlWriteCmd(controller, GLCD_CMD_SET_ADDR | x);
}

/*
 * @brief               Check if the controller is busy and wait until it is ready.
 * @param controller    The controller to check.
 */
static void halGlcdCtrlBusyWait(const uint8_t controller)
{
    halGlcdCtrlSelect(controller);

    /* Set busy, display & reset status pins to input */
    GLCD_DATA_DDR &= ~((1<<GLCD_STATUS_BUSY)|(1<<GLCD_STATUS_RESET));
    /* Prepare for read access */
    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_EN)|(1<<GLCD_CTRL_RS));
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RW);
    
    busy_wait_enable();
    
    /* Wait until busy line is low and check if display was reset */
    uint8_t controllerStatus;
    do
    {
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_EN);
        busy_wait_enable();

        controllerStatus = GLCD_DATA_PIN &
                           ((1<<GLCD_STATUS_BUSY)|(1<<GLCD_STATUS_RESET));

        GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_EN);
        busy_wait_enable();
    }
    while(controllerStatus != 0);

    /* Restore initial pin states */
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RS);
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_RW);
    GLCD_DATA_DDR |= (1<<GLCD_STATUS_BUSY)|(1<<GLCD_STATUS_RESET);
}

/*
 * @brief               Select the desired RAM controller(s).
 * @param controller    The desired controller(s) (_0, _1, or _B for both).
 */
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
    else if (GLCD_CONTROLLER_B == controller)
    {
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_CS0);
        GLCD_CTRL_PORT |= (1<<GLCD_CTRL_CS1);
    }
}

//TODO optimize for both controllers
static void halGlcdCtrlClearRAM(void)
{
    for (uint8_t y = 0; y < 8; y++)
    {
        halGlcdCtrlSetAddress(GLCD_CONTROLLER_B, 0, y);
        
        for (uint8_t x = 0; x < MAX_X_CHIP; x++)
            halGlcdCtrlWriteData(GLCD_CONTROLLER_B, 0x00);
    }
}

