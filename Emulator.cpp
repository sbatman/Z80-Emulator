//-------------------------------
//         --Z80 Emulator--
//
// Created by : Steven Batchelor-Manning
//
// Licence : This work is covered under the Creative Commons 
// Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0) licence
//		
// Source : https://github.com/sbatman/Z80-Emulator
//
// Notes : Not all extended instructions have yet been complete
//         Interrupt support has not been implemented
//
//-------------------------------

#include "Types.h"
#include "Registers.h"
#include "Ram.h"
#include "Opcodes.h"
#include "Counter.h"
#include "Math.h"
#include "RAS.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

///	<summary>
/// Initialises the emulator, zeroing th registers and ram, this also prepares some reference tables
///	</summary>
void Init()
{
	printf("INIT\n");
	ZeroRegisters();
	BuildPairtyLookupTable();
	ZeroRam();
	InitCounterStep();
}

///	<summary>
/// Prints the current status of the enulator
///	</summary>
void PrintStatus(const byte currentOpcode, const  double ips)
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
	int newline = 6;

	for (int y = 0; y < 35; y++)
	{
		for (int x = 0; x < 256; x += 8)
		{
			int newy = y;
			word ramposition = 0x4000;
			word yp1 = (newy << 5) & 0x1800;
			newy = y;
			word yp2 = yp1 | ((newy << 2) & 0xE0);
			newy = y;
			word yp3 = yp2 | ((newy << 8) & 0x700);
			ramposition |= yp3;
			ramposition |= (x / 8);
			if (_RAM[ramposition] == 0x00)
			{
				printf("        ");
			}
			else { for (int i = 0; i < 8; i++)printf((_RAM[ramposition] >> (7 - i)) & 0x01 ? "#" : " "); }
		}
		printf("\n");
	}
}

///	<summary>
/// Jumps to the address provided
///	</summary>
void JumpToAddress(const byte h, const byte l)
{
	uint32_t position = h << BYTEWIDTH | l;
	_RPC = position;
}

///	<summary>
/// Jumps to the address stored in the provided address
///	</summary>
void JumpToAddressAtAddress(const byte h, const  byte l)
{
	uint32_t position = h << BYTEWIDTH | l;
	_RPC = _RAM[position];
}


bool skipper = true;

