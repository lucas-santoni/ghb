#pragma once

#include <stdint.h>

#define HEADER_START (0x0)

#define JUNK_START (0x0)
#define JUNK_END (0x100)
#define JUNK_SIZE (JUNK_END - JUNK_START)

#define ENTRY_START (0x100)
#define ENTRY_END (0x104)
#define ENTRY_SIZE (ENTRY_END - ENTRY_START)
#define ENTRY_USUAL (0x0150c300) // 0x00c35001

#define NINTENDO_START (0x104)
#define NINTENDO_END (0x134)
#define NINTENDO_SIZE (NINTENDO_END - NINTENDO_START)

#define TITLE_START (0x134)
#define TITLE_END (0x143)
#define TITLE_SIZE (TITLE_END - TITLE_START)

#define CGB_START (0x143)
#define CGB_END (0x144)
#define CGB_SIZE (CGB_END - CGB_START)
#define CGB_RETROCOMPATIBLE (0x80)
#define CGB_NORETROCOMPATIBLE (0xC0)

#define COMPANY_START (0x144)
#define COMPANY_END (0x146)
#define COMPANY_SIZE (COMPANY_END - COMPANY_START)

#define SGB_START (0x146)
#define SGB_END (0x147)
#define SGB_SIZE (SGB_END - SGB_START)

#define CARTRIDGE_START (0x147)
#define CARTRIDGE_END (0x148)
#define CARTRIDGE_SIZE (CARTRIDGE_END - CARTRIDGE_START)

#define ROM_START (0x148)
#define ROM_END (0x149)
#define ROM_SIZE (ROM_END - ROM_START)

#define RAM_START (0x149)
#define RAM_END (0x14A)
#define RAM_SIZE (RAM_END - RAM_START)

#define DESTINATION_START (0x14A)
#define DESTINATION_END (0x14B)
#define DESTINATION_SIZE (DESTINATION_END - DESTINATION_START)

#define OLDCOMPANY_START (0x14B)
#define OLDCOMPANY_END (0x14C)
#define OLDCOMPANY_SIZE (OLDCOMPANY_END - OLDCOMPANY_START)
#define USE_NEW_LICENSE_CODE (0x33)

#define VERSION_START (0x14C)
#define VERSION_END (0x14D)
#define VERSION_SIZE (VERSION_END - VERSION_START)

#define CHECKSUM_START (0x14D)
#define CHECKSUM_END (0x14E)
#define CHECKSUM_SIZE (CHECKSUM_END - CHECKSUM_START)

#define GLOBAL_START (0x14E)
#define GLOBAL_END (0x14F)
#define GLOBAL_SIZE (GLOBAL_END - GLOBAL_START)

#define HEADER_SIZE (0x14F)

typedef struct {
  uint8_t junk[JUNK_SIZE];
  uint8_t entry[ENTRY_SIZE];
  uint8_t nintendo[NINTENDO_SIZE];
  uint8_t title[TITLE_SIZE];
  uint8_t cgb[CGB_SIZE];
  uint8_t company[COMPANY_SIZE];
  uint8_t sgb[SGB_SIZE];
  uint8_t cartridge[CARTRIDGE_SIZE];
  uint8_t rom[ROM_SIZE];
  uint8_t ram[RAM_SIZE];
  uint8_t destination[DESTINATION_SIZE];
  uint8_t oldcompany[OLDCOMPANY_SIZE];
  uint8_t version[VERSION_SIZE];
  uint8_t checksum[CHECKSUM_SIZE];
  uint8_t global[GLOBAL_SIZE];
} header;
