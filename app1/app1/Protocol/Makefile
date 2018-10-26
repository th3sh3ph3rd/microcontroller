#
# Microcontroller VU
#
# Makefile for generating the lab protocol
#
# Author: Bettina Weiss
# Author: Martin Perner
#
# Date:         23.03.2015
#
# TU Vienna, Embedded Computing Systems Group
#
# Targets:
#	(default)	generates .pdf file of the protocol
#	protocol	generates .pdf file of the protocol
#   listing     generates .pdf file with the code listing
#   complete    generates a .pdf file of the protocol and the code listing
#	print		prints the title page (you need to sign it!)
#
#	help		lists all possible targets
#	clean		removes intermediate files


PROJECT = Protocol.pdf
LISTING = Listing.pdf
COMPLETE = Complete.pdf

# we let latexmk make the dependency managment
.PHONY: $(PROJECT) $(LISTING) print help clean

#------------------------------------------------------------------------------
protocol: $(PROJECT)
#------------------------------------------------------------------------------
	latexmk -pdf -pdflatex="pdflatex -interactive=nonstopmode" -use-make ${<:.pdf=.tex}

#------------------------------------------------------------------------------
listing: $(LISTING)
#------------------------------------------------------------------------------
	latexmk -pdf -pdflatex="pdflatex -interactive=nonstopmode" -use-make ${<:.pdf=.tex}

#------------------------------------------------------------------------------
complete: $(PROJECT) $(LISTING)
#------------------------------------------------------------------------------
	pdfunite $? ${COMPLETE}


#------------------------------------------------------------------------------
print: protocol
#------------------------------------------------------------------------------
	lpr -o page-ranges=1 $(PROJECT)

#------------------------------------------------------------------------------
help:
#------------------------------------------------------------------------------
	@echo -e "\n>>> the following targets are available <<<"
	@echo -e "\t(default) \t generates a .pdf file of the protocol"
	@echo -e "\tprotocol \t generates a .pdf file of the protocol"
	@echo -e "\tlisting \t generates a .pdf file with the code listings"
	@echo -e "\tcomplete \t generates a .pdf file of the protocol and the code listings"
	@echo -e "\tprint \t\t print the title page (you need to sign it!)"
	@echo -e "\n\thelp \t\t list this text"
	@echo -e "\tclean \t\t remove temporary files"

#------------------------------------------------------------------------------
clean:
#------------------------------------------------------------------------------
	latexmk -CA

#------------------------------------------------------------------------------
cleansmall:
#------------------------------------------------------------------------------
	latexmk -c

