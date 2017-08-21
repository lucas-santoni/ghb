#include <stdint.h>
#include <stdbool.h>

#include "header.h"

bool checkEntry(const uint8_t *entry) {
  if (*(uint32_t *)(void *)entry == ENTRY_USUAL)
    return true;
  return false;
}
