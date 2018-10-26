== Mp3 Library ==

How to use it:

Include mp3.h wherever you want to use the mp3 player functions. Link your own object files together with the library (add -lmp3 to the linker command). E.g. call the linker in the following way:

avr-gcc main.o -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -lmp3 -L. -o application.elf

Make sure that the header and library files are in the compilers and linkers search path. E.g. in the same directory as your other source files (-L. adds the current directory to the linkers library search path).
