#pragma once
static const int OP_MATH_ADD_A_A = 0x87;
static const int OP_MATH_ADD_B_A = 0x80;
static const int OP_MATH_ADD_C_A = 0x81;
static const int OP_MATH_ADD_D_A = 0x82;
static const int OP_MATH_ADD_E_A = 0x83;
static const int OP_MATH_ADD_H_A = 0x84;
static const int OP_MATH_ADD_L_A = 0x85;

static const int OP_MATH_ADD_N_A = 0xC6;
static const int OP_MATH_ADD_HL_A = 0x86;

static const int OP_MATH_ADC_A_A = 0x8F;
static const int OP_MATH_ADC_B_A = 0x88;
static const int OP_MATH_ADC_C_A = 0x89;
static const int OP_MATH_ADC_D_A = 0x8A;
static const int OP_MATH_ADC_E_A = 0x8B;
static const int OP_MATH_ADC_H_A = 0x8C;
static const int OP_MATH_ADC_L_A = 0x8D;

static const int OP_MATH_ADC_N_A = 0xCE;
static const int OP_MATH_ADC_HL_A = 0x8E;

static const int OP_MATH_SUB_A_A = 0x97;
static const int OP_MATH_SUB_A_B = 0x90;
static const int OP_MATH_SUB_A_C = 0x91;
static const int OP_MATH_SUB_A_D = 0x92;
static const int OP_MATH_SUB_A_E = 0x93;
static const int OP_MATH_SUB_A_H = 0x94;
static const int OP_MATH_SUB_A_L = 0x95;

static const int OP_MATH_SUB_N_A = 0xD6;
static const int OP_MATH_SUB_HL_A = 0x96;

static const int OP_MATH_SBC_A_A = 0x9F;
static const int OP_MATH_SBC_A_B = 0x98;
static const int OP_MATH_SBC_A_C = 0x99;
static const int OP_MATH_SBC_A_D = 0x9A;
static const int OP_MATH_SBC_A_E = 0x9B;
static const int OP_MATH_SBC_A_H = 0x9C;
static const int OP_MATH_SBC_A_L = 0x9D;

static const int OP_MATH_SBC_N_A = 0xDE;
static const int OP_MATH_SBC_HL_A = 0x9E;

static const int OP_MATH_AND_A_A = 0xA7;
static const int OP_MATH_AND_A_B = 0xA0;
static const int OP_MATH_AND_A_C = 0xA1;
static const int OP_MATH_AND_A_D = 0xA2;
static const int OP_MATH_AND_A_E = 0xA3;
static const int OP_MATH_AND_A_H = 0xA4;
static const int OP_MATH_AND_A_L = 0xA5;

static const int OP_MATH_AND_N_A = 0xE6;
static const int OP_MATH_AND_HL_A = 0xA6;

static const int OP_MATH_OR_A_A = 0xB7;
static const int OP_MATH_OR_A_B = 0xB0;
static const int OP_MATH_OR_A_C = 0xB1;
static const int OP_MATH_OR_A_D = 0xB2;
static const int OP_MATH_OR_A_E = 0xB3;
static const int OP_MATH_OR_A_H = 0xB4;
static const int OP_MATH_OR_A_L = 0xB5;

static const int OP_MATH_OR_N_A = 0xF6;
static const int OP_MATH_OR_HL_A = 0xB6;

static const int OP_MATH_XOR_A_A = 0xAF;
static const int OP_MATH_XOR_A_B = 0xA8;
static const int OP_MATH_XOR_A_C = 0xA9;
static const int OP_MATH_XOR_A_D = 0xAA;
static const int OP_MATH_XOR_A_E = 0xAB;
static const int OP_MATH_XOR_A_H = 0xAC;
static const int OP_MATH_XOR_A_L = 0xAD;

static const int OP_MATH_XOR_N_A = 0xEE;
static const int OP_MATH_XOR_HL_A = 0xAE;

static const int OP_MATH_CP_A_A = 0xBF;
static const int OP_MATH_CP_A_B = 0xB8;
static const int OP_MATH_CP_A_C = 0xB9;
static const int OP_MATH_CP_A_D = 0xBA;
static const int OP_MATH_CP_A_E = 0xBB;
static const int OP_MATH_CP_A_H = 0xBC;
static const int OP_MATH_CP_A_L = 0xBD;

static const int OP_MATH_CP_N_A = 0xFE;
static const int OP_MATH_CP_HL_A = 0xBE;

static const int OP_MATH_INC_A_A = 0x3C;
static const int OP_MATH_INC_A_B = 0x04;
static const int OP_MATH_INC_A_C = 0x0C;
static const int OP_MATH_INC_A_D = 0x14;
static const int OP_MATH_INC_A_E = 0x1C;
static const int OP_MATH_INC_A_H = 0x24;
static const int OP_MATH_INC_A_L = 0x2C;

static const int OP_MATH_INC_HL_A = 0x34;

static const int OP_MATH_DEC_A_A = 0x3D;
static const int OP_MATH_DEC_A_B = 0x05;
static const int OP_MATH_DEC_A_C = 0x0D;
static const int OP_MATH_DEC_A_D = 0x15;
static const int OP_MATH_DEC_A_E = 0x1D;
static const int OP_MATH_DEC_A_H = 0x25;
static const int OP_MATH_DEC_A_L = 0x2D;

static const int OP_MATH_DEC_HL_A = 0x35;

static const int OP_MATH_ADD_BC_HL = 0x09;
static const int OP_MATH_ADD_DE_HL = 0x19;
static const int OP_MATH_ADD_HL_HL = 0x29;
static const int OP_MATH_ADD_SP_HL = 0x39;

static const int OP_MATH_ADC_BC_HL = 0x4A;
static const int OP_MATH_ADC_DE_HL = 0x5A;
static const int OP_MATH_ADC_HL_HL = 0x6A;
static const int OP_MATH_ADC_SP_HL = 0x7A;

static const int OP_MATH_INC_BC = 0x03;
static const int OP_MATH_INC_DE = 0x13;
static const int OP_MATH_INC_HL = 0x23;
static const int OP_MATH_INC_SP = 0x33;

static const int OP_MATH_DEC_BC = 0x0B;
static const int OP_MATH_DEC_DE = 0x1B;
static const int OP_MATH_DEC_HL = 0x2B;
static const int OP_MATH_DEC_SP = 0x3B;

static const int OP_MATH_SBC_HL_BC = 0x42;
static const int OP_MATH_SBC_HL_DE = 0x52;
static const int OP_MATH_SBC_HL_HL = 0x62;
static const int OP_MATH_SBC_HL_SP = 0x72;

static const int OP_MATH_ADD_BC_IX = 0x09;
static const int OP_MATH_ADD_DE_IX = 0x19;
static const int OP_MATH_ADD_IX_IX = 0x29;
static const int OP_MATH_ADD_SP_IX = 0x39;