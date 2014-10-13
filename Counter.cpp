#include "Counter.h"

uint32_t CounterStep[255];

void InitCounterStep()
{
	for (uint8_t i = 0; i < MAXBYTE; i++) CounterStep[i] = 1;

	CounterStep[OP_Load::N_A] = 2;
	CounterStep[OP_Load::N_B] = 2;
	CounterStep[OP_Load::N_C] = 2;
	CounterStep[OP_Load::N_D] = 2;
	CounterStep[OP_Load::N_E] = 2;
	CounterStep[OP_Load::N_H] = 2;
	CounterStep[OP_Load::N_L] = 2;
	CounterStep[OP_Load::IXD_R] = 3;
	CounterStep[OP_Load::IYD_R] = 3;
	CounterStep[OP_Load::NN_A] = 3;
	CounterStep[OP_Load::ED] = 2;
	CounterStep[OP_Load::NN_BC] = 3;
	CounterStep[OP_Load::NN_DE] = 3;
	CounterStep[OP_Load::NN_HL] = 3;
	CounterStep[OP_Load::NN_SP] = 3;
	CounterStep[OP_Load::NN_HL_M] = 3;
	CounterStep[OP_Load::A_NN] = 3;
	CounterStep[OP_Load::HL_NN] = 3;
	CounterStep[OP_Math::ADD_N_A] = 2;
	CounterStep[OP_Math::ADC_N_A] = 2;
	CounterStep[OP_Math::SUB_N_A] = 2;
	CounterStep[OP_Math::SBC_N_A] = 2;
	CounterStep[OP_Math::AND_N_A] = 2;
	CounterStep[OP_Math::OR_N_A] = 2;
	CounterStep[OP_Math::XOR_N_A] = 2;
	CounterStep[OP_Math::CP_N_A] = 2;
	CounterStep[OP_Stack::JR_E] = 2;
	CounterStep[OP_Stack::JR_Z] = 2;
	CounterStep[OP_RAS::CB] = 2;
	CounterStep[OP_Stack::JR_NZ_E] = 2;
	CounterStep[OP_Stack::JR_C_E] = 2;
	CounterStep[OP_Stack::JP_NZ] = 3;
	CounterStep[OP_Stack::JP_Z] = 3;
	CounterStep[OP_Stack::JP_NC] = 3;
	CounterStep[OP_Stack::JP_C] = 3;
	CounterStep[OP_Stack::JP_PO] = 3;
	CounterStep[OP_Stack::JP_PE] = 3;
	CounterStep[OP_Stack::JP_P] = 3;
	CounterStep[OP_Stack::JP_N] = 3;
	CounterStep[OP_Load::N_HL] = 2;
	CounterStep[OP_IO::OUT_NA] = 2;
	CounterStep[OP_Stack::JR_NC_E] = 2;
	CounterStep[OP_Stack::JP] = 0;
	CounterStep[OP_Stack::DJNZ] = 2;
}