/**
 *
 * @file VolumeAdcP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-09
 *
 * VolumeAdc module implementation.
 *
**/

#include <debug.h>

module VolumeAdcP {
    provides
    {
        interface Atm1280AdcConfig;
        interface ResourceConfigure;
    };
    uses interface GeneralIO as VolumePin;
}

implementation {
    async command uint8_t Atm1280AdcConfig.getChannel()
    {
        return ATM1280_ADC_SNGL_ADC0;
    }

    async command uint8_t Atm1280AdcConfig.getRefVoltage()
    {
        return ATM1280_ADC_VREF_AVCC;
    }

    async command uint8_t Atm1280AdcConfig.getPrescaler()
    {
        return ATM1280_ADC_PRESCALE_128;
    }

    async command void ResourceConfigure.configure()
    {
        call VolumePin.makeInput();
    }

    async command void ResourceConfigure.unconfigure()
    {

    }
}

