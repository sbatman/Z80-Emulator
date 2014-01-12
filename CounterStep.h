#pragma once
#include "Opcodes.h"

#define MAXOPCODE 255

int CounterStep[255];

void InitCounterStep()
{
	for (int i = 0; i < MAXOPCODE; i++)
	{
		CounterStep[i] = 1;
	}

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
	CounterStep[OP_LD_NN_DD_BC] = 4;
	CounterStep[OP_LD_NN_DD_DE] = 4;
	CounterStep[OP_LD_NN_DD_HL] = 4;
	CounterStep[OP_LD_NN_DD_SP] = 4;
	CounterStep[OP_LD_HL_NN] = 3;
	CounterStep[OP_MATH_ADD_N_A] = 2;
	CounterStep[OP_MATH_ADC_N_A] = 2;
	CounterStep[OP_MATH_SUB_N_A] = 2;
	CounterStep[OP_MATH_SBC_N_A] = 2;
} 