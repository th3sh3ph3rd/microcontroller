/**
 *
 * @file RadioScannerP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-20
 *
 * Implementation of the RadioScanner app.
 *
**/

//TODO take strings from PROGMEM, also in database file!!

#include <avr/pgmspace.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <text.h>

module RadioScannerP_new {
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
        interface Timer<TMilli> as VolumeTimer;
        interface Timer<TMilli> as ErrorTimer;
    }
}

implementation {
    #define BAND_LIMIT_LO   875
    #define BAND_LIMIT_HI   1080

    #define VOLUME_UPDATE_RATE  300
    #define ERROR_MSG_TIMEOUT   1000

    enum app_state {INIT, KBCTRL, TUNEINP, TUNE, SEEK, BANDSEEK, ADD};
    static enum app_state appState;

    static char kbChar;
    static uint16_t currChan;

    #define TUNEINPUT_BUF_SZ 5
    static struct
    {
        uint8_t idx;
        char buf[TUNEINPUT_BUF_SZ];
    } tuneInput;
    
    //TODO defines should actually come from interface file
    #define PS_BUF_SZ   8
    #define RT_BUF_SZ   64
    #define CT_BUF_SZ   6
    static struct
    {
        bool PSAvail;
        uint16_t piCode;
        /* Need space for null termination */
        char PS[PS_BUF_SZ+1];
        char RT[RT_BUF_SZ+1];
        char CT[CT_BUF_SZ];
    } rds;

    /* Buffers for name and note are needed, as channelInfo struct only contains pointers */
    #define NAME_SZ 8
    #define NOTE_SZ 40
    typedef struct
    {
        channelInfo info;
        char name[NAME_SZ];
        char note[NOTE_SZ];
    } channel_t;
    #define CHANNEL_LIST_SZ 15
    static struct
    {
        uint8_t entries;
        uint8_t current;
        channel_t list[CHANNEL_LIST_SZ]; 
    } channels;
    #define FAV_CNT         9
    static struct
    {
        uint8_t entries;
        uint8_t table[FAV_CNT];
    } favourites;

    static uint8_t oldVolume;
    static uint8_t newVolume;

    static uint8_t errno;

    task void inputTuneChannel(void);
    task void displayChannelInfo(void);
    task void setVolume(void);
    task void displayHardError(void);
    task void displaySoftError(void);

    static void printVolume(void);
    static void clearRDSData(void);
    static void addChannel(void);
    static void addFavourite(void);

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
                /* Add/update current channel info */
                case 'a':
                    call Radio.receiveRDS(FALSE);
                    atomic { appState = ADD; }
                    addChannel();
                    break;

                /* Add current channel to favourites */
                case 'f':
                    atomic { appState = ADD; }
                    addFavourite();
                    break;

                /* Tune to previous list entry */
                case 'h':
                    if (channels.current == 0)
                        channels.current = channels.entries-1;
                    else
                        channel.current--;
                    atomic { appState = TUNE; }
                    call Radio.tune(channels.list[channels.current].info.frequency);
                    break;

                /* Tune to next list entry */
                case 'l':
                    if (channels.current == channels.entries-1)
                        channels.current = 0;
                    else
                        channel.current++;
                    atomic { appState = TUNE; }
                    call Radio.tune(channels.list[channels.current].info.frequency);
                    break;

                /* Add note */
                //case 'n':
                //    call Radio.receiveRDS(FALSE);

                //TODO tune to channel 0 (875) before seek
                case 's':
                    call Radio.receiveRDS(FALSE);
                    clearRDSData();
                    atomic { appState = BANDSEEK; }
                    //call Radio.tune(875);
                    call Radio.seek(BAND);
                    break;

                /* Enter frequency and tune to channel */
                case 't':
                    call Radio.receiveRDS(FALSE);
                    clearRDSData();
                    atomic
                    {
                        tuneInput.idx = 0;
                        memset(tuneInput.buf, 0, TUNEINPUT_BUF_SZ);
                        appState = TUNEINP;
                    }
                    post inputTuneChannel();
                    break;

                /* Seek next higher channel */
                case ',':
                    call Radio.receiveRDS(FALSE);
                    clearRDSData();
                    atomic { appState = SEEK; }
                    call Radio.seek(DOWN);
                    break;

                /* Seek next lower channel */
                case '.':
                    call Radio.receiveRDS(FALSE);
                    clearRDSData();
                    atomic { appState = SEEK; }
                    call Radio.seek(UP);
                    break;

                default:
                    /* Favourites access */
                    if (isdigit(c))
                    {
                        uint8_t fav = (uint8_t) strtoul(c, NULL, 10);
                        if (fav > 0)
                        {
                            atomic { appState = TUNE; }
                            call Radio.tune(channels.list[favourites.list[fav]].info.frequency);
                        }
                    }
                    break;
            }
        }
        else if (TUNEINP == state)
            post inputTuneChannel();
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
        call Glcd.drawTextPgm(text_channelInput, 0, 10);
        
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
            if (call Radio.tune(channel) != SUCCESS)
            {
                errno = E_BAND_LIMIT;
                post displaySoftError();
            }
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
   
    //TODO display id if in list and qdial, if in favourites
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
        call Glcd.drawTextPgm(text_channel, 0, 7);
        call Glcd.drawText(freqBuf, 54, 7);
        call Glcd.drawTextPgm(text_MHz, 94, 7);

        call Radio.receiveRDS(TRUE);
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
            call Radio.setVolume(newVolume);
            oldVolume = newVolume;
            printVolume();
        }
    }

    /*
     * @brief Display an error message according to errno and remain in this state forever.
     */
    task void displayHardError(void)
    {
        call Glcd.fill(0x00);
        call Glcd.drawTextPgm(text_error, 0, 10);
        switch (errno)
        {
            case E_FMCLICK_INIT:
                call Glcd.drawTextPgm(text_FMClickInitFail, 0, 20);
                break;

            default:
                call Glcd.drawTextPgm(text_unknownError, 0, 20);
                break;
        }

        //TODO may require endless loop here
    }
    
    /*
     * @brief Display an error message according to errno and return to previous state.
     */
    task void displaySoftError(void)
    {
        call Glcd.fill(0x00);
        call Glcd.drawTextPgm(text_error, 0, 10);
        switch (errno)
        {
            case E_BAND_LIMIT:
                call Glcd.drawTextPgm(text_bandLimit, 0, 20);
                break;
            
            case E_LIST_FULL:
                call Glcd.drawTextPgm(text_listFull, 0, 20);
                break;

            case E_FAVS_FULL:
                call Glcd.drawTextPgm(text_favsFull, 0, 20);
                break;

            default:
                call Glcd.drawTextPgm(text_unknownError, 0, 20);
                break;
        }

        call ErrorTimer.startOneShot(ERROR_MSG_TIMEOUT);
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

    /*
     * @brief Clear the RDS buffers.
     */
    static void clearRDSData(void)
    {
        atomic { rds.PSAvail = FALSE; }
        memset(rds.PS, 0, PS_BUF_SZ+1);
        memset(rds.RT, 0, RT_BUF_SZ+1);
        memset(rds.CT, 0, CT_BUF_SZ);
    }
    
    /*
     * @brief Add/update the current channel to the local list and the DB.
     */
    static void addChannel(void)
    {
        uint8_t i, id;
        id = 0xff;
        /* Check if channel already in list */
        for (i = 0; i<channels.entries; i++)
        {
            uint16_t freq;
            atomic { freq = currChan; }
            if (channels.list[i].info.frequency == freq)
            {
                id = i;
                break;
            }
        }

        /* Channel already in list, update */
        if (id < CHANNEL_LIST_SZ)
        {
            bool PSAvail;
            atomic { PSAvail = rds.PSAvail; }
            if (channels.list[id].info.name == NULL && PSAvail)
            {
                uint16_t piCode;
                atomic { piCode = rds.piCode; }
                channels.list[id].info.pi_code = piCode;
                memcpy(channels.list[id].name, rds.PS, PS_BUF_SZ);
                channels.list[id].info.name = channels.list[id].name;
                call DB.saveChannel(id, &channels.list[id].info);
            }
            /* Nothing to update */
            else
            {
                atomic {appState = KBCTRL; }
                post displayChannelInfo();
            }
        }
        /* Add channel to list */
        else
        {
            if (channels.entries >= CHANNEL_LIST_SZ)
            {
                errno = E_LIST_FULL;
                post displaySoftError();
            }
            else
            {
                bool PSAvail;
                uint16_t freq;
                channelInfo newChan;

                atomic 
                { 
                    PSAvail = rds.PSAvail;
                    freq = currChan;
                }
                
                newChan.quickDial = 0;
                newChan.frequency = freq;
                newChan.pi_code = 0;
                newChan.name = NULL;
                newChan.notes = NULL;

                memcpy(&channels.list[channels.entries].info, &newChan, sizeof(channelInfo));
                channels.current = channels.entries;
                
                if (PSAvail)
                {
                    uint16_t piCode;
                    atomic { piCode = rds.piCode; }
                    channels.list[channels.entries].info.pi_code = piCode;
                    memcpy(channels.list[channels.entries].name, rds.PS, PS_BUF_SZ);
                    channels.list[channels.entries].info.name = channels.list[channels.entries].name;
                }
            
                call DB.saveChannel(0xff, &channels.list[channels.entries].info);
                
                channels.entries++;
            }
        }
    }

    /*
     * @brief Add the current channel to the favourites list.
     */
    static void addFavourite(void)
    {
        if (favourites.entries < FAV_CNT)
        {
            //TODO handle case if channel not even in list
            if (currChan != channels.list[channels.current].info.frequency)
            {

            }
            else
            {
                favourites.list[favourites.entries] = channels.current;
                channels.list[channels.entries].info.quickDial = favourites.entries++;
                addChannel();
            }
        }
        else
        {
            errno = E_FAVS_FULL;
            post displaySoftError();
        }
    }

    
    ////////////////////////
    /* Events */
    ////////////////////////

    event void Boot.booted()
    {
        char textBuf[8];
        atomic { appState = INIT; }

        channels.entries = 0;
        channels.current = 0;
        favourites.entries = 0;

        oldVolume = 0;
        newVolume = 0;

        strcpy_P(textBuf, text_volume);
        textBuf[7] = '\0';
        call Lcd.goTo(0,0);
        call Lcd.write(textBuf);
        printVolume();

        call Glcd.fill(0x00);
        call Keyboard.init();
        call RadioInit.init();
        call DBInit.init();
        call Glcd.drawText("init fm", 0, 10);

        clearRDSData();
    }
    
    event void Radio.initDone(error_t res)
    {
        if (SUCCESS == res)
        {
            //TODO probably move this somewhere else
            call VolumeTimer.startPeriodic(VOLUME_UPDATE_RATE);
            atomic { appState = KBCTRL; }
            post readyScreen();
        }
        else
        {
            errno = E_FMCLICK_INIT;
            post displayHardError();
        }
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
                atomic 
                { 
                    rds.PSAvail = TRUE;
                    rds.piCode = ((uint16_t)buf[PS_BUF_SZ+1]) & 0x00ff;
                    rds.piCode |= ((uint16_t)buf[PS_BUF_SZ]) << 8;
                }
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
    
    event void VolumeTimer.fired()
    {
        call volumeKnob.read();
    }

    event void ErrorTimer.fired()
    {
        atomic { appState = KBCTRL; }
        post displayChannelInfo(); 
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
        uint8_t state;
        atomic { state = appState; }

        switch (state)
        {
            //TODO maybe notify user
            case ADD:
                atomic { state = KBCTRL; }
                post displayChannelInfo();
                break;

            default:
                atomic { state = KBCTRL; }
                post displayChannelInfo();
                break;
        }
    }
}
