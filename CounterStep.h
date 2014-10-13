#pragma once
#include "Opcodes.h"

#define MAXOPCODE 255

uint32_t CounterStep[255];

void InitCounterStep()
{
	for (uint32_t i = 0; i < MAXOPCODE; i++)
		CounterStep[i] = 1;
	CounterStep[OP_LD_N_A] = 2;
	CounterStep[OP_LD_N_B] = 2;
	CounterStep[OP_LD_N_C] = 2;
	CounterStep[OP_LD_N_D] = 2;
	CounterStep[OP_LD_N_E] = 2;
	CounterStep[OP_LD_N_H] = 2;
	CounterStep[OP_LD_N_L] = 2;
	CounterStep[OP_LD_IXD_R] = 3;
	CounterStep[OP_LD_IYD_R] = 3;
	CounterStep[OP_LD_NN_A] = 3;
	CounterStep[OP_LD_ED] = 2;
	CounterStep[OP_LD_NN_BC] = 3;
	CounterStep[OP_LD_NN_DE] = 3;
	CounterStep[OP_LD_NN_HL] = 3;
	CounterStep[OP_LD_NN_SP] = 3;
	CounterStep[OP_LD_NN_HL_M] = 3;
	CounterStep[OP_LD_A_NN]=3;
	CounterStep[OP_LD_HL_NN] = 3;
	CounterStep[OP_MATH_ADD_N_A] = 2;
	CounterStep[OP_MATH_ADC_N_A] = 2;
	CounterStep[OP_MATH_SUB_N_A] = 2;
	CounterStep[OP_MATH_SBC_N_A] = 2;
	CounterStep[OP_MATH_AND_N_A] = 2;
	CounterStep[OP_MATH_OR_N_A] = 2;
	CounterStep[OP_MATH_XOR_N_A] = 2;
	CounterStep[OP_MATH_CP_N_A] = 2;
	CounterStep[OP_SK_JR_E] = 2;
	CounterStep[OP_SK_JR_Z] = 2;
	CounterStep[OP_RAS_CB] = 2;
	CounterStep[OP_SK_JR_NZ_E] = 2;
	CounterStep[OP_SK_JR_C_E] = 2;
	CounterStep[OP_SK_JP_NZ] = 3;
	CounterStep[OP_SK_JP_Z] = 3;
	CounterStep[OP_SK_JP_NC] = 3;
	CounterStep[OP_SK_JP_C] = 3;
	CounterStep[OP_SK_JP_PO] = 3;
	CounterStep[OP_SK_JP_PE] = 3;
	CounterStep[OP_SK_JP_P] = 3;
	CounterStep[OP_SK_JP_N] = 3;
	CounterStep[OP_LD_N_HL] = 2;
	CounterStep[OP_IO_OUT_NA] = 2;
	CounterStep[OP_SK_JR_NC_E] = 2;
	CounterStep[OP_SK_JP] = 0;
	CounterStep[OP_SK_DJNZ]=2;
}