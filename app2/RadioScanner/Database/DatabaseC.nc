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
    components DatabaseP;
    components new UdpC(UDP_PORT);

    Init = DatabaseP.Init;
    Database = DatabaseP.Database;

    Database.UdpSend -> UdpC;
    Database.UdpReceive -> UdpC;
}

