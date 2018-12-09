/**
 *
 * @file VolumeAdcC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * Configuration of the VolumeAdc module.
 *
**/

#include <debug.h>

configuration VolumeAdcC {
    provides interface Read<uint16_t>;
}

implementation {
    components VolumeAdcP;
    components new AdcReadClientC() as Adc;
    components HplAtm1280GeneralIOC as IO;

    Read = Adc.Read;

    VolumeAdcP.VolumePin -> IO.PortF0;

    VolumeAdcP.Atm1280AdcConfig <- Adc.Atm1280AdcConfig;
    VolumeAdcP.ResourceConfigure <- Adc.ResourceConfigure;
}

