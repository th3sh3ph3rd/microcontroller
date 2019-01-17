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

//TODO note and name pointer problem
//-> sometimes we send utter bs instead of empty name/note
//-> only a part of the note gets sent

//TODO RDS probably doesnt get turned back on reliably 
//-> maybe bc. of decodeRDS in FMClick 

//TODO PSAvail not correct
//-> on update we send the wrong name sometimes

//TODO favourites synchronized inconsistently
//-> dont add fav to next index, but to next free slot

//TODO set volume initially 
//-> 15 is displayed inititally?



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
        interface Timer<TMilli> as RDSTimer;
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
    task void startSeekBand(void);
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
        //TODO only for debugging
        channelInfo chan = {1, 1038, 12345, "  OE1   ", "yo servas habe dere"};
        atomic { c = kbChar; }
        
        switch (c)
        {
            /* Add/update current channel info */
            case 'a':
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
                call DB.purgeChannelList();
                favourites.entries = 0;
                memset(favourites.table, 0xff, FAV_CNT);
                atomic 
                { 
                    channels.entries = 0;
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

            //TODO move to function
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
                            atomic { errno = E_FAV_NSET; }
                            post displaySoftError();
                        }
                    }
                }
                break;
        }
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
                atomic { errno = E_CHAN_INVAL; }
                post displaySoftError();
            }
            else
            {
                atomic { nextChan = channel; }
                post startTune();
            }
        }
    }
    
    //TODO put line spacing in macros
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
            noteInput.buf[noteInput.idx] = '\0';
            memset(channels.list[id].note, 0, NOTE_SZ+1);
            strncpy(channels.list[id].note, noteInput.buf, NOTE_SZ);
            call DB.saveChannel(id, &channels.list[id].info);            
        }
    }
   
    //TODO put line spacing in macros
    task void displayChannelInfo(void)
    {
        char freqBuf[5], idBuf[4], line[22];
        uint8_t id, qdial;
        uint16_t chan;
        enum app_state state;
       
        atomic 
        {
            state = appState;
            chan = currChan; 
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
            sprintf(idBuf, "c%02d", id);
            idBuf[3] = '\0';
            call Glcd.drawText(idBuf, 60, 7);
            
            qdial = channels.list[id].info.quickDial;
            if (qdial > 0)
            {
                sprintf(idBuf, "f%d", qdial);
                idBuf[2] = '\0';
                call Glcd.drawText(idBuf, 84, 7);
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

        //call Radio.receiveRDS(TRUE);

        if (BANDSEEK == state)
            call RDSTimer.startOneShot(RDS_TIMEOUT);
        
        //TODO only for debugging
        //call Glcd.drawText(channels.list[id].name, 0, 40);
        //call Glcd.drawText(channels.list[id].note, 0, 40);
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
     * @brief Start seeking the whole band.
     */
    task void startSeekBand(void)
    {
        if (call Radio.seek(BAND) != SUCCESS)
            post startSeekBand();
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
        
        call Radio.receiveRDS(FALSE);
        id = getListId(freq);

        /* Channel already in list, update */
        if (id < CHANNEL_LIST_SZ)
        {
            bool PSAvail;
            atomic { PSAvail = rds.PSAvail; }
            
            //if (channels.list[id].info.name == NULL && PSAvail)
            if (PSAvail)
            {
                memcpy(channels.list[id].name, rds.PS, NAME_SZ);
                atomic 
                { 
                    channels.list[id].info.pi_code = rds.piCode; 
                    channels.list[id].info.name = channels.list[id].name;
                    channels.list[id].name[NAME_SZ] = '\0';
                }
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
                atomic { errno = E_LIST_FULL; }
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
                atomic 
                {
                    channels.list[channels.entries].info.name = channels.list[channels.entries].name;
                    channels.list[channels.entries].info.notes = channels.list[channels.entries].note;
                }
                memset(channels.list[channels.entries].info.name, 0, NAME_SZ+1);
                memset(channels.list[channels.entries].info.notes, 0, NOTE_SZ+1);
                
                if (PSAvail)
                {
                    uint16_t piCode;
                    atomic 
                    { 
                        piCode = rds.piCode;
                        channels.list[channels.entries].info.pi_code = piCode;
                    }
                    snprintf(channels.list[channels.entries].name, NAME_SZ, "%-8s", rds.PS);
                }
            
                call DB.saveChannel(0xff, &channels.list[channels.entries].info);
                
                atomic { channels.entries++; }
            }
        }
    }

    /*
     * @brief Display an error message according to errno and remain in this state forever.
     */
    task void displayHardError(void)
    {
        uint8_t err;
        atomic { err = errno; }
        
        call Radio.receiveRDS(FALSE);
        call Glcd.fill(0x00);
        call Glcd.drawTextPgm(text_error, 0, 10);
        
        switch (err)
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
        uint8_t err;
        atomic { err = errno; }
        
        call Radio.receiveRDS(FALSE);
        call Glcd.fill(0x00);
        call Glcd.drawTextPgm(text_error, 0, 10);
        
        switch (err)
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
                    atomic { errno = E_IS_FAV; }
                    post displaySoftError();
                }
                else
                {
                    favourites.table[favourites.entries] = id;
                    atomic { channels.list[id].info.quickDial = ++favourites.entries; }
                    call DB.saveChannel(id, &channels.list[id].info);
                }
            }
            /* Channel not in list */
            else
            {
                atomic { errno = E_CHAN_NLIST; }
                post displaySoftError();
            }
        }
        /* Favourites full */
        else
        {
            atomic { errno = E_FAVS_FULL; }
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
            atomic { errno = E_CHAN_NLIST; }
            post displaySoftError();
        }
    }
    
    ////////////////////////
    /* Events */
    ////////////////////////

    event void Boot.booted()
    {
        char textBuf[8];
        uint8_t id;

        /* Initialize list datastructure */
        for (id = 0; id < CHANNEL_LIST_SZ; id++)
        {
            memset(channels.list[id].name, 0, NAME_SZ+1);
            memset(channels.list[id].note, 0, NOTE_SZ+1);
            channels.list[id].info.name = channels.list[id].name;
            channels.list[id].info.notes = channels.list[id].note;
        }

        atomic 
        { 
            appState = INIT; 
            channels.entries = 0;
        }

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
    }
    
    event void Radio.initDone(error_t res)
    {
        if (res == SUCCESS)
        {
            call Radio.receiveRDS(FALSE);
            call VolumeTimer.startPeriodic(VOLUME_UPDATE_RATE);
            call DB.getChannelList(FALSE);
        }
        else
        {
            atomic { errno = E_FMCLICK_INIT; }
            post displayHardError();
        }
    }
 
    async event void Keyboard.receivedChar(uint8_t c)
    {
        enum app_state state;

        atomic 
        { 
            state = appState;
            kbChar = c; 
        }

        switch (state)
        {
            case KBCTRL:
                post handleChar();
                break;

            case TUNEINP:
                post inputTuneChannel();
                break;

            case NOTE:
                post inputNote();
                break;

            default:
                break;
        }
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
                post startSeekBand();
                break;

            case TUNE:
                atomic { appState = KBCTRL; }
                post displayChannelInfo();
                break;

            default:
                atomic { appState = KBCTRL; }
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
                if (channel <= BAND_LIMIT_HI)
                    post displayChannelInfo();
                else
                {
                    if (channels.entries > 0)
                    {
                        clearRDSData();
                        atomic
                        {
                            nextChan = channels.list[0].info.frequency;
                            appState = TUNE;
                        }
                        post startTune();
                    }
                    else
                    {
                        atomic { appState = KBCTRL; }
                        post displayChannelInfo();
                    }
                }
                break;

            case SEEK:
                atomic { appState = KBCTRL; }
                post displayChannelInfo();
                break;

            default:
                atomic { appState = KBCTRL; }
                post displayChannelInfo();
                break;
        }
    }
   
    async event void Radio.rdsReceived(RDSType type, char *buf)
    {
        enum app_state state;
        atomic { state = appState; }

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
                if (BANDSEEK == state)
                    post addChannel();
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
    
    event void RDSTimer.fired()
    {
        post addChannel();
    }

    event void volumeKnob.readDone(error_t res, uint16_t val)
    {
        newVolume = (uint8_t)(val >> 6);
        post setVolume();
    }
    
    event void DB.receivedChannelEntry(uint8_t id, channelInfo channel)
    {
        enum app_state state;
        atomic { state = appState; }

        if (INIT == state)
        {
            /* Received last DB entry */
            if (id == 0xff)
            {
                /* Tune to first channel in list */
                if (channels.entries > 0)
                {
                    clearRDSData();
                    atomic
                    {
                        nextChan = channels.list[0].info.frequency;
                        appState = TUNE;
                    }
                    post startTune();
                }
                /* DB empty - start band seek */
                else
                {
                    clearRDSData();
                    call DB.purgeChannelList();
                    favourites.entries = 0;
                    memset(favourites.table, 0xff, FAV_CNT);
                    atomic 
                    { 
                        channels.entries = 0;
                        appState = BANDSEEK;
                        nextChan = BAND_LIMIT_LO;
                    }
                    post startTune();
                }
            }
            else
            {
                memcpy(&channels.list[channels.entries].info, &channel, sizeof(channelInfo)); 
                snprintf(channels.list[channels.entries].name, NAME_SZ, "%-8s", channel.name);
                strncpy(channels.list[channels.entries].note, channel.notes, NOTE_SZ);

                if (channel.quickDial > 0)
                {
                    call Glcd.drawText("fav", 50, 30);
                    favourites.table[favourites.entries++] = channels.entries;
                }
 
                atomic { channels.entries++; }
            }
        }
    }

    event void DB.savedChannel(uint8_t id, uint8_t result)
    {
        uint8_t state;
        atomic { state = appState; }
 
        if (result == 0)
        {
            switch (state)
            {
                case ADD:
                    atomic { appState = KBCTRL; }
                    post displayChannelInfo();
                    break;

                case FAV:
                    atomic { appState = KBCTRL; }
                    post displayChannelInfo();
                    break;

                //TODO change this to seek band!
                case BANDSEEK:
                    clearRDSData();
                    post startSeekBand();
                    break;

                default:
                    atomic { appState = KBCTRL; }
                    post displayChannelInfo();
                    break;
            }
        }
        else if (result == 1)
        {
            atomic { errno = E_DB_FULL; }
            post displaySoftError();
        }
        else
        {
            atomic { errno = E_DB_ERR; }
            post displaySoftError();
        }
    }
}

