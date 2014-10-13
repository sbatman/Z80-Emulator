#pragma once
#include "Types.h"
#include <stdio.h>

static const int RAMLENGTH = 65536;

extern byte _RAM [];

void ZeroRam();

void WriteWordAtAddress(const word address, const word wordToWrite);

void WriteByteAtAddress(const word address, const byte byteToWrite);

word BytesToWord(const byte H, const byte L);

word ReadWordAtAddress(const word address);

byte ReadByteAtAddress(const word address);

void SaveRamToFile(const char * filename);

void LoadRomFromFile(const char * filename);