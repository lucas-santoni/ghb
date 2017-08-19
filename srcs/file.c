#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>

// Check if it is a regulare file
// We avoid directories or special files
// TODO: Symbolic links ?
bool isRegularFile(const char *path) {
  struct stat s;
  stat(path, &s);
  return S_ISREG(s.st_mode);
}
