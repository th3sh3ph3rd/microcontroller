/**
 *
 * @file    DatabaseP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-26
 *
 * Database module implementation.
 *
**/

#include <ip.h>
#include <stdio.h>
#include <string.h>
#include <udp_config.h>

//TODO find out if send queue is needed
//TODO find out if cmd/param strings have to be stored in progmem
//TODO response error (delete) on line 492 in database.c

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
        interface Pool<udp_msg_t> as MsgPool;
        interface Queue<udp_msg_t *> as SendQ;
        interface Queue<udp_msg_t *> as RecvQ;

        interface Glcd;
    }
}

implementation {
    #define NOTE_MAX_LEN    40
    #define ERR_MSG_MAX_LEN 20

    bool sendBusy;
    bool recvBusy;

    /* Task prototypes */
    task void sendTask(void);
    task void recvTask(void);

    /* Function prototypes */
    static void decodeMessage(udp_msg_t *msg);
    static bool prepareMessage(udp_msg_t *msg, uint8_t **paramStart);
    static bool parseChannelInfo(char *params, channelInfo *channel);

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

        call IpControl.setIp(&cip);
        call IpControl.setNetmask(&cnm);
        call IpControl.setGateway(&cgw);

        ip = call IpControl.getIp();

        sprintf(ipBuf, ">%03d.%03d.%03d.%03d", ip->bytes.b1, ip->bytes.b2, ip->bytes.b3, ip->bytes.b4);
        call Glcd.drawText(ipBuf, 0, 60);

        sendBusy = FALSE;
        recvBusy = FALSE;

        call Control.start();

        return SUCCESS;
    }

    /**
     * Save a new channel, or change properties of an existing one.
     * @param id The channel index from the database store, 0xFF to autoselect,
     *           must be between 0 and 15 if passed manually
     * @param channel The channel information, see channelInfo typedef
     */
    //TODO make sure no \r and \n are in the values and the name is exactly 8 char and note max 40 char, make part of contract -> set last byte to 0
    //TODO implement update channel, probably make dependant on id
    command void Database.saveChannel(uint8_t id, channelInfo *channel)
    {
        /* Allocate memory for the udp message */
        udp_msg_t *udpMsg = call MsgPool.get();
        memset(udpMsg->data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf(udpMsg->data, "add\rid=%d,name=%s,qdial=%d,freq=%d,picode=%d,note=%s\n",
                id, channel->name, channel->quickDial, channel->frequency, channel->pi_code, channel->notes);
        udpMsg->data[MAX_MSG_LEN-1] = '\0';
        udpMsg->len = strlen(udpMsg->data);

        call SendQ.enqueue(udpMsg);

        if (!sendBusy)
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
        /* Allocate memory for the udp message */
        udp_msg_t *udpMsg = call MsgPool.get();
        memset(udpMsg->data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf(udpMsg->data, "list\r\n");
        udpMsg->len = strlen(udpMsg->data);

        call SendQ.enqueue(udpMsg);

        if (!sendBusy)
            post sendTask();
    }

    /**
     * Request the channel list from the database server
     * Received channels will be signaled through receivedChannelEntry
     */
    command void Database.getChannel(uint8_t id)
    {
        /* Allocate memory for the udp message */
        udp_msg_t *udpMsg = call MsgPool.get();
        memset(udpMsg->data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf(udpMsg->data, "get\rid=%d\n", id);
        udpMsg->len = strlen(udpMsg->data);

        call SendQ.enqueue(udpMsg);

        if (!sendBusy)
            post sendTask();
    }

    /**
     * Request that the Database purges all channels and their state
     * Received channels will be signaled through receivedChannelEntry
     */
    command void Database.purgeChannelList()
    {
        /* Allocate memory for the udp message */
        udp_msg_t *udpMsg = call MsgPool.get();
        memset(udpMsg->data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf((char *) udpMsg->data, "purgeall\r\n");
        udpMsg->len = strlen((char *) udpMsg->data)+1;

        call SendQ.enqueue(udpMsg);

        if (!sendBusy)
            post sendTask();
    }

    ////////////////////////
    /* Tasks              */
    ////////////////////////

    task void sendTask(void)
    {
        if (! (call SendQ.empty()))
        {
            in_addr_t destination = { .bytes {DESTINATION}};
            udp_msg_t *udpMsg = call SendQ.head();

            //TODO repost task on error?
            if (call UdpSend.send(&destination, UDP_PORT, udpMsg->data, udpMsg->len) == SUCCESS)
                sendBusy = TRUE;
            else
                sendBusy = FALSE;
        }
        else
            sendBusy = FALSE;
    }

    task void recvTask(void)
    {
        udp_msg_t *udpMsg = call RecvQ.dequeue();
       
        decodeMessage(udpMsg);

        /* Free up memory */
        call MsgPool.put(udpMsg);

        if (! (call RecvQ.empty()))
            post recvTask();
        else
            recvBusy = FALSE;
    }

    ////////////////////////
    /* Internal functions */
    ////////////////////////
    
    static void decodeMessage(udp_msg_t *msg)
    {
        uint8_t *paramStart;

        /* Invalid message */
        if (!prepareMessage(msg, &paramStart))
            return;

        if (strncmp((char *) msg->data, "ok\0", 3) == 0)
        {
            //add: ok\rid=...\n signal savedChannel
            //get: ok\rid=...,freq=...,name=...,qdial=...,picode=...,note=...\n signal receivedChannelEntry
            //purgeall: ok\r\n
            //list: ok\rid,id,id,id,...\n
           
            char *k, *sp;
            char workBuf[msg->len-2];
            memcpy(workBuf, paramStart, msg->len-3);
            workBuf[msg->len-2] = '\0'; //TODO is this needed?

            k = strtok_r(workBuf, "=", &sp);

            /* Need to signal only certain events with return params */
            if (k != NULL && strcmp("id", k) == 0)
            {
                uint8_t id = (uint8_t) strtol(sp, NULL, 10);

                if (id >= 0 && id < 16)
                {
                    /* add or get respond with just the id */
                    if (strchr(sp, ',') == NULL)
                        signal Database.savedChannel(id, 0);
                    /* We got some channel response */ 
                    else
                    {
                        char name[8];
                        char notes[40];
                        channelInfo channel;
                        channel.name = name;
                        channel.notes = notes;
                        if (parseChannelInfo(k, &channel))
                            signal Database.receivedChannelEntry(id, channel);
                    }   
                }
            }
            //TODO deal with list response at this point
            //TODO put all ids in a queue and call getChannel for every entry
        }
        else if (strncmp((char *) msg->data, "err\0", 4) == 0)
        {
            //add: err\rcmd=add,msg=...\n signal savedChannel
            //update: err\rcmd=update,msg=...\n signal savedChannel
            //get: err\rcmd=update,msg=...\n
            //purgeall: err\rcmd=update,msg=...\n
            
            char *k, *v, *sp;
            char workBuf[msg->len-3];
            uint8_t cmd = 0;
            uint8_t res = 0;
            memcpy(workBuf, paramStart, msg->len-4);
            workBuf[msg->len-3] = '\0'; //TODO is this needed?
            
            k = strtok_r(workBuf, "=", &sp);
            if (k == NULL) 
                return;

            while (k != NULL)
            {
                v = sp;

                if (strcmp("cmd", k) == 0) 
                {
                    if (strcmp("add", v) == 0 || strcmp("update", v) == 0)
                        cmd = 1;
                    /* Not interested in other responses */
                    else
                        return;
                }
                else if (strcmp("msg", k) == 0) 
                {
                    if (strcmp("Channel DB Full", v) == 0)
                        res = 1;
                    else //TODO maybe differentiate more between errors
                        res = 2;
                }

                v = strchr(sp, ',');
                sp = v + 1;

                k = strtok_r(NULL, "=", &sp);
            }

            if (cmd != 0)
                signal Database.savedChannel(0xff, res); //TODO which ID to signal?
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
            *paramStart++;
        } 
        else 
            *paramStart = &msg->data[msg->len-1];

        return TRUE;    
    }

    static bool parseChannelInfo(char *params, channelInfo *channel)
    {
        char *k, *v, *sp;
        bool gotName =  FALSE;

        k = strtok_r(params, "=", &sp);
        if (k == NULL) 
            return FALSE;

        while (k != NULL)
        {
            v = sp;

            if (strcmp("freq", k) == 0)
            {
                uint16_t freq = (uint16_t) strtol(v, NULL, 10);
                if (freq < 875 || freq > 1080)
                    return FALSE;
                channel->frequency = freq;
            } 
            else if (strcmp("picode", k) == 0) 
            {
                uint16_t pi_code = (uint16_t) strtol(v, NULL, 10);
                //TODO add appropriate check
                channel->pi_code = pi_code;
            } 
            else if (strcmp("qdial", k) == 0) 
            {
                uint8_t qdial = (uint8_t) strtol(v, NULL, 10);
                if (qdial < 1 || qdial > 9)
                    return FALSE;
                channel->quickDial = qdial;
            } 
            else if (strcmp("name", k) == 0) 
            {
                //TODO what is it doing???
                snprintf(channel->name, 9, "%-8s", v);
                channel->name[8] = '\0';
                
                sp += 8;
                /* Name is either too long or delimiter is missing */
                if (*sp != ',')
                    return FALSE; 
                sp++;
                gotName = TRUE;
            } 
            else if (strcmp("note", k) == 0) 
            {
                strncpy(channel->notes, v, 40);
                channel->name[40] = '\0';
                 
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
        /* Free up memory and remove queue entry */
        call MsgPool.put(call SendQ.dequeue());

        if (! (call SendQ.empty()))
            post sendTask();
        else
            sendBusy = FALSE;
    }

    event void UdpReceive.received(in_addr_t *srcIp, uint16_t srcPort, uint8_t *data, uint16_t len)
    {
        udp_msg_t *udpMsg = call MsgPool.get();
       
        call Glcd.drawText(data, 0, 50);

        /* Truncate message if too long */
        if (len > MAX_MSG_LEN)
            len = MAX_MSG_LEN;

        memcpy(udpMsg->data, data, len);
        udpMsg->len = len;
        call RecvQ.enqueue(udpMsg);

        if (!recvBusy)
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

