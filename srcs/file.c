#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>

bool isRegularFile(const char *path) {
  struct stat s;
  stat(path, &s);
  return S_ISREG(s.st_mode);
}
