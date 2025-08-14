// Simple KSP-like craft to print SRAM memory contents

/*
  Author: Martin Eden
  Last mod.: 2025-08-14
*/

/*
  There are three types of memories in AVR: SRAM, Flash and EEPROM.

  SRAM is fast and infinitely rewritable. But not persistent.

  Flash (aka PROGMEM) is fast and persistent. Lifespan about 10k writes.

  EEPROM is slow and persistent. Lifespan about 100k writes.

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

  Quantum world lol.
*/

#include <me_BaseTypes.h>
#include <me_Uart.h>
#include <me_Console.h>
#include <me_WorkMemory.h>

/*
  Print memory contents

  Memory range is hardcoded.

  Output format

    "(" Byte.. ")"

    Byte values are represented as 3-digit decimals in ASCII.

  Sample output:

    ( 032 010 013 )\n
*/
void PrintMemory()
{
  // Memory starts to repeat itself after offset 2304 ( = 2048 + 256)

  TAddress StartAddr = 0;
  TAddress EndAddr = 2048 + 256;
  TUint_1 ByteValue;

  Console.Write("(");

  for (TAddress Addr = StartAddr; Addr <= EndAddr; ++Addr)
  {
    me_WorkMemory::GetByte(&ByteValue, Addr);
    Console.Print(ByteValue);
  }

  Console.Write(")");

  Console.EndLine();
}

void setup()
{
  me_Uart::Init(me_Uart::Speed_115k_Bps);

  PrintMemory();
}

void loop()
{
}

/*
  2024-05-24
  2024-10-03
  2024-12-09
  2025-08-14
*/
