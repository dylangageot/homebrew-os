# Author: Dylan Gageot
# Description:
# 	Makefile for compiling and upload Homebrew OS.

# Define cross compile environment.
CROSS_COMPILE ?= arm-none-eabi-

# Define directories.
BUILD_DIR = build/
SRC_DIR = src/
INCLUDE_DIR = include/
UPLOAD_DIR = /var/lib/tftpboot/
SRC_RPI_DIR = $(SRC_DIR)rpi/

# Define specific file path.
LKR_SCRIPT = ldscripts/link.lds

# Define compiler and linker flags.
CFLAGS = -mfpu=neon-vfpv4 \
	 -mfloat-abi=hard \
	 -march=armv7-a \
	 -mtune=cortex-a7 \
	 -O0 \
	 -I$(INCLUDE_DIR)
LFLAGS = -nostartfiles \
	 -T $(LKR_SCRIPT) \

all: clean $(BUILD_DIR)kernel.img

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.s
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)%.o: $(SRC_RPI_DIR)%.s
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)kernel.img: $(BUILD_DIR)main.o $(BUILD_DIR)start.o \
       	$(BUILD_DIR)cstartup.o $(BUILD_DIR)system_timer.o
	$(CROSS_COMPILE)gcc $(CFLAGS) $^ -o $(BUILD_DIR)kernel.elf $(LFLAGS)
	$(CROSS_COMPILE)objcopy -O binary $(BUILD_DIR)kernel.elf \
		$(BUILD_DIR)kernel.img

upload: $(BUILD_DIR)kernel.img
	rm -f $(UPLOAD_DIR)kernel*
	cp $^ $(UPLOAD_DIR)

clean:
	rm -f build/*
