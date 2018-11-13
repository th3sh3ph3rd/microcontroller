/**
 *
 * @file hal_glcd.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-13
 *
 * Implementation of the glcd driver.
 *
 */

#include <stdint.h>

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
uint8_t halGlcdInit(void);

/**
 * @brief       Set the internal RAM address.
 * @param xCol  X RAM column.
 * @param yPage Y RAM page.
 */
uint8_t halGlcdSetAddress(const uint8_t xCol,
                          const uint8_t yPage);

/**
 * @brief       Write data to the RAM at the currently set address.
 * @param data  The data.
 */
uint8_t halGlcdWriteData(const uint8_t data);

/**
 * @brief       Read data from the RAM at the currently set address.
 * @return      The data.
 */
uint8_t halGlcdReadData(void);

