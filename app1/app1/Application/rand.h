/**
 *
 * @file rand.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-26
 *
 * Header file for the PRNG module.
 *
 */


#ifndef __RAND__
#define __RAND__

#include <stdint.h>

#define POLYNOMIAL 0x80E3

/**
 * @brief       Shift the LFSR to the right, shifting in the LSB of the parameter. Usually not called directly.
 * @param in    The bit to shift into the LFSR.
 * @return      The bit shifted out of the LFSR.
 */
uint8_t rand_shift(uint8_t in);

/**
 * @brief       Feed one random bit to the LFSR (reseeding).
 * @param in    The random bit to feed into the LFSR.
 */
void rand_feed(uint8_t in);

/**
 * @brief       Get one bit of random data from the LFSR.
 * @return      A random bit.
 */
uint8_t rand1(void);

/**
 * @brief       Get a random 16-bit number.
 * @return      A random 16-bit number.
 */
uint16_t rand16(void);

#endif

