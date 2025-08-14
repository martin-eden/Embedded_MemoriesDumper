# What

(2024-05, 2024-12, 2025-08)

It's the question that drives us, Neo.

Arduino program to transmit all memory contents via UART (115200 baud).


## Sample output (trimmed)

```
( 000 000 255 255 179 235 [...] )
```

## Notes

All integers are represented as fixed-length decimals in ASCII.

Yes I've tried neat hex dumps. It's dead-end. Just a pleasant
look for human specie.


## Details

[Craft](MemoryDumper.ino)


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
