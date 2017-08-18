#include <stdio.h>
#include <stdint.h>

void usage(const char *self) {
  if (!self)
    return;

  printf("GHB is a GameBoy Header Beautifier.\n"
      "It reads a GambeBoy ROM file and prints some informations.\n\n"
      "USGAGE: %s [ROM file]\n", self);
}
