# What

(2024-05)

Arduino program to transmit all memory contents via UART (57600 baud).
Plus companion Lua script to convert ASCII hex bytes to binary.

Simple KSP-like craft. But useful. It's the question that drives us, Neo.


## Requirements

  * Arduino Uno
  * arduino-cli
  * bash
  * Lua 5.4


## Install

Run [Install.sh](Install.sh).


## Remove

Run [Remove.sh](Remove.sh).


## Sample output (trimmed)

```
[Memory explorer]: Okay, we are here.
[0x0000 .. +2304]: 09 00 FF FC FF FF FF DF 01 11 05 03 00 00 C0 00 50 01 00 00 30 08
```


## Details

[Craft](MemoryExplorer.ino)

[Companion converter](HexToBin.lua)


## See also

[My other repositories](https://github.com/martin-eden/contents).
