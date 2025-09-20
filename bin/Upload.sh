#!/bin/bash

# Just upload compiled binary

# Author: Martin Eden
# Last mod.: 2025-09-20

# "Works on my machine.."

avrdude \
  -U flash:w:MemoriesDumper.ino.hex:i \
  -P /dev/ttyUSB0 \
  -b 115200 \
  -C ATmega328.avrdude.conf \
  -p atmega328p \
  -c arduino \
  -D \
  -qq

echo "Code loaded to board."

# 2024-10-13
# 2025-09-19
