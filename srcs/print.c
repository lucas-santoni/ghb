#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "header.h"
#include "colors.h"
#include "print.h"
#include "cartridge.h"
#include "nintendoLogo.h"
#include "rom.h"
#include "ram.h"

inline void printEntry(const header *h) {
  bool check = false;
  if (*(uint32_t *)(void *)h->entry == ENTRY_USUAL)
    check = true;

  printf("Entry:\t\t\t%s", check ? "" : YELLOW);

  printf("%02x", *h->entry);
  for (uint32_t i = 1; i < sizeof(h->entry); ++i)
    printf(" %02x", *(h->entry + i));

  printf(RESET "\n");
}

inline void printNintendo(const header *h) {
  bool check = checkNintendoLogo(h->nintendo);

  printf("Nintendo:\t\t%s", check ? "" : RED);
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
    printf("Monochromatic & Color\n");
  else
    printf(YELLOW "Monochromatic" RESET "\n");
}

// TODO: Setup a table fot this
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
    printf(RED "No" RESET "\n");
}

inline void printCartridge(const header *h) {
  char *type = getCartridgeType(*h->cartridge);

  printf("Cartridge:\t\t");
  if (type == NULL)
    printf(RED "Unknown" RESET);
  else
    printf("%s", type);
  printf("\n");
}

inline void printRom(const header *h) {
  char *size = getRomSize(*h->rom);

  printf("ROM Size:\t\t");
  if (size == NULL)
    printf(RED "Unknown" RESET);
  else
    printf("%s", size);
  printf("\n");
}

inline void printRam(const header *h) {
  char *size = getRamSize(*h->ram);

  printf("RAM Size:\t\t");
  if (size == NULL)
    printf(RED "Unknown" RESET);
  else
    printf("%s", size);
  printf("\n");
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
    printf(RED "Unknown" RESET "\n");
  else
    printf("%d\n", *h->version);
}
