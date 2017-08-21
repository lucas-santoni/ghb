#include <stddef.h>

#include "dict.h"

static const dict romSizes[] = {
  {0x00, "32KByte (no ROM banking)"},
  {0x01, "64KByte (4 banks)"},
  {0x02, "128KByte (8 banks)"},
  {0x03, "256KByte (16 banks)"},
  {0x04, "512KByte (32 banks)"},
  {0x05, "1MByte (64 banks, only 63 banks used by MBC1)"},
  {0x06, "2MByte (128 banks, only 125 banks used by MBC1)"},
  {0x07, "4MByte (256 banks)"},
  {0x08, "8MByte (512 banks)"},
  {0x52, "1.1MByte (72 banks)"},
  {0x53, "1.2MByte (80 banks)"},
  {0x54, "1.5MByte (96 banks)"}
};

char *getRomSize(uint32_t opcode) {
  for (uint32_t i = 0; i < sizeof(romSizes); ++i) {
    if (opcode == romSizes[i].key) {
      return romSizes[i].value;
    }
  }

  return NULL;
}
