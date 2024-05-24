// Simple KSP-like craft to transfer all memory contents via Serial

/*
  Memory in AVR is registers (first 32 bytes) then state of board
  (until byte 256) then user memory (2048 bytes).

  Also there is 32 KiB program memory and 1024 bytes of persistent
  memory. Those are not covered by this craft.
*/

/*
  Author: Martin Eden
  Last mod.: 2024-05-24
*/

#include <me_BaseTypes.h>
#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>

#include <me_MemorySegment.h>

using namespace me_BaseTypes;

// Forwards:
void SendMemoryScan();

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);
  InstallStandardStreams();
  printf("[Memory explorer]: Okay, we are here.\n");
  SendMemoryScan();
}

void loop()
{
}

// Forwards:
void SendSegment(me_MemorySegment::TMemorySegment Segment);

/*
  Send memory state via Serial.

  Memory range is hardcoded.
*/
void SendMemoryScan()
{
  /*
    Set memory range to transmit.

    Memory starts to repeat itself after offset (2048 + 256).
  */
  me_MemorySegment::TMemorySegment Range =
    {
      .Start = { .Addr = 0 },
      .Size = 2048 + 256,
    };

  SendSegment(Range);
}

/*
  Send memory segment via Serial.

  Format sample: "[0x12EF .. +3]: 20 0A 0C \n"
*/
void SendSegment(me_MemorySegment::TMemorySegment Segment)
{
  printf("[0x%04X .. +%d]: ", Segment.Start.Addr, Segment.Size);

  for (TUint_2 Offset = 0; Offset < Segment.Size; ++Offset)
  {
    printf("%02X ", Segment.Start.Bytes[Offset]);
  }
  printf("\n");
}

/*
  2024-05-24
*/
