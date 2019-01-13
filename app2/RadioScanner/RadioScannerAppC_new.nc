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
configuration RadioScannerAppC {

}

implementation {
	components MainC, RadioScannerP_new, DatabaseC, FMClickC, PS2C, GlcdC, VolumeAdcC;
        components BufferedLcdC as Lcd;
        components new TimerMilliC() as VolumeTimer;
        components new TimerMilliC() as ErrorTimer;

        RadioScannerP_new.Boot -> MainC.Boot;
        RadioScannerP_new.Glcd -> GlcdC.Glcd;
        RadioScannerP_new.Lcd -> Lcd;
        RadioScannerP_new.DBInit -> DatabaseC.Init;
        RadioScannerP_new.DB -> DatabaseC.Database;
        RadioScannerP_new.RadioInit -> FMClickC.Init;
        RadioScannerP_new.Radio -> FMClickC.FMClick;
        RadioScannerP_new.Keyboard -> PS2C.PS2;
        RadioScannerP_new.volumeKnob -> VolumeAdcC.Read;
        RadioScannerP_new.VolumeTimer -> VolumeTimer;
        RadioScannerP_new.ErrorTimer -> ErrorTimer;
}
