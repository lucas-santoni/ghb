#include "status.h"
#include "args.h"
#include "usage.h"
#include "ghb.h"

extern arguments args;

// Entry point
int main(int argc, char * const argv[]) {
  if (parseCommandLineArguments(argc, argv) != SUCCESS) {
    usage(*argv);
    return ERROR_ARGS;
  }

  return ghb(args.romPath);
}
