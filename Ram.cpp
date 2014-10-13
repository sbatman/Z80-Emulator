#include "Ram.h"
#include "string"

byte _RAM[RAMLENGTH];

void ZeroRam()
{
	memset(&_RAM, 0, RAMLENGTH);
}

void WriteWordAtAddress(const word address, const word wordToWrite)
{
	_RAM[address] = (wordToWrite) & MAXBYTE;
	_RAM[address + 1] = (wordToWrite >> BYTEWIDTH) & MAXBYTE;
}
void WriteByteAtAddress(const word address, const  byte byteToWrite)
{
	_RAM[address] = byteToWrite;
}

word BytesToWord(const byte H, const byte L)
{
	return H << BYTEWIDTH | L;
}

word ReadWordAtAddress(const word address)
{
	return BytesToWord(_RAM[address + 1], _RAM[address]);
}

byte ReadByteAtAddress(const word address)
{
	return _RAM[address];
}

void SaveRamToFile(const char * filename)
{
	FILE * f;
	fopen_s(&f, filename, "wb");
	fwrite(_RAM, 1, RAMLENGTH, f);
	fclose(f);
}

void LoadRomFromFile(const char * filename)
{
	FILE * f;
	fopen_s(&f, filename, "rb");
	fread(_RAM, RAMLENGTH, 1, f);
	fclose(f);
}
