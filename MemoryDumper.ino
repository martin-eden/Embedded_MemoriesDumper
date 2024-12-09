// Simple KSP-like craft to print SRAM memory contents

/*
  Author: Martin Eden
  Last mod.: 2024-12-09
*/

/*
  There are three types of memories in AVR: SRAM, Flash and EEPROM.

  SRAM is fast and infinitely rewritable. But non-persistent.

  Flash (aka PROGMEM) is fast and persistent. But has a lifespan
  about 10k writes.

  EEPROM is persistent and has a lifespan about 100k writes.
  But slow to write.

           | Read time | Write time | Write endurance |  Amount
   --------+-----------+------------+-----------------+----------
    SRAM   |     1     |       1    |       INF       |     2k
    Flash  |     1     |    ? 1k    |       10k       |    32k
    EEPROM |     1     |     10k    |      100k       |     1k
*/

/*
  Microcontroller has special stuff like timers, protocol codecs,
  sleep modes, encryption, memory access etc.

  It can be thought as functions hardcoded in transistors. They are
  running parallel with main code. Their state lives in lower SRAM
  addresses (from 0 to 255).

  Reading at some positions from that addresses can trigger hardware
  magic. For example parsed UART byte lives at offset 192. Reading
  that location will make appear there next parsed UART byte.

  So reading is not transparent. Quantum world lol.
*/

#include <me_BaseTypes.h>

#include <me_MemorySegment.h>

#include <me_Uart.h>
#include <me_UartSpeeds.h>
#include <me_Console.h>

void setup()
{
  me_Uart::Init(me_UartSpeeds::Bps_115k);

  PrintMemory();
}

void loop()
{
}

/*
  Print memory segment offset and contents

  Format

    Start "(" Bytes.. ")"

  Description

    We're sending two elements: data offset and data.

    Integers are represented as decimals in ASCII.

  Sample output:

    01337 ( 032 010 013 )\n
*/
void PrintSegment(
  me_MemorySegment::TMemorySegment Memseg
)
{
  Console.Print(Memseg.Addr);

  Console.Write("(");

  for (TUint_2 Offset = 0; Offset < Memseg.Size; ++Offset)
  {
    Console.Print(Memseg.Bytes[Offset]);
  }

  Console.Write(")");

  Console.EndLine();
}

/*
  Print memory contents

  Memory range is hardcoded.
*/
void PrintMemory()
{
  // Memory starts to repeat itself after offset (2048 + 256)

  me_MemorySegment::TMemorySegment Range;

  Range.Addr = 0;
  Range.Size = 2048 + 256;

  PrintSegment(Range);
}

/*
  2024-05-24
  2024-10-03
  2024-12-09
*/
