/**
 *
 * @file FMClickP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-12
 *
 * FMClick module implementation.
 *
**/

module FMClickP {
    provides
    {
        interface Init;
        interface FMClick;
    };
    uses
    {
        interface HplAtm128Interrupt as Int;
        interface Resource as I2CResource;
        interface I2CPacket<TI2BasicAddr> as I2C;
        interface Timer<TMilli> as Timer;
        interface GeneralIO as RSTPin;
        interface GeneralIO as SDIOPin;
    }
}

implementation {
    #define XOSCEN_DELAY_MS     500
    #define DEVICE_WRITE_ADDR   0x10
    #define DEVICE_READ_ADDR    0x21

    enum driver_state {INIT};
    enum write_state {XOSCEN, ENABLE, DISABLE};

    enum driver_state driverState;
    enum write_state writeState;

    command error_t Init.init()
    {
        RSTPin.MakeOutput();
        RSTPin.Clr();
        
        driverState = INIT;

        /* Select 2-wire mode */
        SDIOPin.MakeOutput();
        SDIOPin.Clr();

        /* Finish reset */
        RSTPin.Set();

        /* Set XOSCEN and wait 500 ms */
        writeState = XOSCEN;
        //TODO pass pointer to command buffer
        I2C.write(I2C_START | I2C_STOP, DEVICE_WRITE_ADDR, 2, NULL);

        return SUCCESS; 
    }

    void finishInit()
    {
        //Set ENABLE and clear DISABLE
        signal FMCLick.InitDone(SUCCESS);
    }

    command error_t tune(uint16_t channel);

    command error_t seek(bool up);

    command uint16_t getChannel(void);

    command error_t setVolume(uint8_t);

    command error_t receiveRDS(bool enable);

    event void Timer.fired()
    {
        switch (driverState)
        {
            case INIT:
                finishInit(), then disable, then signal initDone;
                break;

            default:
                break;
        }
    }
    
    async event I2C.readDone(/*TODO add parameters*/)
    {

    }

    async event I2C.writeDone(/*TODO add parameters*/)
    {
        switch(writeState)
        {
            case XOSCEN:
                Timer.startOneShot(XOSCEN_DELAY_MS);
                //TODO write ENABLE, then disable, then signal initDone
                break;

            default:
                break;
    }
}

