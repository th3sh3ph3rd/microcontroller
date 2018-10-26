#
# Microcontroller VU
#
# General Makefile of the application template
#
# Author: Martin Perner
#
# Date:         23.03.2015
#
# TU Vienna, Embedded Computing Systems Group
#
#
# Targets:
#	(default)	help -- lists all possible targets
#	help		lists all possible targets
#	protocol	generates an archive for the protocol submission
#   code        generates an archive for the code submission

MATRNR = 3333333
PROTO_FOLDER = Protocol
APP_FOLDER = Application

.PHONY: help protocol code clean

help:
	@echo -e "\n>>> the following targets are available <<<"
	@echo -e "\t(default) \t\t list this text"
	@echo -e "\thelp \t\t list this text"
	@echo -e "\tprotocol \t generates an archive for the protocol submission"
	@echo -e "\tcode \t generates an archive for the code submission"
	@echo -e "\tclean \t\t remove temporary files"

protocol:
	make -C $(PROTO_FOLDER) protocol
	make -C $(PROTO_FOLDER) cleansmall
	tar --transform 's,^,$(MATRNR)/,S' -czf protocol_$(MATRNR).tar.gz $(PROTO_FOLDER)/

code:
	make -C $(APP_FOLDER) clean || exit 0
	make -C $(PROTO_FOLDER) listing
	tar --transform 's,^,$(MATRNR)/,S' -czf code_$(MATRNR).tar.gz $(PROTO_FOLDER)/Listing.pdf $(PROTO_FOLDER)/listings.tex $(APP_FOLDER)/

clean:
	rm -f protocol_$(MATRNR).tar.gz code_$(MATRNR).tar.gz
