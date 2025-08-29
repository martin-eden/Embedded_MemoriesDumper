// Print contents of SRAM, Flash and EEPROM.

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
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

/*
  Memories can be read as streams

  We like stream interface. If we can't use it, we'll use direct functions.
*/

#include <me_ProgramMemory.h>
#include <me_Eeprom.h>

#include <me_StreamTools.h>
#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Console.h>

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
  TAddressSegment AddrSeg = { .Addr = 0, .Size = TUint_2_Max };
  me_StreamsCollection::TWorkmemInputStream RamStream;
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
  TAddress Address = 0;
  TUnit Unit;

  Console.Write("PROGMEM (");

  while (me_ProgramMemory::GetByteFrom(&Unit, Address))
  {
    Console.Print(Unit);
    ++Address;
  }

  Console.Write(")");
  Console.EndLine();
}

/*
  Print EEPROM memory contents

  Savegames are stored there.
*/
void PrintEeprom()
{
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
