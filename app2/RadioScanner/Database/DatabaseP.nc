/**
 *
 * @file    DatabaseP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-26
 *
 * Database module implementation.
 *
**/

#include <avr/pgmspace.h>
#include <ip.h>
#include <stdio.h>
#include <string.h>
#include <udp_config.h>
#include <commands.h>

//TODO find bug in get/list
//TODO init error handling
//TODO implement functionality in network stack

module DatabaseP {
    provides 
    {
        interface Init;
        interface Database;
    }
    uses
    {
        interface UdpSend;
        interface UdpReceive;
        interface IpControl;
        interface SplitControl as Control;

        interface Glcd;
    }
}

implementation {
    #define NAME_MAX_LEN    8
    #define NOTE_MAX_LEN    40
    #define ERR_MSG_MAX_LEN 20

    #define DB_MAX_ENTRIES  15

    enum db_state {IDLE, INIT, ADD, LIST, GET, PURGE};
    static enum db_state dbState;
    static bool getList;
    static bool favOnly;

    static struct
    {
        udp_msg_t send;
        udp_msg_t recv;
    } msgBuf;

    static struct
    {
        uint8_t entries;
        uint8_t currId;
        uint8_t ids[DB_MAX_ENTRIES];
    } list;

    typedef struct
    {
        char add[CMD_ADD_LEN+1];
        char update[CMD_UPDATE_LEN+1];
        char id[CMD_ID_LEN+1];
        char freq[CMD_FREQ_LEN+1];
        char qdial[CMD_QDIAL_LEN+1];
        char picode[CMD_PICODE_LEN+1];
        char name[CMD_NAME_LEN+1];
        char note[CMD_NOTE_LEN+1];
    } params_t;

    /* Task prototypes */
    task void sendTask(void);
    task void recvTask(void);
    task void fetchList(void);

    /* Function prototypes */
    static void decodeMessage(udp_msg_t *msg);
    static void decodeAdd(udp_msg_t *msg);
    static void decodeList(udp_msg_t *msg);
    static void decodeGet(udp_msg_t *msg);
    static bool prepareMessage(udp_msg_t *msg, uint8_t **paramStart);
    static bool parseChannelInfo(char *params, channelInfo *channel, uint8_t *id);
    static void getParamsPgm(params_t *p);

    ////////////////////////
    /* Interface commands */
    ////////////////////////

    command error_t Init.init(void)
    {
        in_addr_t *ip;
        in_addr_t cip = { .bytes {IP}};
        in_addr_t cnm = { .bytes {NETMASK}};
        in_addr_t cgw = { .bytes {GATEWAY}};
        char ipBuf[17];

        atomic { dbState = INIT; }

        call IpControl.setIp(&cip);
        call IpControl.setNetmask(&cnm);
        call IpControl.setGateway(&cgw);

        ip = call IpControl.getIp();

        sprintf(ipBuf, ">%03d.%03d.%03d.%03d", ip->bytes.b1, ip->bytes.b2, ip->bytes.b3, ip->bytes.b4);
        call Glcd.drawText(ipBuf, 0, 60);

        getList = FALSE;

        call Control.start();

        //TODO maybe move to control.startDone and signal init error to app
        atomic { dbState = IDLE; }
        
        return SUCCESS;
    }

    /**
     * Save a new channel, or change properties of an existing one.
     * @param id The channel index from the database store, 0xFF to autoselect,
     *           must be between 0 and 15 if passed manually
     * @param channel The channel information, see channelInfo typedef
     */
    //TODO make sure no \r and \n are in the values and the name is exactly 8 char and note max 40 char, make part of contract -> set last byte to 0
    command void Database.saveChannel(uint8_t id, channelInfo *channel)
    {
        enum db_state state;
        params_t params;
        atomic { state = dbState; }

        if (IDLE != state)
            return;

        atomic { dbState = ADD; }

        getParamsPgm(&params);
        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        if (id == 0xff)
        {
            sprintf((char *) msgBuf.send.data, "%s\r%s=%d,%s=%-8s,%s=%d,%s=%d,%s=%d,%s=%s\n",
                    params.add, params.id, 0, params.name, channel->name, params.qdial,
                    channel->quickDial, params.freq, channel->frequency, params.picode,
                    channel->pi_code, params.note, channel->notes);
        }
        else if (id < DB_MAX_ENTRIES)
        {
            sprintf((char *) msgBuf.send.data, "%s\r%s=%d,%s=%-8s,%s=%d,%s=%d,%s=%d,%s=%s\n",
                    params.update, params.id, id, params.name, channel->name, params.qdial,
                    channel->quickDial, params.freq, channel->frequency, params.picode,
                    channel->pi_code, params.note, channel->notes);
        }

        msgBuf.send.data[MAX_MSG_LEN-1] = '\0';
        msgBuf.send.len = strlen((char *) msgBuf.send.data);

        post sendTask();
    }

    /**
     * Request the channel list from the database server
     * Received channels will be signaled through receivedChannelEntry
     * @param onlyFavorites tells server to send only the channels with a
     *        registered quickDial number, if not zero
     */
    command void Database.getChannelList(uint8_t onlyFavorites)
    {
        enum db_state state;
        char listp[CMD_LIST_LEN+1];
        atomic { state = dbState; }

        if (IDLE != state)
            return;
        
        atomic { dbState = LIST; }
       
        favOnly = onlyFavorites;
        strncpy_P(listp, cmd_list, CMD_LIST_LEN+1);
        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf((char *) msgBuf.send.data, "%s\r\n", listp);
        msgBuf.send.len = strlen((char *) msgBuf.send.data);

        post sendTask();
    }

    /**
     * Request the channel list from the database server
     * Received channels will be signaled through receivedChannelEntry
     */
    command void Database.getChannel(uint8_t id)
    {
        enum db_state state;
        char get[CMD_GET_LEN+1], idp[CMD_ID_LEN+1];
        atomic { state = dbState; }

        if (IDLE != state)
            return;
        
        atomic { dbState = GET; }
        
        strncpy_P(get, cmd_get, CMD_GET_LEN+1);
        strncpy_P(idp, cmd_id, CMD_ID_LEN+1);
        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf((char *) msgBuf.send.data, "%s\r%s=%d\n", get, idp, id);
        msgBuf.send.len = strlen((char *) msgBuf.send.data);

        post sendTask();
    }

    /**
     * Request that the Database purges all channels and their state
     * Received channels will be signaled through receivedChannelEntry
     */
    command void Database.purgeChannelList()
    {
        enum db_state state;
        char purge[CMD_PURGEALL_LEN+1];
        atomic { state = dbState; }

        if (IDLE != state)
            return;
        
        atomic { dbState = PURGE; }
        
        strncpy_P(purge, cmd_purgeall, CMD_PURGEALL_LEN+1);
        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf((char *) msgBuf.send.data, "%s\r\n", purge);
        msgBuf.send.len = strlen((char *) msgBuf.send.data);
        
        post sendTask();
    }

    ////////////////////////
    /* Tasks              */
    ////////////////////////

    task void sendTask(void)
    {
        in_addr_t destination = { .bytes {DESTINATION}};

        if (call UdpSend.send(&destination, UDP_PORT, msgBuf.send.data, msgBuf.send.len) != SUCCESS)
            post sendTask();
    }

    task void recvTask(void)
    {
        decodeMessage(&msgBuf.recv);
        atomic { dbState = IDLE; }
    }

    task void fetchList(void)
    {
        if (list.entries - list.currId > 0)
            call Database.getChannel(list.ids[list.currId++]);
        else /* Already received last entry */
        {
            channelInfo dummy;
            getList = FALSE;
            list.entries = 0;
            list.currId = 0;
            atomic { dbState = IDLE; }
            signal Database.receivedChannelEntry(0xff, dummy);
        }
    }

    ////////////////////////
    /* Internal functions */
    ////////////////////////
    
    static void decodeMessage(udp_msg_t *msg)
    {
        enum db_state state;
        atomic { state = dbState; }
        
        switch (state)
        {
            case ADD:
                decodeAdd(msg);
                break;

            case LIST:
                decodeList(msg);
                break;

            case GET:
                decodeGet(msg);
                if (getList)
                    post fetchList();
                break;

            case PURGE:
                break;

            default:
                return;
        }
    }

    static void decodeAdd(udp_msg_t *msg)
    {
        uint8_t *paramStart;

        /* Invalid message */
        if (!prepareMessage(msg, &paramStart))
            return;

        if (strncmp_P((char *) msg->data, cmd_ok, CMD_OK_LEN) == 0)
        {
            char *k, *v;
            uint8_t id;

            k = strtok_r((char *) paramStart, "=", &v);
            id = (uint8_t) strtoul(v, NULL, 10);

            if (id < DB_MAX_ENTRIES)
                signal Database.savedChannel(id, 0);
            else
                signal Database.savedChannel(0, 2);
        }
        else
        {
            uint8_t res = 2;
            char *_msg = strstr_P((char *) paramStart, cmd_msg);

            if (_msg != NULL)
            {
                /* Move to actual message */
                _msg += 4;

                if (strncmp_P(_msg, cmd_dbFull, CMD_DBFULL_LEN) == 0)
                    res = 1;
            }

            signal Database.savedChannel(0, res);
        }
    }
    
    static void decodeList(udp_msg_t *msg)
    {
        uint8_t *paramStart;
        uint8_t id;
        char *k, *sp;
        
        /* Database empty */
        if (msg->data[2] == '\n')
        {
            channelInfo dummy;
            signal Database.receivedChannelEntry(0xff, dummy);
            return;
        }
        
        /* Invalid message */
        if (!prepareMessage(msg, &paramStart))
            return;

        list.entries = 0;
        list.currId = 0;
        k = strtok_r((char *) paramStart, ",", &sp);

        while (k != NULL)
        {
            id = (uint8_t) strtol(k, NULL, 10);
            if (id < DB_MAX_ENTRIES)
                list.ids[list.entries++] = id;

            k = strtok_r(NULL, ",", &sp);
        }

        if (list.entries > 0)
        {
            getList = TRUE;
            post fetchList();
        }
    }
    
    static void decodeGet(udp_msg_t *msg)
    {
        uint8_t *paramStart;
        uint8_t id;
        /* Space for NULL termination */
        char name[NAME_MAX_LEN+1];
        char notes[NOTE_MAX_LEN+1];
        channelInfo channel;

        /* Invalid message */
        if (!prepareMessage(msg, &paramStart))
            return;

        memset(name, 0, NAME_MAX_LEN+1);
        memset(notes, 0, NOTE_MAX_LEN+1);
        channel.name = name;
        channel.notes = notes;

        if (parseChannelInfo((char *) paramStart, &channel, &id))
        {
            /* Filter favourites */
            if (favOnly)
            {
                if (channel.quickDial > 0)
                    signal Database.receivedChannelEntry(id, channel);
            }
            else
                signal Database.receivedChannelEntry(id, channel);
        }
        else
        {
            channelInfo dummy;
            signal Database.receivedChannelEntry(0xfe, dummy);
        }
    }
    
    static bool prepareMessage(udp_msg_t *msg, uint8_t **paramStart)
    {
        /* Valid message is terminated with newline */
        if (msg->data[msg->len-1] != '\n')
            return FALSE;

        msg->data[msg->len-1] = '\0';

        /* Search start of parameter string */
        *paramStart = (uint8_t *) strchr((char *) msg->data, '\r');
        if (*paramStart != NULL)
        {
            **paramStart = '\0';
            (*paramStart)++;
        } 
        else 
            *paramStart = &msg->data[msg->len];
        
        return TRUE;    
    }

    /*
     * @brief           Parse a UDP message into a channelInfo struct.
     * @param params    The parameters to parse.
     * @param channel   The struct to parse into.
     * @param id        The ID of the DB entry is stored here.
     * @return          Return if the params were valid.
     */
    static bool parseChannelInfo(char *params, channelInfo *channel, uint8_t *id)
    {
        char *k, *v, *sp;
        bool gotName = FALSE;

        k = strtok_r(params, "=", &sp);
        if (k == NULL) 
            return FALSE;

        while (k != NULL)
        {
            v = sp;

            if (strncmp_P(k, cmd_id, CMD_ID_LEN) == 0)
            {
                uint8_t _id = (uint8_t) strtoul(v, NULL, 10);
                if (_id >= DB_MAX_ENTRIES)
                    return FALSE;

                *id = _id;
            } 
            else if (strncmp_P(k, cmd_freq, CMD_FREQ_LEN) == 0)
            {
                uint16_t freq = (uint16_t) strtoul(v, NULL, 10);
                if (freq < 875 || freq > 1080)
                    return FALSE;

                channel->frequency = freq;
            } 
            else if (strncmp_P(k, cmd_picode, CMD_PICODE_LEN) == 0) 
            {
                uint16_t pi_code = (uint16_t) strtoul(v, NULL, 10);
                channel->pi_code = pi_code;
            } 
            else if (strncmp_P(k, cmd_qdial, CMD_QDIAL_LEN) == 0) 
            {
                uint8_t qdial = (uint8_t) strtoul(v, NULL, 10);
                if (qdial > 9)
                    return FALSE;

                channel->quickDial = qdial;
            } 
            else if (strncmp_P(k, cmd_name, CMD_NAME_LEN) == 0) 
            {
                snprintf(channel->name, NAME_MAX_LEN, "%-8s", v);
                channel->name[NAME_MAX_LEN] = '\0';
                
                /* Name is either too long or delimiter is missing */
                sp += 8;
                if (*sp != ',')
                    return FALSE;

                sp++;
                gotName = TRUE;
            } 
            else if (strncmp_P(k, cmd_note, CMD_NOTE_LEN) == 0) 
            {
                if (*v != '\0')
                    strncpy(channel->notes, v, NOTE_MAX_LEN);
                
                channel->name[NOTE_MAX_LEN] = '\0';
                 
                /* According to specification, note is the last parameter */
                return TRUE;
            }

            if (!gotName)
            {
                v = strchr(sp, ',');
                if (v == NULL) 
                    return FALSE;

                sp = v + 1;
            }

            k = strtok_r(NULL, "=", &sp);
            gotName = FALSE;
        }

        /* This should never be reached */
        return FALSE;
    }

    /*
     * @brief Load the UDP message parameters from PROGMEM.
     */
    static void getParamsPgm(params_t *p)
    {
        strncpy_P(p->add, cmd_add, CMD_ADD_LEN+1);
        strncpy_P(p->update, cmd_update, CMD_UPDATE_LEN+1);
        strncpy_P(p->id, cmd_id, CMD_ID_LEN+1);
        strncpy_P(p->freq, cmd_freq, CMD_FREQ_LEN+1);
        strncpy_P(p->picode, cmd_picode, CMD_PICODE_LEN+1);
        strncpy_P(p->qdial, cmd_qdial, CMD_QDIAL_LEN+1);
        strncpy_P(p->name, cmd_name, CMD_NAME_LEN+1);
        strncpy_P(p->note, cmd_note, CMD_NOTE_LEN+1);
    }

    ////////////////////////
    /* Events             */
    ////////////////////////

    event void UdpSend.sendDone(error_t error)
    {
        if (error != SUCCESS)
            post sendTask();
    }

    event void UdpReceive.received(in_addr_t *srcIp, uint16_t srcPort, uint8_t *data, uint16_t len)
    {
        /* Truncate message if too long */
        if (len > MAX_MSG_LEN)
            len = MAX_MSG_LEN;

        memcpy(msgBuf.recv.data, data, len);
        msgBuf.recv.len = len;
        
        post recvTask();
    }

    event void Control.startDone(error_t error)
    {

    }

    //TODO maybe do some error handling
    event void Control.stopDone(error_t error)
    {

    }
}

