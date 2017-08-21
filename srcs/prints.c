#include <stddef.h>

#include "print.h"

// Array of function pointers
// Each function prints one information about the header
printer prints[] = {
  printEntry,
  printNintendo,
  printTitle,
  printCgb,
  printCompany,
  printSgb,
  printCartridge,
  printRom,
  printRam,
  printDestination,
  printVersion,
  NULL
};
