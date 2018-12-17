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
        interface I2CPacket<TI2CBasicAddr> as I2C;
        interface Timer<TMilli> as Timer;
        interface GeneralIO as RSTPin;
        interface GeneralIO as SDIOPin;
        interface Glcd;
    }
}

implementation {
    /* I2C addresses */
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
    #define DISABLE_MASK        0x0040
    #define DMUTE_REG           0x02
    #define DMUTE_MASK          0x4000
    #define GPIO2_REG           0x04
    #define GPIO2_MASK          0x000c
    #define GPIO2_VAL           0x0004 /* Configures GPIO2 to fire RDS/STC interrupts */
    #define BLNDADJ_REG         0x04
    #define BLNDADJ_MASK        0x00c0
    #define BLNDADJ_VAL         0x0000 /* Default */
    #define VOLEXT_REG          0x06
    #define VOLEXT_MASK         0x0100
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
    #define RDS_MASK            0x1000
    #define RDSIEN_REG          0x04
    #define RDSIEN_MASK         0x8000
    #define STCIEN_REG          0x04
    #define STCIEN_MASK         0x4000
    #define BAND_REG            0x05
    #define BAND_MASK           0x00c0
    #define BAND_VAL            0x0000 /* European FM band */
    #define SPACE_REG           0x05
    #define SPACE_MASK          0x0030 
    #define SPACE_VAL           0x0008 /* Europe FM channel spacing */
    #define DE_REG              0x04
    #define DE_MASK             0x0800 /* Europe FM de-emphasis settings */
    #define TUNE_REG            0x03
    #define TUNE_MASK           0x8000
    #define CHAN_REG            0x03
    #define CHAN_MASK           0x03ff
    #define READCHAN_REG        0x0b
    #define READCHAN_MASK       0x03ff
    #define VOLUME_REG          0x05
    #define VOLUME_MASK         0x000f
    #define SEEKUP_REG          0x02
    #define SEEKUP_MASK         0x0200
    #define SKMODE_REG          0x02
    #define SKMODE_MASK         0x0400
    #define SEEK_REG            0x02
    #define SEEK_MASK           0x0100
    #define RDSA_REG            0x0c
    #define RDSB_REG            0x0d
    #define RDSC_REG            0x0e
    #define RDSD_REG            0x0f

    #define XOSCEN_DELAY_MS     1000
  
    //TODO do we need to read registers before every write?
    //     if yes, call readreg in interface function to avoid additional state

    uint16_t shadowRegisters[REGISTER_NUM];
    uint8_t comBuffer[REGISTER_NUM*REGISTER_WIDTH];

    enum driver_state {IDLE, INIT, TUNE, SEEK, VOL, CONFRDS};
    enum com_state {REQ, COM};
    enum bus_state {NOOP, READ, WRITE};
    enum init_state {SETUP, XOSCEN, WAITXOSC, ENABLE, READREGF, CONFIG, FINISH};
    enum tune_state {STARTTUNE, WAITTUNE, TUNECHAN, ENDTUNE, FINTUNE};
    enum seek_state {STARTSEEK, WAITSEEK, SEEKCHAN, ENDSEEK, FINSEEK};

    //TODO make bitfield
    struct
    {
        enum driver_state   driver;
        enum com_state      read;
        enum com_state      write;
        enum bus_state      bus;
        enum init_state     init;
        enum tune_state     tune;
        enum seek_state     seek;
    } states;

    uint16_t nextChannel;

    void readRegisters()
    {
        enum com_state state;
        atomic { state = states.read; }
        if (REQ == state)
        {
            atomic
            {
                states.bus = READ;
                states.read = COM;
            }

            //TODO check error?
            call I2CResource.request();
        }
        else if (COM == state)
        {
            while (call I2C.read(I2C_START | I2C_STOP, DEVICE_READ_ADDR, REGISTER_NUM*REGISTER_WIDTH, comBuffer) != SUCCESS);
            atomic { states.read = REQ; }
        }
    }

    void registerWriteback()
    {
        uint8_t i = READ_START_ADDR;
        uint8_t j;
        for (j = 0; j < REGISTER_NUM*REGISTER_WIDTH; j += REGISTER_WIDTH)
        {
            shadowRegisters[i] = (comBuffer[j] << 8) | comBuffer[j+1];
            i = (i+1) & (REGISTER_NUM-1);
        }
    }

    void writeRegisters()
    {
        enum com_state state;
        atomic { state = states.write; }
        
        if (REQ == state)
        {
            /* Write buffered registers to communication buffer */
            uint8_t i = WRITE_START_ADDR;
            uint8_t j;
            
            for (j = 0; j < REGISTER_NUM*REGISTER_WIDTH; j += REGISTER_WIDTH)
            {
                atomic
                {
                    comBuffer[j] = (uint8_t) (shadowRegisters[i] >> 8);
                    comBuffer[j+1] = (uint8_t) shadowRegisters[i];
                }
                i = (i+1) & (REGISTER_NUM-1);
            }

            atomic
            {
                states.bus = WRITE;
                states.write = COM;
            }

            //TODO check error?
            call I2CResource.request();
        } 
        else if (COM == state)
        {
            while (call I2C.write(I2C_START | I2C_STOP, DEVICE_WRITE_ADDR, REGISTER_NUM*REGISTER_WIDTH, comBuffer) != SUCCESS);
            atomic { states.write = REQ; }
        }
    }

    //TODO sgnal FAIL on error
    task void _init()
    {
        enum init_state state;
        atomic { state = states.init; }
        
        if (SETUP == state)
        {
            call RSTPin.makeOutput();
            call RSTPin.clr();
            
            /* Select 2-wire mode */
            call SDIOPin.makeOutput();
            call SDIOPin.clr();

            /* Set falling edge on STC/RDS interrupt */
            call Int.edge(0);

            /* Finish reset */
            call RSTPin.set();

            /* Read initial register file state */
            readRegisters();

            atomic { states.init = XOSCEN; }
        }
        else if (XOSCEN == state)
        {
            /* Start internal oscillator */
            atomic { shadowRegisters[XOSCEN_REG] |= XOSCEN_MASK; }
            writeRegisters();

            atomic { states.init = WAITXOSC; }
        }
        else if (WAITXOSC == state)
        {
            /* Wait for oscillator to stabilize */
            call Timer.startOneShot(XOSCEN_DELAY_MS);
            
            atomic { states.init = ENABLE; }
        }
        else if (ENABLE == state)
        {
            atomic
            {
                /* Start device powerup and disable mute */
                shadowRegisters[ENABLE_REG] |= ENABLE_MASK;
                shadowRegisters[DISABLE_REG] &= ~DISABLE_MASK;
                shadowRegisters[DMUTE_REG] &= ~DMUTE_MASK;
            }

            writeRegisters();

            atomic { states.init = READREGF; }
        }
        else if (READREGF == state)
        {
            /* Read initial register file state */
            readRegisters();
            
            atomic { states.init = CONFIG; }
        }
        else if (CONFIG == state)
        {
            atomic
            {
                /* Enable STC interrupt and configure GPIO2 for interrupt transmission */
                shadowRegisters[GPIO2_REG] = (shadowRegisters[GPIO2_REG] & ~GPIO2_MASK) | GPIO2_VAL;
                shadowRegisters[STCIEN_REG] |= STCIEN_MASK;

                /* General configuration */
                shadowRegisters[BLNDADJ_REG] = (shadowRegisters[BLNDADJ_REG] & ~BLNDADJ_MASK) | BLNDADJ_VAL;
                shadowRegisters[VOLEXT_REG] &= ~VOLEXT_MASK; /* Don't use extended volume range */
                shadowRegisters[SEEKTH_REG] = (shadowRegisters[SEEKTH_REG] & ~SEEKTH_MASK) | SEEKTH_VAL;
                shadowRegisters[SKSNR_REG] = (shadowRegisters[SKSNR_REG] & ~SKSNR_MASK) | SKSNR_VAL;
                shadowRegisters[SKCNT_REG] = (shadowRegisters[SKCNT_REG] & ~SKCNT_MASK) | SKCNT_VAL;

                /* Regional FM settings */
                shadowRegisters[BAND_REG] = (shadowRegisters[BAND_REG] & ~BAND_MASK) | BAND_VAL;
                shadowRegisters[SPACE_REG] = (shadowRegisters[SPACE_REG] & ~SPACE_MASK) | SPACE_VAL;
                shadowRegisters[DE_REG] |= DE_MASK;
        
                //TODO remove this later
                shadowRegisters[VOLUME_REG] = (shadowRegisters[VOLUME_REG] & ~VOLUME_MASK) | (15 & VOLUME_MASK);
            }

            writeRegisters();

            atomic { states.init = FINISH; }
        }
        else if (FINISH == state)
        {
            //TODO pass correct exit state
            signal FMClick.initDone(SUCCESS);

            atomic { states.driver = IDLE; }
        }
    }

    //TODO sgnal FAIL on error
    task void _tune()
    {
        enum tune_state state;
        atomic { state = states.tune; }
        
        if (STARTTUNE == state)
        {
            call Glcd.drawText("a", 0, 20);
            atomic
            {
                /* Enable tuning and set channel register */
                shadowRegisters[TUNE_REG] |= TUNE_MASK;
                shadowRegisters[CHAN_REG] |= (shadowRegisters[CHAN_REG] & ~CHAN_MASK) | 
                                             (CHAN_MASK & (nextChannel - 875)); 
            }

            writeRegisters();

            atomic { states.tune = WAITTUNE; }
        }
        else if (WAITTUNE == state)
        {
            call Glcd.drawText("b", 0, 20);
            //TODO maybe move this to previous state to avoid missing interrupt
            /* Enable STC interrupt */
            call Int.enable();

            atomic { states.tune = TUNECHAN; }
        }
        else if (TUNECHAN == state)
        {
            call Glcd.drawText("c", 0, 20);
            readRegisters();

            atomic { states.tune = ENDTUNE; }
        }
        else if (ENDTUNE == state)
        {
            call Glcd.drawText("d", 0, 20);
            /* Disable tuning */
            atomic { shadowRegisters[TUNE_REG] &= ~TUNE_MASK; }
            writeRegisters();

            atomic { states.tune = FINTUNE; }
        }
        //TODO need to verify that STC has been cleared?
        else if (FINTUNE == state)
        {
            uint16_t channel;
            call Glcd.drawText("e", 0, 20);
            atomic { channel = (shadowRegisters[READCHAN_REG] & READCHAN_MASK) + 875; }
            signal FMClick.tuneComplete(channel);

            atomic { states.driver = IDLE; }
        }
    }

    //TODO convert to task (avoid signal recursion)
    error_t _seek(bool up)
    {
        if (states.seek == STARTSEEK)
        {
            atomic
            {
                /* Wrap around band limits */
                shadowRegisters[SKMODE_REG] &= ~SKMODE_MASK;
                shadowRegisters[SEEK_REG] |= SEEK_MASK;
            }

            //TODO to seek entire band set CHAN to 00, SEEKUP to 1 and SKMODE to 1

            if (up)
                atomic { shadowRegisters[SEEKUP_REG] |= SEEKUP_MASK; }
            else
                atomic { shadowRegisters[SEEKUP_REG] &= ~SEEKUP_MASK; }

            writeRegisters();

            states.seek = WAITSEEK;
            return SUCCESS;
        }
        else if (states.seek == WAITSEEK)
        {
            //TODO maybe move this to previous state to avoid missing interrupt
            /* Enable STC interrupt */
            call Int.enable();

            states.seek = SEEKCHAN;
            return SUCCESS;
        }
        else if (states.seek == SEEKCHAN)
        {
            readRegisters();

            states.seek = ENDSEEK;
            return SUCCESS;
        }
        else if (states.seek == ENDSEEK)
        {
            /* Disable seeking */
            atomic { shadowRegisters[SEEK_REG] &= ~SEEK_MASK; }
            writeRegisters();

            states.seek = FINSEEK;
            return SUCCESS;
        }
        //TODO need to verify that STC has been cleared?
        else if (states.seek == FINSEEK)
        {
            //TODO generate new signal for seek
            //TODO check SF/BL bits if channel is valid
            signal FMClick.tuneComplete(shadowRegisters[READCHAN_REG] & READCHAN_MASK);

            states.driver = IDLE;
        }
        return SUCCESS;
    }

    command error_t Init.init()
    {
        enum driver_state state;
        atomic { state = states.driver; }

        if (IDLE != state)
            return FAIL;

        atomic 
        {
            states.driver = INIT;
            states.read = REQ;
            states.write = REQ;
            states.bus = NOOP;
            states.init = SETUP;
        }

        post _init();
        return SUCCESS; 
    }

    command error_t FMClick.tune(uint16_t channel)
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        if (IDLE != state)
            return FAIL;

        call Glcd.drawText("x", 0, 20);
        
        atomic
        {
            states.driver = TUNE;
            states.tune = STARTTUNE;
            nextChannel = channel;
        }

        post _tune();
        return SUCCESS;
    }

    command error_t FMClick.seek(bool up)
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        if (IDLE != state)
            return FAIL;

        atomic
        {
            states.driver = SEEK;
            states.seek = STARTSEEK;
        }

        return _seek(up);
    }

    command uint16_t FMClick.getChannel(void)
    {
        uint16_t channel;
        atomic { channel = (shadowRegisters[READCHAN_REG] & READCHAN_MASK) + 875; }
        return channel;
    }

    //TODO generate signal when finished
    command error_t FMClick.setVolume(uint8_t volume)
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        if (IDLE != state)
            return FAIL;
 
        atomic { states.driver = VOL; }

        //TODO only set if volume actually changed
        atomic { shadowRegisters[VOLUME_REG] = (shadowRegisters[VOLUME_REG] & ~VOLUME_MASK) | (volume & VOLUME_MASK); }
        writeRegisters();

        return SUCCESS;
    }

    command error_t FMClick.receiveRDS(bool enable)
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        if (IDLE != state)
            return FAIL;

        atomic { states.driver = CONFRDS; }

        //TODO compare with current RDS state and only send command if it changed
        
        if (enable)
        {
            atomic
            {
                shadowRegisters[RDS_REG] |= RDS_MASK;
                shadowRegisters[RDSIEN_REG] |= RDSIEN_MASK;
            }
        }
        else
        {
            atomic
            {
                shadowRegisters[RDS_REG] &= ~RDS_MASK;
                shadowRegisters[RDSIEN_REG] &= ~RDSIEN_MASK;
            }
        }

        writeRegisters();

        return SUCCESS;
    }

    event void Timer.fired()
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        switch (state)
        {
            case INIT:
                post _init();
                break;

            default:
                break;
        }
    }
   
    //TODO handle error
    async event void I2C.readDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        call I2CResource.release();
        atomic { states.bus = NOOP; }
        
        registerWriteback();

        switch (state)
        {
            case INIT:
                post _init();
                break;

            case TUNE:
                post _tune();
                break;
            
            case SEEK:
                _seek(0);
                break;
            
            default:
                break;
        }
    }

    //TODO handle error
    async event void I2C.writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        call I2CResource.release();
        atomic { states.bus = NOOP; }

        switch (state)
        {
            case INIT:
                post _init();
                break;

            case TUNE:
                post _tune();
                break;

            case SEEK:
                _seek(0);
                break;
            
            case CONFRDS:
                atomic { states.driver = IDLE; }
                break;
            
            case VOL:
                atomic { states.driver = IDLE; }
                break;
            
            default:
                break;
        }
    }

    async event void Int.fired()
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        //TODO first int STC, subseq. ints RDS
        call Int.disable(); //TODO disable after all RDS info has been received if enabled

        switch (state)
        {
            case TUNE:
                post _tune();
                break;

            case SEEK:
                _seek(0);
                break;
            
            default:
                break;
        }
    }

    event void I2CResource.granted()
    {
        enum driver_state state;
        atomic { state = states.bus; }
        
        switch (state)
        {
            case READ:
                readRegisters();
                break;

            case WRITE:
                writeRegisters();
                break;

            default:
                call I2CResource.release();
                break;
        }
    }
}

