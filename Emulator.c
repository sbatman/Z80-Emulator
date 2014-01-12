#include "Registers.h"
#include "Ram.h"
#include "Opcodes.h"
#include "CounterStep.h"
#include "Test.h"

#include <stdio.h>

void Math_Add_A_R(byte value, bool addCarry);

int main()
{



	printf("INIT\n");
	ZeroRegisters();
	ZeroRam();
	InitCounterStep();
	printf("START\n");
	PrepTest();

	for (;;)
	{
		int next = _RAM[_RPC];
		int opcost = CounterStep[next];
		if (next == OP_STOP) break;
		switch (next)
		{

		case OP_LD_A_A: _RA_A = _RA_A; break;
		case OP_LD_B_A: _RA_A = _RB_A; break;
		case OP_LD_C_A: _RA_A = _RC_A; break;
		case OP_LD_D_A: _RA_A = _RD_A; break;
		case OP_LD_E_A: _RA_A = _RE_A; break;
		case OP_LD_H_A: _RA_A = _RH_A; break;
		case OP_LD_L_A: _RA_A = _RL_A; break;

		case OP_LD_A_B: _RB_A = _RA_A; break;
		case OP_LD_B_B: _RB_A = _RB_A; break;
		case OP_LD_C_B: _RB_A = _RC_A; break;
		case OP_LD_D_B: _RB_A = _RD_A; break;
		case OP_LD_E_B: _RB_A = _RE_A; break;
		case OP_LD_H_B: _RB_A = _RH_A; break;
		case OP_LD_L_B: _RB_A = _RL_A; break;

		case OP_LD_A_C: _RC_A = _RA_A; break;
		case OP_LD_B_C: _RC_A = _RB_A; break;
		case OP_LD_C_C: _RC_A = _RC_A; break;
		case OP_LD_D_C: _RC_A = _RD_A; break;
		case OP_LD_E_C: _RC_A = _RE_A; break;
		case OP_LD_H_C: _RC_A = _RH_A; break;
		case OP_LD_L_C: _RC_A = _RL_A; break;

		case OP_LD_A_D: _RD_A = _RA_A; break;
		case OP_LD_B_D: _RD_A = _RB_A; break;
		case OP_LD_C_D: _RD_A = _RC_A; break;
		case OP_LD_D_D: _RD_A = _RD_A; break;
		case OP_LD_E_D: _RD_A = _RE_A; break;
		case OP_LD_H_D: _RD_A = _RH_A; break;
		case OP_LD_L_D: _RD_A = _RL_A; break;

		case OP_LD_A_E: _RE_A = _RA_A; break;
		case OP_LD_B_E: _RE_A = _RB_A; break;
		case OP_LD_C_E: _RE_A = _RC_A; break;
		case OP_LD_D_E: _RE_A = _RD_A; break;
		case OP_LD_E_E: _RE_A = _RE_A; break;
		case OP_LD_H_E: _RE_A = _RH_A; break;
		case OP_LD_L_E: _RE_A = _RL_A; break;

		case OP_LD_A_H: _RH_A = _RA_A; break;
		case OP_LD_B_H: _RH_A = _RB_A; break;
		case OP_LD_C_H: _RH_A = _RC_A; break;
		case OP_LD_D_H: _RH_A = _RD_A; break;
		case OP_LD_E_H: _RH_A = _RE_A; break;
		case OP_LD_H_H: _RH_A = _RH_A; break;
		case OP_LD_L_H: _RH_A = _RL_A; break;

		case OP_LD_A_L: _RL_A = _RA_A; break;
		case OP_LD_B_L: _RL_A = _RB_A; break;
		case OP_LD_C_L: _RL_A = _RC_A; break;
		case OP_LD_D_L: _RL_A = _RD_A; break;
		case OP_LD_E_L: _RL_A = _RE_A; break;
		case OP_LD_H_L: _RL_A = _RH_A; break;
		case OP_LD_L_L: _RL_A = _RL_A; break;

		case OP_LD_N_A: _RA_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_B: _RB_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_C: _RC_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_D: _RD_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_E: _RE_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_H: _RH_A = _RAM[_RPC + 1]; break;
		case OP_LD_N_L: _RL_A = _RAM[_RPC + 1]; break;

		case OP_LD_HL_A: _RA_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_B: _RB_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_C: _RC_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_D: _RD_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_E: _RE_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_H: _RH_A = _RAM[_RH_A << 8 | _RL_A]; break;
		case OP_LD_HL_L: _RL_A = _RAM[_RH_A << 8 | _RL_A]; break;

		case OP_LD_IXD_R:
		{
							byte n = _RAM[_RPC + 2];
							switch (_RAM[_RPC + 1])
							{
							case OP_LD_HL_A: _RA_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_B: _RB_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_C: _RC_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_D: _RD_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_E: _RE_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_H: _RH_A = _RAM[_RIX + n]; break;
							case OP_LD_HL_L: _RL_A = _RAM[_RIX + n]; break;
							case OP_LD_A_HL: _RAM[_RIX + n] = _RA_A; break;
							case OP_LD_B_HL: _RAM[_RIX + n] = _RB_A; break;
							case OP_LD_C_HL: _RAM[_RIX + n] = _RC_A; break;
							case OP_LD_D_HL: _RAM[_RIX + n] = _RD_A; break;
							case OP_LD_E_HL: _RAM[_RIX + n] = _RE_A; break;
							case OP_LD_H_HL: _RAM[_RIX + n] = _RH_A; break;
							case OP_LD_L_HL: _RAM[_RIX + n] = _RL_A; break;
							case OP_LD_N_HL:
							{
											   _RAM[_RIX + n] = _RAM[_RPC + 3];
											   opcost = 4;
							}
								break;
							case OP_LD_NN_HL:
							{
												_RIX = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												opcost = 4;
							}
								break;
							case OP_LD_NN_HL_M:
							{
												  int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												  _RIX = _RAM[position + 1] << 8 | _RAM[position];
												  opcost = 4;
							}
								break;
							case OP_LD_HL_NN:
							{
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RAM[position] = (_RIX >> (8 * 1)) & 0xff;
												_RAM[position + 1] = (_RIX >> (8 * 0)) & 0xff;
												opcost = 4;
							}
								break;
							case OP_LD_HL_SP:
							{
												_RSP = _RIX;
												opcost = 2;
							}
								break;
							case OP_SK_PUSH_HL:
							{
												  _RAM[--_RSP] = (_RIX >> (8 * 0)) & 0xff;
												  _RAM[--_RSP] = (_RIX >> (8 * 1)) & 0xff;
												  opcost = 2;
							}
								break;
							case OP_SK_POP_HL:
							{
												 byte A = _RAM[_RSP++];
												 byte B = _RAM[_RSP++];
												 _RIX = B << 8 | A;
												 opcost = 2;
							}
								break;
							case OP_ETS_E_HL_SP:
							{
												   _RAM[_RSP] = (_RIX >> (8 * 0)) & 0xff;
												   _RAM[_RSP + 1] = (_RIX >> (8 * 1)) & 0xff;
							}
								break;
							case OP_MATH_ADD_HL_A:
							{
													 Math_Add_A_R(_RAM[_RIX + n], 0);
													 opcost = 3;
							}
								break;
							case OP_MATH_ADC_HL_A:
							{
													 Math_Add_A_R(_RAM[_RIX + n], 1);
													 opcost = 3;
							}
								break;
							}
		}
			break;
		case OP_LD_IYD_R:
		{
							byte n = _RAM[_RPC + 2];
							switch (_RAM[_RPC + 1])
							{
							case OP_LD_HL_A: _RA_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_B: _RB_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_C: _RC_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_D: _RD_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_E: _RE_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_H: _RH_A = _RAM[_RIY + n]; break;
							case OP_LD_HL_L: _RL_A = _RAM[_RIY + n]; break;
							case OP_LD_A_HL: _RAM[_RIY + n] = _RA_A; break;
							case OP_LD_B_HL: _RAM[_RIY + n] = _RB_A; break;
							case OP_LD_C_HL: _RAM[_RIY + n] = _RC_A; break;
							case OP_LD_D_HL: _RAM[_RIY + n] = _RD_A; break;
							case OP_LD_E_HL: _RAM[_RIY + n] = _RE_A; break;
							case OP_LD_H_HL: _RAM[_RIY + n] = _RH_A; break;
							case OP_LD_L_HL: _RAM[_RIY + n] = _RL_A; break;
							case OP_LD_N_HL:
							{
											   _RAM[_RIY + n] = _RAM[_RPC + 3];
											   opcost = 4;
							}
								break;
							case OP_LD_NN_HL:
							{
												_RIY = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												opcost = 4;
							}
								break;
							case OP_LD_NN_HL_M:
							{
												  int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												  _RIY = _RAM[position + 1] << 8 | _RAM[position];
												  opcost = 4;
							}
								break;
							case OP_LD_HL_NN:
							{
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RAM[position] = (_RIY >> (8 * 1)) & 0xff;
												_RAM[position + 1] = (_RIY >> (8 * 0)) & 0xff;
												opcost = 4;
							}
								break;
							case OP_LD_HL_SP:
							{
												_RSP = _RIY;
												opcost = 2;
							}
								break;
							case OP_SK_PUSH_HL:
							{
												  _RAM[--_RSP] = (_RIY >> (8 * 0)) & 0xff;
												  _RAM[--_RSP] = (_RIY >> (8 * 1)) & 0xff;
												  opcost = 2;
							}
								break;
							case OP_SK_POP_HL:
							{
												 byte A = _RAM[_RSP++];
												 byte B = _RAM[_RSP++];
												 _RIY = B << 8 | A;
												 opcost = 2;
							}
								break;
							case OP_ETS_E_HL_SP:
							{
												   _RAM[_RSP] = (_RIY >> (8 * 0)) & 0xff;
												   _RAM[_RSP + 1] = (_RIY >> (8 * 1)) & 0xff;
							}
								break;
							case OP_MATH_ADD_HL_A:
							{
													 Math_Add_A_R(_RAM[_RIX + n], 0);
													 opcost = 3;
							}
								break;
							case OP_MATH_ADC_HL_A:
							{
													 Math_Add_A_R(_RAM[_RIX + n], 1);
													 opcost = 3;
							}
								break;
							}
		}
			break;

		case OP_LD_A_HL: _RAM[_RH_A << 8 | _RL_A] = _RA_A; break;
		case OP_LD_B_HL: _RAM[_RH_A << 8 | _RL_A] = _RB_A; break;
		case OP_LD_C_HL: _RAM[_RH_A << 8 | _RL_A] = _RC_A; break;
		case OP_LD_D_HL: _RAM[_RH_A << 8 | _RL_A] = _RD_A; break;
		case OP_LD_E_HL: _RAM[_RH_A << 8 | _RL_A] = _RE_A; break;
		case OP_LD_H_HL: _RAM[_RH_A << 8 | _RL_A] = _RH_A; break;
		case OP_LD_L_HL: _RAM[_RH_A << 8 | _RL_A] = _RL_A; break;

		case OP_LD_N_HL: _RAM[_RH_A << 8 | _RL_A] = _RAM[_RPC + 1]; break;
		case OP_LD_BC_A: _RA_A = _RAM[_RB_A << 8 | _RC_A]; break;
		case OP_LD_DE_A: _RA_A = _RAM[_RD_A << 8 | _RE_A]; break;
		case OP_LD_NN_A: _RA_A = _RAM[_RAM[_RPC + 2] << 8 | _RAM[_RPC + 1]];
		case OP_LD_A_BC: _RAM[_RB_A << 8 | _RC_A] = _RA_A; break;
		case OP_LD_A_DE: _RAM[_RD_A << 8 | _RE_A] = _RA_A; break;
		case OP_LD_A_NN: _RAM[_RAM[_RPC + 2] << 8 | _RAM[_RPC + 1]] = _RA_A; break;
		case OP_LD_ED:
		{
						 switch (_RAM[_RPC + 1]){
						 case OP_LD_I_A:
							 _RA_A = _RIV;
							 _RF_A |= ((_RIV & 0x80) != 0) << FLAG_S;
							 _RF_A |= (_RIV == 0) << FLAG_Z;
							 _RF_A |= 0 << FLAG_H;
							 _RF_A |= _IFF2 << FLAG_P;
							 _RF_A |= 0 << FLAG_N;
							 break;
						 case OP_LD_R_A:
							 _RA_A = _RMR;
							 _RF_A |= ((_RIV & 0x80) != 0) << FLAG_S;
							 _RF_A |= (_RMR == 0) << FLAG_Z;
							 _RF_A |= 0 << FLAG_H;
							 _RF_A |= _IFF2 << FLAG_P;
							 _RF_A |= 0 << FLAG_N;
							 break;
						 case OP_LD_A_I: _RIV = _RA_A; break;
						 case OP_LD_A_R: _RMR = _RA_A; break;
						 case OP_LD_NN_DD_BC:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RB_A = _RAM[position + 1];
												_RC_A = _RAM[position];
												opcost = 4;
						 }
							 break;
						 case OP_LD_NN_DD_DE:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RD_A = _RAM[position + 1];
												_RE_A = _RAM[position];
												opcost = 4;
						 }
							 break;
						 case OP_LD_NN_DD_HL:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RH_A = _RAM[position + 1];
												_RL_A = _RAM[position];
												opcost = 4;
						 }
							 break;
						 case OP_LD_NN_DD_SP:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RSP = _RAM[position + 1] << 8 | _RAM[position];
												opcost = 4;
						 }
							 break;
						 case OP_LD_DD_NN_BC:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RAM[position] = _RC_A;
												_RAM[position + 1] = _RB_A;
												opcost = 4;
						 }
							 break;
						 case OP_LD_DD_NN_DE:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RAM[position] = _RE_A;
												_RAM[position + 1] = _RD_A;
												opcost = 4;
						 }
							 break;
						 case OP_LD_DD_NN_HL:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RAM[position] = _RL_A;
												_RAM[position + 1] = _RH_A;
												opcost = 4;
						 }
							 break;
						 case OP_LD_DD_NN_SP:
						 {
												int position = _RAM[_RPC + 3] << 8 | _RAM[_RPC + 2];
												_RAM[position] = (_RSP >> (8 * 0)) & 0xff;
												_RAM[position + 1] = (_RSP >> (8 * 1)) & 0xff;
												opcost = 4;
						 }
							 break;

						 case OP_ETS_LDI:
						 {
											_RAM[DEasWord()] = _RAM[HLasWord()];
											IncrementHL();
											IncrementDE();
											DecrementBC();
											_RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											_RF_A |= 0 << FLAG_H;
											_RF_A |= 0 << FLAG_N;
											opcost = 2;
						 }
							 break;
						 case OP_ETS_LDIR:
						 {
											 _RAM[DEasWord()] = _RAM[HLasWord()];
											 IncrementHL();
											 IncrementDE();
											 DecrementBC();
											 _RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											 _RF_A |= 0 << FLAG_H;
											 _RF_A |= 0 << FLAG_N;
											 opcost = 2;
											 if ((BCasWord() - 1 != 0))_RPC -= 2;
						 }
							 break;
						 case OP_ETS_LDD:
						 {
											_RAM[DEasWord()] = _RAM[HLasWord()];
											DecrementHL();
											DecrementDE();
											DecrementBC();
											_RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											_RF_A |= 0 << FLAG_H;
											_RF_A |= 0 << FLAG_N;
											opcost = 2;
						 }
							 break;
						 case OP_ETS_LDDR:
						 {
											 _RAM[DEasWord()] = _RAM[HLasWord()];
											 DecrementHL();
											 DecrementDE();
											 DecrementBC();
											 _RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											 _RF_A |= 0 << FLAG_H;
											 _RF_A |= 0 << FLAG_N;
											 opcost = 2;
											 if ((BCasWord() - 1 != 0))_RPC -= 2;
						 }
							 break;
						 case OP_ETS_CPI:
						 {
											if (_RAM[HLasWord()] == _RA_A)
											{
												_RF_A |= 1 << FLAG_Z;
											}
											else
											{
												_RF_A |= 0 << FLAG_Z;
											}
											DecrementBC();
											IncrementHL();
											_RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											_RF_A |= 1 << FLAG_N;
											_RF_A |= 0 << FLAG_H;
											_RF_A |= 0 << FLAG_S;
											opcost = 2;
						 }
							 break;
						 case OP_ETS_CPIR:
						 {
											 bool condition = _RAM[HLasWord()] == _RA_A;
											 if (condition)
											 {
												 _RF_A |= 1 << FLAG_Z;
											 }
											 else
											 {
												 _RF_A |= 0 << FLAG_Z;
											 }
											 DecrementBC();
											 IncrementHL();
											 _RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											 _RF_A |= 1 << FLAG_N;
											 _RF_A |= 0 << FLAG_H;
											 _RF_A |= 0 << FLAG_S;
											 opcost = 2;
											 if (condition && (BCasWord() - 1 != 0))
											 {
												 _RPC -= 2;
											 }
						 }
							 break;
						 case OP_ETS_CPD:
						 {
											if (_RAM[HLasWord()] == _RA_A)
											{
												_RF_A |= 1 << FLAG_Z;
											}
											else
											{
												_RF_A |= 0 << FLAG_Z;
											}
											DecrementBC();
											DecrementHL();
											_RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											_RF_A |= 1 << FLAG_N;
											_RF_A |= 0 << FLAG_H;
											_RF_A |= 0 << FLAG_S;
											opcost = 2;
						 }
							 break;
						 case OP_ETS_CPDR:
						 {
											 bool condition = _RAM[HLasWord()] == _RA_A;
											 if (condition)
											 {
												 _RF_A |= 1 << FLAG_Z;
											 }
											 else
											 {
												 _RF_A |= 0 << FLAG_Z;
											 }
											 DecrementBC();
											 DecrementHL();
											 _RF_A |= (BCasWord() - 1 != 0) << FLAG_P;
											 _RF_A |= 1 << FLAG_N;
											 _RF_A |= 0 << FLAG_H;
											 _RF_A |= 0 << FLAG_S;
											 opcost = 2;
											 if (condition && (BCasWord() - 1 != 0))
											 {
												 _RPC -= 2;
											 }
						 }
							 break;
						 }
		}
			break;
		case  OP_LD_NN_BC: _RB_A = _RAM[_RPC + 2]; _RC_A = _RAM[_RPC + 1]; break;
		case  OP_LD_NN_DE: _RD_A = _RAM[_RPC + 2]; _RE_A = _RAM[_RPC + 1]; break;
		case  OP_LD_NN_HL: _RH_A = _RAM[_RPC + 2]; _RL_A = _RAM[_RPC + 1]; break;
		case  OP_LD_NN_SP: _RSP = _RAM[_RPC + 2] << 8 | _RAM[_RPC + 1]; break;
		case OP_LD_NN_HL_M:
		{
							  int position = _RAM[_RPC + 2] << 8 | _RAM[_RPC + 1];
							  _RH_A = _RAM[position + 1];
							  _RL_A = _RAM[position];
		}
			break;

		case OP_LD_HL_NN:
		{
							int position = _RAM[_RPC + 2] << 8 | _RAM[_RPC + 1];
							_RAM[position] = _RL_A;
							_RAM[position + 1] = _RH_A;
		}
			break;
		case OP_LD_HL_SP: _RSP = _RH_A << 8 | _RL_A; break;
		case OP_SK_PUSH_BC:
		{
							  _RAM[--_RSP] = _RB_A;
							  _RAM[--_RSP] = _RC_A;
		}
			break;
		case OP_SK_PUSH_DE:
		{
							  _RAM[--_RSP] = _RD_A;
							  _RAM[--_RSP] = _RE_A;
		}
			break;
		case OP_SK_PUSH_HL:
		{
							  _RAM[--_RSP] = _RH_A;
							  _RAM[--_RSP] = _RL_A;
		}
			break;
		case OP_SK_PUSH_AF:
		{
							  _RAM[--_RSP] = _RA_A;
							  _RAM[--_RSP] = _RF_A;
		}
			break;
		case OP_SK_POP_BC:
		{
							 _RC_A = _RAM[_RSP++];
							 _RB_A = _RAM[_RSP++];
		}
			break;
		case OP_SK_POP_DE:
		{
							 _RE_A = _RAM[_RSP++];
							 _RD_A = _RAM[_RSP++];
		}
			break;
		case OP_SK_POP_HL:
		{
							 _RL_A = _RAM[_RSP++];
							 _RH_A = _RAM[_RSP++];
		}
			break;
		case OP_SK_POP_AF:
		{
							 _RF_A = _RAM[_RSP++];
							 _RA_A = _RAM[_RSP++];
		}
			break;
		case OP_ETS_E_DE_HL:
		{
							   byte tempD = _RD_A;
							   byte tempE = _RE_A;
							   _RD_A = _RH_A;
							   _RE_A = _RL_A;
							   _RH_A = tempD;
							   _RL_A = tempE;

		}
			break;
		case OP_ETS_E_AF_AF:
		{
							   byte tempA = _RA_A;
							   byte tempF = _RF_A;
							   _RA_A = _RA_B;
							   _RF_A = _RF_B;
							   _RA_B = tempA;
							   _RF_B = tempF;

		}
			break;
		case OP_ETS_E_EXX:
		{
							 byte tempB = _RB_A;
							 byte tempC = _RC_A;
							 _RB_A = _RB_B;
							 _RC_A = _RC_B;
							 _RB_B = tempB;
							 _RC_B = tempC;
							 byte tempD = _RD_A;
							 byte tempE = _RE_A;
							 _RD_A = _RD_B;
							 _RE_A = _RE_B;
							 _RD_B = tempD;
							 _RE_B = tempE;
							 byte tempH = _RH_A;
							 byte tempL = _RL_A;
							 _RH_A = _RH_B;
							 _RL_A = _RL_B;
							 _RH_B = tempH;
							 _RL_B = tempL;
		}
			break;
		case OP_ETS_E_HL_SP:
		{
							   _RAM[_RSP] = _RL_A;
							   _RAM[_RSP + 1] = _RH_A;
		}
			break;

		case OP_MATH_ADD_A_A:Math_Add_A_R(_RA_A,0); break;
		case OP_MATH_ADD_B_A:Math_Add_A_R(_RB_A,0); break;
		case OP_MATH_ADD_C_A:Math_Add_A_R(_RC_A,0); break;
		case OP_MATH_ADD_D_A:Math_Add_A_R(_RD_A,0); break;
		case OP_MATH_ADD_E_A:Math_Add_A_R(_RE_A,0); break;
		case OP_MATH_ADD_H_A:Math_Add_A_R(_RH_A,0); break;
		case OP_MATH_ADD_L_A:Math_Add_A_R(_RL_A,0); break;
		case OP_MATH_ADD_N_A:Math_Add_A_R(_RAM[_RPC + 1],0); break;
		case OP_MATH_ADD_HL_A:Math_Add_A_R(_RAM[HLasWord()],0); break;

		case OP_MATH_ADC_A_A:Math_Add_A_R(_RA_A, 1); break;
		case OP_MATH_ADC_B_A:Math_Add_A_R(_RB_A, 1); break;
		case OP_MATH_ADC_C_A:Math_Add_A_R(_RC_A, 1); break;
		case OP_MATH_ADC_D_A:Math_Add_A_R(_RD_A, 1); break;
		case OP_MATH_ADC_E_A:Math_Add_A_R(_RE_A, 1); break;
		case OP_MATH_ADC_H_A:Math_Add_A_R(_RH_A, 1); break;
		case OP_MATH_ADC_L_A:Math_Add_A_R(_RL_A, 1); break;
		case OP_MATH_ADC_N_A:Math_Add_A_R(_RAM[_RPC + 1], 1); break;
		case OP_MATH_ADC_HL_A:Math_Add_A_R(_RAM[HLasWord()], 1); break;

		default:
		{
				   printf("Unkown opcode %i", _RAM[_RPC]);
		}
		}


		_RPC += opcost;

	}

	printf("STOPPED\n");
	PostTest();
	getchar();

	return 0;
}

void Math_Add_A_R(byte value, bool addCarry)
{
	byte result = value + _RA_A;
	SetFlag((((value & 0x0F) + (_RA_A & 0x0F)) & 0x10) != 0, FLAG_H);
	SetFlag(0, FLAG_N);
	SetFlag(((result & 0x80) != 0), FLAG_S);
	SetFlag(((result & 0x100) != 0), FLAG_C);
	SetFlag(((result & 0xff) == 0), FLAG_Z);
	int partASign = _RA_A & 0x80;
	int partBSign = value & 0x80;
	int resultSign = result & 0x80;
	SetFlag(partASign == partBSign && resultSign != partASign, FLAG_P);
	_RA_A = result;
	if (addCarry)_RA_A += ((result & 0x100) != 0);
}