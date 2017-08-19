#include <stdio.h>
#include <stdint.h>

// Tell the user what's up
void usage(const char *self) {
  if (!self)
    return;

  printf("GHB is a GameBoy Header Beautifier.\n"
      "It reads a GambeBoy ROM file and prints some informations.\n\n"
      "USAGE: %s [ROM file]\n", self);
}
