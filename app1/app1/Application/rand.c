/**
 *
 * @file rand.c
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-10-16
 *
 * Implementation of the PRNG module.
 *
 */

#include <avr/io.h>
#include <stdint.h>

#include "rand.h"

/**
 * @brief       The LFSR used for computing random numbers.
 */
static uint16_t lfsr = 1;

/**
 * @brief       Shift the LFSR to the right, shifting in the LSB of the parameter. Usually not called directly.
 * @param in    The bit to shift into the LFSR.
 * @return      The bit shifted out of the LFSR.
 */
uint8_t rand_shift(uint8_t in)
{
    uint8_t out = 0;
    uint16_t poly = POLYNOMIAL;
    
    asm volatile
    (
        "in     __temp_reg__, __SREG__" "\n\t" /* save interrupt flag */
        "cli"                           "\n\t" /* disable interrupts */
        "bst    %A3, 0"                 "\n\t" /* LSB(out) := LSB(lfsr) */
        "bld    %0, 0"                  "\n\t"
        "lsr    %B3"                    "\n\t" /* lsfr >> 1 */
        "ror    %A3"                    "\n\t"
        "bst    %1, 0"                  "\n\t" /* MSB(lfsr) := LSB(in) */
        "bld    %B3, 7"                 "\n\t"
        "out    __SREG__, __temp_reg__" "\n\t" /* restore interrupt flag */
        "sbrs   %0, 0"                  "\n\t" /* if out */
        "rjmp   L_end%="                "\n\t"
        "eor    %A3, %A2"               "\n\t" /* lfsr := lfsr xor poly  */
        "eor    %B3, %B2"               "\n\t"
        "L_end%=:"                      "\n\t"
        : "=r" (out)
        : "r" (in), "r" (poly), "r" (lfsr), "0" (out)
    );

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
//TODO which value to feed???
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

