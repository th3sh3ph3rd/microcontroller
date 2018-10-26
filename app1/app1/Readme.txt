#
# Microcontroller VU
#
# Readme for the application template
#
# Author: Martin Perner
#
# Date:         18.05.2015
#
# TU Wien, Embedded Computing Systems Group
#


The purpose of this template is to provide you with a simple structure for
your application development.
We also provide you with a Makefile which should allow you to easily generate
archives for digital submission via myTI.
Please note that it is your responsibility to check that the archives contain
all files you need to submit!


== First Steps ==

Edit your matriculation number in the Makefile.

Edit your name, email and matriculation number in Protocol/Protocol.tex


== Code Submission ==

For the code submission, edit Protocol/listings.tex to include the required
files:
  + *every* file coded by you, even header files
  + every file provided by us, which you have modified
Be sure that you do not include any files in the code listing that are
automatically generated!
Run 'make clean' in the Application subdirectory, and then 'make listing' in
the Protocol subdirectory and check that Listing.pdf includes all files you
specified.

To generate the archive, run 'make code' in the main directory of the
template.
Be sure to check that the generated file (code_YOURMATRNR.tar.gz) includes all
files required, then upload it in myTI.


== Delivery Talk ==

Before you have the delivery talk with a tutor, please run 'make print' in the
Protocol subdirectory.
This will print the first page of the protocol.
Please sign it, and give it to the tutor during your delivery talk.


== Protocol Submission ==

For the protocol submission, run 'make protocol' in the Protocol subdirectory
to generate the protocol.
To generate the archive, run 'make protocol' in the main directory of the
template.
Be sure to check that the generated file (protocol_YOURMATRNR.tar.gz) includes
all files required, then upload it in myTI.
