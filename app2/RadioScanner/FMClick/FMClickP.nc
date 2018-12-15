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
// -don't read/write all registers, only up to highest required

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
    #define GPIO2_REG           0x04
    #define GPIO2_ADDR          0x0002 /* Configures GPIO2 to fire RDS/STC interrupts */
    #define RDS_REG             0x04
    #define RDS_ADDR            0x0800
    #define RDSIEN_REG          0x04
    #define RDSIEN_ADDR         0x8000
    #define STCIEN_REG          0x04
    #define STCIEN_ADDR         0x4000
    #define SPACE_REG           0x05
    #define SPACE_ADDR          0x0008 /* Europe FM channel spacing */
    #define DE_REG              0x04
    #define DE_ADDR             0x0400 /* Europe FM de-emphasis settings */
    #define TUNE_REG            0x03
    #define TUNE_ADDR           0x8000
    #define CHAN_REG            0x03
    #define CHAN_ADDR           0x01ff
    #define READCHAN_REG        0x0b
    #define READCHAN_ADDR       0x01ff
    #define VOLUME_REG          0x05
    #define VOLUME_ADDR         0x000f

    #define XOSCEN_DELAY_MS     500
  
    //TODO do we need to read registers before every write?
    //     if yes, call readreg in interface function to avoid additional state

    uint16_t shadowRegisters[REGISTER_NUM];
    uint8_t comBuffer[REGISTER_NUM*REGISTER_WIDTH];

    enum driver_state {IDLE, INIT, TUNE, SEEK, VOL, CONFRDS};
    enum init_state {SETUP, XOSCEN, WAITXOSC, ENABLE, READREGF, CONFIG, FINISH};
    enum tune_state {STARTTUNE, WAITTUNE, TUNECHAN, ENDTUNE, FINTUNE};

    //TODO make bitfield
    struct
    {
        enum driver_state driver;
        enum init_state init;
        enum tune_state tune;
    } states;

    void readRegisters()
    {
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
        
        while (call I2C.write(I2C_START | I2C_STOP, DEVICE_WRITE_ADDR, REGISTER_NUM*REGISTER_WIDTH, comBuffer) != SUCCESS);
    }

    //TODO convert to task (avoid signal recursion)
    error_t _init()
    {
        if (SETUP == states.init)
        {
            call RSTPin.MakeOutput();
            call RSTPin.Clr();
            
            /* Select 2-wire mode */
            call SDIOPin.MakeOutput();
            call SDIOPin.Clr();

            /* Set falling edge on STC/RDS interrupt */
            call Int.edge(false);

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
            
            states.init = CONFIG;
            return SUCCESS;
        }
        else if (CONFIG == states.init)
        {
            /* Enable STC interrupt and configure GPIO2 for interrupt transmission */
            shadowRegisters[GPIO2_REG] ^= GPIO2_ADDR;
            shadowRegisters[STCIEN_REG] ^= STCIEN_ADDR;

            //TODO set stereo/mono blend level adjustment (BLNDADJ)?
            //TODO set extended volume range (VOLEXT)?
            //TODO set seek RSSI threshold (SEEKTH) for deciding when a channel is detected?
            //TODO set seek signal2noise ratio threshold (SKSNR) for validating channels?
            //TODO set SKCNT?

            /* Regional FM settings */
            //TODO maybe set BAND if default not sufficient
            shadowRegisters[SPACE_REG] ^= SPACE_ADDR;
            shadowRegisters[DE_REG] ^= DE_ADDR;

            writeRegisters();

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

    //TODO convert to task (avoid signal recursion)
    error_t _tune(uint16_t channel)
    {
        if (states.tune == STARTTUNE)
        {
            /* Enable tuning and set channel register */
            shadowRegisters[TUNE_REG] ^= TUNE_ADDR;
            shadowRegisters[CHAN_REG] ^= CHAN_ADDR & (uint16_t)((float)channel - 87.5)*10; //TODO float allowed here?

            writeRegisters();

            states.tune = WAITTUNE;
            return SUCCESS;
        }
        else if (states.tune == WAITTUNE)
        {
            //TODO maybe move this to previous state to avoid missing interrupt
            /* Enable STC interrupt */
            Int.enable();

            states.tune = TUNECHAN;
            return SUCCESS;
        }
        else if (states.tune == TUNECHAN)
        {
            readRegisters();

            states.tune = ENDTUNE;
            return SUCCESS;
        }
        else if (states.tune == ENDTUNE)
        {
            /* Disable tuning */
            shadowRegisters[TUNE_REG] &= ~TUNE_ADDR;
            writeRegisters();

            states.tune = FINTUNE;
            return SUCCESS;
        }
        //TODO need to verify that STC has been cleared?
        else if (states.tune == FINTUNE)
        {
            signal FMClick.tuneComplete(shadowRegisters[READCHAN_REG] & READCHAN_ADDR);

            states.driver = IDLE;
            return SUCCESS;
        }
    }

    command error_t Init.init()
    {
        if (IDLE != states.driver)
            return FAIL;

        states.driver = INIT;
        states.init = SETUP;

        return _init(); 
    }

    command error_t tune(uint16_t channel)
    {
        if (IDLE != states.driver)
            return FAIL;

        states.driver = TUNE;
        states.tune = STARTTUNE;

        return _tune(channel);
    }

    command error_t seek(bool up)
    {
        if (IDLE != states.driver)
            return FAIL;

        return SUCCESS;
    }

    command uint16_t getChannel(void)
    {
        return shadowRegisters[READCHAN_REG] & READCHAN_ADDR;
    }

    command error_t setVolume(uint8_t volume)
    {
        if (IDLE != states.driver)
            return FAIL;

        states.driver = VOL;

        //TODO only set if volume actually changed
        shadowRegisters[VOL_REG] ^= volume & VOLUME_ADDR;
        writeRegisters;

        return SUCCESS;
    }

    command error_t receiveRDS(bool enable)
    {
        if (IDLE != states.driver)
            return FAIL;

        states.driver = CONFRDS;

        //TODO compare with current RDS state and only send command if it changed
        
        if (enable)
        {
            shadowRegisters[RDS_REG] ^= RDS_ADDR;
            shadowRegisters[RDSIEN_REG] ^= RDSIEN_ADDR;
        }
        else
        {
            shadowRegisters[RDS_REG] &= ~RDS_ADDR;
            shadowRegisters[RDSIEN_REG] &= ~RDSIEN_ADDR;
        }

        writeRegisters();

        return SUCCESS;
    }

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

        switch (states.driver)
        {
            case INIT:
                _init();
                break;

            case TUNE:
                _tune(0);
                break;
            
            default:
                break;
        }
    }

    //TODO handle error
    async event I2C.writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
    { 
        switch (states.driver)
        {
            case INIT:
                _init();
                break;

            case TUNE:
                _tune(0);
                break;

            case CONFRDS:
                states.driver = IDLE;
                break;
            
            case VOL:
                states.driver = IDLE;
                break;
            
            default:
                break;
        }
    }

    async event Int.fired()
    {
        //TODO first int STC, subseq. ints RDS
        Int.disable(); //TODO disable after all RDS info has been received if enabled

        switch (states.driver)
        {
            case TUNE:
                _tune(0);
                break;

            default:
                break;
        }
    }
}

