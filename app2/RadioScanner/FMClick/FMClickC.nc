/**
 *
 * @file FMClickC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-12
 *
 * Configuration of the FMClick module.
 *
**/

configuration FMClickC {
    provides 
    {
        interface Init;
        interface FMClick;
    };
}

implementation {
    components FMClickP, GlcdC;
    components HplAtm128InterruptC as Int; 
    components new Atm128I2CMasterC() as I2C;
    components new TimerMilliC() as Timer;
    components HplAtm1280GeneralIOC as IO;

    Init = FMClickP.Init;
    FMClick = FMClickP.FMClick;

    FMClickP.Int -> Int.Int3;

    FMClickP.I2CResource -> I2C.Resource;
    FMClickP.I2C -> I2C.I2CPacket;

    FMClickP.Timer -> Timer;

    FMClickP.RSTPin -> IO.PortD2;
    FMClickP.SDIOPin -> IO.PortD1;

    FMClickP.Glcd -> GlcdC.Glcd;
}

