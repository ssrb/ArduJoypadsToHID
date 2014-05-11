#
#             LUFA Library
#     Copyright (C) Dean Camera, 2013.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
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
SRC          = $(TARGET).c NESpad.c Descriptors.c /home/sb/Hacking/arduino-1.5.5/hardware/arduino/avr/cores/arduino/wiring_digital.c $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS) $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS)
LUFA_PATH    = /home/sb/Hacking/LUFA/LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/ -I/home/sb/Hacking/arduino-1.5.5/hardware/arduino/avr/cores/arduino\
	-I/home/sb/Hacking/arduino-1.5.5/hardware/arduino/avr/variants/leonardo
LD_FLAGS     =

FLASH_SIZE_KB=32
BOOT_SECTION_SIZE_KB=4

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
