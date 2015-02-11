#pragma once

class OP_Main
{
public:
	static const int  OP_NOP = 0x00;

	static const int  OP_CPL = 0x2F;
	static const int  OP_NEG = 0x44;
	static const int  OP_CCF = 0x3F;
	static const int  OP_SCF = 0x37;

	static const int  OP_DI = 0xF3;
	static const int  OP_EI = 0xFB;

	static const int  OP_ED_IM_1 = 0x56;

	static const int OP_CBMODIFIER = 0xCB;
};

class OP_Stack
{
public:
	static const int PUSH_BC = 0xC5;
	static const int PUSH_DE = 0xD5;
	static const int PUSH_HL = 0xE5;
	static const int PUSH_AF = 0xF5;

	static const int POP_BC = 0xC1;
	static const int POP_DE = 0xD1;
	static const int POP_HL = 0xE1;
	static const int POP_AF = 0xF1;

	static const int JR_E = 0x18;
	static const int JR_Z = 0x28;
	static const int JR_NC_E = 0x30;
	static const int JR_C_E = 0x38;
	static const int JR_NZ_E = 0x20;
	static const int JP = 0xC3;
	static const int JP_HL = 0xE9;
	static const int JP_NZ = 0xC2;
	static const int JP_Z = 0xCA;
	static const int JP_NC = 0xD2;
	static const int JP_C = 0xDA;
	static const int JP_PO = 0xE2;
	static const int JP_PE = 0xEA;
	static const int JP_P = 0xF2;
	static const int JP_N = 0xFA;

	static const int DJNZ = 0x10;
};

class OP_RAS
{
public:
	static const int CB = 0xCb;

	static const int RLA = 0x17;
	static const int RLCA = 0x07;

	static const int RRC_A = 0x0F;
	static const int RRA = 0x1f;

	static const int RL_A = 0x17;
	static const int RL_B = 0x10;
	static const int RL_C = 0x11;
	static const int RL_D = 0x12;
	static const int RL_E = 0x13;
	static const int RL_H = 0x14;
	static const int RL_L = 0x15;
	static const int RLC_A = 0x07;
	static const int RLC_B = 0x00;
	static const int RLC_C = 0x01;
	static const int RLC_D = 0x02;
	static const int RLC_E = 0x03;
	static const int RLC_H = 0x04;
	static const int RLC_L = 0x05;
};

class OP_Math
{
public:
	static const int ADD_A_A = 0x87;
	static const int ADD_B_A = 0x80;
	static const int ADD_C_A = 0x81;
	static const int ADD_D_A = 0x82;
	static const int ADD_E_A = 0x83;
	static const int ADD_H_A = 0x84;
	static const int ADD_L_A = 0x85;

	static const int ADD_N_A = 0xC6;
	static const int ADD_HL_A = 0x86;

	static const int ADC_A_A = 0x8F;
	static const int ADC_B_A = 0x88;
	static const int ADC_C_A = 0x89;
	static const int ADC_D_A = 0x8A;
	static const int ADC_E_A = 0x8B;
	static const int ADC_H_A = 0x8C;
	static const int ADC_L_A = 0x8D;

	static const int ADC_N_A = 0xCE;
	static const int ADC_HL_A = 0x8E;

	static const int SUB_A_A = 0x97;
	static const int SUB_A_B = 0x90;
	static const int SUB_A_C = 0x91;
	static const int SUB_A_D = 0x92;
	static const int SUB_A_E = 0x93;
	static const int SUB_A_H = 0x94;
	static const int SUB_A_L = 0x95;

	static const int SUB_N_A = 0xD6;
	static const int SUB_HL_A = 0x96;

	static const int SBC_A_A = 0x9F;
	static const int SBC_A_B = 0x98;
	static const int SBC_A_C = 0x99;
	static const int SBC_A_D = 0x9A;
	static const int SBC_A_E = 0x9B;
	static const int SBC_A_H = 0x9C;
	static const int SBC_A_L = 0x9D;

	static const int SBC_N_A = 0xDE;
	static const int SBC_HL_A = 0x9E;

	static const int AND_A_A = 0xA7;
	static const int AND_A_B = 0xA0;
	static const int AND_A_C = 0xA1;
	static const int AND_A_D = 0xA2;
	static const int AND_A_E = 0xA3;
	static const int AND_A_H = 0xA4;
	static const int AND_A_L = 0xA5;

	static const int AND_N_A = 0xE6;
	static const int AND_HL_A = 0xA6;

