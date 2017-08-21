#pragma once

#include <stdbool.h>
#include <stdint.h>

#define MIN_ARGS (2)

typedef struct {
  bool force;
  char *romPath;
} arguments;

int32_t parseCommandLineArguments(int argc, char * const argv[]);
