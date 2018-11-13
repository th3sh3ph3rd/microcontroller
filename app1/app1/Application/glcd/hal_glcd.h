/**
 *
 * @file hal_glcd.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-11-13
 *
 * Header file for the glcd driver.
 *
 */

#ifndef __HAL_GLCD__
#define __HAL_GLCD__

#include <stdint.h>

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

#endif

