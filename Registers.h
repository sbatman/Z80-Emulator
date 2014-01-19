#pragma once
#include "Types.h"

//Main Registers
byte _RA_A;
byte _RB_A;
byte _RD_A;
byte _RH_A;

byte _RF_A;
byte _RC_A;
byte _RE_A;
byte _RL_A;

//Alternate Registers
byte _RA_B;
byte _RB_B;
byte _RD_B;
byte _RH_B;

byte _RF_B;
byte _RC_B;
byte _RE_B;
byte _RL_B;

byte _RIV; // Interrupt Vector
byte _RMR; //Memory Refresh

word _RIX; //Index Register
word _RIY; //Index Register
word _RSP; //StackPointer
word _RPC; //Program Counter

bool _IFF1;
bool _IFF2;

byte _InterruptMode;

byte _ParityLookupTable[255];

#define FLAG_S 0x80
#define FLAG_Z 0x40
#define FLAG_H 0x10
#define FLAG_P 0x04
#define FLAG_V 0x04
#define FLAG_N 0x02
#define FLAG_C 0x01

// Thanks to the following line for the speed of this one : http://www-graphics.stanford.edu/~seander/bithacks.html#ParityParallel
void BuildPairtyLookupTable()
{
 for (int x = 0; x < 255; x++)
 {
  int t = x;
  t ^= t >> 4;
  t &= 0xf;
  _ParityLookupTable[x] = !((0x6996 >> t) & 1);
 }
}

void ZeroRegisters()
{
 _InterruptMode = 0;
 _RA_A = 0xFF;
 _RC_A = 0xFF;
 _RD_A = 0xFF;
 _RH_A = 0xFF;
 _RF_A = 0xFF;
 _RB_A = 0xFF;
 _RE_A = 0xFF;
 _RL_A = 0xFF;
 _RA_B = 0xFF;
 _RC_B = 0xFF;
 _RD_B = 0xFF;
 _RH_B = 0xFF;
 _RF_B = 0xFF;
 _RB_B = 0xFF;
 _RE_B = 0xFF;
 _RL_B = 0xFF;
 _RIV = 0;
 _RMR = 0;
 _RIX = 0xffff;
 _RIY = 0xFFFF;
 _RSP = 0xFFFF;
 _RPC = 0;
}

word BCasWord()
{
 return _RB_A << 8 | _RC_A;
}

word AFasWord()
{
 return _RA_A << 8 | _RF_A;
}

word DEasWord()
{
 return _RD_A << 8 | _RE_A;
}

word HLasWord()
{
 return _RH_A << 8 | _RL_A;
}

void DecrementBC()
{
 word currentvalue = BCasWord();
 currentvalue--;
 _RB_A = (currentvalue >> (8 * 1)) & 0xff;
 _RC_A = (currentvalue >> (8 * 0)) & 0xff;
}

void DecrementHL()
{
 word currentvalue = HLasWord();
 currentvalue--;
 _RH_A = (currentvalue >> (8 * 1)) & 0xff;
 _RL_A = (currentvalue >> (8 * 0)) & 0xff;
}

void DecrementDE()
{
 word currentvalue = DEasWord();
 currentvalue--;
 _RD_A = (currentvalue >> (8 * 1)) & 0xff;
 _RE_A = (currentvalue >> (8 * 0)) & 0xff;
}

void IncrementBC()
{
 word currentvalue = BCasWord();
 currentvalue++;
 _RB_A = (currentvalue >> (8 * 1)) & 0xff;
 _RC_A = (currentvalue >> (8 * 0)) & 0xff;
}

void IncrementHL()
{
 word currentvalue = HLasWord();
 currentvalue++;
 _RH_A = (currentvalue >> (8 * 1)) & 0xff;
 _RL_A = (currentvalue >> (8 * 0)) & 0xff;
}

void IncrementDE()
{
 word currentvalue = DEasWord();
 currentvalue++;
 _RD_A = (currentvalue >> (8 * 1)) & 0xff;
 _RE_A = (currentvalue >> (8 * 0)) & 0xff;
}

void SetFlag(bool value, byte flag)
{
 if (value)
 {
  _RF_A |= flag;
 }
 else
 {
  _RF_A &= ~flag;
 }
}
int GetFlag(byte flag)
{
 return (_RF_A & flag) != 0;
}
