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
//TODO put strings from commands in PROGMEM
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
        atomic { state = dbState; }

        if (IDLE != state)
            return;

        atomic { dbState = ADD; }

        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        if (id == 0xff)
            sprintf((char *) msgBuf.send.data, "add\rid=%d,name=%s,qdial=%d,freq=%d,picode=%d,note=%s\n",
                    0, channel->name, channel->quickDial, channel->frequency, channel->pi_code, channel->notes);
        else if (id >= 0 && id <= 15)
            sprintf((char *) msgBuf.send.data, "update\rid=%d,name=%s,qdial=%d,freq=%d,picode=%d,note=%s\n",
                    id, channel->name, channel->quickDial, channel->frequency, channel->pi_code, channel->notes);

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
    //TODO implement onlyFavourites
    command void Database.getChannelList(uint8_t onlyFavorites)
    {
        enum db_state state;
        atomic { state = dbState; }

        if (IDLE != state)
            return;
        
        atomic { dbState = LIST; }
        
        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf((char *) msgBuf.send.data, "list\r\n");
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
        atomic { state = dbState; }

        if (IDLE != state)
            return;
        
        atomic { dbState = GET; }
        
        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf((char *) msgBuf.send.data, "get\rid=%d\n", id);
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
        atomic { state = dbState; }

        if (IDLE != state)
            return;
        
        atomic { dbState = PURGE; }
        
        memset(msgBuf.send.data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf((char *) msgBuf.send.data, "purgeall\r\n");
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
        call Glcd.drawText("fetchabcd", 0, 60);
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
                call Glcd.drawText("get fin", 0, 60);
                if (getList)
                    post fetchList();
                break;

            case PURGE:
                break;

            default:
                return;
        }

//        if (strncmp((char *) msg->data, "ok\0", 3) == 0)
//        {
//            //add: ok\rid=...\n signal savedChannel
//            //get: ok\rid=...,freq=...,name=...,qdial=...,picode=...,note=...\n signal receivedChannelEntry
//            //purgeall: ok\r\n
//            //list: ok\rid,id,id,id,...\n
//           
//            char *k, *sp;
//            char workBuf[msg->len-2];
//            memcpy(workBuf, paramStart, msg->len-3);
//            workBuf[msg->len-2] = '\0'; //TODO is this needed?
//
//            k = strtok_r(workBuf, "=", &sp);
//
//            /* Need to signal only certain events with return params */
//            if (k != NULL && strcmp("id", k) == 0)
//            {
//                uint8_t id = (uint8_t) strtol(sp, NULL, 10);
//
//                if (id >= 0 && id < 16)
//                {
//                    /* add or get respond with just the id */
//                    if (strchr(sp, ',') == NULL)
//                        signal Database.savedChannel(id, 0);
//                    /* We got some channel response */ 
//                    else
//                    {
//                        char name[8];
//                        char notes[40];
//                        channelInfo channel;
//                        channel.name = name;
//                        channel.notes = notes;
//                        if (parseChannelInfo(k, &channel))
//                            signal Database.receivedChannelEntry(id, channel);
//                    }   
//                }
//            }
//            else
//            {
//                uint8_t id;
//                sp = NULL;
//                memcpy(workBuf, paramStart, msg->len-3);
//                workBuf[msg->len-2] = '\0'; 
//
//                k = strtok_r(workBuf, ",", &sp);
//
//                while (k != NULL)
//                {
//                    id = (uint8_t) strtol(k, NULL, 10);
//                    if (id >= 0 && id <= 15)
//                        call Database.getChannel(id);
//
//                    k = strtok_r(NULL, ",", &sp);
//                }
//            }
//        }
//        else if (strncmp((char *) msg->data, "err\0", 4) == 0)
//        {
//            //add: err\rcmd=add,msg=...\n signal savedChannel
//            //update: err\rcmd=update,msg=...\n signal savedChannel
//            //get: err\rcmd=update,msg=...\n
//            //purgeall: err\rcmd=update,msg=...\n
//            
//            char *k, *v, *sp;
//            char workBuf[msg->len-3];
//            uint8_t cmd = 0;
//            uint8_t res = 0;
//            memcpy(workBuf, paramStart, msg->len-4);
//            workBuf[msg->len-3] = '\0'; 
//            
//            k = strtok_r(workBuf, "=", &sp);
//            if (k == NULL) 
//                return;
//
//            while (k != NULL)
//            {
//                v = sp;
//
//                if (strcmp("cmd", k) == 0) 
//                {
//                    if (strcmp("add", v) == 0 || strcmp("update", v) == 0)
//                        cmd = 1;
//                    /* Not interested in other responses */
//                    else
//                        return;
//                }
//                else if (strcmp("msg", k) == 0) 
//                {
//                    if (strcmp("Channel DB Full", v) == 0)
//                        res = 1;
//                    else //TODO maybe differentiate more between errors
//                        res = 2;
//                }
//
//                v = strchr(sp, ',');
//                sp = v + 1;
//
//                k = strtok_r(NULL, "=", &sp);
//            }
//
//            if (cmd != 0)
//                signal Database.savedChannel(0xff, res); //TODO which ID to signal?
//        }
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

        channel.name = name;
        channel.notes = notes;

        call Glcd.drawText("get", 0, 60);
        if (parseChannelInfo((char *) paramStart, &channel, &id))
            signal Database.receivedChannelEntry(id, channel);
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

    static bool parseChannelInfo(char *params, channelInfo *channel, uint8_t *id)
    {
        char *k, *v, *sp;
        bool gotName = FALSE;

        k = strtok_r(params, "=", &sp);
        if (k == NULL) 
        {
            return FALSE;
        }

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
                if (qdial < 1 || qdial > 9)
                    return FALSE;
                channel->quickDial = qdial;
            } 
            else if (strncmp_P(k, cmd_name, CMD_NAME_LEN) == 0) 
            {
                snprintf(channel->name, NAME_MAX_LEN, "%-8s", v);
                channel->name[NAME_MAX_LEN+1] = '\0';
                
                sp += 8;
                /* Name is either too long or delimiter is missing */
                if (*sp != ',')
                    return FALSE; 
                sp++;
                gotName = TRUE;
            } 
            else if (strncmp_P(k, cmd_note, CMD_NOTE_LEN) == 0) 
            {
                strncpy(channel->notes, v, NOTE_MAX_LEN);
                channel->name[NOTE_MAX_LEN+1] = '\0';
                 
                /* According to specification, note is the last parameter */
                return TRUE;
            }

            if (gotName)
            {
                v = strchr(sp, ',');
                if (v == NULL) 
                    return FALSE;
                sp = v + 1;
                gotName = FALSE;
            }

            k = strtok_r(NULL, "=", &sp);
        }

        /* This should never be reached */
        return FALSE;
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

