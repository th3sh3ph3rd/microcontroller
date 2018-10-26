== Wiimote Library ==

How to use it:

Include wii_user.h wherever you want to use the wiimote functions. You have to implement the functions in hal_wt41_fc.h by yourself. Link your object files together with the library (add -lwiimote to the linker command). E.g. call the linker in the following way:

avr-gcc main.o -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -lwiimote -L. -o application.elf

Make sure that the header and library files are in the compilers and linkers search path. E.g. in the same directory as your other source files (-L. adds the current directory to the linkers library search path).
