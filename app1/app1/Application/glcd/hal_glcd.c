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
#define GLCD_CTRL_CS0       PE2
#define GLCD_CTRL_CS1       PE3
#define GLCD_CTRL_RESET     PE7

#define GLCD_DATA_PORT      PORTA
#define GLCD_DATA_DDR       DDRA
#define GLCD_DATA_PIN       PINA

#define GLCD_STATUS_BUSY    PA7
#define GLCD_STATUS_DISP    PA5
#define GLCD_STATUS_RESET   PA4

#define GLCD_CONTROLLER_0   (1<<GLCD_CTRL_CS1)
#define GLCD_CONTROLLER_1   (1<<GLCD_CTRL_CS0)
#define GLCD_CONTROLLER_B   (GLCD_CONTROLLER_1 | GLCD_CONTROLLER_0)

#define GLCD_CMD_ON         0x3f
#define GLCD_CMD_OFF        0x3e
#define GLCD_CMD_SET_ADDR   0x40
#define GLCD_CMD_SET_PAGE   0xb8
#define GLCD_CMD_DISP_START 0xc0

#define MAX_X_CHIP  64
#define MAX_X       128
#define MAX_Y       64

#define busy_wait_setup()      \
        __asm__ __volatile__ (  \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t" ::)

#define busy_wait_enable()      \
        __asm__ __volatile__ (  \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t"        \
            "nop" "\n\t" ::)

//TODO use this for the controller argument
typedef enum {
    CONTROLLER_0 = (1<<GLCD_CTRL_CS1),
    CONTROLLER_1 = (1<<GLCD_CTRL_CS0),
    CONTROLLER_B = (1<<GLCD_CTRL_CS1)|(1<<GLCD_CTRL_CS0)
} controller_t;

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
static uint8_t halGlcdCtrlReadStatus(const uint8_t controller);
static void halGlcdCtrlWriteCmd(const uint8_t controller,
                                const uint8_t data);
static void halGlcdCtrlSetAddress(const uint8_t controller,
                                  const uint8_t x,
                                  const uint8_t y);
static void halGlcdCtrlBusyWait(const uint8_t controller);
static void halGlcdCtrlClearRAM(const uint8_t controller);

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
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_RESET);
    GLCD_CTRL_PORT &= ~(GLCD_CONTROLLER_B);
    
    internalAddr.controller = GLCD_CONTROLLER_0;
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_0, GLCD_CMD_ON);
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_1, GLCD_CMD_ON);
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_0, GLCD_CMD_DISP_START);
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_1, GLCD_CMD_DISP_START);
    halGlcdCtrlClearRAM(GLCD_CONTROLLER_0);
    halGlcdCtrlClearRAM(GLCD_CONTROLLER_1);
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
    internalAddr.x = xCol & (MAX_X-1);
    internalAddr.y = yPage & 7;

    if (xCol < MAX_X_CHIP)
        internalAddr.controller = GLCD_CONTROLLER_0;
    else
        internalAddr.controller = GLCD_CONTROLLER_1;


    halGlcdCtrlSetAddress(internalAddr.controller,
                          internalAddr.x & (MAX_X_CHIP-1), internalAddr.y);

    return 0;
}

/**
 * @brief       Write data to the RAM at the currently set address. The x address is post-incremented.
 * @param data  The data.
 */
uint8_t halGlcdWriteData(const uint8_t data)
{
    halGlcdCtrlWriteData(internalAddr.controller, data);

    if (internalAddr.x == MAX_X-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_0;
        halGlcdCtrlSetAddress(GLCD_CONTROLLER_0, 0, internalAddr.y);
    }
    else if (internalAddr.x == MAX_X_CHIP-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_1;
        halGlcdCtrlSetAddress(GLCD_CONTROLLER_1, 0, internalAddr.y);
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
    /* Dummy read necessary */
    halGlcdCtrlReadData(internalAddr.controller);
    halGlcdCtrlSetAddress(internalAddr.controller, internalAddr.x, internalAddr.y);
    uint8_t data = halGlcdCtrlReadData(internalAddr.controller);
    
    if (internalAddr.x == MAX_X-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_0;
        halGlcdCtrlSetAddress(GLCD_CONTROLLER_0, 0, internalAddr.y);
    }
    else if (internalAddr.x == MAX_X_CHIP-1)
    {
        internalAddr.controller = GLCD_CONTROLLER_1;
        halGlcdCtrlSetAddress(GLCD_CONTROLLER_1, 0, internalAddr.y);
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
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_0, GLCD_CMD_DISP_START | (yShift & (MAX_Y-1)));
    halGlcdCtrlWriteCmd(GLCD_CONTROLLER_1, GLCD_CMD_DISP_START | (yShift & (MAX_Y-1)));
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
    halGlcdCtrlBusyWait(controller);
    
    /* Prepare for data write access */
    GLCD_DATA_PORT = data;
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_EN);
    GLCD_CTRL_PORT = (GLCD_CTRL_PORT & ((1<<GLCD_CTRL_RESET)|(1<<GLCD_CTRL_EN))) | (1<<GLCD_CTRL_RS) | controller;
    busy_wait_setup();
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_EN);
    busy_wait_enable();

    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_EN)|GLCD_CONTROLLER_B);
}

