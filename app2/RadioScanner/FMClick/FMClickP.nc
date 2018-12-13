/**
 *
 * @file FMClickP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-12
 *
 * FMClick module implementation.
 *
**/

//TODO optimizations
// -remove busy-wait loops
// -don't read/write all registers

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
    #define DEVICE_WRITE_ADDR   0x10
    #define DEVICE_READ_ADDR    0x21

    /* Register file addresses */
    #define REGISTER_NUM        16
    #define REGISTER_WIDTH      2
    #define READ_START_ADDR     0x0a
    #define WRITE_START_ADDR    0x02
    #define XOSCEN_REG          0x07
    #define XOSCEN_ADDR         0x8000
    #define ENABLE_REG          0x02
    #define ENABLE_ADDR         0x0000
    #define DISABLE_REG         0x02
    #define DISABLE_ADDR        0x0020
    #define DMUTE_REG           0x02
    #define DMUTE_ADDR          0x4000


    #define XOSCEN_DELAY_MS     500
   
    uint16_t shadowRegisters[REGISTER_NUM];
    uint8_t comBuffer[REGISTER_NUM*REGISTER_WIDTH];

    enum driver_state {INIT, IDLE};
    enum init_state {SETUP, XOSCEN, WAITXOSC, ENABLE, READREGF, FINISH};
    enum com_state {IDLE, BUSY};

    //TODO make bitfield
    struct
    {
        enum driver_state driver;
        enum init_state init;
        enum com_state com;
    } states;

    void readRegisters()
    {
        //TODO get rid of busy wait
        while (comState == BUSY);
        states.com = BUSY;
        while (call I2C.read(I2C_START | I2C_STOP, DEVICE_READ_ADDR, REGISTER_NUM*REGSITER_WIDTH, comBuffer) != SUCCESS);
    }

    void registerWriteback()
    {
        uint8_t i = READ_START_ADDR;
        for (uint8_t j = 0; j < REGISTER_NUM*REGISTER_WIDTH; j += REGISTER_WIDTH)
        {
            shadowRegisters[i] = (comBuffer[j] << 8) | comBuffer[j+1];
            i = (i+1) & (REGISTER_NUM-1);
        }
    }

    void writeRegisters(uint8_t addr)
    {
        uint8_t i = WRITE_START_ADDR;
        for (uint8_t j = 0; j < REGISTER_NUM*REGISTER_WIDTH; j += REGISTER_WIDTH)
        {
            comBuffer[j] = (uint8_t) (shadowRegister[i] >> 8);
            comBuffer[j+1] = (uint8_t) shadowRegister[i];
            i = (i+1) & (REGISTER_NUM-1);
        }
        
        //TODO get rid of busy wait
        while (comState == BUSY);
        states.com = BUSY;
        while (call I2C.write(I2C_START | I2C_STOP, DEVICE_WRITE_ADDR, REGISTER_NUM*REGISTER_WIDTH, comBuffer) != SUCCESS);
    }

    error_t init()
    {
        if (SETUP == states.init)
        {
            call RSTPin.MakeOutput();
            call RSTPin.Clr();
            
            states.driver = INIT;
            states.com = IDLE;

            /* Select 2-wire mode */
            call SDIOPin.MakeOutput();
            call SDIOPin.Clr();

            /* Finish reset */
            call RSTPin.Set();

            /* Read initial register file state */
            readRegisters();

            states.init = XOSCEN;
            return SUCCESS;
        }
        else if (XOSCEN == states.init)
        {
            /* Start internal oscillator */
            shadowRegisters[XOSCEN_REG] ^= XOSCEN_ADDR;
            writeRegisters();

            states.init = WAITXOSC;
            return SUCCESS;
        }
        else if (WAITXOSC == states.init)
        {
            /* Wait for oscillator to stabilize */
            call Timer.startOneShot(XOSCEN_DELAY_MS);
            
            states.init = ENABLE;
            return SUCCESS;
        }
        else if (ENABLE == states.init)
        {
            /* Start device powerup and disable mute */
            shadowRegisters[ENABLE_REG] ^= ENABLE_ADDR;
            shadowRegisters[DISABLE_REG] &= ~DISABLE_ADDR;
            shadowRegisters[DMUTE_REG] &= ~DMUTE_ADDR;
            writeRegisters();

            states.init = READREGF;
            return SUCCESS;
        }
        else if (READREGF == states.init)
        {
            /* Read initial register file state */
            readRegisters();
            
            states.init = FINISH;
            return SUCCESS;
        }
        else if (FINISH == states.init)
        {
            signal FMClick.initDone();

            states.driver = IDLE;
            return SUCCESS;
        }
    }

    command error_t Init.init()
    {
        states.init = SETUP;
        return init(); 
    }

    command error_t tune(uint16_t channel);

    command error_t seek(bool up);

    command uint16_t getChannel(void);

    command error_t setVolume(uint8_t);

    command error_t receiveRDS(bool enable);

    event void Timer.fired()
    {
        switch (states.driver)
        {
            case INIT:
                init();
                break;

            default:
                break;
        }
    }
   
    //TODO handle error
    async event I2C.readDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
    {
        registerWriteback();
        states.com = IDLE;

        switch (states.driver)
        {
            case INIT:
                init();
                break;

            default:
                break;
        }
    }

    //TODO handle error
    async event I2C.writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
    {
        states.com = IDLE;
        
        switch (states.driver)
        {
            case INIT:
                init();
                break;

            default:
                break;
        }
    }
}

