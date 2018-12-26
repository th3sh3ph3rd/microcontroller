MATRNR			= 01614835
PROTO_FOLDER		= Protocol
APP_FOLDER		= RadioScanner

COMPONENT		= RadioScannerAppC
#COMPONENT		= Test/PS2TestAppC
#COMPONENT		= Test/FMClickTestAppC
#COMPONENT		= Test/VolumeAdcTestAppC
TINYOS_ROOT_DIR	       ?= ../tinyos_ws18
CFLAGS 		       += -Wall -Wextra -funsigned-char -funsigned-bitfields -fshort-enums -fpack-struct
CFLAGS		       += -I. -IDatabase -IFMClick -IPS2 -ITest -IVolumeAdc
include $(TINYOS_ROOT_DIR)/Makefile.include
