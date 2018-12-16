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
    #define XOSCEN_MASK         0x8000
    #define ENABLE_REG          0x02
    #define ENABLE_MASK         0x0001
    #define DISABLE_REG         0x02
    #define DISABLE_MASK        0x0020
    #define DMUTE_REG           0x02
    #define DMUTE_MASK          0x4000
    #define GPIO2_REG           0x04
    #define GPIO2_MASK          0x000c
    #define GPIO2_VAL           0x0004 /* Configures GPIO2 to fire RDS/STC interrupts */
    #define BLNDADJ_REG         0x04
    #define BLNDADJ_MASK        0x00c0
    #define BLNDADJ_VAL         0x0000 /* Default */
    #define VOLEXT_REG          0x06
    #define VOLEXT_MASK         0x0080
    #define SEEKTH_REG          0x05
    #define SEEKTH_MASK         0xff00
    #define SEEKTH_VAL          0x1900 /* Recommended */
    #define SKSNR_REG           0x06
    #define SKSNR_MASK          0x00f0
    #define SKSNR_VAL           0x0040 /* Good SNR threshold */ 
    #define SKCNT_REG           0x06
    #define SKCNT_MASK          0x000f
    #define SKCNT_VAL           0x0008 /* More stringent valid station requirements */
    #define RDS_REG             0x04
    #define RDS_MASK            0x0800
    #define RDSIEN_REG          0x04
    #define RDSIEN_MASK         0x8000
    #define STCIEN_REG          0x04
    #define STCIEN_MASK         0x4000
    #define BAND_REG            0x05
    #define BAND_MASK           0x00c0
    #define BAND_VAL            0x0000 /* European FM band */
    #define SPACE_REG           0x05
    #define SPACE_MASK          0x0018 
    #define SPACE_VAL           0x0008 /* Europe FM channel spacing */
    #define DE_REG              0x04
    #define DE_MASK             0x0400 /* Europe FM de-emphasis settings */
    #define TUNE_REG            0x03
    #define TUNE_MASK           0x8000
    #define CHAN_REG            0x03
    #define CHAN_MASK           0x01ff
    #define READCHAN_REG        0x0b
    #define READCHAN_MASK       0x01ff
    #define VOLUME_REG          0x05
    #define VOLUME_MASK         0x000f

    #define XOSCEN_DELAY_MS     500
  
    //TODO do we need to read registers before every write?
    //     if yes, call readreg in interface function to avoid additional state

    uint16_t shadowRegisters[REGISTER_NUM];
    uint8_t comBuffer[REGISTER_NUM*REGISTER_WIDTH];

    enum driver_state {IDLE, INIT, TUNE, SEEK, VOL, CONFRDS};
    enum com_state {REQ, COM};
    enum bus_state {IDLE, READ, WRITE};
    enum init_state {SETUP, XOSCEN, WAITXOSC, ENABLE, READREGF, CONFIG, FINISH};
    enum tune_state {STARTTUNE, WAITTUNE, TUNECHAN, ENDTUNE, FINTUNE};

    //TODO make bitfield
    struct
    {
        enum driver_state   driver;
        enum com_state      read;
        enum com_state      write;
        enum bus_state      bus;
        enum init_state     init;
        enum tune_state     tune;
    } states;

    void readRegisters()
    {
        if (REQ == states.read)
        {
            states.bus = READ;
            states.read = COM;
            //TODO check error?
            call I2CResource.request();
        }
        else if (COM == states.read)
        {
            while (call I2C.read(I2C_START | I2C_STOP, DEVICE_READ_ADDR, REGISTER_NUM*REGSITER_WIDTH, comBuffer) != SUCCESS);
            states.read = REQ;
        }
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

    void writeRegisters()
    {
        if (REQ == states.write)
        {
            /* Write buffered registerst to communication buffer */
            uint8_t i = WRITE_START_ADDR;
            for (uint8_t j = 0; j < REGISTER_NUM*REGISTER_WIDTH; j += REGISTER_WIDTH)
            {
                comBuffer[j] = (uint8_t) (shadowRegister[i] >> 8);
                comBuffer[j+1] = (uint8_t) shadowRegister[i];
                i = (i+1) & (REGISTER_NUM-1);
            }

            states.bus = WRITE;
            states.read = COM;
            //TODO check error?
            call I2CResource.request();
        } 
        else if (COM == states.write)
        {
            while (call I2C.write(I2C_START | I2C_STOP, DEVICE_WRITE_ADDR, REGISTER_NUM*REGISTER_WIDTH, comBuffer) != SUCCESS);
            states.write = REQ;
        }
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
            shadowRegisters[XOSCEN_REG] |= XOSCEN_MASK;
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
            shadowRegisters[ENABLE_REG] |= ENABLE_MASK;
            shadowRegisters[DISABLE_REG] &= ~DISABLE_MASK;
            shadowRegisters[DMUTE_REG] &= ~DMUTE_MASK;
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
            shadowRegisters[GPIO2_REG] = (shadowRegisters[GPIO2_REG] & ~GPIO2_MASK) | GPIO2_VAL;
            shadowRegisters[STCIEN_REG] |= STCIEN_MASK;

            /* General configuration */
            shadowRegisters[BLNDADJ_REG] = (shadowRegisters[BLNDADJ_REG] & ~BLNDADJ_MASK) | BLNDADJ_VAL;
            shadowRegisters[VOLEXT_REG] &= VOLEXT_MASK; /* Don't use extended volume range */
            shadowRegisters[SEEKTH_REG] = (shadowRegisters[SEEKTH_REG] & ~SEEKTH_MASK) | SEEKTH_VAL;
            shadowRegisters[SKSNR_REG] = (shadowRegisters[SKSNR_REG] & ~SKSNR_MASK) | SKSNR_VAL;
            shadowRegisters[SKCNT_REG] = (shadowRegisters[SKCNT_REG] & ~SKCNT_MASK) | SKCNT_VAL;

            /* Regional FM settings */
            shadowRegisters[BAND_REG] = (shadowRegisters[BAND_REG] & ~BAND_MASK) | BAND_VAL;
            shadowRegisters[SPACE_REG] = (shadowRegisters[SPACE_REG] & ~SPACE_MASK) | SPACE_VAL;
            shadowRegisters[DE_REG] |= DE_MASK;

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
            shadowRegisters[TUNE_REG] |= TUNE_MASK;
            //TODO float allowed here? alternative: multiply by 10 before doing calculation
            shadowRegisters[CHAN_REG] |= (shadowRegisters[CHAN_REG] & ~CHAN_MASK) | (CHAN_MASK & (uint16_t)((float)channel - 87.5)*10); 

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
            shadowRegisters[TUNE_REG] &= ~TUNE_MASK;
            writeRegisters();

            states.tune = FINTUNE;
            return SUCCESS;
        }
        //TODO need to verify that STC has been cleared?
        else if (states.tune == FINTUNE)
        {
            signal FMClick.tuneComplete(shadowRegisters[READCHAN_REG] & READCHAN_MASK);

            states.driver = IDLE;
            return SUCCESS;
        }
    }

    command error_t Init.init()
    {
        if (IDLE != states.driver)
            return FAIL;

        states.driver = INIT;
        states.read = REQ;
        states.write = REQ;
        states.bus = IDLE;
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
        return shadowRegisters[READCHAN_REG] & READCHAN_MASK;
    }

    command error_t setVolume(uint8_t volume)
    {
        if (IDLE != states.driver)
            return FAIL;

        states.driver = VOL;

        //TODO only set if volume actually changed
        shadowRegisters[VOL_REG] = (shadowRegisters[VOL_REG] & ~VOLUME_MASK) | (volume & VOLUME_MASK);
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
            shadowRegisters[RDS_REG] |= RDS_MASK;
            shadowRegisters[RDSIEN_REG] |= RDSIEN_MASK;
        }
        else
        {
            shadowRegisters[RDS_REG] &= ~RDS_MASK;
            shadowRegisters[RDSIEN_REG] &= ~RDSIEN_MASK;
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
        I2CResource.release();
        states.bus = IDLE;
        
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
        I2CResource.release();
        states.bus = IDLE;

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

    event void I2CResource.granted()
    {
        switch (states.bus)
        {
            case READ:
                readRegisters();
                break;

            case WRITE:
                writeRegisters();
                break;

            default:
                I2CResource.release();
                break;
        }
    }
}

