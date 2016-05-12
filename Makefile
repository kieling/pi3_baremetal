#
# Makefile with optimal flags for the Rasp Pi 3
#
CC  = arm-none-eabi-gcc
LD  = arm-none-eabi-ld
KC  = arm-none-eabi-objcopy


# -verbose

LDFLAGS = -T rpi.x
CFLAGS  = -nostartfiles -Wall -mcpu=cortex-a53 -mfpu=neon-fp-armv8

#-march=armv8-a -mtune=cortex-a53 -mfloat-abi=hard

# Directories
BUILD = build/
SOURCE = source/

# Outputs
TARGET = $(BUILD)kernel.elf
KERNEL = $(BUILD)kernel.img

all: $(TARGET)
	$(KC) $(TARGET) -O binary $(KERNEL)

$(TARGET): $(SOURCE)main.o $(SOURCE)cstartup.o $(SOURCE)cstubs.o $(SOURCE)start.o
	$(LD) $(LDFLAGS) -o $@ $(SOURCE)main.o $(SOURCE)cstartup.o $(SOURCE)cstubs.o $(SOURCE)start.o

$(BUILD)main.o: $(SOURCE)main.c
	$(CC) $(CFLAGS) -c $<

$(BUILD)cstartup.o: $(SOURCE)cstartup.c
	$(CC) $(CFLAGS) -c $<

$(BUILD)cstubs.o: $(SOURCE)cstubs.c
	$(CC) $(CFLAGS) -c $<

$(BUILD)start.o: $(SOURCE)start.S
	$(CC) $(CFLAGS) -c $<


clean:
	rm -rf $(TARGET)
	rm -rf $(SOURCE)*.o
	rm -rf $(BUILD)*.*
