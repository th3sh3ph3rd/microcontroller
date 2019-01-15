/**
 *
 * @file    DatabaseC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-26
 *
 * Configuration of the Database module.
 *
**/

//TODO don't forget that the typedef in this header has been tweaked
#include <udp_config.h>

configuration DatabaseC {
    provides 
    {
        interface Init;
        interface Database;
    }
}

implementation {
    //TODO tweak accordingly
    #define SEND_Q_LEN  20
    #define RECV_Q_LEN  5
    #define POOL_SIZE (SEND_Q_LEN+RECV_Q_LEN)

    components DatabaseP, IpTransceiverC, LlcTransceiverP, GlcdC;
    components Enc28j60C as EthernetC;
    components new UdpC(UDP_PORT);

    Init = DatabaseP.Init;
    Database = DatabaseP.Database;

    LlcTransceiverP.Mac -> EthernetC;

    DatabaseP.UdpSend -> UdpC;
    DatabaseP.UdpReceive -> UdpC;
    DatabaseP.IpControl -> IpTransceiverC;
    DatabaseP.Control -> EthernetC;

    DatabaseP.Glcd -> GlcdC;
}

