#include <stdint.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#include "args.h"
#include "status.h"
#include "header.h"
#include "entry.h"
#include "nintendoLogo.h"
#include "print.h"
#include "file.h"

extern printer prints[];
extern arguments args;

// Loop through the array of function pointers
// Print all parts of the header
static void printHeader(const header *h) {
  if (!h)
    return;

  if (!checkEntry(h->entry) && !checkNintendoLogo(h->nintendo)
      && !args.force) {
    printf("This file does not seem to be a valid ROM.\n"
        "Use -f if you still want to parse it.\n");
    exit(SEEMS_INVALID);
  }

  for (uint32_t i = 0; prints[i] != NULL; ++i)
    prints[i](h);
}

// Check if filed can be read
// If so, read the header into the structure
// Call the printers
// Close file
int32_t ghb(const char *file) {
  if (!file) {
    fprintf(stderr, "No file provided.\n");
    return ERROR_NO_FILE;
  }

  if (!isRegularFile(file)) {
    fprintf(stderr, "Invalid file.\n");
    return ERROR_FILE;
  }

  FILE *rom = fopen(file, "r");
  if (!rom) {
    fprintf(stderr, "Could not open file.\n");
    return ERROR_OPEN;
  }

  header h;
  bzero(&h, sizeof(header));

  int32_t ret = fread(&h, sizeof(int8_t), sizeof(header), rom);
  if (ret < (int32_t)sizeof(header)) {
    fprintf(stderr, "File too short.\n");
    return ERROR_READ;
  }

  printHeader(&h);

  fclose(rom);
  return SUCCESS;
}
