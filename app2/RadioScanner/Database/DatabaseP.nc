/**
 *
 * @file    DatabaseP.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-26
 *
 * Database module implementation.
 *
**/

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
    }
}

implementation {
    ////////////////////////
    /* Interface commands */
    ////////////////////////

    //TODO signal initDone event
    command Init.init()
    {

    }

    /**
     * Save a new channel, or change properties of an existing one.
     * @param id The channel index from the database store, 0xFF to autoselect,
     *           must be between 0 and 15 if passed manually
     * @param channel The channel information, see channelInfo typedef
     */
    command void saveChannel(uint8_t id, channelInfo *channel);

    /**
     * Request the channel list from the database server
     * Received channels will be signaled through receivedChannelEntry
     * @param onlyFavorites tells server to send only the channels with a
     *        registered quickDial number, if not zero
     */
    command void getChannelList(uint8_t onlyFavorites);

    /**
     * Request the channel list from the database server
     * Received channels will be signaled through receivedChannelEntry
     */
    command void getChannel(uint8_t id);

    /**
     * Request that the Database purges all channels and their state
     * Received channels will be signaled through receivedChannelEntry
     */
    command void purgeChannelList();

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

    ////////////////////////
    /* Internal functions */
    ////////////////////////

    ////////////////////////
    /* Events */
    ////////////////////////

    event void UdpReceive.received(in_addr_t *srcIp, uint16_t srcPort, uint8_t *data, uint16_t len)
    {

    }

}

