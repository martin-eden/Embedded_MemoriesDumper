#!/bin/bash

# Install modules
arduino-cli \
  lib install \
    --git-url \
      https://github.com/martin-eden/Embedded-me_BaseTypes \
      https://github.com/martin-eden/Embedded-me_Uart \
      https://github.com/martin-eden/Embedded-me_UartSpeeds \
      https://github.com/martin-eden/Embedded-me_Console \
      https://github.com/martin-eden/Embedded-me_MemorySegment