/*
 * @brief               Read one byte of data.
 * @param controller    The selected controller.
 * @return              The read byte.
 */
static uint8_t halGlcdCtrlReadData(const uint8_t controller)
{
    uint8_t data;
    
    halGlcdCtrlBusyWait(controller);
   
    /* Set data port to input */
    GLCD_DATA_DDR = 0;
    
    /* Prepare for data read access */
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_EN);
    GLCD_CTRL_PORT = (GLCD_CTRL_PORT & ((1<<GLCD_CTRL_RESET)|(1<<GLCD_CTRL_EN))) | (1<<GLCD_CTRL_RW) | (1<<GLCD_CTRL_RS) | controller;
    busy_wait_setup();
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_EN);
    busy_wait_enable();
    
    data = GLCD_DATA_PIN;

    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_EN)|GLCD_CONTROLLER_B);
    
    /* Restore initial pin states */
    GLCD_DATA_DDR = 0xff;
    
    return data;
}

/*
 * @brief               Read the status byte.
 * @param controller    The selected controller.
 * @return              The read byte.
 */
//TODO remove delays
static uint8_t halGlcdCtrlReadStatus(const uint8_t controller)
{
    uint8_t status;
    
    /* Set data port to input */
    GLCD_DATA_DDR = 0;
    
    /* Prepare for status read access */
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_EN);
    GLCD_CTRL_PORT = (GLCD_CTRL_PORT & ((1<<GLCD_CTRL_RESET)|(1<<GLCD_CTRL_EN))) | (1<<GLCD_CTRL_RW) | controller;
    busy_wait_setup();
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_EN);
    busy_wait_enable();
    
    status = GLCD_DATA_PIN;

    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_EN)|GLCD_CONTROLLER_B);
    
    /* Restore initial pin states */
    GLCD_DATA_DDR = 0xff;

    return status;
}

/*
 * @brief               Write a command byte.
 * @param controller    The selected controller.
 * @param data          The command to write.
 */
static void halGlcdCtrlWriteCmd(const uint8_t controller,
                                const uint8_t data)
{
    halGlcdCtrlBusyWait(controller);
    
    /* Prepare for data write access */
    GLCD_CTRL_PORT &= ~(1<<GLCD_CTRL_EN);
    GLCD_DATA_PORT = data;
    GLCD_CTRL_PORT = (GLCD_CTRL_PORT & ((1<<GLCD_CTRL_RESET)|(1<<GLCD_CTRL_EN))) | controller;
    busy_wait_setup();
    GLCD_CTRL_PORT |= (1<<GLCD_CTRL_EN);
    busy_wait_enable();
   
    GLCD_CTRL_PORT &= ~((1<<GLCD_CTRL_EN)|GLCD_CONTROLLER_B);
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
    halGlcdCtrlWriteCmd(controller, GLCD_CMD_SET_ADDR | x);
    halGlcdCtrlWriteCmd(controller, GLCD_CMD_SET_PAGE | y);
}

/*
 * @brief               Check if the controller is busy and wait until it is ready.
 * @param controller    The controller to check.
 */
static void halGlcdCtrlBusyWait(const uint8_t controller)
{
    uint8_t status;
    do
    {
        status = halGlcdCtrlReadStatus(controller);
    }
    while((status & ((1<<GLCD_STATUS_BUSY)|(1<<GLCD_STATUS_RESET))) != 0);
}

/*
 * @brief               Sets all pages of the given controller to 0x00.
 * @param controller    The controller to clear.
 */
static void halGlcdCtrlClearRAM(const uint8_t controller)
{
    for (uint8_t y = 0; y < 8; y++)
    {
        halGlcdCtrlSetAddress(controller, 0, y);
        
        for (uint8_t x = 0; x < MAX_X_CHIP; x++)
            halGlcdCtrlWriteData(controller, 0x00);
    }
}

