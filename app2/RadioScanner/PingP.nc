/**
 * @author:	Andreas Hagmann <ahagmann@ecs.tuwien.ac.at>
 * @date:	12.12.2011
 *
 * based on an implementation of Harald Glanzer, 0727156 TU Wien
 */

module PingP {
	uses interface IcmpReceive;
	uses interface IcmpSend;
}

implementation {
	
	event void IcmpReceive.received(in_addr_t *srcIp, uint8_t code, uint8_t *data, uint16_t len) {

	      /* received an ICMP echo request */
	      /* send an ICMP echo reply */

	      /* remember programming hint no. 5 ! */

	}
	
	event void IcmpSend.sendDone(error_t error) {
	
	}
}