<b>Raspberry PI Bare Metal software test</b>

SD card should be formatted with a single partition as FAT32.
Copy the /boot files to the SD card or use movetosd script.

boot/ contains the necessary files to boot the Pi:
- bootcode.bin
- start.elf
- kernel.img/kernel7.img - which is actually the compiled program.

Problems with the Raspberry Pi 3 when trying to use old codes (Pi,Pi2,...):
- Leds were moved to an i2c GPIO expander
- GPIO uses the same base addr as Pi2
- The original hardware UART from the Broadcom processor has been reassigned to the Bluetooth chipset and the UART output on the GPIO pins now uses a mini-UART port.
The mini-UART doesnt have a separate clock divisor and uses the core clock frequency.
Mini-UART is mapped to GPIO14/15 as the PL011 UART is now used for bluetooth communications.

<b>Goals:</b>
- LED GPIO example (done)
- Port LIBC (done(?), malloc already working)
- UART via USB for debug

<b>Build PC:</b>
- ARCH w/ Kernel 4.5.2
- arm-none-eabi-gcc @ gcc v5.3.0
