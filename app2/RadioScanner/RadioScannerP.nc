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
        char PS[PS_BUF_SZ+1];
        char RT[RT_BUF_SZ+1];
        char CT[CT_BUF_SZ];
    } rds;

    task void inputTuneChannel();

    ////////////////////////
    /* Tasks              */
    ////////////////////////
    
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
                    atomic { appState = SEEK; }
                    call Radio.seek(DOWN);
                    break;

                case 'l':
                    atomic { appState = SEEK; }
                    call Radio.seek(UP);
                    break;
                
                //TODO tune to channel 0 (875) before seek
                case 's':
                    atomic { appState = BANDSEEK; }
                    //call Radio.tune(875);
                    call Radio.seek(BAND);
                    break;

                case 't':
                    call Radio.receiveRDS(FALSE);
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
        call Glcd.fill(0x00);
        call Glcd.drawText("Radio initialized.", 0, 10);
    }

    task void radioInitFail(void)
    {
        //call Glcd.fill(0x00);
        call Glcd.drawText("Radio init failed!", 0, 10);
    }

    task void finishedTuning(void)
    {
        char buf[5];
        uint16_t chan;
        
        atomic 
        { 
            chan = currChan;
            appState = KBCTRL; 
        }

        sprintf(buf, "%u", chan);
        call Glcd.drawText("tuned to station", 0, 10);
        call Glcd.drawText(buf, 0, 40);
        
        call Radio.receiveRDS(TRUE);
    }

    task void finishedSeeking(void)
    {
        char buf[5];
        uint16_t chan;
        
        atomic 
        { 
            chan = currChan;
            appState = KBCTRL; 
        }

        sprintf(buf, "%u", chan);
        call Glcd.drawText("next station", 0, 10);
        call Glcd.drawText(buf, 0, 40);
    }

    task void handleRDS(void)
    {
        char line1[21], line2[21], line3[25];
        memcpy(line1, rds.RT, 20);
        memcpy(line2, rds.RT+20, 20);
        memcpy(line3, rds.RT+40, 24);
        line1[20] = '\0';
        line2[20] = '\0';
        line3[24] = '\0';

        call Glcd.fill(0x00);
        call Glcd.drawText(rds.PS, 0, 20);
//        call Glcd.drawText(rds.RT, 0, 30);
        call Glcd.drawText(line1, 0, 30);
        call Glcd.drawText(line2, 0, 40);
        call Glcd.drawText(line3, 0, 50);
        call Glcd.drawText(rds.CT, 0, 60);
    }
    
    ////////////////////////
    /* Internal functions */
    ////////////////////////
    
    ////////////////////////
    /* Events */
    ////////////////////////

    event void Boot.booted()
    {
        atomic { appState = INIT; }
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
        enum app_state state; 
        
        atomic 
        { 
            currChan = channel;
            state = appState;
        }
       
        if (BANDSEEK == state)
            post seekBand();
        else
            post finishedTuning();
    }

    async event void Radio.seekComplete(uint16_t channel)
    {
        atomic { currChan = channel; }
        post finishedSeeking();
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

    //TODO only set volume if value has actually changed
    event void volumeKnob.readDone(error_t res, uint16_t val)
    {
        //TODO maybe post task
        //TODO maybe use logarithmic scaling
        call Radio.setVolume((uint8_t)(val >> 6));    
    }
    
    event void DB.receivedChannelEntry(uint8_t id, channelInfo channel)
    {

    }

    event void DB.savedChannel(uint8_t id, uint8_t result)
    {

    }
}
