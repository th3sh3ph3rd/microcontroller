/**
 *
 * @file FMClickC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-12
 *
 * Configuration of the FMClick module.
 *
**/

configuration FMCLickC {
    provides 
    {
        interface Init;
        interface FMClick;
    };
}

implementation {
    components FMClickP;
    components HplAtm128InterruptC as Int; 
    components new Atm128I2CMasterC() as I2C;
    components new TimerMilliC() as Timer;
    components HplAtm1280GeneralIOC as IO;

    Init = FMClickP.Init;
    FMClick = FMClickP.FMClick;

    FMClick.Int -> Int.Int3;

    FMCLick.I2CResource -> I2C.Resource;
    FMCLick.I2C -> I2C.I2CPacket;

    FMClick.Timer -> Timer;

    FMClickP.RSTPin -> IO.PortD2;
    FMClickP.SDIOPin -> IO.PortD1;
}

