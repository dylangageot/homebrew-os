# Author: Dylan Gageot
# Description:
# 	Makefile for compiling and upload Homebrew OS.

# Define cross compile environment.
CROSS_COMPILE ?= arm-none-eabi-

# Define directories.
BUILD_DIR = $(PWD)/build/
SRC_DIR = $(PWD)/src/
INCLUDE_DIR = $(PWD)/include/
UPLOAD_DIR = /var/lib/tftpboot/

# Define specific file path.
LKR_SCRIPT = ldscripts/link.lds

# Define compiler and linker flags.
CFLAGS = \
	 -mfpu=neon-vfpv4 \
	 -mfloat-abi=hard \
	 -march=armv7-a \
	 -mtune=cortex-a7 \
	 -O0 \
	 -I$(INCLUDE_DIR)
LDFLAGS = \
	 -nostartfiles \
	 -T $(LKR_SCRIPT) \

MODULES = boot rpi

all: $(BUILD_DIR)kernel.img

$(MODULES):		
	$(info -- Building $@)
	$(MAKE) -C $(SRC_DIR)$@ CROSS_COMPILE=$(CROSS_COMPILE) \
		CFLAGS="$(CFLAGS)" BUILD_DIR=$(BUILD_DIR)

$(BUILD_DIR)kernel.img: $(MODULES)
	$(info -- Building kernel.img)
	$(CROSS_COMPILE)gcc $(CFLAGS) $(wildcard $(BUILD_DIR)*.o) -o \
		$(BUILD_DIR)kernel.elf $(LFLAGS) 
	$(CROSS_COMPILE)objcopy -O binary $(BUILD_DIR)kernel.elf \
		$(BUILD_DIR)kernel.img

upload: $(BUILD_DIR)kernel.img
	$(info -- Clean)
	rm -f $(UPLOAD_DIR)kernel*
	cp $^ $(UPLOAD_DIR)

clean:
	rm -f build/*
