#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "header.h"
#include "print.h"
#include "colors.h"

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

inline void printEntry(const header *h) {
  bool check = false;
  if (*(uint32_t *)(void *)h->entry == ENTRY_USUAL)
    check = true;

  printf("Entry:\t\t\t%s", check ? GREEN : YELLOW);

  printf("%02x", *h->entry);
  for (uint32_t i = 1; i < sizeof(h->entry); ++i)
    printf(" %02x", *(h->entry + i));

  printf(RESET "\n");
}

inline void printNintendo(const header *h) {
  static const uint8_t nintendoLogoHexDump[] = {
    0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83,
    0x00, 0x0C, 0x00, 0x0D, 0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
    0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99, 0xBB, 0xBB, 0x67, 0x63,
    0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
  };

  bool check = true;
  for (uint32_t i = 0; i < sizeof(nintendoLogoHexDump); ++i) {
    if (nintendoLogoHexDump[i] != *(h->nintendo + i)) {
      check = false;
      break;
    }
  }

  printf("Nintendo:\t\t%s", check ? GREEN : RED);
  printf("%02x", *h->nintendo);
  for (uint32_t i = 1; i < 4; ++i)
    printf(" %02x", *(h->nintendo + i));
  printf("..." RESET "\n");
}

inline void printTitle(const header *h) {
  printf("Title:\t\t\t%s\n", h->title);
}

inline void printCgb(const header *h) {
  printf("Color support:\t\t");
  if (*h->cgb)
    printf(RED "Monochromatic & Color" RESET "\n");
  else
    printf(YELLOW "Monochromatic" RESET "\n");
}

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
    printf(GREEN "Yes" RESET "\n");
  else
    printf(RED "No" RESET "\n");
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
