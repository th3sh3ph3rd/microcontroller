/**
 *
 * @file RadioScannerP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-20
 *
 * Implementation of the RadioScanner app.
 *
**/

#include <avr/pgmspace.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <text.h>

//TODO instead of updating whole screen, write empty line
//TODO use BANDSEEK option from driver, just remove automatic moving
//TODO implement RDS timeout for band seek, maybe with timer and RDS received event
//TODO put display timer start/stop in function and pair with enable/disable RDS and clear RDS data
//TODO move handle char state switcher to event
//TODO implement back key for functions with input
//TODO implement stop key for band seek

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
        interface Timer<TMilli> as VolumeTimer;
        interface Timer<TMilli> as DisplayTimer;
        interface Timer<TMilli> as ErrorTimer;
    }
}

implementation {
    #define BAND_LIMIT_LO   875
    #define BAND_LIMIT_HI   1080

    #define DISPLAY_UPDATE_RATE 1000
    #define VOLUME_UPDATE_RATE  100
    #define ERROR_MSG_TIMEOUT   1000
    #define RDS_TIMEOUT         5000

    enum app_state {INIT, KBCTRL, TUNEINP, TUNE, SEEK, BANDSEEK, ADD};
    static enum app_state appState;

    static char kbChar;
    static uint16_t currChan;
    static uint16_t nextChan;

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
        char name[NAME_SZ+1];
        char note[NOTE_SZ+1];
    } channel_t;

    /* The internal channel list */
    #define CHANNEL_LIST_SZ 15
    static struct
    {
        uint8_t entries;
        uint8_t current;
        channel_t list[CHANNEL_LIST_SZ]; 
    } channels;

    /* Table of favourite channels */
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
    task void startSeekUp(void);
    task void startSeekDown(void);
    task void startTune(void);
    task void addChannel(void);
    task void displayHardError(void);
    task void displaySoftError(void);

    static void printVolume(void);
    static void clearRDSData(void);
    static void addFavourite(void);
    static uint8_t getListId(uint16_t channel);

    ////////////////////////
    /* Tasks              */
    ////////////////////////
   
    task void handleChar(void)
    {
        char c;
        enum app_state state;

        //TODO only for debugging
        channelInfo chan = {1, 1038, 12345, "  OE1   ", "yo servas habe dere"};
        
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
                    atomic { appState = ADD; }
                    post addChannel();
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
                        channels.current--;
                    atomic 
                    { 
                        appState = TUNE;
                        nextChan = channels.list[channels.current].info.frequency;
                    }
                    post startTune();
                    break;

                /* Tune to next list entry */
                case 'l':
                    if (channels.current == channels.entries-1)
                        channels.current = 0;
                    else
                        channels.current++;
                    atomic 
                    { 
                        appState = TUNE;
                        nextChan = channels.list[channels.current].info.frequency;
                    }
                    post startTune();
                    break;

                /* Add note */
                //case 'n':
                //    call Radio.receiveRDS(FALSE);

                case 's':
                    clearRDSData();
                    atomic 
                    { 
                        appState = BANDSEEK;
                        nextChan = BAND_LIMIT_LO;
                    }
                    post startTune();
                    break;

                /* Enter frequency and tune to channel */
                case 't':
                    clearRDSData();
                    call DisplayTimer.stop();
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
                    clearRDSData();
                    call DisplayTimer.stop();
                    atomic { appState = SEEK; }
                    post startSeekDown();
                    break;

                /* Seek next lower channel */
                case '.':
                    clearRDSData();
                    call DisplayTimer.stop();
                    atomic { appState = SEEK; }
                    post startSeekUp();
                    break;

                //TODO following cases are for debugging only
                case 'p':
                    call DB.purgeChannelList();
                    break;

                case 'o':
                    call DB.saveChannel(0xff, &chan);
                    break;

                case 'i':
                    call DB.getChannelList(FALSE);
                    break;

                default:
                    /* Favourites access */
                    if (isdigit(c))
                    {
                        uint8_t fav = (uint8_t)(c - '0');
                        if (fav > 0 && fav <= 9)
                        {
                            uint8_t favId = favourites.table[fav];

                            if (favId < CHANNEL_LIST_SZ)
                            {
                                atomic 
                                { 
                                    appState = TUNE; 
                                    nextChan = channels.list[favId].info.frequency;
                                }
                                call DisplayTimer.stop();
                                post startTune();
                            }
                            else
                            {
                                errno = E_FAV_NSET;
                                post displaySoftError();
                            }
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
            if (channel < BAND_LIMIT_LO || channel > BAND_LIMIT_HI)
            {
                errno = E_CHAN_INVAL;
                post displaySoftError();
            }
            else
            {
                atomic { nextChan = channel; }
                post startTune();
            }
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
   
    //TODO only use one line buffer and alternatingly print to glcd
    task void displayChannelInfo(void)
    {
        char freqBuf[5], idBuf[3];
        char line1[22], line2[22], line3[23];
        uint8_t id, qdial;
        uint16_t chan;
       
        //TODO move state change somewhere else
        atomic 
        { 
            chan = currChan;
            appState = KBCTRL; 
        }

        id = getListId(chan);
        
        /* Display header */
        sprintf(freqBuf, "%d.%d", chan/10, chan%10);
        call Glcd.fill(0x00);
        call Glcd.drawText(freqBuf, 0, 7);
        call Glcd.drawTextPgm(text_MHz, 36, 7);

        /* Display id and quick dial if channel is in list */
        if (id < CHANNEL_LIST_SZ)
        {
            sprintf(idBuf, "c%d", id);
            idBuf[2] = '\0';
            call Glcd.drawText(idBuf, 60, 7);

            if (channels.list[id].info.quickDial > 0)
            {
                sprintf(idBuf, "f%d", id+1);
                idBuf[2] = '\0';
                call Glcd.drawText(idBuf, 78, 7);
            }
        }

        /* Display RDS data */
        memcpy(line1, rds.RT, 21);
        memcpy(line2, rds.RT+21, 21);
        memcpy(line3, rds.RT+42, 22);
        line1[21] = '\0';
        line2[21] = '\0';
        line3[22] = '\0';
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
    
    task void startSeekUp(void)
    {
        if (call Radio.seek(UP) != SUCCESS)
            post startSeekDown();
    }
    
    task void startSeekDown(void)
    {
        if (call Radio.seek(DOWN) != SUCCESS)
            post startSeekDown();
    }

    task void startTune(void)
    {
        uint16_t channel;
        atomic { channel = nextChan; }
        if (call Radio.tune(channel) != SUCCESS)
            post startTune();
    }

    /*
     * @brief Add/update the current channel to the local list and the DB.
     */
    task void addChannel(void)
    {
        uint8_t id;
        uint16_t freq;
        atomic { freq = currChan; }
        
        id = getListId(freq);

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
                call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
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
                channelInfo newChan;

                atomic { PSAvail = rds.PSAvail; }
                
                newChan.quickDial = 0;
                newChan.frequency = freq;
                newChan.pi_code = 1;
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
    }
    
    /*
     * @brief Display an error message according to errno and return to previous state.
     */
    task void displaySoftError(void)
    {
        call DisplayTimer.stop();

        call Glcd.fill(0x00);
        call Glcd.drawTextPgm(text_error, 0, 10);
        
        switch (errno)
        {
            case E_CHAN_INVAL:
                call Glcd.drawTextPgm(text_chanInval, 0, 20);
                break;
            
            case E_LIST_FULL:
                call Glcd.drawTextPgm(text_listFull, 0, 20);
                break;

            case E_FAVS_FULL:
                call Glcd.drawTextPgm(text_favsFull, 0, 20);
                break;

            case E_DB_FULL:
                call Glcd.drawTextPgm(text_dbFull, 0, 20);
                break;

            case E_DB_ERR:
                call Glcd.drawTextPgm(text_dbErr, 0, 20);
                break;
            
            case E_BAND_LIMIT:
                call Glcd.drawTextPgm(text_bandLimit, 0, 20);
                break;
            
            case E_FAV_NSET:
                call Glcd.drawTextPgm(text_favNset, 0, 20);
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
                favourites.table[favourites.entries] = channels.current;
                channels.list[channels.current].info.quickDial = favourites.entries++;
                post addChannel();
            }
        }
        else
        {
            errno = E_FAVS_FULL;
            post displaySoftError();
        }
    }
   
    /*
     * @briefi          Check if the specified channel has been saved to the list.
     * @param channel   Channel frequency to check.
     * @return          Return the channel ID if successful or 0xff on failure.
     */
    static uint8_t getListId(uint16_t channel)
    {
        uint8_t id;

        for (id = 0; id < channels.entries; id++)
        {
            if (channels.list[id].info.frequency == channel)
                return id;
        }
    
        return 0xff;
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
        memset(favourites.table, 0xff, FAV_CNT);

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
            call Radio.receiveRDS(TRUE);
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
        enum app_state state;
        atomic 
        { 
            currChan = channel;
            state = appState;
        }

        switch (state)
        {
            case BANDSEEK:
                post startSeekUp();
                break;

            case TUNE:
                call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
                break;

            default:
                call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
                break;
        }
    }

    async event void Radio.seekComplete(uint16_t channel)
    {
        enum app_state state;
        atomic 
        { 
            currChan = channel;
            state = appState;
        }

        switch (state)
        {
            case BANDSEEK:
                if (channel < BAND_LIMIT_HI)
                {
                    //TODO maybe call clearRDS
                    post displayChannelInfo();
                    post addChannel();
                }
                else
                {
                    errno = E_BAND_LIMIT;
                    post displaySoftError();
                }
                break;

            case SEEK:
                call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
                break;

            default:
                call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
                break;
        }
    }
   
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
                break;

            case RT:
                memset(rds.RT, 0, RT_BUF_SZ+1);
                memcpy(rds.RT, buf, RT_BUF_SZ);
                break;

            case TIME:
                memset(rds.CT, 0, CT_BUF_SZ);
                memcpy(rds.CT, buf, CT_BUF_SZ);
                break;

            default:
                break;
        }
    }
    
    event void VolumeTimer.fired()
    {
        call volumeKnob.read();
    }
    
    event void DisplayTimer.fired()
    {
        post displayChannelInfo(); 
    }

    event void ErrorTimer.fired()
    {
        atomic { appState = KBCTRL; }
        call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
    }

    event void volumeKnob.readDone(error_t res, uint16_t val)
    {
        newVolume = (uint8_t)(val >> 6);
        post setVolume();
    }
    
    event void DB.receivedChannelEntry(uint8_t id, channelInfo channel)
    {
        if (id == 0xff)
        {
            call Glcd.drawText("list end", 0, 60);
        }
        else
        {
            char buf[128], nm[9], nt[41];
            channelInfo chan;
            memcpy(&chan, &channel, sizeof(channelInfo));
            memcpy(nm, channel.name, 8);
            nm[8] = '\0';
            memcpy(nt, channel.name, 40);
            nt[40] = '\0';
            sprintf(buf, "q=%d,f=%d,p=%d,n=%s,n=%s\n", chan.quickDial, chan.frequency, chan.pi_code, nm, nt);
            call Glcd.drawText(buf, 0, 40);
        }
    }

    event void DB.savedChannel(uint8_t id, uint8_t result)
    {
        uint8_t state;
        atomic { state = appState; }
 
        if (result == 0)
        {
            call Glcd.drawText("sc", 0, 40);
            switch (state)
            {
                //TODO maybe notify user
                case ADD:
                    atomic { state = KBCTRL; }
                    call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
                    break;

                case BANDSEEK:
                    post startSeekUp();
                    break;

                default:
                    atomic { state = KBCTRL; }
                    call DisplayTimer.startPeriodic(DISPLAY_UPDATE_RATE);
                    break;
            }
        }
        else if (result == 1)
        {
            errno = E_DB_FULL;
            post displaySoftError();
        }
        else
        {
            errno = E_DB_ERR;
            post displaySoftError();
        }
    }
}
