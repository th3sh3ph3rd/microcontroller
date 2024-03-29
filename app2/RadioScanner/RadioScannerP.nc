/*
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

    #define GLCD_CHARS_PER_LINE     21
    #define GLCD_CHAR_WIDTH         6
    #define GLCD_LEFT_END           0
    #define GLCD_FIRST_LINE         10
    #define GLCD_LINE_SPACE         10
    #define GLCD_TRUE_LEFT_END      122
    #define GLCD_TRUE_FIRST_LINE    7
    #define GLCD_TRUE_LINE_SPACE    8

    enum app_state {INIT, KBCTRL, TUNEINP, TUNE, SEEK, BANDSEEK, ADD, FAV, NOTE};
    static enum app_state appState;

    static char kbChar;
    static uint16_t currChan;
    static uint16_t nextChan;

    /* Buffer for frequency input */
    #define TUNEINPUT_BUF_SZ 5
    static struct
    {
        uint8_t idx;
        char buf[TUNEINPUT_BUF_SZ];
    } tuneInput;
 
    /* RDS data storage */
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
    static void tuneToFavourite(char c);
    static void removeIllegalChars(char *data, uint8_t len);

    ////////////////////////
    /* Tasks              */
    ////////////////////////
   
    task void handleChar(void)
    {
        char c;
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
                call Glcd.drawTextPgm(text_channelInput, GLCD_LEFT_END, GLCD_FIRST_LINE);
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

            default:
                /* Favourites access */
                if (isdigit(c))
                    tuneToFavourite(c);
                break;
        }
    }

    /*
     * @brief Read input from the keyboard and tune to the specified frequency.
     */
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
        
        call Glcd.drawTextPgm(text_emptyTime, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
        call Glcd.drawText(tuneInput.buf, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);

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
    
    /*
     * @brief Read input from the keyboard and save as note.
     */
    task void inputNote(void)
    {
        char c;
        char line[GLCD_CHARS_PER_LINE+1];
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
        memcpy(line, noteInput.buf, GLCD_CHARS_PER_LINE);
        line[GLCD_CHARS_PER_LINE] = '\0';
        call Glcd.drawTextPgm(text_emptyLine,  GLCD_TRUE_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
        call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
        memcpy(line, noteInput.buf+GLCD_CHARS_PER_LINE, GLCD_CHARS_PER_LINE-2);
        line[GLCD_CHARS_PER_LINE-2] = '\0';
        call Glcd.drawTextPgm(text_emptyLine,  GLCD_TRUE_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE*2);
        call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE*2);

        /* Complete entering note */
        if (c == '\n')
        {
            uint8_t id;
            uint16_t channel;
            channel_t *ce;

            atomic 
            {
                appState = ADD;
                channel = currChan;
            }

            id = getListId(channel);
            atomic { ce = &channels.list[id]; }

            noteInput.buf[noteInput.idx] = '\0';
            memset(ce->info.notes, 0, NOTE_SZ+1);
            strncpy(ce->info.notes, noteInput.buf, NOTE_SZ);
            call DB.saveChannel(id, &ce->info);            
        }
    }
  
    /*
     * @brief Main task: display the radio station information.
     */
    task void displayChannelInfo(void)
    {
        char freqBuf[5], idBuf[4], line[GLCD_CHARS_PER_LINE+1];
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
        call Glcd.drawText(freqBuf, GLCD_LEFT_END, GLCD_TRUE_FIRST_LINE);
        call Glcd.drawTextPgm(text_MHz, GLCD_CHAR_WIDTH*6, GLCD_TRUE_FIRST_LINE);

        /* Display list id and quick dial if channel is in list */
        if (id < CHANNEL_LIST_SZ)
        {
            sprintf(idBuf, "c%02d", id);
            idBuf[3] = '\0';
            call Glcd.drawText(idBuf, GLCD_CHAR_WIDTH*10, GLCD_TRUE_FIRST_LINE);
            
            qdial = channels.list[id].info.quickDial;
            if (qdial > 0)
            {
                sprintf(idBuf, "f%d", qdial);
                idBuf[2] = '\0';
                call Glcd.drawText(idBuf, GLCD_CHAR_WIDTH*14, GLCD_TRUE_FIRST_LINE);
            }

            /* Display note */
            memcpy(line, channels.list[id].note, GLCD_CHARS_PER_LINE);
            line[GLCD_CHARS_PER_LINE] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*5);
            call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*5);
            memcpy(line, channels.list[id].note+GLCD_CHARS_PER_LINE, GLCD_CHARS_PER_LINE-2);
            line[GLCD_CHARS_PER_LINE-2] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*6);
            call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*6);
        }

        /* Display initial RDS data */
        call Glcd.drawTextPgm(text_emptyName, GLCD_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
        call Glcd.drawText(rds.PS, GLCD_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
        call Glcd.drawTextPgm(text_emptyTime, GLCD_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
        call Glcd.drawText(rds.CT, GLCD_CHAR_WIDTH*9, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
        memcpy(line, rds.RT, GLCD_CHARS_PER_LINE);
        line[GLCD_CHARS_PER_LINE] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*2);
        call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*2);
        memcpy(line, rds.RT+GLCD_CHARS_PER_LINE, GLCD_CHARS_PER_LINE);
        line[GLCD_CHARS_PER_LINE] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*3);
        call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*3);
        memcpy(line, rds.RT+GLCD_CHARS_PER_LINE*2, GLCD_CHARS_PER_LINE);
        line[GLCD_CHARS_PER_LINE] = '\0';
        call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*4);
        call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*4);

        call Radio.receiveRDS(TRUE);

        if (BANDSEEK == state)
            call RDSTimer.startOneShot(RDS_TIMEOUT);
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
            removeIllegalChars(rds.PS, PS_BUF_SZ);
            call Glcd.drawTextPgm(text_emptyName, GLCD_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
            call Glcd.drawText(rds.PS, GLCD_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
            atomic { rds.newPS = FALSE; }
        }
        if (newCT)
        {
            call Glcd.drawTextPgm(text_emptyTime, GLCD_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
            call Glcd.drawText(rds.CT, GLCD_CHAR_WIDTH*9, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE);
            atomic { rds.newCT = FALSE; }
        }
        if (newRT)
        {
            char line[GLCD_CHARS_PER_LINE+1];

            removeIllegalChars(rds.RT, RT_BUF_SZ);
            memcpy(line, rds.RT, GLCD_CHARS_PER_LINE);
            line[GLCD_CHARS_PER_LINE] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*2);
            call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*2);
            memcpy(line, rds.RT+GLCD_CHARS_PER_LINE, GLCD_CHARS_PER_LINE);
            line[GLCD_CHARS_PER_LINE] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*3);
            call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*3);
            memcpy(line, rds.RT+GLCD_CHARS_PER_LINE*2, GLCD_CHARS_PER_LINE);
            line[GLCD_CHARS_PER_LINE] = '\0';
            call Glcd.drawTextPgm(text_emptyLine, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*4);
            call Glcd.drawText(line, GLCD_TRUE_LEFT_END, GLCD_TRUE_FIRST_LINE+GLCD_TRUE_LINE_SPACE*4);
            
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
            channel_t *c;

            atomic 
            { 
                PSAvail = rds.PSAvail; 
                c = &channels.list[id];
            }
            
            if (PSAvail)
            {
                memset(c->info.name, 0, NAME_SZ+1);
                removeIllegalChars(rds.PS, PS_BUF_SZ);
                snprintf(c->info.name, NAME_SZ, "%-8s", rds.PS);
                atomic { c->info.pi_code = rds.piCode; }
                call DB.saveChannel(id, &c->info);
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
                channel_t *c;

                atomic 
                { 
                    PSAvail = rds.PSAvail; 
                    c = &channels.list[channels.entries++];
                }
                
                c->info.quickDial = 0;
                c->info.frequency = freq;
                c->info.pi_code = 1;
                c->info.name = c->name;
                c->info.notes = c->note;
                memset(c->info.name, 0, NAME_SZ+1);
                memset(c->info.notes, 0, NOTE_SZ+1);
                
                if (PSAvail)
                {
                    atomic { c->info.pi_code = rds.piCode; }
                    snprintf(c->info.name, NAME_SZ, "%-8s", rds.PS);
                }
                /* Add note if no RDS data available */
                else
                    strcpy_P(c->info.notes, text_noRDS);
            
                call DB.saveChannel(0xff, &c->info); 
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
        call Glcd.drawTextPgm(text_error, GLCD_LEFT_END, GLCD_FIRST_LINE);
        
        switch (err)
        {
            case E_FMCLICK_INIT:
                call Glcd.drawTextPgm(text_FMClickInitFail, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;

            default:
                call Glcd.drawTextPgm(text_unknownError, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
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
        call Glcd.drawTextPgm(text_error, GLCD_LEFT_END, GLCD_FIRST_LINE);
        
        switch (err)
        {
            case E_CHAN_INVAL:
                call Glcd.drawTextPgm(text_chanInval, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;
            
            case E_LIST_FULL:
                call Glcd.drawTextPgm(text_listFull, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;

            case E_FAVS_FULL:
                call Glcd.drawTextPgm(text_favsFull, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;

            case E_DB_FULL:
                call Glcd.drawTextPgm(text_dbFull, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;

            case E_DB_ERR:
                call Glcd.drawTextPgm(text_dbErr, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;
            
            case E_BAND_LIMIT:
                call Glcd.drawTextPgm(text_bandLimit, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;
            
            case E_FAV_NSET:
                call Glcd.drawTextPgm(text_favNset, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;
            
            case E_CHAN_NLIST:
                call Glcd.drawTextPgm(text_chanNlist, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;
            
            case E_IS_FAV:
                call Glcd.drawTextPgm(text_isFav, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
                break;

            default:
                call Glcd.drawTextPgm(text_unknownError, GLCD_LEFT_END, GLCD_FIRST_LINE+GLCD_LINE_SPACE);
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
                /* Channel already in favourites */
                if (channels.list[id].info.quickDial > 0)
                {
                    atomic { errno = E_IS_FAV; }
                    post displaySoftError();
                }
                else
                {
                    uint8_t fid;

                    /* Search free quick dial slot */
                    for (fid = 0; fid < FAV_CNT; fid++)
                    {
                        if (favourites.table[fid] == 0xff)
                            break;
                    }

                    favourites.table[fid] = id;
                    favourites.entries++;
                    atomic { channels.list[id].info.quickDial = fid+1; }
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
            call Glcd.drawTextPgm(text_noteInput, GLCD_LEFT_END, GLCD_FIRST_LINE);
            post inputNote();
        }
        else
        {
            atomic { errno = E_CHAN_NLIST; }
            post displaySoftError();
        }
    }

    /*
     * @brief Access the favourite stations.
     */
    static void tuneToFavourite(char c)
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
    
    /*
     * @brief Remove '\n' and '\r' from a string.
     */
    static void removeIllegalChars(char *data, uint8_t len)
    {
        uint8_t i;

        for (i = 0; i < len; i++)
        {
            if (data[i] == '\n' || data[i] == '\r')
                data[i] = ' ';
        }   
    }
    
    ////////////////////////
    /* Events */
    ////////////////////////

    /*
     * @brief Inititalize all modules.
     */
    event void Boot.booted()
    {
        char textBuf[8];
        uint8_t id;
        channel_t *c;

        /* Initialize list datastructure */
        for (id = 0; id < CHANNEL_LIST_SZ; id++)
        {
            atomic { c = &channels.list[id]; }
            c->info.name = c->name;
            c->info.notes = c->note;
            memset(c->info.name, 0, NAME_SZ+1);
            memset(c->info.notes, 0, NOTE_SZ+1);
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
        call Glcd.drawTextPgm(text_init, GLCD_LEFT_END, GLCD_FIRST_LINE);

        call Keyboard.init();
        call RadioInit.init();
        call DBInit.init();
    }
   
    /*
     * @brief If FMClick is ready, we are good to go.
     */
    event void Radio.initDone(error_t res)
    {
        if (res == SUCCESS)
        {
            /* Set volume and fetch database entries */
            call Radio.receiveRDS(FALSE);
            call volumeKnob.read();
            call VolumeTimer.startPeriodic(VOLUME_UPDATE_RATE);
            call DB.getChannelList(FALSE);
        }
        else
        {
            atomic { errno = E_FMCLICK_INIT; }
            post displayHardError();
        }
    }

    /*
     * @brief Handle keyboard input.
     */
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

    /*
     * @brief Select action after radio tuned to station.
     */
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

    /*
     * @brief Select action after radio seek complete.
     */
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
   
    /*
     * @brief Grab the RDS data from the driver.
     */
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

    /*
     * @brief Timeout of soft error message.
     */
    event void ErrorTimer.fired()
    {
        atomic { appState = KBCTRL; }
        post displayChannelInfo();
    }
    
    /*
     * @brief RDS timeout for band seek.
     */
    event void RDSTimer.fired()
    {
        post addChannel();
    }

    /*
     * @brief ADC conversion finished.
     */
    event void volumeKnob.readDone(error_t res, uint16_t val)
    {
        newVolume = (uint8_t)(val >> 6);
        post setVolume();
    }
   
    /*
     * @brief Process channel entry from the DB.
     */
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
            /* Add entry to the list */
            else
            {
                channel_t *c;
                atomic { c = &channels.list[channels.entries++]; }

                memcpy(&c->info, &channel, sizeof(channelInfo));
                c->info.name = c->name;
                c->info.notes = c->note;
                snprintf(c->info.name, NAME_SZ, "%-8s", channel.name);
                strncpy(c->info.notes, channel.notes, NOTE_SZ);

                /* Add entry to favourites */
                if (c->info.quickDial > 0)
                {
                    favourites.table[c->info.quickDial-1] = channels.entries-1;
                    favourites.entries++;
                }
            }
        }
    }

    /*
     * @brief Check if channel has been saved suceessfully to the DB.
     */
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

