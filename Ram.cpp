#include "Ram.h"
#include "string"

byte _RAM[RAMLENGTH];

///	<summary>
/// Sets every byte in the ram to 0
///	</summary>
void ZeroRam()
{
	memset(&_RAM, 0, RAMLENGTH);
}

///	<summary>
/// Writes the provided word to the address provided
///	</summary>
void WriteWordAtAddress(const word address, const word wordToWrite)
{
	_RAM[address] = (wordToWrite) & MAXBYTE;
	_RAM[address + 1] = (wordToWrite >> BYTEWIDTH) & MAXBYTE;
}

///	<summary>
/// Writes the provided byte to the address provided
///	</summary>
void WriteByteAtAddress(const word address, const  byte byteToWrite)
{
	_RAM[address] = byteToWrite;
}

///	<summary>
/// Takes two bytes and returns a word
///	</summary>
word BytesToWord(const byte H, const byte L)
{
	return H << BYTEWIDTH | L;
}

///	<summary>
/// Returns the word at the given address
///	</summary>
word ReadWordAtAddress(const word address)
{
	return BytesToWord(_RAM[address + 1], _RAM[address]);
}

///	<summary>
/// Returns the byte at the given address
///	</summary>
byte ReadByteAtAddress(const word address)
{
	return _RAM[address];
}

///	<summary>
/// Saves the ram as a binary dump to the filename provided
///	</summary>
void SaveRamToFile(const char * filename)
{
	FILE * f;
	fopen_s(&f, filename, "wb");
	fwrite(_RAM, 1, RAMLENGTH, f);
	fclose(f);
}

///	<summary>
/// Imports the ram from a binary dump using the filename provided
///	</summary>
void LoadRomFromFile(const char * filename)
{
	FILE * f;
	fopen_s(&f, filename, "rb");
	fread(_RAM, RAMLENGTH, 1, f);
	fclose(f);
}
