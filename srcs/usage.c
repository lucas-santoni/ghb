#include <stdio.h>
#include <stdint.h>

// Tell the user what's up
void usage(const char *self) {
  if (!self)
    return;

  printf("GHB is a GameBoy Header Beautifier.\n"
      "It reads a GambeBoy ROM file and prints some informations.\n\n"
      "USAGE:\n"
      "\t%s [-hf] [ROM file]\n\n"
      "OPTIONS:\n"
      "\t-h\t\tPrint this usage and exit.\n"
      "\t-f\t\tForce file analysis even though it does not seem valid.",
      self);
}
