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

#define FLAG_S 7;
#define FLAG_Z 6;
#define FLAG_H 4;
#define FLAG_P 2;
#define FLAG_V 2;
#define FLAG_N 1;
#define FLAG_C 0;

void ZeroRegisters()
{
	_RA_A=0;
	_RB_A = 0;
	_RD_A = 0;
	_RH_A = 0;
	_RF_A = 0;
	_RB_A = 0;
	_RE_A = 0;
	_RL_A = 0;
	_RA_B = 0;
	_RB_B = 0;
	_RD_B = 0;
	_RH_B = 0;
	_RF_B = 0;
	_RB_B = 0;
	_RE_B = 0;
	_RL_B = 0;
	_RIV = 0;
	_RMR = 0;
	_RIX = 0;
	_RIY = 0;
	_RSP = 0;
	_RPC = 0;
}