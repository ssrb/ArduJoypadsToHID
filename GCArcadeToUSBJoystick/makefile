# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

# Run "make help" for target help.

MCU          = atmega32u4
ARCH         = AVR8
BOARD        = LEONARDO
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = Joystick
ARDUINO_AVR_LIBS = /home/sb/Hacking/arduino-1.5.5/hardware/arduino/avr
SRC          = $(TARGET).c Gamecube.c Descriptors.c $(ARDUINO_AVR_LIBS)/cores/arduino/wiring_digital.c $(ARDUINO_AVR_LIBS)/cores/arduino/wiring_shift.c $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS)
LUFA_PATH    = /home/sb/Hacking/LUFA/LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/ -I$(ARDUINO_AVR_LIBS)/cores/arduino\
	-I$(ARDUINO_AVR_LIBS)/variants/micro
LD_FLAGS     =

FLASH_SIZE_KB=32
BOOT_SECTION_SIZE_KB=4

AVRDUDE_PROGRAMMER	=	usbtiny

# Default target
all:

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk
