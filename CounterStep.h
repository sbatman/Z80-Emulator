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
} 