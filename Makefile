#
# Makefile with optimal flags for the Rasp Pi 3
#
CC  = arm-none-eabi-gcc
LD  = arm-none-eabi-ld
KC  = arm-none-eabi-objcopy

LDFLAGS =
CFLAGS  = -nostartfiles -Wall -O2 -mcpu=cortex-a53 -mfpu=neon-fp-armv8

#The intermediate directory for compiled object files.
BUILD = build/

SOURCE = source/

#The name of the output file to generate.
TARGET = $(BUILD)kernel.elf

KERNEL = $(BUILD)kernel.img

$(KERNEL): $(TARGET)
	$(KC) $(TARGET) -O binary $(KERNEL)

$(TARGET): $(SOURCE)main.o
	$(LD) $(LDFLAGS) -o $@ $<

$(BUILD)main.o: $(SOURCE)main.c
	$(CC) $(CFLAGS) -c $< $@

clean:
	rm -rf $(TARGET)
	rm -rf $(BUILD)*.o
	rm -rf $(SOURCE)*.o
	rm -rf $(BUILD)*.img
