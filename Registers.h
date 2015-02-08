#pragma once
#include "Types.h"

static const byte FLAG_S = 0x80;
static const byte FLAG_Z = 0x40;
static const byte FLAG_5 = 0x20;
static const byte FLAG_H = 0x10;
static const byte FLAG_3 = 0x08;
static const byte FLAG_P = 0x04;
static const byte FLAG_V = 0x04;
static const byte FLAG_N = 0x02;
static const byte FLAG_C = 0x01;

//Main Registers
extern byte _RA_A;
extern byte _RB_A;
extern byte _RD_A;
extern byte _RH_A;

extern byte _RF_A;
extern byte _RC_A;
extern byte _RE_A;
extern byte _RL_A;

//Alternate Registers
extern byte _RA_B;
extern byte _RB_B;
extern byte _RD_B;
extern byte _RH_B;

extern byte _RF_B;
extern byte _RC_B;
extern byte _RE_B;
extern byte _RL_B;

extern byte _RIV; // Interrupt Vector
extern byte _RMR; //Memory Refresh

extern word _RIX; //Index Register
extern word _RIY; //Index Register
extern word _RSP; //StackPointer
extern word _RPC; //Program Counter

extern bool _IFF1;
extern bool _IFF2;

extern byte _InterruptMode;

extern byte _ParityLookupTable[255];

void BuildPairtyLookupTable();

void ZeroRegisters();

word BCasWord();

word AFasWord();

word DEasWord();

word HLasWord();

void DecrementBC();

void DecrementHL();

void DecrementDE();

void IncrementBC();

void IncrementHL();

void IncrementDE();

void SetFlag(bool value, byte flag);
bool GetFlag(byte flag);