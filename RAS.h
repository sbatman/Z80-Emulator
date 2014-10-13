#pragma once
#include "Types.h"
#include "Registers.h"

byte RAS_RL(byte value)
{
	bool carrySet = GetFlag(FLAG_C) != 0;
	SetFlag((value & 0x80) != 0, FLAG_C);
	value <<= 1;
	value |= static_cast<byte>(carrySet);
	SetFlag(0, FLAG_H);
	SetFlag(0, FLAG_N);
	SetFlag(_ParityLookupTable[value] != 0, FLAG_P);
	return value;
}

void RAS_RLA()
{
	bool carrySet = GetFlag(FLAG_C);
	SetFlag((_RA_A & 0x80) != 0, FLAG_C);
	_RA_A <<= 1;
	_RA_A |= (byte) carrySet;
	SetFlag(0, FLAG_H);
	SetFlag(0, FLAG_N);
}