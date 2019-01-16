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
	components MainC, RadioScannerP, DatabaseC, FMClickC, PS2C, GlcdC, VolumeAdcC;
        components BufferedLcdC as Lcd;
        components new TimerMilliC() as VolumeTimer;
        components new TimerMilliC() as ErrorTimer;
        components new TimerMilliC() as RDSTimer;

        RadioScannerP.Boot -> MainC.Boot;
        RadioScannerP.Glcd -> GlcdC.Glcd;
        RadioScannerP.Lcd -> Lcd;
        RadioScannerP.DBInit -> DatabaseC.Init;
        RadioScannerP.DB -> DatabaseC.Database;
        RadioScannerP.RadioInit -> FMClickC.Init;
        RadioScannerP.Radio -> FMClickC.FMClick;
        RadioScannerP.Keyboard -> PS2C.PS2;
        RadioScannerP.volumeKnob -> VolumeAdcC.Read;
        RadioScannerP.VolumeTimer -> VolumeTimer;
        RadioScannerP.ErrorTimer -> ErrorTimer;
        RadioScannerP.RDSTimer -> RDSTimer;
}
