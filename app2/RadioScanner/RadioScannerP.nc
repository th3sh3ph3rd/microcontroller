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
        interface Init as RadioInit;
        interface FMClick as Radio;
        interface PS2 as Keyboard;
    }
}

implementation {
    #define FM4 1038
    #define RADIO 921
    #define RADIOW 899

    enum app_state {INIT, KBCTRL, TUNEINP};
    enum app_state appState;

    char kbChar;
    uint16_t currChan;

    #define TUNEINPUT_BUF_SZ 5
    struct
    {
        uint8_t idx;
        char buf[TUNEINPUT_BUF_SZ];
    } tuneInput;

    task void inputTuneChannel();

    event void Boot.booted()
    {
        atomic { appState = INIT; }
        call Keyboard.init();
        call RadioInit.init();
        call Glcd.fill(0x00);
        call Glcd.drawText("init fm", 0, 10);
    }

    task void handleChar()
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
                    call Radio.seek(TRUE);
                    break;

                case 'l':
                    call Radio.seek(TRUE);
                    break;

                case 't':
                    //call Radio.tune(RADIOW);
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

    //TODO enable delete
    task void inputTuneChannel()
    {
        char c;
        char buf[TUNEINPUT_BUF_SZ];
        atomic { c = kbChar; }

        call Glcd.fill(0x00);
        call Glcd.drawText("Enter channel:", 0, 10);
        
        if (isdigit(c))
        {
            uint8_t idx;
            atomic { idx = tuneInput.idx; }
            if (idx < TUNEINPUT_BUF_SZ)
            {
                atomic
                {
                    tuneInput.buf[tuneInput.idx] = c;
                    tuneInput.idx++;
                }
            }
        }

        atomic { memcpy(buf, tuneInput.buf, TUNEINPUT_BUF_SZ); }
        call Glcd.drawText(buf, 0, 20);

        if (c == 'g')
        {
            uint16_t channel;
            channel = (uint16_t)strtoul(buf, NULL, 10);
            atomic { appState = KBCTRL; }
            call Radio.tune(channel);
        }
    }

    task void tune2Station()
    {
        call Glcd.drawText("init done", 0, 10);
        //call Radio.setVolume(15); not working, signal needed
        call Glcd.drawText("tune to station", 0, 10);
        call Radio.tune(RADIOW);
    }

    task void readyScreen()
    {
        call Glcd.fill(0x00);
        call Glcd.drawText("Radio initialized.", 0, 10);
    }

    task void radioInitFail()
    {
        //call Glcd.fill(0x00);
        call Glcd.drawText("Radio init failed!", 0, 10);
    }

    task void finishedTuning()
    {
        char buf[5];
        uint16_t chan;
        atomic { chan = currChan; }
        sprintf(buf, "%u", chan);
        call Glcd.drawText("tuned to station", 0, 10);
        call Glcd.drawText(buf, 0, 40);
    }

    task void finishedSeeking()
    {
        char buf[5];
        uint16_t chan;
        atomic { chan = currChan; }
        sprintf(buf, "%u", chan);
        call Glcd.drawText("next station", 0, 10);
        call Glcd.drawText(buf, 0, 40);
    }
    
    event void Radio.initDone(error_t res)
    {
        if (SUCCESS == res)
        {
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
        post finishedTuning();
    }

    async event void Radio.seekComplete(uint16_t channel)
    {
        atomic { currChan = channel; }
        post finishedSeeking();
    }
    
    async event void Radio.rdsReceived(RDSType type, char *buf)
    {

    }
}
