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

module FMClickTestP {
    uses
    {
        interface Boot;
        interface Glcd;
        interface Init as RadioInit;
        interface FMClick as Radio;
    }
}

implementation {
    #define FM4 1038
    #define RADIO 921
    #define RADIOW 899

    uint16_t currChan;

    event void Boot.booted()
    {
        call RadioInit.init();
        call Glcd.fill(0x00);
        call Glcd.drawText("init fm", 0, 10);
    }

    task void tune2Station()
    {
        call Glcd.drawText("init done", 0, 10);
        //call Radio.setVolume(15); not working, signal needed
        call Glcd.drawText("tune to station", 0, 10);
        call Radio.tune(RADIOW);
    }

    task void initFail()
    {
        call Glcd.drawText("init failed!", 0, 10);
    }

    task void finishedTuning()
    {
        char buf[5];
        uint16_t chan;
        atomic { chan = currChan; }
        sprintf(buf, "%u", chan);
        call Glcd.drawText("tuned to station", 0, 10);
        call Glcd.drawText(buf, 0, 30);
    }

    event void Radio.initDone(error_t res)
    {
        if (SUCCESS == res)
            post tune2Station();
        else
            post initFail();
    }
 
    async event void Radio.tuneComplete(uint16_t channel)
    {
        atomic { currChan = channel; }
        post finishedTuning();
    }

    async event void Radio.rdsReceived(RDSType type, char *buf)
    {

    }
}
