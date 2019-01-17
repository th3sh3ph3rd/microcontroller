/**
 *
 * @file    DatabaseC.nc
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2018-12-26
 *
 * Configuration of the Database module.
 *
**/

#include <udp_config.h>

configuration DatabaseC {
    provides 
    {
        interface Init;
        interface Database;
    }
}

implementation {
    components DatabaseP, IpTransceiverC, LlcTransceiverP;
    components Enc28j60C as EthernetC;
    components new UdpC(UDP_PORT);

    Init = DatabaseP.Init;
    Database = DatabaseP.Database;

    LlcTransceiverP.Mac -> EthernetC;

    DatabaseP.UdpSend -> UdpC;
    DatabaseP.UdpReceive -> UdpC;
    DatabaseP.IpControl -> IpTransceiverC;
    DatabaseP.Control -> EthernetC;
}