///	<summary>
///	Program entry point
///	</summary>
uint32_t main()
{
	uint64_t startTime = clock() - 1;
	uint64_t Instructions = 0;
	uint64_t DrawConsoleUpdate = 0;
	Init();
	printf("START\n");
	LoadRomFromFile("Roms/48.bin");
	while (true)
	{

		uint32_t next = _RAM[_RPC];
		if (_RPC == 0x128c)
		{
			int g = 7;
			g = g*g;
		}
		if (DrawConsoleUpdate > (skipper?10000:0))
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

		//The following isnt elegant, but case statements over a limited rage are covered by the compiler
		//to a jump tabble. Long story short, this is one of the quickest way's I have found for interpreting
		//the instruction and executing it

		switch (next)
		{
			case OP_Main::OP_NOP:				break;
			case OP_Load::A_A:	_RA_A = _RA_A;	break;
			case OP_Load::B_A:	_RA_A = _RB_A;	break;
			case OP_Load::C_A:	_RA_A = _RC_A;	break;
			case OP_Load::D_A:	_RA_A = _RD_A;	break;
			case OP_Load::E_A:	_RA_A = _RE_A;	break;
			case OP_Load::H_A:	_RA_A = _RH_A;	break;
			case OP_Load::L_A:	_RA_A = _RL_A;	break;
			case OP_Load::A_B:	_RB_A = _RA_A;	break;
			case OP_Load::B_B:	_RB_A = _RB_A;	break;
			case OP_Load::C_B:	_RB_A = _RC_A;	break;
			case OP_Load::D_B:	_RB_A = _RD_A;	break;
			case OP_Load::E_B:	_RB_A = _RE_A;	break;
			case OP_Load::H_B:	_RB_A = _RH_A;	break;
			case OP_Load::L_B:	_RB_A = _RL_A;	break;
			case OP_Load::A_C:	_RC_A = _RA_A;	break;
			case OP_Load::B_C:	_RC_A = _RB_A;	break;
			case OP_Load::C_C:	_RC_A = _RC_A;	break;
			case OP_Load::D_C:	_RC_A = _RD_A;	break;
			case OP_Load::E_C:	_RC_A = _RE_A;	break;
			case OP_Load::H_C:	_RC_A = _RH_A;	break;
			case OP_Load::L_C:	_RC_A = _RL_A;	break;
			case OP_Load::A_D:	_RD_A = _RA_A;	break;
			case OP_Load::B_D:	_RD_A = _RB_A;	break;
			case OP_Load::C_D:	_RD_A = _RC_A;	break;
			case OP_Load::D_D:	_RD_A = _RD_A;	break;
			case OP_Load::E_D:	_RD_A = _RE_A;	break;
			case OP_Load::H_D:	_RD_A = _RH_A;	break;
			case OP_Load::L_D:	_RD_A = _RL_A;	break;
			case OP_Load::A_E:	_RE_A = _RA_A;	break;
			case OP_Load::B_E:	_RE_A = _RB_A;	break;
			case OP_Load::C_E:	_RE_A = _RC_A;	break;
			case OP_Load::D_E:	_RE_A = _RD_A;	break;
			case OP_Load::E_E:	_RE_A = _RE_A;	break;
			case OP_Load::H_E:	_RE_A = _RH_A;	break;
			case OP_Load::L_E:	_RE_A = _RL_A;	break;
			case OP_Load::A_H:	_RH_A = _RA_A;	break;
			case OP_Load::B_H:	_RH_A = _RB_A;	break;
			case OP_Load::C_H:	_RH_A = _RC_A;	break;
			case OP_Load::D_H:	_RH_A = _RD_A;	break;
			case OP_Load::E_H:	_RH_A = _RE_A;	break;
			case OP_Load::H_H:	_RH_A = _RH_A;	break;
			case OP_Load::L_H:	_RH_A = _RL_A;	break;
			case OP_Load::A_L:	_RL_A = _RA_A;	break;
			case OP_Load::B_L:	_RL_A = _RB_A;	break;
			case OP_Load::C_L:	_RL_A = _RC_A;	break;
			case OP_Load::D_L:	_RL_A = _RD_A;	break;
			case OP_Load::E_L:	_RL_A = _RE_A;	break;
			case OP_Load::H_L:	_RL_A = _RH_A;	break;
			case OP_Load::L_L:	_RL_A = _RL_A;	break;
			case OP_Load::N_A:	_RA_A = _RAM[_RPC + 1];	break;
			case OP_Load::N_B:	_RB_A = _RAM[_RPC + 1];	break;
			case OP_Load::N_C:	_RC_A = _RAM[_RPC + 1];	break;
			case OP_Load::N_D:	_RD_A = _RAM[_RPC + 1];	break;
			case OP_Load::N_E:	_RE_A = _RAM[_RPC + 1];	break;
			case OP_Load::N_H:	_RH_A = _RAM[_RPC + 1];	break;
			case OP_Load::N_L:	_RL_A = _RAM[_RPC + 1];	break;
			case OP_Load::HL_A:	_RA_A = _RAM[HLasWord()];	break;
			case OP_Load::HL_B:	_RB_A = _RAM[HLasWord()];	break;
			case OP_Load::HL_C:	_RC_A = _RAM[HLasWord()];	break;
			case OP_Load::HL_D:	_RD_A = _RAM[HLasWord()];	break;
			case OP_Load::HL_E:	_RE_A = _RAM[HLasWord()];	break;
			case OP_Load::HL_H:	_RH_A = _RAM[HLasWord()];	break;
			case OP_Load::HL_L:	_RL_A = _RAM[HLasWord()];	break;
			case OP_Load::IXD_R:
			{
				byte n = _RAM[_RPC + 2];
				switch (_RAM[_RPC + 1])
				{
					case OP_Load::HL_A: _RA_A = _RAM[_RIX + n];	break;
					case OP_Load::HL_B: _RB_A = _RAM[_RIX + n];	break;
					case OP_Load::HL_C: _RC_A = _RAM[_RIX + n];	break;
					case OP_Load::HL_D: _RD_A = _RAM[_RIX + n];	break;
					case OP_Load::HL_E: _RE_A = _RAM[_RIX + n];	break;
					case OP_Load::HL_H: _RH_A = _RAM[_RIX + n];	break;
					case OP_Load::HL_L: _RL_A = _RAM[_RIX + n];	break;
					case OP_Load::A_HL: _RAM[_RIX + n] = _RA_A;	break;
					case OP_Load::B_HL: _RAM[_RIX + n] = _RB_A;	break;
					case OP_Load::C_HL: _RAM[_RIX + n] = _RC_A;	break;
					case OP_Load::D_HL: _RAM[_RIX + n] = _RD_A;	break;
					case OP_Load::E_HL: _RAM[_RIX + n] = _RE_A;	break;
					case OP_Load::H_HL: _RAM[_RIX + n] = _RH_A;	break;
					case OP_Load::L_HL: _RAM[_RIX + n] = _RL_A;	break;
					case OP_Load::N_HL: _RAM[_RIX + n] = _RAM[_RPC + 3];	opcost = 4;	break;
					case OP_Load::NN_HL:_RIX = ReadWordAtAddress(_RPC + 2);	opcost = 4;	break;
					case OP_Load::NN_HL_M:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RIX = _RAM[position + 1] << BYTEWIDTH | _RAM[position];
						opcost = 4;
					}
					break;
					case OP_Load::HL_NN:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RAM[position] = (_RIX >> BYTEWIDTH) & MAXBYTE;
						_RAM[position + 1] = (_RIX)& MAXBYTE;
						opcost = 4;
					}
					break;
					case OP_Load::HL_SP:
					{
						_RSP = _RIX;
						opcost = 2;
					}
					break;
					case OP_Stack::PUSH_HL:
					{
						Stack_Push_Word(_RIX);
						opcost = 2;
					}
					break;
					case OP_Stack::POP_HL:
					{
						_RIX = Stack_Pop_Word();
						opcost = 2;
					}
					break;
					case OP_ETS::E_HL_SP:
					{
						WriteWordAtAddress(_RSP, _RIX);
						opcost = 2;
					}
					break;
					case OP_Math::ADD_HL_A:
					{
						Math_Add_A_R(_RAM[_RIX + n], 0);
						opcost = 3;
					}
					break;
					case OP_Math::ADC_HL_A:
					{
						Math_Add_A_R(_RAM[_RIX + n], 1);
						opcost = 3;
					}
					break;
					case OP_Math::SUB_HL_A:
					{
						Math_Sub_A_R(_RAM[_RIX + n], 0);
						opcost = 3;
					}
					break;
					case OP_Math::SBC_HL_A:
					{
						Math_Sub_A_R(_RAM[_RIX + n], 1);
						opcost = 3;
					}
					break;
					case OP_Math::AND_HL_A:
					{
						Math_And_A_R(_RAM[_RIX + n]);
						opcost = 3;
					}
					break;
					case OP_Math::OR_HL_A:
					{
						Math_Or_A_R(_RAM[_RIX + n]);
						opcost = 3;
					}
					break;
					case OP_Math::XOR_HL_A:
					{
						Math_Xor_A_R(_RAM[_RIX + n]);
						opcost = 3;
					}
					break;
					case OP_Math::CP_HL_A:
					{
						Math_Cp_A_R(_RAM[_RIX + n]);
						opcost = 3;
					}
					break;
					case OP_Math::INC_HL_A:
					{
						Math_Inc_Byte(_RAM[_RIX + n]);
						opcost = 3;
					}
					break;
					case OP_Math::DEC_HL_A:Math_Dec_Byte(_RAM[_RIX + n]); opcost = 3; break;
					case OP_Math::ADD_BC_IX: Math_Add_PP_IX(BCasWord(), 0); opcost = 2; break;
					case OP_Math::ADD_DE_IX: Math_Add_PP_IX(DEasWord(), 0); opcost = 2; break;
					case OP_Math::ADD_IX_IX:Math_Add_PP_IX(_RIX, 0); opcost = 2; break;
					case OP_Math::ADD_SP_IX:Math_Add_PP_IX(_RSP, 0); opcost = 2; break;



					default:
					{
						printf("Unkown opcode IX:%i \n", _RAM[_RPC + 1]);
					}
				}
			}
			break;
			case OP_Load::IYD_R:
			{
				byte n = _RAM[_RPC + 2];
				switch (_RAM[_RPC + 1])
				{
					case OP_Load::HL_A:
						_RA_A = _RAM[_RIY + n];
						break;
					case OP_Load::HL_B:
						_RB_A = _RAM[_RIY + n];
						break;
					case OP_Load::HL_C:
						_RC_A = _RAM[_RIY + n];
						break;
					case OP_Load::HL_D:
						_RD_A = _RAM[_RIY + n];
						break;
					case OP_Load::HL_E:
						_RE_A = _RAM[_RIY + n];
						break;
					case OP_Load::HL_H:
						_RH_A = _RAM[_RIY + n];
						break;
					case OP_Load::HL_L:
						_RL_A = _RAM[_RIY + n];
						break;
					case OP_Load::A_HL:
						_RAM[_RIY + n] = _RA_A;
						break;
					case OP_Load::B_HL:
						_RAM[_RIY + n] = _RB_A;
						break;
					case OP_Load::C_HL:
						_RAM[_RIY + n] = _RC_A;
						break;
					case OP_Load::D_HL:
						_RAM[_RIY + n] = _RD_A;
						break;
					case OP_Load::E_HL:
						_RAM[_RIY + n] = _RE_A;
						break;
					case OP_Load::H_HL:
						_RAM[_RIY + n] = _RH_A;
						break;
					case OP_Load::L_HL:
						_RAM[_RIY + n] = _RL_A;
						break;
					case OP_Load::N_HL:
					{
						_RAM[_RIY + n] = _RAM[_RPC + 3];
						opcost = 4;
					}
					break;
					case OP_Load::NN_HL:
					{
						_RIY = _RAM[_RPC + 3] << BYTEWIDTH | _RAM[_RPC + 2];
						opcost = 4;
					}
					break;
					case OP_Load::NN_HL_M:
					{
						uint32_t position = _RAM[_RPC + 3] << BYTEWIDTH | _RAM[_RPC + 2];
						_RIY = _RAM[position + 1] << BYTEWIDTH | _RAM[position];
						opcost = 4;
					}
					break;
					case OP_Load::HL_NN:
					{
						uint32_t position = _RAM[_RPC + 3] << BYTEWIDTH | _RAM[_RPC + 2];
						_RAM[position] = (_RIY >> BYTEWIDTH) & MAXBYTE;
						_RAM[position + 1] = (_RIY)& MAXBYTE;
						opcost = 4;
					}
					break;
					case OP_Load::HL_SP:
					{
						_RSP = _RIY;
						opcost = 2;
					}
					break;
					case OP_Stack::PUSH_HL:
					{
						Stack_Push_Word(_RIY);
						opcost = 2;
					}
					break;
					case OP_Stack::POP_HL:
					{
						_RIY = Stack_Pop_Word();
						opcost = 2;
					}
					break;
					case OP_ETS::E_HL_SP:
						WriteWordAtAddress(_RSP, _RIY);
						break;
					case OP_Math::ADD_HL_A:
					{
						Math_Add_A_R(_RAM[_RIY + n], 0);
						opcost = 3;
					}
					break;
					case OP_Math::ADC_HL_A:
					{
						Math_Add_A_R(_RAM[_RIY + n], 1);
						opcost = 3;
					}
					break;
					case OP_Math::SUB_HL_A:
					{
						Math_Sub_A_R(_RAM[_RIY + n], 0);
						opcost = 3;
					}
					break;
					case OP_Math::SBC_HL_A:
					{
						Math_Sub_A_R(_RAM[_RIY + n], 1);
						opcost = 3;
					}
					break;
					case OP_Math::AND_HL_A:
					{
						Math_And_A_R(_RAM[_RIY + n]);
						opcost = 3;
					}
					break;
					case OP_Math::OR_HL_A:
					{
						Math_Or_A_R(_RAM[_RIY + n]);
						opcost = 3;
					}
					break;
					case OP_Math::XOR_HL_A:
					{
						Math_Xor_A_R(_RAM[_RIY + n]);
						opcost = 3;
					}
					break;
					case OP_Math::CP_HL_A:
					{
						Math_Cp_A_R(_RAM[_RIY + n]);
						opcost = 3;
					}
					break;
					case OP_Math::INC_HL_A:
					{
						Math_Inc_Byte(_RAM[_RIY + n]);
						opcost = 3;
					}
					break;
					case OP_Math::DEC_HL_A:
					{
						Math_Dec_Byte(_RAM[_RIY + n]);
						opcost = 3;
					}
					break;

					case OP_Main::OP_CBMODIFIER:
					{
						switch (_RAM[_RPC + 3])
						{
							case OP_XX_CB::CB_BIT_0_HL:
							{
								word address = _RIY + _RAM[_RPC + 2];
								byte value = ReadByteAtAddress(address);
								SetFlag(value & (1 << 0), FLAG_Z);
								SetFlag(value & (1 << 0), FLAG_P);
								SetFlag(value & (1 << 0), FLAG_V);
								SetFlag(1, FLAG_H);
								SetFlag(0, FLAG_N);
								SetFlag(0, FLAG_S);
								SetFlag(GetFlag(FLAG_5)& ((value >> 5) & 0x1), FLAG_5);
								SetFlag(GetFlag(FLAG_3)& ((value >> 3) & 0x1), FLAG_3);
							}
							break;
							default:
							{
								printf("Unkown opcode IYCB:%i \n", _RAM[_RPC + 2]);
							}
						}
					}

					default:
					{
						printf("Unkown opcode IY:%i \n", _RAM[_RPC + 1]);
					}
				}
			}
			break;
			case OP_Load::A_HL:	WriteByteAtAddress(HLasWord(), _RA_A);	break;
			case OP_Load::B_HL:	WriteByteAtAddress(HLasWord(), _RB_A);	break;
			case OP_Load::C_HL:	WriteByteAtAddress(HLasWord(), _RC_A);	break;
			case OP_Load::D_HL:	WriteByteAtAddress(HLasWord(), _RD_A);	break;
			case OP_Load::E_HL:	WriteByteAtAddress(HLasWord(), _RE_A);	break;
			case OP_Load::H_HL:	WriteByteAtAddress(HLasWord(), _RH_A);	break;
			case OP_Load::L_HL:	WriteByteAtAddress(HLasWord(), _RL_A);	break;
			case OP_Load::N_HL:	WriteByteAtAddress(HLasWord(), _RAM[_RPC + 1]);	break;
			case OP_Load::BC_A:	_RA_A = ReadByteAtAddress(BCasWord());	break;
			case OP_Load::DE_A:	_RA_A = ReadByteAtAddress(DEasWord());	break;
			case OP_Load::NN_A:	_RA_A = ReadByteAtAddress(BytesToWord(_RAM[_RPC + 2], _RAM[_RPC + 1]));	break;
			case OP_Load::A_BC:	WriteByteAtAddress(BCasWord(), _RA_A);	break;
			case OP_Load::A_DE:	WriteByteAtAddress(DEasWord(), _RA_A);	break;
			case OP_Load::A_NN:	WriteByteAtAddress(BytesToWord(_RAM[_RPC + 2], _RAM[_RPC + 1]), _RA_A);	break;
			case OP_Load::ED:
			{
				switch (_RAM[_RPC + 1])
				{
					case OP_Load::I_A:
						_RA_A = _RIV;
						SetFlag(((_RA_A & 0x80) != 0), FLAG_S);
						SetFlag((_RA_A == 0), FLAG_Z);
						SetFlag(0, FLAG_H);
						SetFlag(_IFF2, FLAG_P);
						SetFlag(0, FLAG_N);
						break;
					case OP_Load::R_A:
						_RA_A = _RMR;
						SetFlag(((_RA_A & 0x80) != 0), FLAG_S);
						SetFlag((_RA_A == 0), FLAG_Z);
						SetFlag(0, FLAG_H);
						SetFlag(_IFF2, FLAG_P);
						SetFlag(0, FLAG_N);
						break;
					case OP_Load::A_I:
						_RIV = _RA_A;
						break;
					case OP_Load::A_R:
						_RMR = _RA_A;
						break;
					case OP_Load::NN_DD_BC:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RB_A = _RAM[position + 1];
						_RC_A = _RAM[position];
						opcost = 4;
					}
					break;
					case OP_Load::NN_DD_DE:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RD_A = _RAM[position + 1];
						_RE_A = _RAM[position];
						opcost = 4;
					}
					break;
					case OP_Load::NN_DD_HL:
					{
						uint32_t position = ReadWordAtAddress(_RPC + 2);
						_RH_A = _RAM[position + 1];
						_RL_A = _RAM[position];
						opcost = 4;
					}
					break;
					case OP_Load::NN_DD_SP:
					{
						_RSP = ReadWordAtAddress(_RPC + 2);
						opcost = 4;
					}
					break;
					case OP_Load::DD_NN_BC:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), BCasWord());
						opcost = 4;
					}
					break;
					case OP_Load::DD_NN_DE:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), DEasWord());
						opcost = 4;
					}
					break;
					case OP_Load::DD_NN_HL:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), HLasWord());
						opcost = 4;
					}
					break;
					case OP_Load::DD_NN_SP:
					{
						WriteWordAtAddress(ReadWordAtAddress(_RPC + 2), _RSP);
						opcost = 4;
					}
					break;
					case OP_ETS::LDI:
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
					case OP_ETS::LDIR:
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
					case OP_ETS::LDD:
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
					case OP_ETS::LDDR:
					{
						_RAM[DEasWord()] = _RAM[HLasWord()];
						DecrementHL();
						DecrementDE();
						DecrementBC();
						SetFlag((BCasWord() - 1 != 0), FLAG_P);
						SetFlag(0, FLAG_H);
						SetFlag(0, FLAG_N);
						opcost = 2;
						if ((BCasWord() != 0))_RPC -= 2;
					}
					break;
					case OP_ETS::CPI:
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
					case OP_ETS::CPIR:
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
					case OP_ETS::CPD:
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
					case OP_ETS::CPDR:
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
					case OP_Main::OP_NEG:
					{
						byte temp = _RA_A;
						_RA_A = 0;
						Math_Sub_A_R(temp, 0);
						SetFlag(1, FLAG_N);
					}
					break;
					case OP_Math::ADC_BC_HL:	Math_Add_SS_HL(BCasWord(), 1);	break;
					case OP_Math::ADC_DE_HL:	Math_Add_SS_HL(DEasWord(), 1);	break;
					case OP_Math::ADC_HL_HL:	Math_Add_SS_HL(HLasWord(), 1);	break;
					case OP_Math::ADC_SP_HL:	Math_Add_SS_HL(_RSP, 1);	break;
					case OP_Main::OP_ED_IM_1:	_InterruptMode = 1;	break;
					case OP_Math::SBC_HL_BC:	Math_Sub_SS_HL(BCasWord() + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_Math::SBC_HL_DE:	Math_Sub_SS_HL(DEasWord() + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_Math::SBC_HL_HL:	Math_Sub_SS_HL(HLasWord() + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_Math::SBC_HL_SP:	Math_Sub_SS_HL(_RSP + (GetFlag(FLAG_C) != 0), 0);	break;
					case OP_IO::IN_C_A:	break;
					default:
					{
						printf("Unkown opcode ED : %i \n", _RAM[_RPC + 1]);
					}
				}
			}
			break;
			case  OP_Load::NN_BC:
				_RB_A = _RAM[_RPC + 2];
				_RC_A = _RAM[_RPC + 1];
				break;
			case  OP_Load::NN_DE:
				_RD_A = _RAM[_RPC + 2];
				_RE_A = _RAM[_RPC + 1];
				break;
			case  OP_Load::NN_HL:
				_RH_A = _RAM[_RPC + 2];
				_RL_A = _RAM[_RPC + 1];
				break;
			case  OP_Load::NN_SP:
				_RSP = ReadWordAtAddress(_RPC + 1);
				break;
			case OP_Load::NN_HL_M:
			{
				uint32_t position = ReadWordAtAddress(_RPC + 1);
				_RH_A = _RAM[position + 1];
				_RL_A = _RAM[position];
			}
			break;
			case OP_Load::HL_NN:
			{
				uint32_t position = ReadWordAtAddress(_RPC + 1);
				_RAM[position] = _RL_A;
				_RAM[position + 1] = _RH_A;
			}
			break;
			case OP_Load::HL_SP:
				_RSP = HLasWord();
				break;
			case OP_Stack::PUSH_BC:
				Stack_Push_Word(BCasWord());
				break;
			case OP_Stack::PUSH_DE:
				Stack_Push_Word(DEasWord());
				break;
			case OP_Stack::PUSH_HL:
				Stack_Push_Word(HLasWord());
				break;
			case OP_Stack::PUSH_AF:
				Stack_Push_Word(AFasWord());
				break;
			case OP_Stack::POP_BC:
			{
				_RC_A = _RAM[_RSP++];
				_RB_A = _RAM[_RSP++];
			}
			break;
			case OP_Stack::POP_DE:
			{
				_RE_A = _RAM[_RSP++];
				_RD_A = _RAM[_RSP++];
			}
			break;
			case OP_Stack::POP_HL:
			{
				_RL_A = _RAM[_RSP++];
				_RH_A = _RAM[_RSP++];
			}
			break;
			case OP_Stack::POP_AF:
			{
				_RF_A = _RAM[_RSP++];
				_RA_A = _RAM[_RSP++];
			}
			break;
			case OP_ETS::E_DE_HL:
			{
				byte tempD = _RD_A;
				byte tempE = _RE_A;
				_RD_A = _RH_A;
				_RE_A = _RL_A;
				_RH_A = tempD;
				_RL_A = tempE;
			}
			break;
			case OP_ETS::E_AF_AF:
			{
				byte tempA = _RA_A;
				byte tempF = _RF_A;
				_RA_A = _RA_B;
				_RF_A = _RF_B;
				_RA_B = tempA;
				_RF_B = tempF;
			}
			break;
			case OP_ETS::E_EXX:
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
			case OP_ETS::E_HL_SP:
			{
				byte low = _RAM[_RSP];
				byte high = _RAM[_RSP + 1];
				_RAM[_RSP] = _RL_A;
				_RAM[_RSP + 1] = _RH_A;
				_RL_A = low;
				_RH_A = high;
			}
			break;
			case OP_Math::ADD_A_A:	Math_Add_A_R(_RA_A, 0);	break;
			case OP_Math::ADD_B_A:	Math_Add_A_R(_RB_A, 0);	break;
			case OP_Math::ADD_C_A:	Math_Add_A_R(_RC_A, 0);	break;
			case OP_Math::ADD_D_A:	Math_Add_A_R(_RD_A, 0);	break;
			case OP_Math::ADD_E_A:	Math_Add_A_R(_RE_A, 0);	break;
			case OP_Math::ADD_H_A:	Math_Add_A_R(_RH_A, 0);	break;
			case OP_Math::ADD_L_A:	Math_Add_A_R(_RL_A, 0);	break;
			case OP_Math::ADD_N_A:	Math_Add_A_R(_RAM[_RPC + 1], 0);	break;
			case OP_Math::ADD_HL_A:	Math_Add_A_R(_RAM[HLasWord()], 0);	break;
			case OP_Math::ADC_A_A:	Math_Add_A_R(_RA_A, 1);	break;
			case OP_Math::ADC_B_A:	Math_Add_A_R(_RB_A, 1); break;
			case OP_Math::ADC_C_A:	Math_Add_A_R(_RC_A, 1);	break;
			case OP_Math::ADC_D_A:	Math_Add_A_R(_RD_A, 1);	break;
			case OP_Math::ADC_E_A:	Math_Add_A_R(_RE_A, 1);	break;
			case OP_Math::ADC_H_A:	Math_Add_A_R(_RH_A, 1);	break;
			case OP_Math::ADC_L_A:	Math_Add_A_R(_RL_A, 1);	break;
			case OP_Math::ADC_N_A:	Math_Add_A_R(_RAM[_RPC + 1], 1);	break;
			case OP_Math::ADC_HL_A:	Math_Add_A_R(_RAM[HLasWord()], 1);	break;
			case OP_Math::SUB_A_A:	Math_Sub_A_R(_RA_A, 0);	break;
			case OP_Math::SUB_A_B:	Math_Sub_A_R(_RB_A, 0);	break;
			case OP_Math::SUB_A_C:	Math_Sub_A_R(_RC_A, 0);	break;
			case OP_Math::SUB_A_D:	Math_Sub_A_R(_RD_A, 0);	break;
			case OP_Math::SUB_A_E:	Math_Sub_A_R(_RE_A, 0);	break;
			case OP_Math::SUB_A_H:	Math_Sub_A_R(_RH_A, 0);	break;
			case OP_Math::SUB_A_L:	Math_Sub_A_R(_RL_A, 0);	break;
			case OP_Math::SUB_N_A:	Math_Sub_A_R(_RAM[_RPC + 1], 0);	break;
			case OP_Math::SUB_HL_A:	Math_Sub_A_R(_RAM[HLasWord()], 0);	break;
			case OP_Math::SBC_A_A:	Math_Sub_A_R(_RA_A, 1);	break;
			case OP_Math::SBC_A_B:	Math_Sub_A_R(_RB_A, 1);	break;
			case OP_Math::SBC_A_C:	Math_Sub_A_R(_RC_A, 1);	break;
			case OP_Math::SBC_A_D:	Math_Sub_A_R(_RD_A, 1);	break;
			case OP_Math::SBC_A_E:	Math_Sub_A_R(_RE_A, 1);	break;
			case OP_Math::SBC_A_H:	Math_Sub_A_R(_RH_A, 1);	break;
			case OP_Math::SBC_A_L:	Math_Sub_A_R(_RL_A, 1);	break;
			case OP_Math::SBC_N_A:	Math_Sub_A_R(_RAM[_RPC + 1], 1);	break;
			case OP_Math::SBC_HL_A:	Math_Sub_A_R(_RAM[HLasWord()], 1);	break;
			case OP_Math::AND_A_A:	Math_And_A_R(_RA_A);	break;
			case OP_Math::AND_A_B:	Math_And_A_R(_RB_A);	break;
			case OP_Math::AND_A_C:	Math_And_A_R(_RC_A);	break;
			case OP_Math::AND_A_D:	Math_And_A_R(_RD_A);	break;
			case OP_Math::AND_A_E:	Math_And_A_R(_RE_A);	break;
			case OP_Math::AND_A_H:	Math_And_A_R(_RH_A);	break;
			case OP_Math::AND_A_L:	Math_And_A_R(_RL_A);	break;
			case OP_Math::AND_N_A:	Math_And_A_R(_RAM[_RPC + 1]);	break;
			case OP_Math::AND_HL_A:	Math_And_A_R(_RAM[HLasWord()]);	break;
			case OP_Math::OR_A_A:	Math_Or_A_R(_RA_A);	break;
			case OP_Math::OR_A_B:	Math_Or_A_R(_RB_A);	break;
			case OP_Math::OR_A_C:	Math_Or_A_R(_RC_A);	break;
			case OP_Math::OR_A_D:	Math_Or_A_R(_RD_A);	break;
			case OP_Math::OR_A_E:	Math_Or_A_R(_RE_A);	break;
			case OP_Math::OR_A_H:	Math_Or_A_R(_RH_A);	break;
			case OP_Math::OR_A_L:	Math_Or_A_R(_RL_A);	break;
			case OP_Math::OR_N_A:	Math_Or_A_R(_RAM[_RPC + 1]);	break;
			case OP_Math::OR_HL_A:	Math_Or_A_R(_RAM[HLasWord()]);	break;
			case OP_Math::XOR_A_A:	Math_Xor_A_R(_RA_A);	break;
			case OP_Math::XOR_A_B:	Math_Xor_A_R(_RB_A);	break;
			case OP_Math::XOR_A_C:	Math_Xor_A_R(_RC_A);	break;
			case OP_Math::XOR_A_D:	Math_Xor_A_R(_RD_A);	break;
			case OP_Math::XOR_A_E:	Math_Xor_A_R(_RE_A);	break;
			case OP_Math::XOR_A_H:	Math_Xor_A_R(_RH_A);	break;
			case OP_Math::XOR_A_L:	Math_Xor_A_R(_RL_A);	break;
			case OP_Math::XOR_N_A:	Math_Xor_A_R(_RAM[_RPC + 1]);	break;
			case OP_Math::XOR_HL_A:	Math_Xor_A_R(_RAM[HLasWord()]);	break;
			case OP_Math::CP_A_A:	Math_Cp_A_R(_RA_A);	break;
			case OP_Math::CP_A_B:	Math_Cp_A_R(_RB_A);	break;
			case OP_Math::CP_A_C:	Math_Cp_A_R(_RC_A);	break;
			case OP_Math::CP_A_D:	Math_Cp_A_R(_RD_A);	break;
			case OP_Math::CP_A_E:	Math_Cp_A_R(_RE_A);	break;
			case OP_Math::CP_A_H:	Math_Cp_A_R(_RH_A);	break;
			case OP_Math::CP_A_L:	Math_Cp_A_R(_RL_A);	break;
			case OP_Math::CP_N_A:	Math_Cp_A_R(_RAM[_RPC + 1]); break;
			case OP_Math::CP_HL_A:	Math_Cp_A_R(_RAM[HLasWord()]);	break;
			case OP_Math::INC_A_A:	_RA_A = Math_Inc_Byte(_RA_A);	break;
			case OP_Math::INC_A_B:	_RB_A = Math_Inc_Byte(_RB_A);	break;
			case OP_Math::INC_A_C:	_RC_A = Math_Inc_Byte(_RC_A);	break;
			case OP_Math::INC_A_D:	_RD_A = Math_Inc_Byte(_RD_A);	break;
			case OP_Math::INC_A_E:	_RE_A = Math_Inc_Byte(_RE_A);	break;
			case OP_Math::INC_A_H:	_RH_A = Math_Inc_Byte(_RH_A);	break;
			case OP_Math::INC_A_L:	_RL_A = Math_Inc_Byte(_RL_A);	break;
			case OP_Math::INC_HL_A:	_RAM[HLasWord()] = Math_Inc_Byte(_RAM[HLasWord()]);	break;
			case OP_Math::DEC_A_A:	_RA_A = Math_Dec_Byte(_RA_A);	break;
			case OP_Math::DEC_A_B:	_RB_A = Math_Dec_Byte(_RB_A);	break;
			case OP_Math::DEC_A_C:	_RC_A = Math_Dec_Byte(_RC_A);	break;
			case OP_Math::DEC_A_D:	_RD_A = Math_Dec_Byte(_RD_A);	break;
			case OP_Math::DEC_A_E:	_RE_A = Math_Dec_Byte(_RE_A);	break;
			case OP_Math::DEC_A_H:	_RH_A = Math_Dec_Byte(_RH_A);	break;
			case OP_Math::DEC_A_L:	_RL_A = Math_Dec_Byte(_RL_A);	break;
			case OP_Math::DEC_HL_A:	_RAM[HLasWord()] = Math_Dec_Byte(_RAM[HLasWord()]);		break;
			case OP_Main::OP_CPL:
			{
				_RA_A = ~_RA_A;
				SetFlag(1, FLAG_H);
				SetFlag(1, FLAG_N);
			}
			break;
			case OP_Main::OP_CCF:
			{
				SetFlag(GetFlag(FLAG_C) == 0, FLAG_C);
				SetFlag(0, FLAG_N);
			}
			break;
			case OP_Main::OP_SCF:
			{
				SetFlag(1, FLAG_C);
				SetFlag(0, FLAG_N);
				SetFlag(0, FLAG_H);
			}
			break;
			case OP_Main::OP_DI:
			{
				_IFF1 = 0;
				_IFF2 = 0;
			}
			break;
			case OP_Main::OP_EI:	_IFF1 = 1;	_IFF2 = 1;	break;
			case OP_Math::ADD_BC_HL:	Math_Add_SS_HL(BCasWord(), 0);	break;
			case OP_Math::ADD_DE_HL:	Math_Add_SS_HL(DEasWord(), 0);	break;
			case OP_Math::ADD_HL_HL:	Math_Add_SS_HL(HLasWord(), 0);	break;
			case OP_Math::ADD_SP_HL:	Math_Add_SS_HL(_RSP, 0);		break;
			case OP_Math::INC_BC:
			{
				word newValue = BCasWord() + 1;
				_RB_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RC_A = (newValue)& MAXBYTE;
			}
			break;
			case OP_Math::INC_DE:
			{
				word newValue = DEasWord() + 1;
				_RD_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RE_A = (newValue)& MAXBYTE;
			}
			break;
			case OP_Math::INC_HL:
			{
				word newValue =( HLasWord() + 1)&0xffff;
				_RH_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RL_A = (newValue)& MAXBYTE;
			}
			break;
			case OP_Math::INC_SP:
				_RSP++;
				break;
			case OP_Math::DEC_BC:
			{
				word newValue = BCasWord() - 1;
				_RB_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RC_A = (newValue)& MAXBYTE;
			}
			break;
			case OP_Math::DEC_DE:
			{
				word newValue = DEasWord() - 1;
				_RD_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RE_A = (newValue)& MAXBYTE;
			}
			break;
			case OP_Math::DEC_HL:
			{
				word newValue = HLasWord() - 1;
				_RH_A = (newValue >> BYTEWIDTH) & MAXBYTE;
				_RL_A = (newValue)& MAXBYTE;
			}
			break;
			case OP_Math::DEC_SP:
				_RSP--;
				break;
			case OP_CTRRTN::CR_CALL:
			{
				word newRPC = ReadWordAtAddress(_RPC + 1);
				_RPC += 3;
				Stack_Push_Word(_RPC);
				_RPC = newRPC;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::CR_CALLNZ:
			{
				word newRPC = ReadWordAtAddress(_RAM[_RPC + 1]);
				_RPC += 3;
				if (!GetFlag(FLAG_Z))
				{
					Stack_Push_Word(_RPC);
					_RPC = newRPC;
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JR_NZ_E:
				if (GetFlag(FLAG_Z) == 0)	_RPC += (int8_t)_RAM[_RPC + 1];
				break;
			case OP_CTRRTN::RST_00H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x00;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RST_08H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x08;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RST_10H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x10;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RST_18H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x18;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RST_20H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x20;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RST_28H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x28;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RST_30H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x30;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RST_38H:
			{
				Stack_Push_Word(_RPC + 1);
				_RPC = 0x38;
				opcost = 0;
			}
			break;
			case OP_CTRRTN::RET:
				_RPC = Stack_Pop_Word();
				opcost = 0;
				break;
			case OP_CTRRTN::RET_NZ:
				if (GetFlag(FLAG_Z) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_CTRRTN::RET_Z:
				if (GetFlag(FLAG_Z) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_CTRRTN::RET_NC:
				if (GetFlag(FLAG_C) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_CTRRTN::RET_C:
				if (GetFlag(FLAG_C) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_CTRRTN::RET_PO:
				if (GetFlag(FLAG_P) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_CTRRTN::RET_PE:
				if (GetFlag(FLAG_P) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_CTRRTN::RET_P:
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) == 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_CTRRTN::RET_N:
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) != 0)
				{
					_RPC = Stack_Pop_Word();
					opcost = 0;
				}
				break;
			case OP_Stack::JP:
				JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
				break;
			case OP_Stack::JP_NZ:
			{
				if (GetFlag(FLAG_Z) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JP_Z:
			{
				if (GetFlag(FLAG_Z) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JP_NC:
			{
				if (GetFlag(FLAG_C) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JP_C:
			{
				if (GetFlag(FLAG_C) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JP_PO:
			{
				if (GetFlag(FLAG_P) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JP_PE:
			{
				if (GetFlag(FLAG_P) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JP_P:
			{
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) == 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_Stack::JP_N:
			{
				if ((GetFlag(FLAG_P) | GetFlag(FLAG_Z)) != 0)
				{
					JumpToAddress(_RAM[_RPC + 2], _RAM[_RPC + 1]);
					opcost = 0;
				}
			}
			break;
			case OP_RAS::RLCA:
			{
				uint32_t hbit = (_RA_A & 0x80) != 0;
				_RA_A = ((_RA_A << 1) & MAXBYTE);
				if (hbit)_RA_A |= 0x01;
			}
			break;
			case OP_Stack::JR_C_E:
			{
				if (GetFlag(FLAG_C) != 0)
				{
					int8_t jump = _RAM[_RPC + 1];
					_RPC += jump;
					opcost = 0;
				}
			}
			case OP_Stack::JR_NC_E:
			{
				if (GetFlag(FLAG_C) == 0)
				{
					int8_t jump = _RAM[_RPC + 1];
					_RPC += jump;
					opcost = 2;
				}
			}
			break;
			case OP_Stack::JR_E: _RPC += static_cast<int8_t>(_RAM[_RPC + 1]);	break;
			case OP_Stack::JR_Z: if (GetFlag(FLAG_Z) != 0)_RPC += static_cast<int8_t>(_RAM[_RPC + 1]);	break;
			case OP_Stack::DJNZ:
			{
				_RB_A--;
				if (_RB_A != 0) _RPC += static_cast<int8_t>(_RAM[_RPC + 1]);
			}
			break;
			case OP_RAS::CB:
			{
				opcost = 2;
				switch (_RAM[_RPC + 1])
				{
					case OP_RAS::RL_A:	_RA_A = RAS_RL(_RA_A);	break;
					case OP_RAS::RL_B:	_RB_A = RAS_RL(_RB_A);	break;
					case OP_RAS::RL_C:	_RC_A = RAS_RL(_RC_A);	break;
					case OP_RAS::RL_D:	_RD_A = RAS_RL(_RD_A);	break;
					case OP_RAS::RL_E:	_RE_A = RAS_RL(_RE_A);	break;
					case OP_RAS::RL_H:	_RH_A = RAS_RL(_RH_A);	break;
					case OP_RAS::RL_L:	_RL_A = RAS_RL(_RL_A);	break;
					default:
					{
						printf("Unkown opcode CB : %i \n", _RAM[_RPC + 1]);
					}
				}
			}
			break;
			case OP_RAS::RRC_A:
			{
				SetFlag((_RA_A & 0x01) != 0, FLAG_C);
				_RA_A >>= 1;
				_RA_A |= static_cast<byte>(GetFlag(FLAG_C) << 7);
				SetFlag(0, FLAG_H);
				SetFlag(0, FLAG_N);
			}
			break;
			case OP_RAS::RRA:
			{
				uint32_t currentCFlag = GetFlag(FLAG_C);
				SetFlag((_RA_A & 0x01), FLAG_C);
				_RA_A >>= 1;
				_RA_A |= (currentCFlag << 7);
				SetFlag(0, FLAG_H);
				SetFlag(0, FLAG_N);
			}
			break;
			case OP_RAS::RLA:
				RAS_RLA();
				break;
			case OP_IO::OUT_NA:
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