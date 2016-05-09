
Raspberry PI Bare Metal software test

boot/ contains the necessary files to boot the Pi:
- bootcode.bin
- start.elf
- kernel.img - which is actually the compiled program. 

SD card should be formatted with a single partition as FAT32. 
Copy the /boot files to the SD card, and try it on the Pi.
Automated script will be added later. 

