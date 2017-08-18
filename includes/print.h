#pragma once

#include <stdint.h>

#include "header.h"

void printEntry(const header *h);
void printNintendo(const header *h);
void printTitle(const header *h);
void printCgb(const header *h);
void printCompany(const header *h);
void printSgb(const header *h);
void printCartridge(const header *h);
void printRom(const header *h);
void printRam(const header *h);
void printDestination(const header *h);
void printVersion(const header *h);

typedef void (*printers)(const header *h);
