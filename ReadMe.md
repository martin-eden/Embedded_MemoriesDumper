# What

(2024-05, 2024-12)

It's the question that drives us, Neo.

Arduino program to transmit all memory contents via UART (115200 baud).


## Sample output (trimmed)

```
00000 ( 000 000 255 255 179 235 [...] )
```

## Wtf?!

How to describe memory segment?

What is memory segment?

It is segment of memory units. Segment can be described as starting point
and length. Memory units are bytes.

All integers are represented as fixed-length decimals in ASCII.

Data is wrapped in list. So we don't need to transfer length of segment.

(And yes, I've tried neat hex dumps. It's dead-end. Just a pleasant
look for human specie. Program that processes that hex dump output
will need to parse it back to machine bytes. So we're just making this
parsing simpler.)


## Details

[Craft](MemoryDumper.ino)


## Requirements

  * Arduino Uno
  * arduino-cli


## Install

Run [Install.sh](Install.sh).


## Remove

Run [Remove.sh](Remove.sh).


## See also

[My other repositories](https://github.com/martin-eden/contents).
