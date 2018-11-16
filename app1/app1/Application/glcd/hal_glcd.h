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
 * @brief       Set the internal address.
 * @param xCol  X column.
 * @param yPage Y page.
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

/**
 * @brief           Set the display row address displayed at the top of the screen.
 * @param yShift    The y-shift address.
 */
uint8_t halGlcdSetYShift(uint8_t yShift);

/**
 * @brief       Get the display row address displayed at the top of the screen.
 * @return      The y-shift address.
 */
uint8_t halGlcdGetYShift(void);

/*
 * @brief           Fills the whole screen with the desired pattern.
 * @param pattern   The pattern for filling the screen.
 */
uint8_t halGlcdFillScreen(uint8_t pattern);

#endif

