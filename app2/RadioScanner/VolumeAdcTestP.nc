/**
 *
 * @file RadioScannerAppC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * VolumeAdc test module implementation.
 *
**/

#include <debug.h>

module VolumeAdcTestP {
    uses
    {
        interface Boot;
        interface Read<uint16_t> as Adc;
        interface Timer<TMilli> as Timer;
        interface GeneralIOPort as Leds;
    }
}

implementation {
    event void Boot.booted()
    {
        call Leds.makeOutput(0xff);
        call Leds.clear(0xff);
        call Timer.startPeriodic(10);
    }

    event void Timer.fired()
    {
        call Adc.read();
    }

    event void Adc.readDone(error_t res, uint16_t val)
    {
        call Leds.write((uint8_t) val);
    }
}
