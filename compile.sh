#!/bin/sh
set -x #echo on

arm-none-eabi-gcc -O0 -nostartfiles -Wall -mcpu=cortex-a53 -mfpu=neon-fp-armv8 -g -Wl,-T,rpi.x source/main.c source/cstubs.c source/cstartup.c source/start.S -o build/kernel.elf
arm-none-eabi-objcopy build/kernel.elf -O binary build/kernel.img
