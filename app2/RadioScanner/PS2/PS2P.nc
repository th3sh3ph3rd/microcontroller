/**
 *
 * @file    PS2P.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * PS2 module implementation.
 *
**/

#include <debug.h>

module PS2P {
    provides interface PS2;
    uses
    {
        interface HplAtmegaPinChange as ClockPin;
        interface GeneralIO as DataPin;
    }
}

implementation {
    command void PS2.init(void)
    {
        /* Configure data pin as input and enable pull-up */
        DataPin.makeInput();
        DataPin.set();

        /* Enable PCINT2 on the clock line */
        ClockPin.enable();
    }

    async event void PS2.receivedChar(uint8_t chr)
    {

    }
}

