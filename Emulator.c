#include "Registers.h"
#include "Ram.h"
#include "Opcodes.h"
#include "CounterStep.h"
#include "Test.h"
#include "Math.h"
#include "Stack.h"


#include <stdio.h>


int main()
{
 printf("INIT\n");
 ZeroRegisters();
 BuildPairtyLookupTable();
 ZeroRam();
 InitCounterStep();
 printf("START\n");
 PrepTest();
 int tick = 0;
 for (;;)
 {
  system("cls");
  int next = _RAM[_RPC];
  printf("Current Addresss : %x \n", _RPC);
  if (next != 0)printf("Next OpCode : %x \n", next);
  printf("_A%*i\n", 8, _RA_A);
  printf("_B%*i\n", 8, _RB_A);
  printf("_C%*i\n", 8, _RC_A);
  printf("_D%*i\n", 8, _RD_A);
  printf("_E%*i\n", 8, _RE_A);
  printf("_H%*i\n", 8, _RH_A);
  printf("_L%*i\n", 8, _RL_A);

  int opcost = CounterStep[next];
  //if (next == OP_STOP) break;
  if (tick % 10 == 0)
  {
   int g = 7;
   g = g*g;
  }
  tick++;

  switch (next)
  {
   case OP_STOP:break;
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
					 case OP_MATH_SUB_HL_A:
					 {
										   Math_Sub_A_R(_RAM[_RIX + n], 0);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_SBC_HL_A:
					 {
										   Math_Sub_A_R(_RAM[_RIX + n], 1);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_AND_HL_A:
					 {
										   Math_And_A_R(_RAM[_RIX + n]);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_OR_HL_A:
					 {
										  Math_Or_A_R(_RAM[_RIX + n]);
										  opcost = 3;
					 }
					  break;
					 case OP_MATH_XOR_HL_A:
					 {
										   Math_Xor_A_R(_RAM[_RIX + n]);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_CP_HL_A:
					 {
										  Math_Cp_A_R(_RAM[_RIX + n]);
										  opcost = 3;
					 }
					  break;
					 case OP_MATH_INC_HL_A:
					 {
										   Math_Inc_Byte(_RAM[_RIX + n]);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_DEC_HL_A:
					 {
										   Math_Dec_Byte(_RAM[_RIX + n]);
										   opcost = 3;
					 }
					  break;
					 default:
					 {
							 printf("Unkown opcode IX:%i \n", _RAM[_RPC + 1]);
					 }
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
										   Math_Add_A_R(_RAM[_RIY + n], 0);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_ADC_HL_A:
					 {
										   Math_Add_A_R(_RAM[_RIY + n], 1);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_SUB_HL_A:
					 {
										   Math_Sub_A_R(_RAM[_RIY + n], 0);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_SBC_HL_A:
					 {
										   Math_Sub_A_R(_RAM[_RIY + n], 1);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_AND_HL_A:
					 {
										   Math_And_A_R(_RAM[_RIY + n]);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_OR_HL_A:
					 {
										  Math_Or_A_R(_RAM[_RIY + n]);
										  opcost = 3;
					 }
					  break;
					 case OP_MATH_XOR_HL_A:
					 {
										   Math_Xor_A_R(_RAM[_RIY + n]);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_CP_HL_A:
					 {
										  Math_Cp_A_R(_RAM[_RIY + n]);
										  opcost = 3;
					 }
					  break;
					 case OP_MATH_INC_HL_A:
					 {
										   Math_Inc_Byte(_RAM[_RIY + n]);
										   opcost = 3;
					 }
					  break;
					 case OP_MATH_DEC_HL_A:
					 {
										   Math_Dec_Byte(_RAM[_RIY + n]);
										   opcost = 3;
					 }
					  break;
					 default:
					 {
							 printf("Unkown opcode IY:%i \n", _RAM[_RPC + 1]);
					 }
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
				  case OP_NEG:
				  {
							  byte temp = _RA_A;
							  _RA_A = 0;
							  Math_Sub_A_R(temp, 0);
							  SetFlag(1, FLAG_N);
				  }
				   break;
				  case OP_MATH_ADC_BC_HL: Math_Add_SS_HL(BCasWord(), 1); break;
				  case OP_MATH_ADC_DE_HL: Math_Add_SS_HL(DEasWord(), 1); break;
				  case OP_MATH_ADC_HL_HL: Math_Add_SS_HL(HLasWord(), 1); break;
				  case OP_MATH_ADC_SP_HL: Math_Add_SS_HL(_RSP, 1); break;
				  default:
				  {
						  printf("Unkown opcode ED : %i \n", _RAM[_RPC + 1]);
				  }
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

   case OP_MATH_ADD_A_A:Math_Add_A_R(_RA_A, 0); break;
   case OP_MATH_ADD_B_A:Math_Add_A_R(_RB_A, 0); break;
   case OP_MATH_ADD_C_A:Math_Add_A_R(_RC_A, 0); break;
   case OP_MATH_ADD_D_A:Math_Add_A_R(_RD_A, 0); break;
   case OP_MATH_ADD_E_A:Math_Add_A_R(_RE_A, 0); break;
   case OP_MATH_ADD_H_A:Math_Add_A_R(_RH_A, 0); break;
   case OP_MATH_ADD_L_A:Math_Add_A_R(_RL_A, 0); break;
   case OP_MATH_ADD_N_A:Math_Add_A_R(_RAM[_RPC + 1], 0); break;
   case OP_MATH_ADD_HL_A:Math_Add_A_R(_RAM[HLasWord()], 0); break;

   case OP_MATH_ADC_A_A:Math_Add_A_R(_RA_A, 1); break;
   case OP_MATH_ADC_B_A:Math_Add_A_R(_RB_A, 1); break;
   case OP_MATH_ADC_C_A:Math_Add_A_R(_RC_A, 1); break;
   case OP_MATH_ADC_D_A:Math_Add_A_R(_RD_A, 1); break;
   case OP_MATH_ADC_E_A:Math_Add_A_R(_RE_A, 1); break;
   case OP_MATH_ADC_H_A:Math_Add_A_R(_RH_A, 1); break;
   case OP_MATH_ADC_L_A:Math_Add_A_R(_RL_A, 1); break;
   case OP_MATH_ADC_N_A:Math_Add_A_R(_RAM[_RPC + 1], 1); break;
   case OP_MATH_ADC_HL_A:Math_Add_A_R(_RAM[HLasWord()], 1); break;

   case OP_MATH_SUB_A_A:Math_Sub_A_R(_RA_A, 0); break;
   case OP_MATH_SUB_A_B:Math_Sub_A_R(_RB_A, 0); break;
   case OP_MATH_SUB_A_C:Math_Sub_A_R(_RC_A, 0); break;
   case OP_MATH_SUB_A_D:Math_Sub_A_R(_RD_A, 0); break;
   case OP_MATH_SUB_A_E:Math_Sub_A_R(_RE_A, 0); break;
   case OP_MATH_SUB_A_H:Math_Sub_A_R(_RH_A, 0); break;
   case OP_MATH_SUB_A_L:Math_Sub_A_R(_RL_A, 0); break;
   case OP_MATH_SUB_N_A:Math_Sub_A_R(_RAM[_RPC + 1], 0); break;
   case OP_MATH_SUB_HL_A:Math_Sub_A_R(_RAM[HLasWord()], 0); break;

   case OP_MATH_SBC_A_A:Math_Sub_A_R(_RA_A, 1); break;
   case OP_MATH_SBC_A_B:Math_Sub_A_R(_RB_A, 1); break;
   case OP_MATH_SBC_A_C:Math_Sub_A_R(_RC_A, 1); break;
   case OP_MATH_SBC_A_D:Math_Sub_A_R(_RD_A, 1); break;
   case OP_MATH_SBC_A_E:Math_Sub_A_R(_RE_A, 1); break;
   case OP_MATH_SBC_A_H:Math_Sub_A_R(_RH_A, 1); break;
   case OP_MATH_SBC_A_L:Math_Sub_A_R(_RL_A, 1); break;
   case OP_MATH_SBC_N_A:Math_Sub_A_R(_RAM[_RPC + 1], 1); break;
   case OP_MATH_SBC_HL_A:Math_Sub_A_R(_RAM[HLasWord()], 1); break;

   case OP_MATH_AND_A_A:Math_And_A_R(_RA_A); break;
   case OP_MATH_AND_A_B:Math_And_A_R(_RB_A); break;
   case OP_MATH_AND_A_C:Math_And_A_R(_RC_A); break;
   case OP_MATH_AND_A_D:Math_And_A_R(_RD_A); break;
   case OP_MATH_AND_A_E:Math_And_A_R(_RE_A); break;
   case OP_MATH_AND_A_H:Math_And_A_R(_RH_A); break;
   case OP_MATH_AND_A_L:Math_And_A_R(_RL_A); break;
   case OP_MATH_AND_N_A:Math_And_A_R(_RAM[_RPC + 1]); break;
   case OP_MATH_AND_HL_A:Math_And_A_R(_RAM[HLasWord()]); break;

   case OP_MATH_OR_A_A:Math_Or_A_R(_RA_A); break;
   case OP_MATH_OR_A_B:Math_Or_A_R(_RB_A); break;
   case OP_MATH_OR_A_C:Math_Or_A_R(_RC_A); break;
   case OP_MATH_OR_A_D:Math_Or_A_R(_RD_A); break;
   case OP_MATH_OR_A_E:Math_Or_A_R(_RE_A); break;
   case OP_MATH_OR_A_H:Math_Or_A_R(_RH_A); break;
   case OP_MATH_OR_A_L:Math_Or_A_R(_RL_A); break;
   case OP_MATH_OR_N_A:Math_Or_A_R(_RAM[_RPC + 1]); break;
   case OP_MATH_OR_HL_A:Math_Or_A_R(_RAM[HLasWord()]); break;

   case OP_MATH_XOR_A_A:Math_Xor_A_R(_RA_A); break;
   case OP_MATH_XOR_A_B:Math_Xor_A_R(_RB_A); break;
   case OP_MATH_XOR_A_C:Math_Xor_A_R(_RC_A); break;
   case OP_MATH_XOR_A_D:Math_Xor_A_R(_RD_A); break;
   case OP_MATH_XOR_A_E:Math_Xor_A_R(_RE_A); break;
   case OP_MATH_XOR_A_H:Math_Xor_A_R(_RH_A); break;
   case OP_MATH_XOR_A_L:Math_Xor_A_R(_RL_A); break;
   case OP_MATH_XOR_N_A:Math_Xor_A_R(_RAM[_RPC + 1]); break;
   case OP_MATH_XOR_HL_A:Math_Xor_A_R(_RAM[HLasWord()]); break;

   case OP_MATH_CP_A_A:Math_Cp_A_R(_RA_A); break;
   case OP_MATH_CP_A_B:Math_Cp_A_R(_RB_A); break;
   case OP_MATH_CP_A_C:Math_Cp_A_R(_RC_A); break;
   case OP_MATH_CP_A_D:Math_Cp_A_R(_RD_A); break;
   case OP_MATH_CP_A_E:Math_Cp_A_R(_RE_A); break;
   case OP_MATH_CP_A_H:Math_Cp_A_R(_RH_A); break;
   case OP_MATH_CP_A_L:Math_Cp_A_R(_RL_A); break;
   case OP_MATH_CP_N_A:Math_Cp_A_R(_RAM[_RPC + 1]); break;
   case OP_MATH_CP_HL_A:Math_Cp_A_R(_RAM[HLasWord()]); break;

   case OP_MATH_INC_A_A:_RA_A = Math_Inc_Byte(_RA_A); break;
   case OP_MATH_INC_A_B:_RB_A = Math_Inc_Byte(_RB_A); break;
   case OP_MATH_INC_A_C:_RC_A = Math_Inc_Byte(_RC_A); break;
   case OP_MATH_INC_A_D:_RD_A = Math_Inc_Byte(_RD_A); break;
   case OP_MATH_INC_A_E:_RE_A = Math_Inc_Byte(_RE_A); break;
   case OP_MATH_INC_A_H:_RH_A = Math_Inc_Byte(_RH_A); break;
   case OP_MATH_INC_A_L:_RL_A = Math_Inc_Byte(_RL_A); break;
   case OP_MATH_INC_HL_A:_RAM[HLasWord()] = Math_Inc_Byte(_RAM[HLasWord()]); break;

   case OP_MATH_DEC_A_A:_RA_A = Math_Dec_Byte(_RA_A); break;
   case OP_MATH_DEC_A_B:_RB_A = Math_Dec_Byte(_RB_A); break;
   case OP_MATH_DEC_A_C:_RC_A = Math_Dec_Byte(_RC_A); break;
   case OP_MATH_DEC_A_D:_RD_A = Math_Dec_Byte(_RD_A); break;
   case OP_MATH_DEC_A_E:_RE_A = Math_Dec_Byte(_RE_A); break;
   case OP_MATH_DEC_A_H:_RH_A = Math_Dec_Byte(_RH_A); break;
   case OP_MATH_DEC_A_L:_RL_A = Math_Dec_Byte(_RL_A); break;
   case OP_MATH_DEC_HL_A:_RAM[HLasWord()] = Math_Dec_Byte(_RAM[HLasWord()]); break;

   case OP_CPL:
   {
			   _RA_A = ~_RA_A;
			   SetFlag(1, FLAG_H);
			   SetFlag(1, FLAG_N);
   }
	break;
   case OP_CCF:
   {
			   SetFlag(GetFlag(FLAG_C) == 0, FLAG_C);
			   SetFlag(0, FLAG_N);
   }
	break;
   case OP_SCF:
   {
			   SetFlag(1, FLAG_C);
			   SetFlag(0, FLAG_N);
			   SetFlag(0, FLAG_H);
   }
	break;
   case OP_DI:
   {
			  _IFF1 = 0;
			  _IFF2 = 0;
   }
	break;
   case OP_EI:
   {
			  _IFF1 = 1;
			  _IFF2 = 1;
   }
	break;

   case OP_MATH_ADD_BC_HL: Math_Add_SS_HL(BCasWord(), 0); break;
   case OP_MATH_ADD_DE_HL: Math_Add_SS_HL(DEasWord(), 0); break;
   case OP_MATH_ADD_HL_HL: Math_Add_SS_HL(HLasWord(), 0); break;
   case OP_MATH_ADD_SP_HL: Math_Add_SS_HL(_RSP, 0); break;

   case OP_MATH_INC_BC:
   {
					   word newValue = BCasWord() + 1;
					   _RB_A = (newValue >> (8 * 1)) & 0xff;
					   _RC_A = (newValue >> (8 * 0)) & 0xff;
   }
	break;
   case OP_MATH_INC_DE:
   {
					   word newValue = DEasWord() + 1;
					   _RD_A = (newValue >> (8 * 1)) & 0xff;
					   _RE_A = (newValue >> (8 * 0)) & 0xff;
   }
	break;
   case OP_MATH_INC_HL:
   {
					   word newValue = HLasWord() + 1;
					   _RH_A = (newValue >> (8 * 1)) & 0xff;
					   _RL_A = (newValue >> (8 * 0)) & 0xff;
   }
	break;
   case OP_MATH_INC_SP:_RSP++; break;

   case OP_MATH_DEC_BC:
   {
					   word newValue = BCasWord() - 1;
					   _RB_A = (newValue >> (8 * 1)) & 0xff;
					   _RC_A = (newValue >> (8 * 0)) & 0xff;
   }
	break;
   case OP_MATH_DEC_DE:
   {
					   word newValue = DEasWord() - 1;
					   _RB_A = (newValue >> (8 * 1)) & 0xff;
					   _RC_A = (newValue >> (8 * 0)) & 0xff;
   }
	break;
   case OP_MATH_DEC_HL:
   {
					   word newValue = HLasWord() - 1;
					   _RB_A = (newValue >> (8 * 1)) & 0xff;
					   _RC_A = (newValue >> (8 * 0)) & 0xff;
   }
	break;
   case OP_MATH_DEC_SP:_RSP--; break;
   case OP_CR_CALL:
   {
				   word newRPC = _RAM[_RPC + 2] << 8 | _RAM[_RPC + 1];
				   _RPC += 3;
				   Stack_Push_Word(_RPC);
				   _RPC = newRPC;
				   opcost = 0;
   }
	break;
   case OP_JR_NZ_E:
   {
				   if (GetFlag(FLAG_Z) == 0)
				   {
					_RPC += _RAM[_RPC + 1];
				   }
   }
	break;
   case OP_RST_38H:
   {
				   Stack_Push_Word(_RPC);
				   _RPC = 0x38;
				   opcost=0;
   }
	break;
   case OP_RET: _RPC = Stack_Pop_Word(); break;
   case OP_RET_NZ: if (GetFlag(FLAG_Z) == 0)_RPC = Stack_Pop_Word(); break;
   case OP_RET_Z: if (GetFlag(FLAG_Z) != 0)_RPC = Stack_Pop_Word(); break;
   case OP_RET_NC: if (GetFlag(FLAG_C) == 0)_RPC = Stack_Pop_Word(); break;
   case OP_RET_C: if (GetFlag(FLAG_C) != 0)_RPC = Stack_Pop_Word(); break;
   case OP_RET_PO: if (GetFlag(FLAG_P) == 0)_RPC = Stack_Pop_Word(); break;
   case OP_RET_PE: if (GetFlag(FLAG_P) != 0)_RPC = Stack_Pop_Word(); break;
   case OP_RET_P: if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) == 0)_RPC = Stack_Pop_Word(); break;
   case OP_RET_N: if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) != 0)_RPC = Stack_Pop_Word(); break;

   case OP_RAS_RLCA:
   {
					int hbit = (_RA_A % 0x80) != 0;
					_RA_A = _RA_A << 1;
					if (hbit)_RA_A |= 0x01;
   }
	break;
   case OP_RAS_JR_C_E:
   {
					  if (GetFlag(FLAG_C) != 0){
					   byte jump = _RAM[_RPC + 1];
					   signed char tc = jump;
					   _RPC += jump;
					  }
   }
	break;
   case OP_RAS_CB:
   {
				  switch (_RAM[_RPC + 1]){
				   default:
				   {
						   printf("Unkown opcode CB : %i \n", _RAM[_RPC + 1]);
				   }
				  }
   }
	break;

   default:
   {
		   printf("Unkown opcode %i \n", _RAM[_RPC]);
   }
  }

  _RPC += opcost;

 }

 printf("STOPPED\n");
 PostTest();

 getchar();

 return 0;
}