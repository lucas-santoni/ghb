#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#include "status.h"
#include "args.h"
#include "usage.h"
#include "ghb.h"

// TODO: More testing
// TODO: Update readme
// TODO: Merge

int32_t checkArgs(int argc, char * const argv[]) {
  if (!argv || !*argv)
    exit(ERROR_ARGS);

  if (argc < MIN_ARGS)
    return FAILURE;

  return SUCCESS;
}

int main(int argc, char * const argv[]) {
  if (checkArgs(argc, argv) != SUCCESS) {
    usage(*argv);
    return ERROR_ARGS;
  }

  ++argv;
  return ghb(*argv);
}
