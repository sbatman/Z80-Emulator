#include "Types.h"
#include "Registers.h"
#include "Ram.h"
#include "Opcodes.h"
#include "CounterStep.h"
#include "Math.h"
#include "RAS.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void Init()
{
	printf("INIT\n");
	ZeroRegisters();
	BuildPairtyLookupTable();
	ZeroRam();
	InitCounterStep();
}

void PrintStatus(byte currentOpcode, double ips)
{
	printf("IPS: %f\n", ips);
	printf("Current Addresss : %x \n", _RPC);
	printf("Current OpCode : %x \n", currentOpcode);
	printf("Current Stack Pointer : %x \n", _RSP);
	printf("_A%*x\n", BYTEWIDTH, _RA_A);
	printf("_B%*x\n", BYTEWIDTH, _RB_A);
	printf("_C%*x\n", BYTEWIDTH, _RC_A);
	printf("_D%*x\n", BYTEWIDTH, _RD_A);
	printf("_E%*x\n", BYTEWIDTH, _RE_A);
	printf("_H%*x\n", BYTEWIDTH, _RH_A);
	printf("_L%*x\n\n", BYTEWIDTH, _RL_A);
	printf("F_S%*i\n", BYTEWIDTH, GetFlag(FLAG_S));
	printf("F_Z%*i\n", BYTEWIDTH, GetFlag(FLAG_Z));
	printf("F_H%*i\n", BYTEWIDTH, GetFlag(FLAG_H));
	printf("F_P%*i\n", BYTEWIDTH, GetFlag(FLAG_P));
	printf("F_N%*i\n", BYTEWIDTH, GetFlag(FLAG_N));
	printf("F_C%*i\n", BYTEWIDTH, GetFlag(FLAG_C));
}

void JumpToAddress(byte h, byte l)
{
	uint32_t position = h << BYTEWIDTH | l;
	_RPC = position;
}

void JumpToAddressAtAddress(byte h, byte l)
{
	uint32_t position = h << BYTEWIDTH | l;
	_RPC = _RAM[position];
}

