#pragma once
#include "Types.h"
#include "Registers.h"

//Bank 1 Registers
byte _RA_A = 0;
byte _RB_A = 0;
byte _RD_A = 0;
byte _RH_A = 0;

byte _RF_A = 0;
byte _RC_A = 0;
byte _RE_A = 0;
byte _RL_A = 0;

//Bank 2 Registers
byte _RA_B = 0;
byte _RB_B = 0;
byte _RD_B = 0;
byte _RH_B = 0;

byte _RF_B = 0;
byte _RC_B = 0;
byte _RE_B = 0;
byte _RL_B = 0;

byte _RIV = 0; // Interrupt Vector
byte _RMR = 0; //Memory Refresh

word _RIX = 0; //Index Register
word _RIY = 0; //Index Register
word _RSP; //StackPointer
word _RPC; //Program Counter

bool _IFF1 = 0;
bool _IFF2 = 0;

byte _InterruptMode = 0;

byte _ParityLookupTable[255];

///	<summary>
/// Prepares the parity lookup table
/// Thanks to the following link for the speed of this one : http://www-graphics.stanford.edu/~seander/bithacks.html#ParityParallel
///	</summary>
void BuildPairtyLookupTable()
{
	for (uint32_t x = 0; x < MAXBYTE; x++)
	{
		uint32_t t = x;
		t ^= t >> 4;
		t &= 0xf;
		_ParityLookupTable[x] = !((0x6996 >> t) & 1);
	}
}

///	<summary>
/// Sets all of the registers to their intended initial values
///	</summary>
void ZeroRegisters()
{
	_InterruptMode = 0;
	_RA_A = MAXBYTE;
	_RC_A = MAXBYTE;
	_RD_A = MAXBYTE;
	_RH_A = MAXBYTE;
	_RF_A = MAXBYTE;
	_RB_A = MAXBYTE;
	_RE_A = MAXBYTE;
	_RL_A = MAXBYTE;
	_RA_B = MAXBYTE;
	_RC_B = MAXBYTE;
	_RD_B = MAXBYTE;
	_RH_B = MAXBYTE;
	_RF_B = MAXBYTE;
	_RB_B = MAXBYTE;
	_RE_B = MAXBYTE;
	_RL_B = MAXBYTE;
	_RIV = 0;
	_RMR = 0;
	_RIX = MAXWORD;
	_RIY = MAXWORD;
	_RSP = MAXWORD;
	_RPC = 0;
}

///	<summary>
/// Returns the registers b and c as a combined word
///	</summary>
word BCasWord()
{
	return _RB_A << BYTEWIDTH | _RC_A;
}

///	<summary>
/// Returns the registers a and f as a combined word
///	</summary>
word AFasWord()
{
	return _RA_A << BYTEWIDTH | _RF_A;
}

///	<summary>
/// Returns the registers d and e as a combined word
///	</summary>
word DEasWord()
{
	return _RD_A << BYTEWIDTH | _RE_A;
}

///	<summary>
/// Returns the registers h and l as a combined word
///	</summary>
word HLasWord()
{
	return _RH_A << BYTEWIDTH | _RL_A;
}

///	<summary>
/// Decrements the registers (bc treated as a word)
///	</summary>
void DecrementBC()
{
	word currentvalue = BCasWord();
	currentvalue--;
	_RB_A = (currentvalue >> BYTEWIDTH) & MAXBYTE;
	_RC_A = currentvalue & MAXBYTE;
}

///	<summary>
/// Decrements the registers (hl treated as a word)
///	</summary>
void DecrementHL()
{
	word currentvalue = HLasWord();
	currentvalue--;
	_RH_A = (currentvalue >> BYTEWIDTH) & MAXBYTE;
	_RL_A = currentvalue & MAXBYTE;
}

///	<summary>
/// Decrements the registers (de treated as a word)
///	</summary>
void DecrementDE()
{
	word currentvalue = DEasWord();
	currentvalue--;
	_RD_A = (currentvalue >> BYTEWIDTH) & MAXBYTE;
	_RE_A = currentvalue & MAXBYTE;
}

///	<summary>
/// Increment the registers (bc treated as a word)
///	</summary>
void IncrementBC()
{
	word currentvalue = BCasWord();
	currentvalue++;
	_RB_A = (currentvalue >> BYTEWIDTH) & MAXBYTE;
	_RC_A = currentvalue & MAXBYTE;
}

///	<summary>
/// Increment the registers (hl treated as a word)
///	</summary>
void IncrementHL()
{
	word currentvalue = HLasWord();
	currentvalue++;
	_RH_A = (currentvalue >> BYTEWIDTH) & MAXBYTE;
	_RL_A = currentvalue & MAXBYTE;
}

///	<summary>
/// Increment the registers (de treated as a word)
///	</summary>
void IncrementDE()
{
	word currentvalue = DEasWord();
	currentvalue++;
	_RD_A = (currentvalue >> BYTEWIDTH) & MAXBYTE;
	_RE_A = currentvalue & MAXBYTE;
}

///	<summary>
/// Sets the specified flag to the provided state
///	</summary>
void SetFlag(bool value, byte flag)
{
	if (value)	_RF_A |= flag;	else _RF_A &= ~flag;
}

///	<summary>
/// Returns the specified flags state
///	</summary>
bool GetFlag(byte flag)
{
	return (_RF_A & flag) != 0;
}
