#include <stdio.h>
#include <stdint.h>

#include "header.h"
#include "colors.h"
#include "print.h"
#include "cartridge.h"
#include "entry.h"
#include "nintendoLogo.h"
#include "rom.h"
#include "ram.h"
#include "company.h"

// Check the entry bytes
// They do not *need* to be the same but they are most
// of the time so it still makes sense to check them
inline void printEntry(const header *h) {
  bool check = checkEntry(h->entry);
  printf("Entry:\t\t\t%s", check ? "" : YELLOW);

  printf("%02x", *h->entry);
  for (uint32_t i = 1; i < sizeof(h->entry); ++i)
    printf(" %02x", *(h->entry + i));

  printf(RESET "\n");
}

// The bytes here are supposed to always be the
// same so it makes sense to check them
inline void printNintendo(const header *h) {
  bool check = checkNintendoLogo(h->nintendo);

  printf("Nintendo:\t\t%s", check ? "" : RED);
  printf("%02x", *h->nintendo);
  for (uint32_t i = 1; i < 4; ++i)
    printf(" %02x", *(h->nintendo + i));
  printf("..." RESET "\n");
}

// The title is all uppercase
inline void printTitle(const header *h) {
  printf("Title:\t\t\t%s\n", h->title);
}

// Color support
inline void printCgb(const header *h) {
  printf("Color support:\t\t");
  if (*h->cgb)
    printf("Monochromatic & Color\n");
  else
    printf(YELLOW "Monochromatic" RESET "\n");
}

// Each company allowed to make games is associated
// to a specific value
inline void printCompany(const header *h) {
  char *company = NULL;
  if (*h->oldcompany == USE_NEW_LICENSE_CODE)
    company = getNewCompany(*h->company);
  else
    company = getOldCompany(*h->oldcompany);

  printf("Licensee code:\t\t%s\n", company);
}

// Super Game Boy support
inline void printSgb(const header *h) {
  printf("Super Game Boy:\t\t");
  if (*h->sgb)
    printf("Yes\n");
  else
    printf(RED "No" RESET "\n");
}

// Cartridge type
// Each one associated to a value
inline void printCartridge(const header *h) {
  char *type = getCartridgeType(*h->cartridge);

  printf("Cartridge:\t\t");
  if (type == NULL)
    printf(RED "Unknown" RESET);
  else
    printf("%s", type);
  printf("\n");
}

// ROM type
// Each one associated to a value
inline void printRom(const header *h) {
  char *size = getRomSize(*h->rom);

  printf("ROM Size:\t\t");
  if (size == NULL)
    printf(RED "Unknown" RESET);
  else
    printf("%s", size);
  printf("\n");
}

// RAM type
// Each one associated to a value
inline void printRam(const header *h) {
  char *size = getRamSize(*h->ram);

  printf("RAM Size:\t\t");
  if (size == NULL)
    printf(RED "Unknown" RESET);
  else
    printf("%s", size);
  printf("\n");
}

// Is this game supposed to be distributed in Japan
// or in the rest of the world ?
inline void printDestination(const header *h) {
  printf("Destination:\t\t");
  if (!*h->destination)
    printf("Japanese\n");
  else
    printf("Non-Japanese\n");
}

// Version of the game, natural number
// Unknown most of the time
inline void printVersion(const header *h) {
  printf("Version:\t\t");
  if (!*h->version)
    printf(RED "Unknown" RESET "\n");
  else
    printf("%d\n", *h->version);
}
