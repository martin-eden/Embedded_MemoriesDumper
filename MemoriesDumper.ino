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
  (Some) memories can be read as streams

  We like stream interface. But there is some code and memory overhead
  from them.

  If it's problem for you, use direct calls. See [me_StreamCollections]
  for direct calls.

  But concrete function names will change over time. When they do,
  you have to adjust your code (and we have to adjust that streams
  collection).
*/

#include <me_ProgramMemory.h>
#include <me_Eeprom.h>

#include <me_StreamTools.h>
#include <me_StreamsCollection.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Console.h>

void PrintStream(
  const TAsciiz Name,
  IInputStream * DataStream
)
{
  TUnit Unit;

  Console.Write(Name);
  Console.Write(" (");

  while (DataStream->Read(&Unit))
    Console.Print(Unit);

  Console.Write(")");
  Console.EndLine();
}

/*
  Print RAM contents

  Program state is stored there.
*/
void PrintRam()
{
  TAddressSegment AddrSeg = { .Addr = 0, .Size = TUint_2_Max };
  me_StreamsCollection::TWorkmemInputStream RamStream;

  if (!RamStream.Init(AddrSeg))
    return;

  PrintStream("RAM", &RamStream);
}

/*
  Print program memory contents

  Program code is stored there.
*/
void PrintFlash()
{
  TAddressSegment AddrSeg = { .Addr = 0, .Size = TUint_2_Max };
  me_StreamsCollection::TProgmemInputStream FlashStream;

  if (!FlashStream.Init(AddrSeg))
    return;

  PrintStream("PROGMEM", &FlashStream);
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
