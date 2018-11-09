== SD Card Library ==

This driver accesses SDCards in SPI mode.

Notes for application 1 (changes):
- sdcardAvailable() got depreacated, sdcardInit() will now return E_NOCARD if
it could not reset any card - as a heurisic to detect if a card is inserted.
This has the advanage that it works with both, revision 1.10 and revision
1.21 boards

- The spi driver interface was extended to control the spi prescaler.

- The error_t definition was extended with E_UNKNOWN_CARD.

- The meaning of blockAddress changed. Now it determines the address of the block to read as byte address.
Make sure that this value is aligned to your block size, as otherwise read will abort with errors.

Infos:
- The driver was tested with the sd-cards in the lab and some other. It works with the cards
in the lab as it is. If you use another card make sure, that it supports a block size of 32 bytes,
or change the block size (bigger cards may only work with 512 or above).


== How to use it ==

Include sdcard.h wherever you want to use the SD Card functions. Link your own object files together with the library (add -lsdcard to the linker command). E.g. call the linker in the following way:

avr-gcc main.o -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -lsdcard -L. -o application.elf

Make sure that the header and library files are in the compilers and linkers search path. E.g. in the same directory as your other source files (-L. adds the current directory to the linkers library search path).
