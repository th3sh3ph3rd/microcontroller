/**
 *
 * @file    PS2C.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * Configuration of the PS2 module.
 *
**/

configuration PS2C {
    provides interface PS2;
}

implementation {
    components PS2P;
    components HplAtmegaPinChange2C as PinChangeIRQ;
    components HplAtm1280GeneralIOC as IO;

    PS2 = PS2P.PS2;
    PS2P.ClockIRQ -> PinChangeIRQ;

    PS2P.ClockPin -> IO.PortK7;
    PS2P.DataPin -> IO.PortK6;
}

