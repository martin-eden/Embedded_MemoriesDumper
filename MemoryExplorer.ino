// Simple KSP-like craft to transfer all memory contents via Serial

/*
  Memory in Arduino Uno (AVR arch) is generic registers (first 32 bytes),
  state registers (until byte 256) then user memory (2048 bytes).

  Also there is 32 KiB program memory and 1024 bytes of persistent
  memory. Those are not covered by this craft.
*/

/*
  Author: Martin Eden
  Last mod.: 2024-10-03
*/

#include <me_BaseTypes.h>
#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>

#include <me_MemorySegment.h>

// Forwards:
void SendMemoryScan();

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);
  InstallStandardStreams();
  printf("[Memory explorer]: Okay, we are here.\n");
  PrintMemory();
}

void loop()
{
}

// Forwards:
void SendSegment(me_MemorySegment::TMemorySegment Segment);

/*
  Print memory

  Memory range is hardcoded.
*/
void PrintMemory()
{
  /*
    Set memory range to transmit.

    Memory starts to repeat itself after offset (2048 + 256).
  */
  me_MemorySegment::TMemorySegment Range;

  Range.Start.Addr = 0;
  Range.Size = 2048 + 256;

  SendSegment(Range);
}

/*
  Print memory segment offset and contents

  Format sample: "[0x12EF .. +3]: 20 0A 0C \n"
*/
void SendSegment(me_MemorySegment::TMemorySegment Segment)
{
  printf("[0x%04X .. +%d]: ", Segment.Start.Addr, Segment.Size);

  for (TUint_2 Offset = 0; Offset < Segment.Size; ++Offset)
  {
    printf("%02X ", Segment.Bytes[Offset]);
  }
  printf("\n");
}

/*
  2024-05-24
  2024-10-03
*/
