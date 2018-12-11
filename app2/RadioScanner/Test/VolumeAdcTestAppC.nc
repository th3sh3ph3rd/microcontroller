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
configuration VolumeAdcTestAppC {

}

implementation {
	components MainC, VolumeAdcTestP, VolumeAdcC;
        components new TimerMilliC() as Timer;
        components HplAtm1280GeneralIOFastPortC as IO;

        VolumeAdcTestP.Boot -> MainC.Boot;
        VolumeAdcTestP.Adc -> VolumeAdcC.Read;
        VolumeAdcTestP.Timer -> Timer;
        VolumeAdcTestP.Leds -> IO.PortA;
}
