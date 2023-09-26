PROJECT = usb-keyboard
BUILD_DIR = bin

CFILES = main.c usb_init.c
# CFLAGS += -DHAS_WCID -DWCID_VENDOR_CODE=0x44U
# -DHAS_WCID_20 -DWCID_VENDOR_CODE=0x44U

# TODO - you will need to edit these two lines!
DEVICE = stm32f411ceu6
OOCD_FILE = board/stm32f411ce_blackpill_ftdi.cfg

# You shouldn't have to edit anything below here.
OPENCM3_DIR = ../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