uint32_t main()
{
	long long startTime = clock() - 1;
	long long Instructions = 0;
	long long DrawConsoleUpdate = 0;
	Init();
	printf("START\n");
	LoadRomFromFile("Roms/TestGraphicsMemory.bin");
	while (true)
	{
		uint32_t next = _RAM[_RPC];
		if (DrawConsoleUpdate > 1000000)
		{
			DrawConsoleUpdate = 0;
#ifdef _WIN32
			system("cls");
#else
			system("clear");
#endif
			float ips = Instructions / static_cast<float>(((clock() - startTime) / CLOCKS_PER_SEC));
			PrintStatus(next, ips);
		}
		uint32_t opcost = CounterStep[next];
		Instructions++;
		DrawConsoleUpdate++;
		switch (next)
		{
			case OP_NOP:				break;
			case OP_LD_A_A:	_RA_A = _RA_A;	break;
			case OP_LD_B_A:	_RA_A = _RB_A;	break;
			case OP_LD_C_A:	_RA_A = _RC_A;	break;
			case OP_LD_D_A:	_RA_A = _RD_A;	break;
			case OP_LD_E_A:	_RA_A = _RE_A;	break;
			case OP_LD_H_A:	_RA_A = _RH_A;	break;
			case OP_LD_L_A:	_RA_A = _RL_A;	break;
			case OP_LD_A_B:	_RB_A = _RA_A;	break;
			case OP_LD_B_B:	_RB_A = _RB_A;	break;
			case OP_LD_C_B:	_RB_A = _RC_A;	break;
			case OP_LD_D_B:	_RB_A = _RD_A;	break;
			case OP_LD_E_B:	_RB_A = _RE_A;	break;
			case OP_LD_H_B:	_RB_A = _RH_A;	break;
			case OP_LD_L_B:	_RB_A = _RL_A;	break;
			case OP_LD_A_C:	_RC_A = _RA_A;	break;
			case OP_LD_B_C:	_RC_A = _RB_A;	break;
			case OP_LD_C_C:	_RC_A = _RC_A;	break;
			case OP_LD_D_C:	_RC_A = _RD_A;	break;
			case OP_LD_E_C:	_RC_A = _RE_A;	break;
			case OP_LD_H_C:	_RC_A = _RH_A;	break;
			case OP_LD_L_C:	_RC_A = _RL_A;	break;
			case OP_LD_A_D:	_RD_A = _RA_A;	break;
			case OP_LD_B_D:	_RD_A = _RB_A;	break;
			case OP_LD_C_D:	_RD_A = _RC_A;	break;
			case OP_LD_D_D:	_RD_A = _RD_A;	break;
			case OP_LD_E_D:	_RD_A = _RE_A;	break;
			case OP_LD_H_D:	_RD_A = _RH_A;	break;
			case OP_LD_L_D:	_RD_A = _RL_A;	break;
			case OP_LD_A_E:	_RE_A = _RA_A;	break;
			case OP_LD_B_E:	_RE_A = _RB_A;	break;
			case OP_LD_C_E:	_RE_A = _RC_A;	break;
			case OP_LD_D_E:	_RE_A = _RD_A;	break;
			case OP_LD_E_E:	_RE_A = _RE_A;	break;
			case OP_LD_H_E:	_RE_A = _RH_A;	break;
			case OP_LD_L_E:	_RE_A = _RL_A;	break;
			case OP_LD_A_H:	_RH_A = _RA_A;	break;
			case OP_LD_B_H:	_RH_A = _RB_A;	break;
			case OP_LD_C_H:	_RH_A = _RC_A;	break;
			case OP_LD_D_H:	_RH_A = _RD_A;	break;
			case OP_LD_E_H:	_RH_A = _RE_A;	break;
			case OP_LD_H_H:	_RH_A = _RH_A;	break;
			case OP_LD_L_H:	_RH_A = _RL_A;	break;
			case OP_LD_A_L:	_RL_A = _RA_A;	break;
			case OP_LD_B_L:	_RL_A = _RB_A;	break;
			case OP_LD_C_L:	_RL_A = _RC_A;	break;
			case OP_LD_D_L:	_RL_A = _RD_A;	break;
			case OP_LD_E_L:	_RL_A = _RE_A;	break;
			case OP_LD_H_L:	_RL_A = _RH_A;	break;
			case OP_LD_L_L:	_RL_A = _RL_A;	break;
			case OP_LD_N_A:	_RA_A = _RAM[_RPC + 1];	break;
			case OP_LD_N_B:	_RB_A = _RAM[_RPC + 1];	break;
			case OP_LD_N_C:	_RC_A = _RAM[_RPC + 1];	break;
			case OP_LD_N_D:	_RD_A = _RAM[_RPC + 1];	break;
			case OP_LD_N_E:	_RE_A = _RAM[_RPC + 1];	break;
			case OP_LD_N_H:	_RH_A = _RAM[_RPC + 1];	break;
			case OP_LD_N_L:	_RL_A = _RAM[_RPC + 1];	break;
			case OP_LD_HL_A:	_RA_A = _RAM[HLasWord()];	break;
			case OP_LD_HL_B:	_RB_A = _RAM[HLasWord()];	break;
			case OP_LD_HL_C:	_RC_A = _RAM[HLasWord()];	break;
			case OP_LD_HL_D:	_RD_A = _RAM[HLasWord()];	break;
			case OP_LD_HL_E:	_RE_A = _RAM[HLasWord()];	break;
			case OP_LD_HL_H:	_RH_A = _RAM[HLasWord()];	break;
			case OP_LD_HL_L:	_RL_A = _RAM[HLasWord()];	break;
			case OP_LD_IXD_R:
			{
				byte n = _RAM[_RPC + 2];
				switch (_RAM[_RPC + 1])
				{
					case OP_LD_HL_A: _RA_A = _RAM[_RIX + n];	break;
					case OP_LD_HL_B: _RB_A = _RAM[_RIX + n];	break;
					case OP_LD_HL_C: _RC_A = _RAM[_RIX + n];	break;
					case OP_LD_HL_D: _RD_A = _RAM[_RIX + n];	break;
					case OP_LD_HL_E: _RE_A = _RAM[_RIX + n];	break;
					case OP_LD_HL_H: _RH_A = _RAM[_RIX + n];	break;
					case OP_LD_HL_L: _RL_A = _RAM[_RIX + n];	break;
					case OP_LD_A_HL: _RAM[_RIX + n] = _RA_A;	break;
					case OP_LD_B_HL: _RAM[_RIX + n] = _RB_A;	break;
					case OP_LD_C_HL: _RAM[_RIX + n] = _RC_A;	break;
					case OP_LD_D_HL: _RAM[_RIX + n] = _RD_A;	break;
					case OP_LD_E_HL: _RAM[_RIX + n] = _RE_A;	break;
					case OP_LD_H_HL: _RAM[_RIX + n] = _RH_A;	break;
					case OP_LD_L_HL: _RAM[_RIX + n] = _RL_A;	break;
					case OP_LD_N_HL: _RAM[_RIX + n] = _RAM[_RPC + 3];	opcost = 4;	break;
					case OP_LD_NN_HL:_RIX = ReadWordAtAddress(_RPC + 2);	opcost = 4;	break;
					case OP_LD_NN_HL_M:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RIX = _RAM[position + 1] << BYTEWIDTH | _RAM[position];
						opcost = 4;
					}
					break;
					case OP_LD_HL_NN:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RAM[position] = (_RIX >> BYTEWIDTH) & MAXBYTE;
						_RAM[position + 1] = (_RIX) & MAXBYTE;
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
						Stack_Push_Word(_RIX);
						opcost = 2;
					}
					break;
					case OP_SK_POP_HL:
					{
						_RIX=Stack_Pop_Word();
						opcost = 2;
					}
					break;
					case OP_ETS_E_HL_SP:
					{
						WriteWordAtAddress(_RSP, _RIX);
						opcost = 2;
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
					case OP_MATH_DEC_HL_A:Math_Dec_Byte(_RAM[_RIX + n]); opcost = 3; break;
					case OP_MATH_ADD_BC_IX: Math_Add_PP_IX(BCasWord(), 0); opcost = 2; break;
					case OP_MATH_ADD_DE_IX: Math_Add_PP_IX(DEasWord(), 0); opcost = 2; break;
					case OP_MATH_ADD_IX_IX:Math_Add_PP_IX(_RIX, 0); opcost = 2; break;
					case OP_MATH_ADD_SP_IX:Math_Add_PP_IX(_RSP, 0); opcost = 2; break;
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
					case OP_LD_HL_A:
						_RA_A = _RAM[_RIY + n];
						break;
					case OP_LD_HL_B:
						_RB_A = _RAM[_RIY + n];
						break;
					case OP_LD_HL_C:
						_RC_A = _RAM[_RIY + n];
						break;
					case OP_LD_HL_D:
						_RD_A = _RAM[_RIY + n];
						break;
					case OP_LD_HL_E:
						_RE_A = _RAM[_RIY + n];
						break;
					case OP_LD_HL_H:
						_RH_A = _RAM[_RIY + n];
						break;
					case OP_LD_HL_L:
						_RL_A = _RAM[_RIY + n];
						break;
					case OP_LD_A_HL:
						_RAM[_RIY + n] = _RA_A;
						break;
					case OP_LD_B_HL:
						_RAM[_RIY + n] = _RB_A;
						break;
					case OP_LD_C_HL:
						_RAM[_RIY + n] = _RC_A;
						break;
					case OP_LD_D_HL:
						_RAM[_RIY + n] = _RD_A;
						break;
					case OP_LD_E_HL:
						_RAM[_RIY + n] = _RE_A;
						break;
					case OP_LD_H_HL:
						_RAM[_RIY + n] = _RH_A;
						break;
					case OP_LD_L_HL:
						_RAM[_RIY + n] = _RL_A;
						break;
					case OP_LD_N_HL:
					{
						_RAM[_RIY + n] = _RAM[_RPC + 3];
						opcost = 4;
					}
					break;
					case OP_LD_NN_HL:
					{
						_RIY = _RAM[_RPC + 3] << BYTEWIDTH | _RAM[_RPC + 2];
						opcost = 4;
					}
					break;
					case OP_LD_NN_HL_M:
					{
						uint32_t position = _RAM[_RPC + 3] << BYTEWIDTH | _RAM[_RPC + 2];
						_RIY = _RAM[position + 1] << BYTEWIDTH | _RAM[position];
						opcost = 4;
					}
					break;
					case OP_LD_HL_NN:
					{
						uint32_t position = _RAM[_RPC + 3] << BYTEWIDTH | _RAM[_RPC + 2];
						_RAM[position] = (_RIY >> BYTEWIDTH) & MAXBYTE;
						_RAM[position + 1] = (_RIY) & MAXBYTE;
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
						Stack_Push_Word(_RIY);
						opcost = 2;
					}
					break;
					case OP_SK_POP_HL:
					{
						_RIY = Stack_Pop_Word();
						opcost = 2;
					}
					break;
					case OP_ETS_E_HL_SP:
						WriteWordAtAddress(_RSP, _RIY);
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
			case OP_LD_A_HL:	WriteByteAtAddress(HLasWord(), _RA_A);	break;
			case OP_LD_B_HL:	WriteByteAtAddress(HLasWord(), _RB_A);	break;
			case OP_LD_C_HL:	WriteByteAtAddress(HLasWord(), _RC_A);	break;
			case OP_LD_D_HL:	WriteByteAtAddress(HLasWord(), _RD_A);	break;
			case OP_LD_E_HL:	WriteByteAtAddress(HLasWord(), _RE_A);	break;
			case OP_LD_H_HL:	WriteByteAtAddress(HLasWord(), _RH_A);	break;
			case OP_LD_L_HL:	WriteByteAtAddress(HLasWord(), _RL_A);	break;
			case OP_LD_N_HL:	WriteByteAtAddress(HLasWord(), _RAM[_RPC + 1]);	break;
			case OP_LD_BC_A:	_RA_A = ReadByteAtAddress(BCasWord());	break;
			case OP_LD_DE_A:	_RA_A = ReadByteAtAddress(DEasWord());	break;
			case OP_LD_NN_A:	_RA_A = ReadByteAtAddress(BytesToWord(_RPC + 2, _RPC + 1));	break;
			case OP_LD_A_BC:	WriteByteAtAddress(BCasWord(), _RA_A);	break;
			case OP_LD_A_DE:	WriteByteAtAddress(DEasWord(), _RA_A);	break;
			case OP_LD_A_NN:	WriteByteAtAddress(BytesToWord(_RPC + 2, _RPC + 1), _RA_A);	break;
			case OP_LD_ED:
			{
				switch (_RAM[_RPC + 1])
				{
					case OP_LD_I_A:
						_RA_A = _RIV;
						SetFlag(((_RA_A & 0x80) != 0), FLAG_S);
						SetFlag((_RA_A == 0), FLAG_Z);
						SetFlag(0, FLAG_H);
						SetFlag(_IFF2, FLAG_P);
						SetFlag(0, FLAG_N);
						break;
					case OP_LD_R_A:
						_RA_A = _RMR;
						SetFlag(((_RA_A & 0x80) != 0), FLAG_S);
						SetFlag((_RA_A == 0), FLAG_Z);
						SetFlag(0, FLAG_H);
						SetFlag(_IFF2, FLAG_P);
						SetFlag(0, FLAG_N);
						break;
					case OP_LD_A_I:
						_RIV = _RA_A;
						break;
					case OP_LD_A_R:
						_RMR = _RA_A;
						break;
					case OP_LD_NN_DD_BC:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RB_A = _RAM[position + 1];
						_RC_A = _RAM[position];
						opcost = 4;
					}
					break;
					case OP_LD_NN_DD_DE:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RD_A = _RAM[position + 1];
						_RE_A = _RAM[position];
						opcost = 4;
					}
					break;
					case OP_LD_NN_DD_HL:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RH_A = _RAM[position + 1];
						_RL_A = _RAM[position];
						opcost = 4;
					}
					break;
					case OP_LD_NN_DD_SP:
					{
						_RSP = ReadWordAtAddress(_RPC + 2);
						opcost = 4;
					}
					break;
					case OP_LD_DD_NN_BC:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), BCasWord());
						opcost = 4;
					}
					break;
					case OP_LD_DD_NN_DE:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), DEasWord());
						opcost = 4;
					}
					break;
					case OP_LD_DD_NN_HL:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), HLasWord());
						opcost = 4;
					}
					break;
					case OP_LD_DD_NN_SP:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), _RSP);
						opcost = 4;
					}
					break;
					case OP_ETS_LDI:
					{
						_RAM[DEasWord()] = _RAM[HLasWord()];
						IncrementHL();
						IncrementDE();
						DecrementBC();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						opcost = 2;
					}
					break;
					case OP_ETS_LDIR:
					{
						uint32_t iterations = BCasWord();
						if (iterations == 0)iterations = 64;
						while (iterations != 0)
						{
							iterations--;
							_RAM[DEasWord()] = _RAM[HLasWord()];
							IncrementHL();
							IncrementDE();
							DecrementBC();
							Instructions++;
						}
						SetFlag((BCasWord() != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						opcost = 2;
					}
					break;
					case OP_ETS_LDD:
					{
						_RAM[DEasWord()] = _RAM[HLasWord()];
						DecrementHL();
						DecrementDE();
						DecrementBC();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						opcost = 2;
					}
					break;
					case OP_ETS_LDDR:
					{
						_RAM[DEasWord()] = _RAM[HLasWord()];
						DecrementHL();
						DecrementDE();
						DecrementBC();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						opcost = 2;
						if ((BCasWord() - 1 != 0))_RPC -= 2;
					}
					break;
					case OP_ETS_CPI:
					{
						if (_RAM[HLasWord()] == _RA_A)
							SetFlag(1, FLAG_Z);
						else
							SetFlag(0, FLAG_Z);
						DecrementBC();
						IncrementHL();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						SetFlag(0, FLAG_S);
						opcost = 2;
					}
					break;
					case OP_ETS_CPIR:
					{
						bool condition = _RAM[HLasWord()] == _RA_A;
						SetFlag(condition, FLAG_Z);
						DecrementBC();
						IncrementHL();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						SetFlag(0, FLAG_S);
						opcost = 2;
						if (condition && (BCasWord() - 1 != 0))
							_RPC -= 2;
					}
					break;
					case OP_ETS_CPD:
					{
						SetFlag(_RAM[HLasWord()] == _RA_A, FLAG_Z);
						DecrementBC();
						DecrementHL();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						SetFlag(0, FLAG_S);
						opcost = 2;
					}
					break;
					case OP_ETS_CPDR:
					{
						bool condition = _RAM[HLasWord()] == _RA_A;
						SetFlag(condition, FLAG_Z);
						DecrementBC();
						DecrementHL();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						SetFlag(0, FLAG_S);
						opcost = 2;
						if (condition && (BCasWord() - 1 != 0))
							_RPC -= 2;
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
					case OP_MATH_ADC_BC_HL:	Math_Add_SS_HL(BCasWord(), 1);	break;
					case OP_MATH_ADC_DE_HL:	Math_Add_SS_HL(DEasWord(), 1);	break;
					case OP_MATH_ADC_HL_HL:	Math_Add_SS_HL(HLasWord(), 1);	break;
					case OP_MATH_ADC_SP_HL:	Math_Add_SS_HL(_RSP, 1);	break;
					case OP_ED_IM_1:	_InterruptMode = 1;	break;
					case OP_MATH_SBC_HL_BC:	Math_Sub_SS_HL(BCasWord() + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_MATH_SBC_HL_DE:	Math_Sub_SS_HL(DEasWord() + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_MATH_SBC_HL_HL:	Math_Sub_SS_HL(HLasWord() + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_MATH_SBC_HL_SP:	Math_Sub_SS_HL(_RSP + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_IO_IN_C_A:	break;
					default:
					{
						printf("Unkown opcode ED : %i \n", _RAM[_RPC + 1]);
					}
				}
			}
			break;
			case  OP_LD_NN_BC:
				_RB_A = _RAM[_RPC + 2];
				_RC_A = _RAM[_RPC + 1];
				break;
			case  OP_LD_NN_DE:
				_RD_A = _RAM[_RPC + 2];
				_RE_A = _RAM[_RPC + 1];
				break;
			case  OP_LD_NN_HL:
				_RH_A = _RAM[_RPC + 2];
				_RL_A = _RAM[_RPC + 1];
				break;
			case  OP_LD_NN_SP:
				_RSP = ReadWordAtAddress(_RPC + 1);
				break;
			case OP_LD_NN_HL_M:
			{
				uint32_t position = ReadWordAtAddress(_RPC + 1);
				_RH_A = _RAM[position + 1];
				_RL_A = _RAM[position];
			}
			break;
			case OP_LD_HL_NN:
			{
				uint32_t position = ReadWordAtAddress(_RPC + 1);
				_RAM[position] = _RL_A;
				_RAM[position + 1] = _RH_A;
			}
			break;
			case OP_LD_HL_SP:
				_RSP = HLasWord();
				break;
			case OP_SK_PUSH_BC:
				Stack_Push_Word(BCasWord());
				break;
			case OP_SK_PUSH_DE:
				Stack_Push_Word(DEasWord());
				break;
			case OP_SK_PUSH_HL:
				Stack_Push_Word(HLasWord());
				break;
			case OP_SK_PUSH_AF:
				Stack_Push_Word(AFasWord());
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
				byte low = _RAM[_RSP];
				byte high = _RAM[_RSP + 1];
				_RAM[_RSP] = _RL_A;
				_RAM[_RSP + 1] = _RH_A;
				_RL_A = low;
				_RH_A = high;
			}
			break;
			case OP_MATH_ADD_A_A:	Math_Add_A_R(_RA_A, 0);	break;
			case OP_MATH_ADD_B_A:	Math_Add_A_R(_RB_A, 0);	break;
			case OP_MATH_ADD_C_A:	Math_Add_A_R(_RC_A, 0);	break;
			case OP_MATH_ADD_D_A:	Math_Add_A_R(_RD_A, 0);	break;
			case OP_MATH_ADD_E_A:	Math_Add_A_R(_RE_A, 0);	break;
			case OP_MATH_ADD_H_A:	Math_Add_A_R(_RH_A, 0);	break;
			case OP_MATH_ADD_L_A:	Math_Add_A_R(_RL_A, 0);	break;
			case OP_MATH_ADD_N_A:	Math_Add_A_R(_RAM[_RPC + 1], 0);	break;
			case OP_MATH_ADD_HL_A:	Math_Add_A_R(_RAM[HLasWord()], 0);	break;
			case OP_MATH_ADC_A_A:	Math_Add_A_R(_RA_A, 1);	break;
			case OP_MATH_ADC_B_A:	Math_Add_A_R(_RB_A, 1); break;
			case OP_MATH_ADC_C_A:	Math_Add_A_R(_RC_A, 1);	break;
			case OP_MATH_ADC_D_A:	Math_Add_A_R(_RD_A, 1);	break;
			case OP_MATH_ADC_E_A:	Math_Add_A_R(_RE_A, 1);	break;
			case OP_MATH_ADC_H_A:	Math_Add_A_R(_RH_A, 1);	break;
			case OP_MATH_ADC_L_A:	Math_Add_A_R(_RL_A, 1);	break;
			case OP_MATH_ADC_N_A:	Math_Add_A_R(_RAM[_RPC + 1], 1);	break;
			case OP_MATH_ADC_HL_A:	Math_Add_A_R(_RAM[HLasWord()], 1);	break;
			case OP_MATH_SUB_A_A:	Math_Sub_A_R(_RA_A, 0);	break;
			case OP_MATH_SUB_A_B:	Math_Sub_A_R(_RB_A, 0);	break;
			case OP_MATH_SUB_A_C:	Math_Sub_A_R(_RC_A, 0);	break;
			case OP_MATH_SUB_A_D:	Math_Sub_A_R(_RD_A, 0);	break;
			case OP_MATH_SUB_A_E:	Math_Sub_A_R(_RE_A, 0);	break;
			case OP_MATH_SUB_A_H:	Math_Sub_A_R(_RH_A, 0);	break;
			case OP_MATH_SUB_A_L:	Math_Sub_A_R(_RL_A, 0);	break;
			case OP_MATH_SUB_N_A:	Math_Sub_A_R(_RAM[_RPC + 1], 0);	break;
			case OP_MATH_SUB_HL_A:	Math_Sub_A_R(_RAM[HLasWord()], 0);	break;
			case OP_MATH_SBC_A_A:	Math_Sub_A_R(_RA_A, 1);	break;
			case OP_MATH_SBC_A_B:	Math_Sub_A_R(_RB_A, 1);	break;
			case OP_MATH_SBC_A_C:	Math_Sub_A_R(_RC_A, 1);	break;
			case OP_MATH_SBC_A_D:	Math_Sub_A_R(_RD_A, 1);	break;
			case OP_MATH_SBC_A_E:	Math_Sub_A_R(_RE_A, 1);	break;
			case OP_MATH_SBC_A_H:	Math_Sub_A_R(_RH_A, 1);	break;
			case OP_MATH_SBC_A_L:	Math_Sub_A_R(_RL_A, 1);	break;
			case OP_MATH_SBC_N_A:	Math_Sub_A_R(_RAM[_RPC + 1], 1);	break;
			case OP_MATH_SBC_HL_A:	Math_Sub_A_R(_RAM[HLasWord()], 1);	break;
			case OP_MATH_AND_A_A:	Math_And_A_R(_RA_A);	break;
			case OP_MATH_AND_A_B:	Math_And_A_R(_RB_A);	break;
			case OP_MATH_AND_A_C:	Math_And_A_R(_RC_A);	break;
			case OP_MATH_AND_A_D:	Math_And_A_R(_RD_A);	break;
			case OP_MATH_AND_A_E:	Math_And_A_R(_RE_A);	break;
			case OP_MATH_AND_A_H:	Math_And_A_R(_RH_A);	break;
			case OP_MATH_AND_A_L:	Math_And_A_R(_RL_A);	break;
			case OP_MATH_AND_N_A:	Math_And_A_R(_RAM[_RPC + 1]);	break;
			case OP_MATH_AND_HL_A:	Math_And_A_R(_RAM[HLasWord()]);	break;
			case OP_MATH_OR_A_A:	Math_Or_A_R(_RA_A);	break;
			case OP_MATH_OR_A_B:	Math_Or_A_R(_RB_A);	break;
			case OP_MATH_OR_A_C:	Math_Or_A_R(_RC_A);	break;
			case OP_MATH_OR_A_D:	Math_Or_A_R(_RD_A);	break;
			case OP_MATH_OR_A_E:	Math_Or_A_R(_RE_A);	break;
			case OP_MATH_OR_A_H:	Math_Or_A_R(_RH_A);	break;
			case OP_MATH_OR_A_L:	Math_Or_A_R(_RL_A);	break;
			case OP_MATH_OR_N_A:	Math_Or_A_R(_RAM[_RPC + 1]);	break;
			case OP_MATH_OR_HL_A:	Math_Or_A_R(_RAM[HLasWord()]);	break;
			case OP_MATH_XOR_A_A:	Math_Xor_A_R(_RA_A);	break;
			case OP_MATH_XOR_A_B:	Math_Xor_A_R(_RB_A);	break;
			case OP_MATH_XOR_A_C:	Math_Xor_A_R(_RC_A);	break;
			case OP_MATH_XOR_A_D:	Math_Xor_A_R(_RD_A);	break;
			case OP_MATH_XOR_A_E:	Math_Xor_A_R(_RE_A);	break;
			case OP_MATH_XOR_A_H:	Math_Xor_A_R(_RH_A);	break;
			case OP_MATH_XOR_A_L:	Math_Xor_A_R(_RL_A);	break;
			case OP_MATH_XOR_N_A:	Math_Xor_A_R(_RAM[_RPC + 1]);	break;
			case OP_MATH_XOR_HL_A:	Math_Xor_A_R(_RAM[HLasWord()]);	break;
			case OP_MATH_CP_A_A:	Math_Cp_A_R(_RA_A);	break;
			case OP_MATH_CP_A_B:	Math_Cp_A_R(_RB_A);	break;
			case OP_MATH_CP_A_C:	Math_Cp_A_R(_RC_A);	break;
			case OP_MATH_CP_A_D:	Math_Cp_A_R(_RD_A);	break;
			case OP_MATH_CP_A_E:	Math_Cp_A_R(_RE_A);	break;
			case OP_MATH_CP_A_H:	Math_Cp_A_R(_RH_A);	break;
			case OP_MATH_CP_A_L:	Math_Cp_A_R(_RL_A);	break;
			case OP_MATH_CP_N_A:	Math_Cp_A_R(_RAM[_RPC + 1]); break;
			case OP_MATH_CP_HL_A:	Math_Cp_A_R(_RAM[HLasWord()]);	break;
			case OP_MATH_INC_A_A:	_RA_A = Math_Inc_Byte(_RA_A);	break;
			case OP_MATH_INC_A_B:	_RB_A = Math_Inc_Byte(_RB_A);	break;
			case OP_MATH_INC_A_C:	_RC_A = Math_Inc_Byte(_RC_A);	break;
			case OP_MATH_INC_A_D:	_RD_A = Math_Inc_Byte(_RD_A);	break;
			case OP_MATH_INC_A_E:	_RE_A = Math_Inc_Byte(_RE_A);	break;
			case OP_MATH_INC_A_H:	_RH_A = Math_Inc_Byte(_RH_A);	break;
			case OP_MATH_INC_A_L:	_RL_A = Math_Inc_Byte(_RL_A);	break;
			case OP_MATH_INC_HL_A:	_RAM[HLasWord()] = Math_Inc_Byte(_RAM[HLasWord()]);	break;
			case OP_MATH_DEC_A_A:	_RA_A = Math_Dec_Byte(_RA_A);	break;
			case OP_MATH_DEC_A_B:	_RB_A = Math_Dec_Byte(_RB_A);	break;
			case OP_MATH_DEC_A_C:	_RC_A = Math_Dec_Byte(_RC_A);	break;
			case OP_MATH_DEC_A_D:	_RD_A = Math_Dec_Byte(_RD_A);	break;
			case OP_MATH_DEC_A_E:	_RE_A = Math_Dec_Byte(_RE_A);	break;
			case OP_MATH_DEC_A_H:	_RH_A = Math_Dec_Byte(_RH_A);	break;
			case OP_MATH_DEC_A_L:	_RL_A = Math_Dec_Byte(_RL_A);	break;
			case OP_MATH_DEC_HL_A:	_RAM[HLasWord()] = Math_Dec_Byte(_RAM[HLasWord()]);		break;
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
			case OP_EI:	_IFF1 = 1;	_IFF2 = 1;	break;
			case OP_MATH_ADD_BC_HL:	Math_Add_SS_HL(BCasWord(), 0);	break;
			case OP_MATH_ADD_DE_HL:	Math_Add_SS_HL(DEasWord(), 0);	break;
			case OP_MATH_ADD_HL_HL:	Math_Add_SS_HL(HLasWord(), 0);	break;
			case OP_MATH_ADD_SP_HL:	Math_Add_SS_HL(_RSP, 0);		break;
			case OP_MATH_INC_BC:
			{
				word newValue = BCasWord() + 1;
				_RB_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RC_A = (newValue) & MAXBYTE;
			}
			break;
			case OP_MATH_INC_DE:
			{
				word newValue = DEasWord() + 1;
				_RD_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RE_A = (newValue) & MAXBYTE;
			}
			break;
			case OP_MATH_INC_HL:
			{
				word newValue = HLasWord() + 1;
				_RH_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RL_A = (newValue) & MAXBYTE;
			}
			break;
			case OP_MATH_INC_SP:
				_RSP++;
				break;
			case OP_MATH_DEC_BC:
			{
				word newValue = BCasWord() - 1;
				_RB_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RC_A = (newValue) & MAXBYTE;
			}
			break;
			case OP_MATH_DEC_DE:
			{
				word newValue = DEasWord() - 1;
				_RD_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RE_A = (newValue) & MAXBYTE;
			}
			break;
			case OP_MATH_DEC_HL:
			{
				word newValue = HLasWord() - 1;
				_RH_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RL_A = (newValue) & MAXBYTE;
			}
			break;
			case OP_MATH_DEC_SP:
				_RSP--;
				break;
			case OP_CR_CALL:
			{
				word newRPC = ReadWordAtAddress(_RPC + 1);
				_RPC += 3;
				Stack_Push_Word(_RPC);
				_RPC = newRPC;
				opcost = 0;
			}
			break;
			case OP_SK_JR_NZ_E:
				if (GetFlag(FLAG_Z) == 0)	_RPC += _RAM[_RPC + 1];
				break;
			case OP_RST_00H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x00;
				opcost = 0;
			}
			break;
			case OP_RST_08H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x08;
				opcost = 0;
			}
			break;
			case OP_RST_10H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x10;
				opcost = 0;
			}
			break;
			case OP_RST_18H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x18;
				opcost = 0;
			}
			break;
			case OP_RST_20H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x20;
				opcost = 0;
			}
			break;
			case OP_RST_28H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x28;
				opcost = 0;
			}
			break;
			case OP_RST_30H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x30;
				opcost = 0;
			}
			break;
			case OP_RST_38H:
			{
				Stack_Push_Word(_RPC);
				_RPC = 0x38;
				opcost = 0;
			}
			break;
			case OP_RET:
				_RPC = Stack_Pop_Word();
				opcost = 0;
				break;
			case OP_RET_NZ:
				if (GetFlag(FLAG_Z) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_RET_Z:
				if (GetFlag(FLAG_Z) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_RET_NC:
				if (GetFlag(FLAG_C) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_RET_C:
				if (GetFlag(FLAG_C) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_RET_PO:
				if (GetFlag(FLAG_P) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_RET_PE:
				if (GetFlag(FLAG_P) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_RET_P:
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_RET_N:
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_SK_JP:
				JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
				break;
			case OP_SK_JP_NZ:
			{
				if (GetFlag(FLAG_Z) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_SK_JP_Z:
			{
				if (GetFlag(FLAG_Z) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_SK_JP_NC:
			{
				if (GetFlag(FLAG_C) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_SK_JP_C:
			{
				if (GetFlag(FLAG_C) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_SK_JP_PO:
			{
				if (GetFlag(FLAG_P) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_SK_JP_PE:
			{
				if (GetFlag(FLAG_P) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_SK_JP_P:
			{
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_SK_JP_N:
			{
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_RAS_RLCA:
			{
				uint32_t hbit = (_RA_A & 0x80) != 0;
				_RA_A = ((_RA_A << 1) & MAXBYTE);
				if (hbit)_RA_A |= 0x01;
			}
			break;
			case OP_SK_JR_C_E:
			{
				if (GetFlag(FLAG_C) != 0)
				{
					signed char jump = _RAM[_RPC + 1];
					_RPC += jump;
					opcost = 0;
				}
			}
			case OP_SK_JR_NC_E:
			{
				if (GetFlag(FLAG_C) == 0)
				{
					signed char jump = _RAM[_RPC + 1];
					_RPC += jump;
					opcost = 2;
				}
			}
			break;
			case OP_SK_JR_E: _RPC += static_cast<signed char>(_RAM[_RPC + 1]);	break;
			case OP_SK_JR_Z: if (GetFlag(FLAG_Z) != 0)_RPC += static_cast<signed char>(_RAM[_RPC + 1]);	break;
			case OP_SK_DJNZ:
			{
				_RB_A--;
				if (_RB_A != 0) _RPC += static_cast<signed char>(_RAM[_RPC + 1]);
			}
			break;
			case OP_RAS_CB:
			{
				opcost = 2;
				switch (_RAM[_RPC + 1])
				{
					case OP_RAS_RL_A:	_RA_A = RAS_RL(_RA_A);	break;
					case OP_RAS_RL_B:	_RB_A = RAS_RL(_RB_A);	break;
					case OP_RAS_RL_C:	_RC_A = RAS_RL(_RC_A);	break;
					case OP_RAS_RL_D:	_RD_A = RAS_RL(_RD_A);	break;
					case OP_RAS_RL_E:	_RE_A = RAS_RL(_RE_A);	break;
					case OP_RAS_RL_H:	_RH_A = RAS_RL(_RH_A);	break;
					case OP_RAS_RL_L:	_RL_A = RAS_RL(_RL_A);	break;
					default:
					{
						printf("Unkown opcode CB : %i \n", _RAM[_RPC + 1]);
					}
				}
			}
			break;
			case OP_RAS_RRC_A:
			{
				SetFlag((_RA_A & 0x01) != 0, FLAG_C);
				_RA_A >>= 1;
				_RA_A |= static_cast<byte>(GetFlag(FLAG_C) << 7);
				SetFlag(0, FLAG_H);
				SetFlag(0, FLAG_N);
			}
			break;
			case OP_RAS_RRA:
			{
				uint32_t currentCFlag = GetFlag(FLAG_C);
				SetFlag((_RA_A & 0x01), FLAG_C);
				_RA_A >>= 1;
				_RA_A |= (currentCFlag << 7);
				SetFlag(0, FLAG_H);
				SetFlag(0, FLAG_N);
			}
			break;
			case OP_RAS_RLA:
				RAS_RLA();
				break;
			case OP_IO_OUT_NA:
			{
				//TODO THIS
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
	PrintStatus(0, 0);
	SaveRamToFile("out.bin");
	getchar();
	return 0;
}