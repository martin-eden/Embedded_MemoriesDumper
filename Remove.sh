#!/bin/bash

# Remove modules
arduino-cli \
  lib uninstall \
    me_BaseTypes \
    me_UartSpeeds \
    me_InstallStandardStreams \
    me_MemoryPoint \
    me_MemorySegment
