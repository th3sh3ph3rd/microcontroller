/**
 *
 * @file RadioScannerAppC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * Top-level wiring of the RadioScanner app.
 *
**/

#include <debug.h>
configuration PS2TestAppC {

}

implementation {
	components MainC, PS2TestP, PS2C, GlcdC;

        PS2TestP.Boot -> MainC.Boot;
        PS2TestP.Glcd -> GlcdC.Glcd;
        PS2TestP.Keyboard -> PS2C.PS2;
}
