#pragma once
#include "Types.h"

void Math_Add_SS_HL(word value, bool addCarry);

void Math_Add_PP_IX(word value, bool addCarry);

void Math_Sub_SS_HL(word value, bool addCarry);

void Math_Add_A_R(byte value, bool addCarry);

void Math_Sub_A_R(byte value, bool addCarry);

void Math_And_A_R(byte value);

void Math_Or_A_R(byte value);

void Math_Xor_A_R(byte value);

void Math_Cp_A_R(byte value);

byte Math_Inc_Byte(byte value);

byte Math_Dec_Byte(byte value);