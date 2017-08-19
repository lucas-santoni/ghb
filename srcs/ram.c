#include <stddef.h>

#include "dict.h"
#include "colors.h"

static const dict ramSizes[] = {
  {0x00, RED "None" RESET},
  {0x01, "2 KBytes"},
  {0x02, "8 Kbytes"},
  {0x03, "32 KBytes (4 banks of 8KBytes each)"},
  {0x04, "128 KBytes (16 banks of 8KBytes each)"},
  {0x05, "64 KBytes (8 banks of 8KBytes each)"}
};

char *getRamSize(uint32_t opcode) {
  for (uint32_t i = 0; i < sizeof(ramSizes); ++i) {
    if (opcode == ramSizes[i].key) {
      return ramSizes[i].value;
    }
  }

  return NULL;
}
