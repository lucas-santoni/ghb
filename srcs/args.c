#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

#include "args.h"
#include "status.h"
#include "usage.h"

extern int opter;
arguments args = {
  .force = false,
  .romPath = NULL
};

// Parse command line arguments
// An unknown option does not exit
// See usage for explanations
int32_t parseCommandLineArguments(int argc, char * const argv[]) {
  if (!argv || !*argv)
    exit(ERROR_ARGS);

  if (argc < MIN_ARGS)
    return FAILURE;

  opterr = false;
  int32_t unknown = false;
  int32_t opt;
  while ((opt = getopt(argc, argv, "hf")) != FAILURE) {
    switch (opt) {
      case 'h': usage(*argv); exit(USAGE_ASKED);
      case 'f': args.force = true; break;
      case '?':
        unknown = true;
        if (isprint(optopt))
          fprintf(stderr, "Error ! Unknown option: -- %c.\n", optopt);
        break;
      default:
        usage(*argv);
    }
  }

  if (argv[optind] != NULL)
    args.romPath = argv[optind];
  if (unknown)
    printf("Unkown option(s) ignored.\n\n");
  return SUCCESS;
}
