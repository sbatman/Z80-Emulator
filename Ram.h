#pragma once
#include "Types.h"

#define RAMLENGTH 65536

byte _RAM[RAMLENGTH];

void ZeroRam()
{
	for (int i = 0; i < RAMLENGTH; i++) _RAM[i] = 0;
}