	static const int OR_A_A = 0xB7;
	static const int OR_A_B = 0xB0;
	static const int OR_A_C = 0xB1;
	static const int OR_A_D = 0xB2;
	static const int OR_A_E = 0xB3;
	static const int OR_A_H = 0xB4;
	static const int OR_A_L = 0xB5;

	static const int OR_N_A = 0xF6;
	static const int OR_HL_A = 0xB6;

	static const int XOR_A_A = 0xAF;
	static const int XOR_A_B = 0xA8;
	static const int XOR_A_C = 0xA9;
	static const int XOR_A_D = 0xAA;
	static const int XOR_A_E = 0xAB;
	static const int XOR_A_H = 0xAC;
	static const int XOR_A_L = 0xAD;

	static const int XOR_N_A = 0xEE;
	static const int XOR_HL_A = 0xAE;

	static const int CP_A_A = 0xBF;
	static const int CP_A_B = 0xB8;
	static const int CP_A_C = 0xB9;
	static const int CP_A_D = 0xBA;
	static const int CP_A_E = 0xBB;
	static const int CP_A_H = 0xBC;
	static const int CP_A_L = 0xBD;

	static const int CP_N_A = 0xFE;
	static const int CP_HL_A = 0xBE;

	static const int INC_A_A = 0x3C;
	static const int INC_A_B = 0x04;
	static const int INC_A_C = 0x0C;
	static const int INC_A_D = 0x14;
	static const int INC_A_E = 0x1C;
	static const int INC_A_H = 0x24;
	static const int INC_A_L = 0x2C;

	static const int INC_HL_A = 0x34;

	static const int DEC_A_A = 0x3D;
	static const int DEC_A_B = 0x05;
	static const int DEC_A_C = 0x0D;
	static const int DEC_A_D = 0x15;
	static const int DEC_A_E = 0x1D;
	static const int DEC_A_H = 0x25;
	static const int DEC_A_L = 0x2D;

	static const int DEC_HL_A = 0x35;

	static const int ADD_BC_HL = 0x09;
	static const int ADD_DE_HL = 0x19;
	static const int ADD_HL_HL = 0x29;
	static const int ADD_SP_HL = 0x39;

	static const int ADC_BC_HL = 0x4A;
	static const int ADC_DE_HL = 0x5A;
	static const int ADC_HL_HL = 0x6A;
	static const int ADC_SP_HL = 0x7A;

	static const int INC_BC = 0x03;
	static const int INC_DE = 0x13;
	static const int INC_HL = 0x23;
	static const int INC_SP = 0x33;

	static const int DEC_BC = 0x0B;
	static const int DEC_DE = 0x1B;
	static const int DEC_HL = 0x2B;
	static const int DEC_SP = 0x3B;

	static const int SBC_HL_BC = 0x42;
	static const int SBC_HL_DE = 0x52;
	static const int SBC_HL_HL = 0x62;
	static const int SBC_HL_SP = 0x72;

	static const int ADD_BC_IX = 0x09;
	static const int ADD_DE_IX = 0x19;
	static const int ADD_IX_IX = 0x29;
	static const int ADD_SP_IX = 0x39;
};

class OP_Load
{
	//source destination
public:
	static const int A_A = 0x7F;
	static const int B_A = 0x78;
	static const int C_A = 0x79;
	static const int D_A = 0x7A;
	static const int E_A = 0x7B;
	static const int H_A = 0x7C;
	static const int L_A = 0x7D;

	static const int A_B = 0x47;
	static const int B_B = 0x40;
	static const int C_B = 0x41;
	static const int D_B = 0x42;
	static const int E_B = 0x43;
	static const int H_B = 0x44;
	static const int L_B = 0x45;

	static const int A_C = 0x4f;
	static const int B_C = 0x48;
	static const int C_C = 0x49;
	static const int D_C = 0x4A;
	static const int E_C = 0x4B;
	static const int H_C = 0x4C;
	static const int L_C = 0x4D;

	static const int A_D = 0x57;
	static const int B_D = 0x50;
	static const int C_D = 0x51;
	static const int D_D = 0x52;
	static const int E_D = 0x53;
	static const int H_D = 0x54;
	static const int L_D = 0x55;

	static const int A_E = 0x5F;
	static const int B_E = 0x58;
	static const int C_E = 0x59;
	static const int D_E = 0x5A;
	static const int E_E = 0x5B;
	static const int H_E = 0x5C;
	static const int L_E = 0x5D;

	static const int A_H = 0x67;
	static const int B_H = 0x60;
	static const int C_H = 0x61;
	static const int D_H = 0x62;
	static const int E_H = 0x63;
	static const int H_H = 0x64;
	static const int L_H = 0x65;

