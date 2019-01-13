/**
 *
 * @file RadioScannerP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-20
 *
 * Implementation of the RadioScanner app.
 *
**/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

module RadioScannerP {
    uses
    {
        interface Boot;
        interface Glcd;
        interface BufferedLcd as Lcd;
        interface Init as DBInit;
        interface Database as DB;
        interface Init as RadioInit;
        interface FMClick as Radio;
        interface PS2 as Keyboard;
        interface Read<uint16_t> as volumeKnob;
        interface Timer<TMilli> as Timer;
    }
}

implementation {
    #define FM4 1038
    #define RADIO 921
    #define RADIOW 899

    enum app_state {INIT, KBCTRL, TUNEINP, TUNE, SEEK, BANDSEEK};
    enum app_state appState;

    char kbChar;
    uint16_t currChan;

    #define TUNEINPUT_BUF_SZ 5
    struct
    {
        uint8_t idx;
        char buf[TUNEINPUT_BUF_SZ];
    } tuneInput;
    
    //TODO defines should actually come from interface file
    #define PS_BUF_SZ   8
    #define RT_BUF_SZ   64
    #define CT_BUF_SZ   6
    struct
    {
        uint16_t piCode;
        char PS[PS_BUF_SZ+1];
        char RT[RT_BUF_SZ+1];
        char CT[CT_BUF_SZ];
    } rds;

    uint8_t oldVolume;
    uint8_t newVolume;

    task void inputTuneChannel(void);
    task void displayChannelInfo(void);
    task void setVolume(void);

    static void printVolume(void);

    ////////////////////////
    /* Tasks              */
    ////////////////////////
   
    //TODO clear RDS buffers between channel switches
    task void handleChar(void)
    {
        char c;
        enum app_state state;

        atomic 
        { 
            c = kbChar;
            state = appState;
        }

        if (KBCTRL == appState)
        {
            switch (c)
            {
                case 'h':
                    while(call Radio.receiveRDS(FALSE) != SUCCESS);
                    atomic { appState = SEEK; }
                    call Radio.seek(DOWN);
                    break;

                case 'l':
                    while(call Radio.receiveRDS(FALSE) != SUCCESS);
                    atomic { appState = SEEK; }
                    call Radio.seek(UP);
                    break;
                
                //TODO tune to channel 0 (875) before seek
                case 's':
                    while(call Radio.receiveRDS(FALSE) != SUCCESS);
                    atomic { appState = BANDSEEK; }
                    //call Radio.tune(875);
                    call Radio.seek(BAND);
                    break;

                case 't':
                    while(call Radio.receiveRDS(FALSE) != SUCCESS);
                    atomic
                    {
                        tuneInput.idx = 0;
                        memset(tuneInput.buf, 0, TUNEINPUT_BUF_SZ);
                        appState = TUNEINP;
                    }
                    post inputTuneChannel();
                    break;

                default:
                    break;
            }
        }
        else if (TUNEINP == state)
        {
            post inputTuneChannel();
        }
    }

    //TODO only write text once
    task void inputTuneChannel(void)
    {
        char c;
        uint8_t idx;
        char buf[TUNEINPUT_BUF_SZ];
        
        atomic 
        { 
            c = kbChar;
            idx = tuneInput.idx; 
        }

        call Glcd.fill(0x00);
        call Glcd.drawText("Enter channel:", 0, 10);
        
        if (isdigit(c))
        {
            if (idx < TUNEINPUT_BUF_SZ-1)
                atomic { tuneInput.buf[tuneInput.idx++] = c; }
        }

        /* Backspace */
        if (c == '\b' && idx > 0)
            atomic { tuneInput.buf[--tuneInput.idx] = '\0'; }
        
        atomic { memcpy(buf, tuneInput.buf, TUNEINPUT_BUF_SZ); }
        call Glcd.drawText(buf, 0, 20);

        /* Complete entering channel */
        if (c == 'g')
        {
            uint16_t channel = (uint16_t)strtoul(buf, NULL, 10);
            atomic { appState = TUNE; }
            call Radio.tune(channel); //TODO on failure change state back to KBCTRL - also for other commands!!
        }
    }

    task void seekBand(void)
    {
        call Radio.seek(BAND);
    }

    task void readyScreen(void)
    {
        channelInfo chan1 = {1, 1038, 12345, "  FM4   ", "YOLO"};
        channelInfo chan2 = {1, 1038, 12345, "  OE3   ", ""};
        channelInfo chan3 = {1, 1038, 12345, "  OE1   ", "yo servas habe dere"};
        channelInfo chan4 = {1, 920, 15645, "  OE23  ", "78489hj 893zlaw8z jkhsdf "};
        call Glcd.fill(0x00);
        call Glcd.drawText("Radio initialized.", 0, 10);
        //call DB.saveChannel(1, &chan1);
        //call DB.saveChannel(1, &chan2);
        //call DB.saveChannel(1, &chan3);
        //call DB.saveChannel(1, &chan4);
        //call DB.purgeChannelList();
        //call DB.getChannel(0);
        //call DB.getChannelList(FALSE);
        //call DB.saveChannel(7, &chan4);
    }

    task void radioInitFail(void)
    {
        //call Glcd.fill(0x00);
        call Glcd.drawText("Radio init failed!", 0, 10);
    }
    
    task void displayChannelInfo(void)
    {
        char freqBuf[5];
        uint16_t chan;
        
        atomic 
        { 
            chan = currChan;
            appState = KBCTRL; 
        }

        sprintf(freqBuf, "%d.%d", chan/10, chan%10);
        call Glcd.fill(0x00);
        call Glcd.drawText("Channel: ", 0, 7);
        call Glcd.drawText(freqBuf, 54, 7);
        call Glcd.drawText("MHz", 94, 7);

        while (call Radio.receiveRDS(TRUE) != SUCCESS);
    }

    task void handleRDS(void)
    {
        char line1[22], line2[22], line3[23];
        memcpy(line1, rds.RT, 21);
        memcpy(line2, rds.RT+21, 21);
        memcpy(line3, rds.RT+42, 22);
        line1[21] = '\0';
        line2[21] = '\0';
        line3[22] = '\0';

        call Glcd.fill(0x00);
        call Glcd.drawText(rds.PS, 0, 15);
        call Glcd.drawText(rds.CT, 54, 15);
        call Glcd.drawText(line1, 122, 23);
        call Glcd.drawText(line2, 122, 31);
        call Glcd.drawText(line3, 122, 39);
    }

    /* 
     * @brief Set the volume on the FMClick board if the value has changed.
     */
    task void setVolume(void)
    {
        if (newVolume != oldVolume)
        {
            if (call Radio.setVolume(newVolume) == SUCCESS)
            {
                oldVolume = newVolume;
                printVolume();
            }
        }
    }
    
    ////////////////////////
    /* Internal functions */
    ////////////////////////
   
    /* 
     * @brief Print the current volume value on the lcd screen.
     */
    static void printVolume(void)
    {
        char volBuf[3];
        
        sprintf(volBuf, "%02d", oldVolume);
        volBuf[2] = '\0';

        call Lcd.goTo(0,8);
        call Lcd.write(volBuf);
        call Lcd.forceRefresh();
    }
    
    ////////////////////////
    /* Events */
    ////////////////////////

    event void Boot.booted()
    {
        atomic { appState = INIT; }

        oldVolume = 0;
        newVolume = 0;

        call Lcd.goTo(0,0);
        call Lcd.write("Volume:");
        printVolume();

        call Glcd.fill(0x00);
        call Keyboard.init();
        call RadioInit.init();
        call DBInit.init();
        call Glcd.drawText("init fm", 0, 10);
    }
    
    event void Radio.initDone(error_t res)
    {
        if (SUCCESS == res)
        {
            //TODO probably move this somewhere else
            call Timer.startPeriodic(300);
            atomic { appState = KBCTRL; }
            post readyScreen();
        }
        else
            post radioInitFail();
    }
 
    async event void Keyboard.receivedChar(uint8_t c)
    {
        atomic { kbChar = c; }
        post handleChar();
    }

    async event void Radio.tuneComplete(uint16_t channel)
    {
        atomic { currChan = channel; }
        post displayChannelInfo();
    }

    async event void Radio.seekComplete(uint16_t channel)
    {
        atomic { currChan = channel; }
        post displayChannelInfo();
    }
   
    //TODO only post task if app is idle
    //TODO only set PS once, then ignore
    async event void Radio.rdsReceived(RDSType type, char *buf)
    { 
        switch (type)
        {
            case PS:
                memset(rds.PS, 0, PS_BUF_SZ+1);
                memcpy(rds.PS, buf, PS_BUF_SZ);
                rds.piCode = ((uint16_t)buf[PS_BUF_SZ+1]) & 0x00ff;
                rds.piCode |= ((uint16_t)buf[PS_BUF_SZ]) << 8;
                post handleRDS();
                break;

            case RT:
                memset(rds.RT, 0, RT_BUF_SZ+1);
                memcpy(rds.RT, buf, RT_BUF_SZ);
                post handleRDS();
                break;

            case TIME:
                memset(rds.CT, 0, CT_BUF_SZ);
                memcpy(rds.CT, buf, CT_BUF_SZ);
                post handleRDS();
                break;

            default:
                break;
        }
    }
    
    event void Timer.fired()
    {
        call volumeKnob.read();
    }

    event void volumeKnob.readDone(error_t res, uint16_t val)
    {
        newVolume = (uint8_t)(val >> 6);
        post setVolume();
    }
    
    event void DB.receivedChannelEntry(uint8_t id, channelInfo channel)
    {
        char buf[128];
        sprintf(buf, "q=%d,f=%d,p=%d,n=%s,n=%s\n", channel.quickDial, channel.frequency, channel.pi_code, channel.name, channel.notes);
        call Glcd.drawText(buf, 0, 40);
    }

    event void DB.savedChannel(uint8_t id, uint8_t result)
    {
        //call Glcd.drawText("sc ev", 0, 40);
    }
}
