#!/bin/bash

# Remove modules
arduino-cli \
  lib uninstall \
    me_MemorySegment \
    me_Console \
    me_Uart \
    me_UartSpeeds \
    me_BaseTypes
