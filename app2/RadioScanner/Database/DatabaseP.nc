/**
 *
 * @file    DatabaseP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-26
 *
 * Database module implementation.
 *
**/

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
        interface Pool<udp_msg_t> as MsgPool;
        interface Queue<udp_msg_t *> as SendQ;
        interface Queue<udp_msg_t *> as RecvQ;
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

    ////////////////////////
    /* Interface commands */
    ////////////////////////

    //TODO signal initDone event
    command Init.init()
    {
        //TODO check if some ip init is necessary
        MsgPool.init();
        sendBusy = FALSE;
        recvBusy = FALSE;
    }

    /**
     * Save a new channel, or change properties of an existing one.
     * @param id The channel index from the database store, 0xFF to autoselect,
     *           must be between 0 and 15 if passed manually
     * @param channel The channel information, see channelInfo typedef
     */
    //TODO make sure no \r and \n are in the values and the name is exactly 8 char and note max 40 char, make part of contract -> set last byte to 0
    //TODO implement update channel, probably make dependant on id
    command void saveChannel(uint8_t id, channelInfo *channel)
    {
        /* Allocate memory for the udp message */
        udp_msg_t *udpMsg = call MsgPool.get();
        memset(udpMsg->data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf(udpMsg->data, "add\rid=%d,name=%s,qdial=%d,freq=%d,picode=%d,note=%s\n",
                id, channel->name, channel->quickDial, channel->frequency, channel->pi_code);
        udpMsg->[MAX_MSG_LEN-1];
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
    command void getChannelList(uint8_t onlyFavorites)
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
    command void getChannel(uint8_t id)
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
    command void purgeChannelList()
    {
        /* Allocate memory for the udp message */
        udp_msg_t *udpMsg = call MsgPool.get();
        memset(udpMsg->data, 0, MAX_MSG_LEN);

        /* Compose udp message */
        sprintf(udpMsg->data, "purgeall\r\n");
        udpMsg->len = strlen(udpMsg->data);

        call SendQ.enqueue(udpMsg);

        if (!sendBusy)
            post sendTask();
    }

    //TODO signal these events and remove prototypes
    /**
     * Received highscore entry from the server.
     * @param id The channel index from the database store
     * @param channel The channel information, see channelInfo typedef
     */
    event void receivedChannelEntry(uint8_t id, channelInfo channel);

    /**
     * Server proceesed our request to save a Channel
     * @param id The channel index from the database store, the one we passed
     *           or the which was choosen if 0xFF was passed.
     * @param result 0 = OK, 1 = No free index (only ID auto choose), 2 = DB error 
     */
    event void savedChannel(uint8_t id, uint8_t result);

    ////////////////////////
    /* Tasks              */
    ////////////////////////

    task void sendTask(void)
    {
        if (! (call SendQ.empty()))
        {
            static in_addr_t destination = { .bytes {DESTINATION}};
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

        if (strncmp(msg, "ok\0", 3) == 0)
        {
        }
        else if (strncmp(msg, "err\0", 4) == 0)
        {
        }
    }

    static bool prepareMessage(udp_msg_t *msg, uint8_t **paramStart)
    {
        /* Valid message is terminated with newline */
        if (msg->data[msg->len-1] != '\n')
            return false;

        msg->data[msg->len-1] = '\0';

        /* Search start of parameter string */
        *paramStart = strchr(msg->data, '\r');
        if (*paramStart != NULL)
        {
            **paramStart = '\0';
            *paramStart++;
        } 
        else 
            *paramStart = &msg->data[msg->len-1];

        return true;    
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
        /* Truncate message if too long */
        if (len > MAX_MSG_LEN)
            len = MAX_MSG_LEN

        udp_msg_t *udpMsg = call MsgPool.get();
        memcpy(udpMsg->data, data, len);
        udpMsg->len = len;
        call RecvQ.enqueue(udpMsg);

        if (!recvBusy)
            post recvTask();
    }

}

