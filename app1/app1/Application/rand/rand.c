/**
 *
 * @file rand.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-26
 *
 * Implementation of the PRNG module.
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdint.h>

#include <rand.h>

/* The LFSR used for computing pseudo-random numbers. */
static uint16_t lfsr = 1;

/* The polynomial for the PRNG */
static const uint16_t poly = POLYNOMIAL;

/**
 * @brief       Shift the LFSR to the right, shifting in the LSB of the parameter. Usually not called directly.
 * @param in    The bit to shift into the LFSR.
 * @return      The bit shifted out of the LFSR.
 */
uint8_t rand_shift(uint8_t in)
{
    uint8_t out = 0;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        asm volatile
        (
            "bst    %A1, 0"                 "\n\t" /* LSB(out) := LSB(lfsr) */
            "bld    %0, 0"                  "\n\t"
            "lsr    %B1"                    "\n\t" /* lsfr >> 1 */
            "ror    %A1"                    "\n\t"
            "bst    %2, 0"                  "\n\t" /* MSB(lfsr) := LSB(in) */
            "bld    %B1, 7"                 "\n\t"
            "sbrs   %0, 0"                  "\n\t" /* if out */
            "rjmp   L_end%="                "\n\t"
            "eor    %A1, %A3"               "\n\t" /* lfsr := lfsr xor poly  */
            "eor    %B1, %B3"               "\n\t"
            "L_end%=:"                      "\n\t"
            : "=r" (out), "=r" (lfsr)
            : "r" (in), "r" (poly), "0" (out), "1" (lfsr)
        );
    }

    return out;
}

/**
 * @brief       Feed one random bit to the LFSR (reseeding).
 * @param in    The random bit to feed into the LFSR.
 */
void rand_feed(uint8_t in)
{
    (void) rand_shift(in);
}

/**
 * @brief       Get one bit of random data from the LFSR.
 * @return      A random bit.
 */
uint8_t rand1()
{
    return rand_shift(0);
}

/**
 * @brief       Get a random 16-bit number.
 * @return      A random 16-bit number.
 */
uint16_t rand16()
{
    uint16_t randnum = 0;

    for (uint8_t i = 0; i < 16; i++)
    {
        randnum |= rand1() << i;
    }

    return randnum;
}

