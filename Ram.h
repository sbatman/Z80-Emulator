#pragma once
#include "Types.h"

#define RAMLENGTH 65536

byte _RAM[RAMLENGTH];

void ZeroRam()
{
	for (int i = 0; i < RAMLENGTH; i++) _RAM[i] = 0;
}

void WriteWordAtAddress(word address, word wordToWrite)
{
	_RAM[address] = (wordToWrite >> (8 * 0)) & 0xff;
	_RAM[address + 1] = (wordToWrite >> (8 * 1)) & 0xff;
}
void WriteByteAtAddress(word address, byte byteToWrite)
{
	_RAM[address] = byteToWrite;
}

word BytesToWord(byte H, byte L)
{
	return H << 8 | L;
}

word ReadWordAtAddress(word address)
{
	return BytesToWord(_RAM[address + 1], _RAM[address ]);
}

