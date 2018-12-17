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
configuration FMClickTestAppC {

}

implementation {
	components MainC, FMClickTestP, FMClickC, GlcdC;

        FMClickTestP.Boot -> MainC.Boot;
        FMClickTestP.Glcd -> GlcdC.Glcd;
        FMClickTestP.RadioInit -> FMClickC.Init;
        FMClickTestP.Radio -> FMClickC.FMClick;
}
