/**
 *
 * @file FMClickP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-12
 *
 * FMClick module implementation.
 *
**/

//TODO read only required registers
//TODO make function prototypes and move internal functions to bottom of file
//TODO extend interface to provide seekDone signal and functions for seeking entire band or next channel

#include <stdio.h>
#include <string.h>

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
        interface GeneralIO as INTPin;
        interface Glcd;
    }
}

implementation {
    /* I2C addresses */
    #define DEVICE_WRITE_ADDR   0x10
    #define DEVICE_READ_ADDR    0x10

    /* Register file parameters */
    #define REGISTER_NUM        16
    #define REGISTER_WIDTH      2       /* Bytes per register word */
    #define READ_START_ADDR     0x0a    /* First address read by I2C communication */
    #define WRITE_START_ADDR    0x02    /* First address written by I2C communication */
    
    /* Register file addresses */
    #define DEVID_REG           0x00
    #define CHIPID_REG          0x01
    #define POWERCONF_REG       0x02
    #define CHANNEL_REG         0x03
    #define SYSCONF1_REG        0x04
    #define SYSCONF2_REG        0x05
    #define SYSCONF3_REG        0x06
    #define TEST1_REG           0x07
    #define STATRSSI_REG        0x0a
    #define READCHAN_REG        0x0b
    #define RDSA_REG            0x0c
    #define RDSB_REG            0x0d
    #define RDSC_REG            0x0e
    #define RDSD_REG            0x0f

    /* Chip ID */
    #define POWERUP_VAL         0x1253
    #define POWERDOWN_VAL       0x1200

    /* Power Configuration */
    #define ENABLE_MASK         0x0001
    #define DISABLE_MASK        0x0040
    #define DMUTE_MASK          0x4000
    #define SEEKUP_MASK         0x0200
    #define SKMODE_MASK         0x0400
    #define SEEK_MASK           0x0100

    /* Channel */
    #define TUNE_MASK           0x8000
    #define CHAN_MASK           0x03ff

    /* System Configuration 1 */
    #define GPIO2_MASK          0x000c
    #define GPIO2_VAL           0x0004  /* Configures GPIO2 to fire RDS/STC interrupts */
    #define BLNDADJ_MASK        0x00c0
    #define BLNDADJ_VAL         0x0000  /* Default */
    #define RDS_MASK            0x1000
    #define RDSIEN_MASK         0x8000
    #define STCIEN_MASK         0x4000
    #define DE_MASK             0x0800 /* Europe FM de-emphasis settings */

    /* System Configuration 2 */
    #define SEEKTH_MASK         0xff00
    #define SEEKTH_VAL          0x1900  /* Recommended */
    #define BAND_MASK           0x00c0
    #define BAND_VAL            0x0000 /* European FM band */
    #define SPACE_MASK          0x0030 
    #define SPACE_VAL           0x0010 /* Europe FM channel spacing */
    #define VOLUME_MASK         0x000f

    /* System Configuration 3 */
    #define VOLEXT_MASK         0x0100
    #define SKSNR_MASK          0x00f0
    #define SKSNR_VAL           0x0040  /* Good SNR threshold */ 
    #define SKCNT_MASK          0x000f
    #define SKCNT_VAL           0x0008  /* More stringent valid station requirements */

    /* Test 1 */
    #define XOSCEN_MASK         0x8000

    /* Status RSSI */
    #define RDSR_MASK           0x8000
    #define STC_MASK            0x4000
    #define SFBL_MASK           0x2000
    #define BLERA_MASK          0x0600
    #define ST_MASK             0x0100
    #define RSSI_MASK           0x00ff

    /* Read Channel */
    #define READCHAN_MASK       0x03ff

    #define RESET_DELAY_MS      10
    #define READ_DELAY_MS       1000
    #define XOSCEN_DELAY_MS     600
    #define POWERUP_DELAY_MS    150

    #define BAND_LOW_END        875
    #define BAND_HIGH_END       1080

    uint16_t shadowRegisters[REGISTER_NUM];
    uint8_t comBuffer[REGISTER_NUM*REGISTER_WIDTH];
    uint8_t writeAddr;

    enum driver_state {IDLE, INIT, TUNE, SEEK, VOL, CONFRDS};
    enum com_state {REQ, COM};
    enum bus_state {NOOP, READ, WRITE};
    enum init_state {SETUP,INITREG, XOSCEN, WAITXOSC, ENABLE, WAITPOWERUP, READREGF, CONFIG, FINISH};
    enum tune_state {STARTTUNE, WAITTUNE, TUNECHAN, ENDTUNE, READTUNE, FINTUNE};
    enum seek_state {STARTSEEK, WAITSEEK, SEEKCHAN, ENDSEEK, READSEEK, FINSEEK};

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
    bool seekUp;

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
            //TODO maybe throw error (GLCD?) instead of hanging
            while (call I2C.read(I2C_START | I2C_STOP,
                   DEVICE_READ_ADDR,
                   REGISTER_NUM*REGISTER_WIDTH,
                   comBuffer) != SUCCESS);
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
            uint8_t bytesToSend;

            atomic { bytesToSend = (writeAddr-WRITE_START_ADDR+1)*REGISTER_WIDTH; }
           
            for (j = 0; j < bytesToSend; j += REGISTER_WIDTH)
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
            uint8_t bytesToSend;
            atomic { bytesToSend = (writeAddr-WRITE_START_ADDR+1)*REGISTER_WIDTH; }
            
            //TODO maybe throw error (GLCD?) instead of hanging
            while (call I2C.write(I2C_START | I2C_STOP, 
                   DEVICE_WRITE_ADDR,
                   bytesToSend,
                   comBuffer) != SUCCESS);
            atomic { states.write = REQ; }
        }
    }

    //TODO sgnal FAIL on error
    task void init()
    {
        enum init_state state;
        atomic { state = states.init; }
        
        if (SETUP == state)
        {
            /* Finish reset */
            call RSTPin.set();
            call Timer.startOneShot(READ_DELAY_MS); 
            atomic { states.init = INITREG; }
        }
        if (INITREG == state)
        {
            /* Read initial register file state */
            atomic { states.init = XOSCEN; }
            readRegisters(); 
        }
        //TODO remove if not needed
        else if (XOSCEN == state)
        {
            /* Start internal oscillator and clear RDSD */
            atomic
            { 
                shadowRegisters[TEST1_REG] |= XOSCEN_MASK;
                shadowRegisters[RDSD_REG] = 0x0000;
                writeAddr = RDSD_REG;
                states.init = WAITXOSC;
            }
            writeRegisters();
        }
        else if (WAITXOSC == state)
        {
            /* Wait for oscillator to stabilize */
            atomic { states.init = ENABLE; }
            call Timer.startOneShot(XOSCEN_DELAY_MS); 
        }
        else if (ENABLE == state)
        {
            atomic
            {
                /* Start device powerup and disable mute */
                shadowRegisters[POWERCONF_REG] = (shadowRegisters[POWERCONF_REG] & ~DISABLE_MASK) |
                                                 ENABLE_MASK | DMUTE_MASK;
                writeAddr = POWERCONF_REG;
                states.init = WAITPOWERUP;
            }
            writeRegisters();
        }
        else if (WAITPOWERUP == state)
        {
            /* Wait for chip powerup */
            call Timer.startOneShot(POWERUP_DELAY_MS); 
            atomic { states.init = READREGF; }
        }
        else if (READREGF == state)
        {
            /* Read register file state */
            atomic { states.init = CONFIG; }
            readRegisters();
        }
        else if (CONFIG == state)
        {
            char buf[7];

            uint16_t chipIDReg;
            atomic { chipIDReg = shadowRegisters[CHIPID_REG]; }
            
            sprintf(buf, "0x%X", shadowRegisters[CHIPID_REG]);
            call Glcd.drawText(buf, 0, 20);
            sprintf(buf, "0x%X", shadowRegisters[POWERCONF_REG]);
            call Glcd.drawText(buf, 36, 20);
            
            if (POWERUP_VAL != chipIDReg)
            {
                atomic { states.driver = IDLE; }
                signal FMClick.initDone(FAIL);
                return;
            }

            atomic
            {
                /* Enable STC interrupt and configure GPIO2 for interrupt transmission */
                shadowRegisters[SYSCONF1_REG] = (shadowRegisters[SYSCONF1_REG] & ~(GPIO2_MASK | BLNDADJ_MASK)) |
                                                GPIO2_VAL | BLNDADJ_VAL | STCIEN_MASK | DE_MASK;
                /* General and regional configuration */
                shadowRegisters[SYSCONF2_REG] = (shadowRegisters[SYSCONF2_REG] &
                                                ~(SEEKTH_MASK | BAND_MASK | SPACE_MASK | VOLUME_MASK)) |
                                                SEEKTH_VAL | BAND_VAL | SPACE_VAL | 15;
                shadowRegisters[SYSCONF3_REG] = (shadowRegisters[SYSCONF3_REG] &
                                                ~(VOLEXT_MASK | SKSNR_MASK | SKCNT_MASK)) |
                                                SKSNR_VAL | SKCNT_MASK;
                writeAddr = SYSCONF3_REG;
                states.init = FINISH;
            }

            writeRegisters();
        }
        else if (FINISH == state)
        {
            atomic { states.driver = IDLE; }
            signal FMClick.initDone(SUCCESS);
        }
    }

    //TODO sgnal FAIL on error
    task void tune()
    {
        enum tune_state state;
        static uint16_t channel;
        atomic { state = states.tune; }
        
        if (STARTTUNE == state)
        {
            atomic
            {
                shadowRegisters[CHANNEL_REG] |= (shadowRegisters[CHANNEL_REG] & ~CHAN_MASK) | 
                                                TUNE_MASK | (CHAN_MASK & (nextChannel - BAND_LOW_END)); 
                writeAddr = CHANNEL_REG;
                states.tune = WAITTUNE;
            }
            writeRegisters();
        }
        else if (WAITTUNE == state)
        {
            /* Enable STC interrupt */
            //TODO timeout for interrupt
            atomic { states.tune = TUNECHAN; }
            call Int.enable();
        }
        else if (TUNECHAN == state)
        {
            atomic { states.tune = ENDTUNE; }
            readRegisters();
        }
        else if (ENDTUNE == state)
        {
            /* Read channel and disable tuning */
            atomic
            {
                channel = (shadowRegisters[READCHAN_REG] & READCHAN_MASK) + BAND_LOW_END;
                shadowRegisters[CHANNEL_REG] &= ~TUNE_MASK;
                writeAddr = CHANNEL_REG;
                states.tune = READTUNE;
            }
            writeRegisters();
        }
        else if (READTUNE == state)
        {
            /* Read registers to check STC bit */
            atomic { states.tune = FINTUNE; }
            readRegisters();
        }
        else if (FINTUNE == state)
        {
            char buf[7];
            uint8_t stc;

            sprintf(buf, "0x%X", shadowRegisters[SYSCONF2_REG]);
            call Glcd.drawText(buf, 0, 30);
            sprintf(buf, "0x%X", shadowRegisters[READCHAN_REG]);
            call Glcd.drawText(buf, 36, 30);
           
            atomic { stc = (shadowRegisters[STATRSSI_REG] & STC_MASK) >> 8; }

            /* Tuning complete */
            if (!stc)
            {
                atomic { states.driver = IDLE; }
                signal FMClick.tuneComplete(channel);
            }
            /* Read the register file until STC is cleared */
            else
            {
                atomic { states.tune = READTUNE; }
                post tune();
            }
        }
    }

    //TODO convert to task (avoid signal recursion)
    void task seek()
    {
        enum seek_state state;
        static uint8_t sfbl;
        static uint16_t channel;
        atomic { state = states.seek; }
        
        if (STARTSEEK == state)
        {
            atomic
            {
                /* Wrap around band limits */
                shadowRegisters[POWERCONF_REG] = (shadowRegisters[POWERCONF_REG] & ~SKMODE_MASK) | SEEK_MASK;
            }

            //TODO to seek entire band set CHAN to 00, SEEKUP to 1 and SKMODE to 1

            if (seekUp)
                atomic { shadowRegisters[POWERCONF_REG] |= SEEKUP_MASK; }
            else
                atomic { shadowRegisters[POWERCONF_REG] &= ~SEEKUP_MASK; }

            atomic 
            { 
                writeAddr = POWERCONF_REG; 
                states.seek = WAITSEEK;
            }
            writeRegisters();
        }
        else if (WAITSEEK == state)
        {
            /* Enable STC interrupt */
            call Int.enable();
            atomic { states.seek = SEEKCHAN; }
        }
        else if (SEEKCHAN == state)
        {
            atomic { states.seek = ENDSEEK; }
            readRegisters();
        }
        //TODO verify that STC is set, check SF/BL and RSSI
        else if (ENDSEEK == state)
        {
            /* Read sfbl bit and channel and disable seeking */
            atomic {   
                sfbl = (uint8_t)((shadowRegisters[STATRSSI_REG] & SFBL_MASK) >> 8);
                channel = (shadowRegisters[READCHAN_REG] & READCHAN_MASK) + BAND_LOW_END;
                shadowRegisters[POWERCONF_REG] &= ~SEEK_MASK;
                writeAddr = POWERCONF_REG;
                states.seek = READSEEK;
            }
            writeRegisters();
        }
        else if (READSEEK == state)
        {
            /* Read registers to check STC bit */
            atomic { states.seek = FINSEEK; }
            readRegisters();
        }
        else if (FINSEEK == state)
        {   
            char buf[7];
            uint8_t stc;
            atomic { stc = (shadowRegisters[STATRSSI_REG] & STC_MASK) >> 8; }
            
            sprintf(buf, "0x%X", shadowRegisters[SYSCONF2_REG]);
            call Glcd.drawText(buf, 0, 30);
            sprintf(buf, "0x%X", shadowRegisters[READCHAN_REG]);
            call Glcd.drawText(buf, 36, 30);
            
            /* Seek complete */
            if (!stc)
            {
                /* Channel valid */
                if (!sfbl)
                {
                    atomic { states.driver = IDLE; }
                    signal FMClick.seekComplete(channel);
                }
                /* Channel invalid, continue seeking */
                else
                {
                    atomic { states.driver = STARTSEEK; }
                    post seek();
                }
            }
            /* Read the register file until STC is cleared */
            else
            {
                atomic { states.seek = READSEEK; }
                post seek();
            }
        }
    }

    //TODO check if RESET and READ delay can be removed
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
            memset(shadowRegisters, 0, sizeof(shadowRegisters));
            memset(comBuffer, 0, sizeof(comBuffer));
        }

        /* Start board reset */
        call RSTPin.makeOutput();
        call RSTPin.clr();
        
        /* Select 2-wire mode */
        call SDIOPin.makeOutput();
        call SDIOPin.clr();

        /* Set interrupt pin as input, disable pullup and set falling edge on STC/RDS interrupt */
        call INTPin.makeInput();
        call INTPin.clr();
        call Int.edge(FALSE);

        //post init();
        call Timer.startOneShot(RESET_DELAY_MS);
        return SUCCESS; 
    }

    //TODO check if channel is valid
    //TODO check if board has been initialized (internal state)
    command error_t FMClick.tune(uint16_t channel)
    {
        enum driver_state state;
        atomic { state = states.driver; }
        
        if (IDLE != state)
            return FAIL;
        
        atomic
        {
            states.driver = TUNE;
            states.tune = STARTTUNE;
            nextChannel = channel;
        }

        post tune();
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
            seekUp = up;
        }

        post seek();
        return SUCCESS;
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
        atomic { shadowRegisters[SYSCONF2_REG] = (shadowRegisters[SYSCONF2_REG] & ~VOLUME_MASK) | (volume & VOLUME_MASK); }
            
        atomic { writeAddr = 0x05; }
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
                shadowRegisters[SYSCONF1_REG] |= RDS_MASK;
                shadowRegisters[SYSCONF1_REG] |= RDSIEN_MASK;
            }
        }
        else
        {
            atomic
            {
                shadowRegisters[SYSCONF1_REG] &= ~RDS_MASK;
                shadowRegisters[SYSCONF1_REG] &= ~RDSIEN_MASK;
            }
        }

        atomic { writeAddr = 0x04; }
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
                post init();
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
        
        if (FAIL == error)
        {
            readRegisters();
            return;
        }

        call I2CResource.release();
        atomic { states.bus = NOOP; }
        
        registerWriteback();

        switch (state)
        {
            case INIT:
                post init();
                break;

            case TUNE:
                post tune();
                break;
            
            case SEEK:
                post seek();
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

        if (FAIL == error)
        {
            writeRegisters();
            return;
        }
        
        call I2CResource.release();
        atomic { states.bus = NOOP; }

        switch (state)
        {
            case INIT:
                post init();
                break;

            case TUNE:
                post tune();
                break;

            case SEEK:
                post seek();
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
                post tune();
                break;

            case SEEK:
                post seek();
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

