#include <stdio.h>
#include <stdint.h>

#include "header.h"
#include "print.h"

printers prints[] = {
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

// TODO: Does it make any sense to implement a checker
// for this ?
inline void printEntry(const header *h) {
  printf("Entry:\t\t\t%02x", *h->entry);
  for (uint32_t i = 1; i < sizeof(h->entry); ++i)
    printf(" %02x", *(h->entry + i));
  printf("\n");
}

// TODO: Implement a checker for this
// as this data is meant to be static
// TODO: Setup a table for this
inline void printNintendo(const header *h) {
  printf("Nintendo:\t\t%02x", *h->nintendo);
  for (uint32_t i = 1; i < sizeof(h->nintendo) / 4; ++i)
    printf(" %02x", *(h->nintendo + i));
  printf("...\n");
}

inline void printTitle(const header *h) {
  printf("Title:\t\t\t%s\n", h->title);
}

inline void printCgb(const header *h) {
  printf("Color support:\t\t");
  if (*h->cgb)
    printf("Monochromatic & Color\n");
  else
    printf("Monochromatic\n");
}

// TODO: Execute this only only if old
// format says to
inline void printCompany(const header *h) {
  printf("Licensee code:\t\t");
  if (*h->oldcompany == USE_NEW_LICENSE_CODE)
    printf("%02x (new)\n", *h->company);
  else
    printf("%02x (old)\n", *h->oldcompany);
}

inline void printSgb(const header *h) {
  printf("Super Game Boy:\t\t");
  if (*h->sgb)
    printf("Yes\n");
  else
    printf("No\n");
}

// TODO: Setup a table for this
inline void printCartridge(const header *h) {
  printf("Cartridge:\t\t%02x\n", *h->cartridge);
}

// TODO: Setup a table for this
inline void printRom(const header *h) {
  printf("ROM Size:\t\t%02x\n", *h->rom);
}

// TODO: Setup a table for this
inline void printRam(const header *h) {
  printf("RAM Size:\t\t%02x\n", *h->ram);
}

inline void printDestination(const header *h) {
  printf("Destination:\t\t");
  if (!*h->destination)
    printf("Japanese\n");
  else
    printf("Non-Japanese\n");
}

inline void printVersion(const header *h) {
  printf("Version:\t\t");
  if (!*h->version)
    printf("Unknown");
  else
    printf("%d\n", *h->version);
}