	static const int A_L = 0x6F;
	static const int B_L = 0x68;
	static const int C_L = 0x69;
	static const int D_L = 0x6A;
	static const int E_L = 0x6B;
	static const int H_L = 0x6C;
	static const int L_L = 0x6D;

	static const int N_A = 0x3E;
	static const int N_B = 0x06;
	static const int N_C = 0x0E;
	static const int N_D = 0x16;
	static const int N_E = 0x1E;
	static const int N_H = 0x26;
	static const int N_L = 0x2E;

	static const int HL_A = 0x7E;
	static const int HL_B = 0x46;
	static const int HL_C = 0x4E;
	static const int HL_D = 0x56;
	static const int HL_E = 0x5E;
	static const int HL_H = 0x66;
	static const int HL_L = 0x6E;

	static const int IXD_R = 0xDD;
	static const int IYD_R = 0xFD;

	static const int A_HL = 0x77;
	static const int B_HL = 0x70;
	static const int C_HL = 0x71;
	static const int D_HL = 0x72;
	static const int E_HL = 0x73;
	static const int H_HL = 0x74;
	static const int L_HL = 0x75;

	static const int N_HL = 0x36;

	static const int BC_A = 0x0A;
	static const int DE_A = 0x1A;
	static const int NN_A = 0x3A;
	static const int A_BC = 0x02;
	static const int A_DE = 0x12;
	static const int A_NN = 0x32;

	static const int ED = 0xED;
	static const int I_A = 0x57;
	static const int R_A = 0x5F;
	static const int A_I = 0x47;
	static const int A_R = 0x4F;

	//16-bit load group
	static const int NN_BC = 0x01;
	static const int NN_DE = 0x11;
	static const int NN_HL = 0x21;
	static const int NN_SP = 0x31;

	static const int NN_HL_M = 0x2A;

	static const int NN_DD_BC = 0x4B;
	static const int NN_DD_DE = 0x5B;
	static const int NN_DD_HL = 0x6B;
	static const int NN_DD_SP = 0x7B;

	static const int HL_NN = 0x22;

	static const int DD_NN_BC = 0x43;
	static const int DD_NN_DE = 0x53;
	static const int DD_NN_HL = 0x63;
	static const int DD_NN_SP = 0x73;

	static const int HL_SP = 0xF9;

};

class OP_IO
{
public:
	static const int OUT_NA = 0xD3;
	static const int IN_C_A = 0x78;
};

class OP_ETS
{
public:
	static const int E_DE_HL = 0xEB;
	static const int E_AF_AF = 0x08;
	static const int E_EXX = 0xD9;
	static const int E_HL_SP = 0xE3;

	static const int LDI = 0xA0;
	static const int LDIR = 0xB0;
	static const int LDD = 0xA8;
	static const int LDDR = 0xB8;

	static const int CPI = 0xA1;
	static const int CPIR = 0xB1;

	static const int CPD = 0xA9;
	static const int CPDR = 0xB9;
};

class OP_CTRRTN
{
public:
	static const int  CR_CALL = 0xCD;
	static const int  CR_CALLP = 0xF4;
	static const int  CR_CALLNZ = 0xC4;

	static const int  RST_00H = 0xC7;
	static const int  RST_08H = 0xCF;
	static const int  RST_10H = 0xD7;
	static const int  RST_18H = 0xDF;
	static const int  RST_20H = 0xE7;
	static const int  RST_28H = 0xEF;
	static const int  RST_30H = 0xF7;
	static const int  RST_38H = 0xFF;

	static const int  RET = 0xC9;
	static const int  RET_NZ = 0xC0;
	static const int  RET_Z = 0xC8;
	static const int  RET_NC = 0xD0;
	static const int  RET_C = 0xD8;
	static const int  RET_PO = 0xE0;
	static const int  RET_PE = 0xE8;
	static const int  RET_P = 0xF0;
	static const int  RET_N = 0xF8;
};

class OP_XX_CB
{
public:
	static const int CB_BIT_0_HL = 0x46;
	static const int CB_BIT_1_HL = 0x4E;
	static const int CB_SET_0_HL = 0xC6;
	static const int CB_SET_1_HL = 0xCE;
	static const int CB_SET_4_HL = 0xE6;
	static const int CB_REST_1_HL = 0x8E;
	static const int CB_REST_4_HL = 0xA6;
	static const int CB_REST_5_HL = 0xAE;
	static const int CB_REST_0_HL = 0x86;
};