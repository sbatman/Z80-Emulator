#include "RAS.h"

byte RAS_RL(const byte value)
{
	byte returnValue = value;
	bool carrySet = GetFlag(FLAG_C) != 0;
	SetFlag((returnValue & 0x80) != 0, FLAG_C);
	returnValue <<= 1;
	returnValue |= static_cast<byte>(carrySet);
	SetFlag(0, FLAG_H);
	SetFlag(0, FLAG_N);
	SetFlag(_ParityLookupTable[returnValue] != 0, FLAG_P);
	return returnValue;
}

byte RAS_RLC(const byte value)
{
	byte returnValue = value;	
	SetFlag((returnValue & 0x80) != 0, FLAG_C);
	bool carrySet = GetFlag(FLAG_C) != 0;
	returnValue <<= 1;
	returnValue |= static_cast<byte>(carrySet);
	SetFlag(0, FLAG_H);
	SetFlag(0, FLAG_N);
	SetFlag(_ParityLookupTable[returnValue] != 0, FLAG_P);
	return returnValue;
}

void RAS_RLA()
{
	bool carrySet = GetFlag(FLAG_C);
	SetFlag((_RA_A & 0x80) != 0, FLAG_C);
	_RA_A <<= 1;
	_RA_A |= static_cast<byte>(carrySet);
	SetFlag(0, FLAG_H);
	SetFlag(0, FLAG_N);
}