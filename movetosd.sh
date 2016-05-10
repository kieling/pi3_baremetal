#!/bin/sh
mkdir /run/media/sdcard
mount /dev/mmcblk0p1 /run/media/sdcard

cp -rf build/kernel.img   ~/../../run/media/sdcard/
cp -rf boot/start.elf     ~/../../run/media/sdcard/
cp -rf boot/bootcode.bin  ~/../../run/media/sdcard/
cp -rf build/kernel.img  ~/../../run/media/sdcard/kernel7.img

if [ -f /run/media/sdcard/kernel.img ] && [ -f /run/media/sdcard/start.elf ] && [ -f /run/media/sdcard/bootcode.bin ] ; then
    echo "Files copied."
else
    echo "Error, files not found."
fi
