/**
 * @author:	Andreas Hagmann <ahagmann@ecs.tuwien.ac.at>
 * @date:	12.12.2011
 *
 * based on an implementation of Harald Glanzer, 0727156 TU Wien
 */

#include <string.h>

#define ICMP_DATA_LENGTH           100

module PingP {
	uses interface IcmpReceive;
	uses interface IcmpSend;
}

implementation {
	
        /* Received echo request - just send the packet back */
	event void IcmpReceive.received(in_addr_t *srcIp, uint8_t code, uint8_t *data, uint16_t len) {
            in_addr_t destIp;
            uint8_t dataBuf[ICMP_DATA_LENGTH];

            memcpy(&destIp, srcIp, sizeof(in_addr_t));
            memset(&dataBuf, 0, ICMP_DATA_LENGTH);
            memcpy(&dataBuf, data, ICMP_DATA_LENGTH);

            call IcmpSend.send(&destIp, ICMP_TYPE_ECHO_REPLY, code, dataBuf, len);
	}
	
	event void IcmpSend.sendDone(error_t error) {
	
	}
}
