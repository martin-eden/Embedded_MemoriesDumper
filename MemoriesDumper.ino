// Print contents of SRAM, Flash and EEPROM.

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

/*
  There are three types of memories in AVR: SRAM, Flash and EEPROM.

  We gonna dump em all.

  SRAM is fast and infinitely rewritable. But not persistent.

  Flash (aka PROGMEM) is fast and persistent. Lifespan about 10k writes.

  EEPROM is slow and persistent. Lifespan about 100k writes.

           | Read time | Write time | Write endurance |  Amount
   --------+-----------+------------+-----------------+----------
    SRAM   |     1     |       1    |       INF       |     2k
    Flash  |     1     |    ? 1k    |       10k       |    32k
    EEPROM |     1     |     10k    |      100k       |     1k
*/

#include <me_WorkMemory.h>
#include <me_ProgramMemory.h>
#include <me_Eeprom.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Console.h>

#include <me_MemsegStreams.h>

/*
  Print RAM contents

  Program state is stored there.

  Output format

    "RAM (" Byte.. ")" NewLine

    Byte values are represented as 3-digit decimals in ASCII.

  Sample output:

    RAM ( 032 010 .. 013 )\n
*/
void PrintRam()
{
  /*
    We can implement it in different ways using [me_WorkMemory]

    1. We can call GetByteFrom().
    2. We can pass function pointer Op_GetByte() as TOperation type.
    3. We can use TInputStream to traverse memory as stream.

    We'll use option (3).
  */

  TAddressSegment AddrSeg = { .Addr = 0, .Size = TUint_2_Max };
  me_WorkMemory::TInputStream RamStream;
  TUnit Unit;

  RamStream.Init(AddrSeg);

  Console.Write("RAM (");

  while (RamStream.Read(&Unit))
    Console.Print(Unit);

  Console.Write(")");
  Console.EndLine();
}

/*
  Print program memory contents

  Program code is stored there.
*/
void PrintFlash()
{
  /*
    At the moment of writing this comment, [me_ProgramMemory] does
    not provide input stream interface. But it provides Op_GetByte()
    as TOperation.

    We'll use option (2). We will use adapter to convert operation and
    address span to input stream.
  */

  TAddressSegment AddrSeg = { .Addr = 0, .Size = TUint_2_Max };
  me_MemsegStreams::TMemsegInputStream ProgmemStream;
  TOperation UnitReader = me_ProgramMemory::Op_GetByte;
  TUnit Unit;

  ProgmemStream.Init(AddrSeg, UnitReader);

  Console.Write("PROGMEM (");

  while (ProgmemStream.Read(&Unit))
    Console.Print(Unit);

  Console.Write(")");
  Console.EndLine();
}

/*
  Print EEPROM memory contents

  Savegames are stored there.
*/
void PrintEeprom()
{
  /*
    At the moment of writing this comment, [me_Eeprom] provides
    only Get Byte operation.

    We'll to use option (1). We still can wrap that Get Byte as
    TOperation and wrap TOperation as Stream if we wish so.
    But we won't.
  */

  TAddress Address = 0;
  TUnit Unit;

  Console.Write("EEPROM (");

  while (me_Eeprom::Get(&Unit, Address))
  {
    Console.Print(Unit);
    ++Address;
  }

  Console.Write(")");
  Console.EndLine();
}

void setup()
{
  Console.Init();

  Console.Print("( Memories dump demo");
  Console.Indent();

  PrintRam();
  PrintFlash();
  PrintEeprom();

  Console.Unindent();
  Console.Print(") Done");
}

void loop()
{
}

/*
  2024 # # #
  2025-08-14
  2025-08-27
*/
