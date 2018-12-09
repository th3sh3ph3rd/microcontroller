/**
 *
 * @file    PS2C.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * Configuration of the PS2 module.
 *
**/

#include <debug.h>

configuration PS2C {
    provides interface PS2;
}

implementation {
    components PS2P;
    components HplAtmegaPinChange2C as PinChange;
    components HplAtm1289GeneralIOC as IO;

    PS2 = PS2P.PS2;

    PS2P.ClockPin -> PinChange;

    //TODO use correct port!!!
    PS2P.DataPin -> IO.PortC0;
}

