#!/bin/sh
arm-none-eabi-objdump -D build/kernel.elf > build/kernel.asm
arm-none-eabi-nm build/kernel.elf > build/kernel.nm
