# What

(2024-05, 2024-12, 2025-08)

It's the question that drives us, Neo.

Arduino program to transmit all memories content via UART (at 115200 baud).

Transmits contents of SRAM, PROGMEM and EEPROM. That's the entire
history of you.


## Sample output (trimmed)

```
( Memories dump demo
  RAM ( 160 000 [...] )
  PROGMEM ( 012 148 [...] )
  EEPROM ( 255 255 [...] )
) Done

```

## Notes

All integers are represented as fixed-length decimals in ASCII.

Yes I've tried neat hex dumps. It's dead-end. Just a pleasant
look for human specie.


## Details

[Craft](MemoriesDumper.ino)


## Requirements

  * Arduino Uno
  * arduino-cli


## Install/remove

Clone [GetLibs][GetLibs] repo and run it's code.

It allows install/remove all my libraries.


## See also

* [My other embedded C++ stuff][Embedded]
* [My other repositories][Repos]


[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs
[Embedded]: https://github.com/martin-eden/Embedded_Crafts
[Repos]: https://github.com/martin-eden/contents
