#pragma once
#include "Types.h"
#include "Registers.h"

byte RAS_RL(byte value)
{
 bool carrySet = GetFlag(FLAG_C);
 SetFlag((value & 0x80) != 0, FLAG_C);
 value <<= 1;
 value |= (byte) carrySet;
 SetFlag(0, FLAG_H);
 SetFlag(0, FLAG_N);
 SetFlag(_ParityLookupTable[value], FLAG_P);
 return value;
}

byte RAS_RLA()
{
 bool carrySet = GetFlag(FLAG_C);
 SetFlag((_RA_A & 0x80) != 0, FLAG_C);
 _RA_A <<= 1;
 _RA_A |= (byte) carrySet;
 SetFlag(0, FLAG_H);
 SetFlag(0, FLAG_N);
}