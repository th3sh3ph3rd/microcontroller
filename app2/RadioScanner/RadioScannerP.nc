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

//TODO implement note feature
//TODO database deepcopy note
//TODO use BANDSEEK option from driver, just remove automatic moving
//TODO implement RDS timeout for band seek, maybe with timer and RDS received event
//TODO RDS probably doesnt get turned back on reliably
//TODO move handle char state switcher to event
//TODO automatically update RDS info to DB if available
//TODO implement back key for functions with input
//TODO implement stop key for band seek
//TODO cleanup keyboard driver
//TODO udp additional functionality

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
        interface Timer<TMilli> as ErrorTimer;
    }
}

implementation {
    #define BAND_LIMIT_LO   875
    #define BAND_LIMIT_HI   1080

    #define DISPLAY_UPDATE_RATE 1000
    #define VOLUME_UPDATE_RATE  100
    #define ERROR_MSG_TIMEOUT   700
    #define RDS_TIMEOUT         5000

    enum app_state {INIT, KBCTRL, TUNEINP, TUNE, SEEK, BANDSEEK, ADD, FAV, NOTE};
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
        bool newPS;
        bool newRT;
        bool newCT;
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

    static struct
    {
        uint8_t idx;
        char buf[NOTE_SZ+1];
    } noteInput;
    
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
    task void inputNote(void);
    task void displayChannelInfo(void);
    task void displayRDS(void);
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
    static uint8_t getNextId(uint16_t channel);
    static void tuneNextHighest(void);
    static void addNote(void);

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
                    call Radio.receiveRDS(FALSE);
                    atomic { appState = ADD; }
                    post addChannel();
                    break;

                /* Add current channel to favourites */
                case 'f':
                    atomic { appState = FAV; }
                    addFavourite();
                    break;

                /* Tune to list entry with next highest frequency */
                case 'l':
                    tuneNextHighest();
                    break;

                /* Add note */
                case 'n':
                    atomic { appState = NOTE; }
                    addNote();
                    break;

                case 's':
                    call Radio.receiveRDS(FALSE);
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
                    call Radio.receiveRDS(FALSE);
                    clearRDSData();
                    atomic
                    {
                        tuneInput.idx = 0;
                        memset(tuneInput.buf, 0, TUNEINPUT_BUF_SZ);
                        appState = TUNEINP;
                    }
                    call Glcd.fill(0x00);
                    call Glcd.drawTextPgm(text_channelInput, 0, 10);
                    post inputTuneChannel();
                    break;

                /* Seek next higher channel */
                case '.':
                    call Radio.receiveRDS(FALSE);
                    clearRDSData();
                    atomic { appState = SEEK; }
                    post startSeekUp();
                    break;

                /* Seek next lower channel */
                case ',':
                    call Radio.receiveRDS(FALSE);
                    clearRDSData();
                    atomic { appState = SEEK; }
                    post startSeekDown();
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
                            uint8_t favId = favourites.table[fav-1];

                            if (favId < CHANNEL_LIST_SZ)
                            {
                                call Radio.receiveRDS(FALSE);
                                clearRDSData();
                                atomic 
                                { 
                                    appState = TUNE; 
                                    nextChan = channels.list[favId].info.frequency;
                                }
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
        else if (NOTE == state)
            post inputNote();
    }

    task void inputTuneChannel(void)
    {
        char c;
        atomic { c = kbChar; }
        
        if (isdigit(c))
        {
            if (tuneInput.idx < TUNEINPUT_BUF_SZ-1)
                tuneInput.buf[tuneInput.idx++] = c;
        }

        /* Backspace */
        if (c == '\b' && tuneInput.idx > 0)
            tuneInput.buf[--tuneInput.idx] = '\0';
        
        call Glcd.drawTextPgm(text_emptyTime, 0, 20);
        call Glcd.drawText(tuneInput.buf, 0, 20);

        /* Complete entering channel */
        if (c == '\n')
        {
            uint16_t channel = (uint16_t) strtoul(tuneInput.buf, NULL, 10);
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
    
    task void inputNote(void)
    {
        char c;
        char line[22];
        atomic { c = kbChar; }
        
        /* Backspace */
        if (c == '\b')
        {
            if (noteInput.idx > 0)
                noteInput.buf[--noteInput.idx] = '\0';
        }
        else if (c != '\n' && c != '\r' && c != '\0')
        {
            if (noteInput.idx < NOTE_SZ)
                noteInput.buf[noteInput.idx++] = c;
        }
      
        /* Write input to screen */
        memcpy(line, noteInput.buf, 21);
        line[21] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, 122, 20);
        call Glcd.drawText(line, 122, 20);
        memcpy(line, noteInput.buf+21, 19);
        line[19] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, 122, 30);
        call Glcd.drawText(line, 122, 30);

        /* Complete entering note */
        if (c == '\n')
        {
            uint8_t id;
            uint16_t channel;

            atomic 
            {
                appState = ADD;
                channel = currChan; 
            }

            id = getListId(channel);
            memcpy(channels.list[id].note, noteInput.buf, NOTE_SZ+1);
            call DB.saveChannel(id, &channels.list[id].info);            
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
   
    //TODO put line spacing in macros
    task void displayChannelInfo(void)
    {
        char freqBuf[5], idBuf[3], line[22];
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
            channels.current = id;
            sprintf(idBuf, "c%d", id);
            idBuf[2] = '\0';
            call Glcd.drawText(idBuf, 60, 7);
            
            qdial = channels.list[id].info.quickDial;
            if (qdial > 0)
            {
                sprintf(idBuf, "f%d", qdial);
                idBuf[2] = '\0';
                call Glcd.drawText(idBuf, 78, 7);
            }

            /* Display note */
            memcpy(line, channels.list[id].note, 21);
            line[21] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, 122, 47);
            call Glcd.drawText(line, 122, 47);
            memcpy(line, channels.list[id].note+21, 19);
            line[19] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, 122, 55);
            call Glcd.drawText(line, 122, 55);
        }

        /* Display initial RDS data */
        call Glcd.drawTextPgm(text_emptyName, 0, 15);
        call Glcd.drawText(rds.PS, 0, 15);
        call Glcd.drawTextPgm(text_emptyTime, 0, 15);
        call Glcd.drawText(rds.CT, 54, 15);
        memcpy(line, rds.RT, 21);
        line[21] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, 122, 23);
        call Glcd.drawText(line, 122, 23);
        memcpy(line, rds.RT+21, 21);
        line[21] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, 122, 31);
        call Glcd.drawText(line, 122, 31);
        memcpy(line, rds.RT+42, 21);
        line[21] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, 122, 39);
        call Glcd.drawText(line, 122, 39);

        call Radio.receiveRDS(TRUE);
    }

    /*
     * @brief Update the RDS information on screen.
     */
    task void displayRDS(void)
    {
        bool newPS, newRT, newCT;

        atomic
        {
            newPS = rds.newPS;
            newRT = rds.newRT;
            newCT = rds.newCT;
        }

        if (newPS)
        {
            call Glcd.drawTextPgm(text_emptyName, 0, 15);
            call Glcd.drawText(rds.PS, 0, 15);
            atomic { rds.newPS = FALSE; }
        }
        if (newCT)
        {
            call Glcd.drawTextPgm(text_emptyTime, 0, 15);
            call Glcd.drawText(rds.CT, 54, 15);
            atomic { rds.newCT = FALSE; }
        }
        if (newRT)
        {
            char line[22];
            
            memcpy(line, rds.RT, 21);
            line[21] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, 122, 23);
            call Glcd.drawText(line, 122, 23);

            memcpy(line, rds.RT+21, 21);
            line[21] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, 122, 31);
            call Glcd.drawText(line, 122, 31);
            
            memcpy(line, rds.RT+42, 21);
            line[21] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, 122, 39);
            call Glcd.drawText(line, 122, 39);
            
            atomic { rds.newRT = FALSE; }
        }
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
     * @brief Start seeking upwards.
     */
    task void startSeekUp(void)
    {
        if (call Radio.seek(UP) != SUCCESS)
            post startSeekUp();
    }
    
    /*
     * @brief Start seeking downwards.
     */
    task void startSeekDown(void)
    {
        if (call Radio.seek(DOWN) != SUCCESS)
            post startSeekDown();
    }

    /*
     * @brief Start tuning to a specific frequency.
     */
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
                channelInfo newChan;

                atomic { PSAvail = rds.PSAvail; }
                
                newChan.quickDial = 0;
                newChan.frequency = freq;
                newChan.pi_code = 1;
                newChan.name = NULL;
                newChan.notes = NULL;

                memcpy(&channels.list[channels.entries].info, &newChan, sizeof(channelInfo));
                channels.list[channels.entries].info.name = channels.list[channels.entries].name;
                channels.list[channels.entries].info.notes = channels.list[channels.entries].note;
                *channels.list[channels.entries].name = '\0';
                *channels.list[channels.entries].note = '\0';
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
        call Radio.receiveRDS(FALSE);
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
        call Radio.receiveRDS(FALSE);
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
            
            case E_CHAN_NLIST:
                call Glcd.drawTextPgm(text_chanNlist, 0, 20);
                break;
            
            case E_IS_FAV:
                call Glcd.drawTextPgm(text_isFav, 0, 20);
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
        atomic 
        { 
            rds.PSAvail = FALSE;
            rds.newPS = FALSE;
            rds.newRT = FALSE;
            rds.newCT = FALSE;
        }
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
            uint8_t id;
            uint16_t chan;

            atomic { chan = currChan; }
            id = getListId(chan);

            if (id < CHANNEL_LIST_SZ)
            {
                uint8_t i;
                bool foundId = FALSE;

                for (i = 0; i < favourites.entries; i++)
                {
                    if (favourites.table[i] == id)
                    {
                        foundId = TRUE;
                        break;
                    }
                }

                /* Channel already in favourites */
                if (foundId)
                {
                    errno = E_IS_FAV;
                    post displaySoftError();
                }
                else
                {
                    favourites.table[favourites.entries] = id;
                    channels.list[id].info.quickDial = ++favourites.entries;
                    call DB.saveChannel(id, &channels.list[id].info);
                }
            }
            else
            {
                errno = E_CHAN_NLIST;
                post displaySoftError();
            }
        }
        else
        {
            errno = E_FAVS_FULL;
            post displaySoftError();
        }
    }
   
    /*
     * @brief           Check if the specified channel has been saved to the list.
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
    
    /*
     * @brief           Get the ID of the channel with the next highest frequency in the list.
     * @param channel   Channel frequency to start from.
     * @return          Return the channel ID if successful or 0xff on failure.
     */
    //TODO check if sub underflow always leads to channel with least freq if there is no higher
    static uint8_t getNextId(uint16_t channel)
    {
        uint8_t id, next;
        uint16_t currDist, minDist;

        next = 0xff;
        minDist = 0xffff;
        for (id = 0; id < channels.entries; id++)
        {
            currDist = channels.list[id].info.frequency - channel;
            if (currDist > 0 && currDist < minDist)
            {
                next = id;
                minDist = currDist;
            }
        }

        return next;
    }

    /*
     * @brief Tune to the channel with the next highest frequency.
     */
    static void tuneNextHighest(void)
    {
        if (channels.entries > 0)
        {
            uint8_t nextId;
            uint16_t channel;

            atomic { channel = currChan; }
            nextId = getNextId(channel);

            if (nextId < CHANNEL_LIST_SZ)
            {
                call Radio.receiveRDS(FALSE);
                clearRDSData();
                atomic 
                { 
                    appState = TUNE;
                    nextChan = channels.list[nextId].info.frequency;
                }
                post startTune();
            }
        }
    }

    /*
     * @brief Start adding a note to a channel.
     */
    static void addNote(void)
    {
        uint8_t id;
        uint16_t channel;

        atomic { channel = currChan; }
        id = getListId(channel);

        if (id < CHANNEL_LIST_SZ)
        {
            call Radio.receiveRDS(FALSE);
            atomic { kbChar = '\0'; }
            noteInput.idx = 0;
            memset(noteInput.buf, 0, NOTE_SZ+1);
            call Glcd.fill(0x00);
            call Glcd.drawTextPgm(text_noteInput, 0, 10);
            post inputNote();
        }
        else
        {
            errno = E_CHAN_NLIST;
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
                post displayChannelInfo();
                break;

            default:
                post displayChannelInfo();
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
                    //TODO take care about RDS and app state
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
                post displayChannelInfo();
                break;

            default:
                post displayChannelInfo();
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
                    rds.newPS = TRUE;
                    rds.piCode = ((uint16_t)buf[PS_BUF_SZ+1]) & 0x00ff;
                    rds.piCode |= ((uint16_t)buf[PS_BUF_SZ]) << 8;
                }
                break;

            case RT:
                atomic { rds.newRT = TRUE; }
                memset(rds.RT, 0, RT_BUF_SZ+1);
                memcpy(rds.RT, buf, RT_BUF_SZ);
                break;

            case TIME:
                atomic { rds.newCT = TRUE; }
                memset(rds.CT, 0, CT_BUF_SZ);
                memcpy(rds.CT, buf, CT_BUF_SZ);
                break;

            default:
                break;
        }

        post displayRDS();
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
                case ADD:
                    atomic { state = KBCTRL; }
                    post displayChannelInfo();
                    break;

                case FAV:
                    atomic { state = KBCTRL; }
                    post displayChannelInfo();
                    break;

                case BANDSEEK:
                    post startSeekUp();
                    break;

                default:
                    atomic { state = KBCTRL; }
                    post displayChannelInfo();
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
