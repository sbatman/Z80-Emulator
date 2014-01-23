#pragma once
#define OP_MATH_ADD_A_A 0x87
#define OP_MATH_ADD_B_A 0x80
#define OP_MATH_ADD_C_A 0x81
#define OP_MATH_ADD_D_A 0x82
#define OP_MATH_ADD_E_A 0x83
#define OP_MATH_ADD_H_A 0x84
#define OP_MATH_ADD_L_A 0x85

#define OP_MATH_ADD_N_A 0xC6
#define OP_MATH_ADD_HL_A 0x86

#define OP_MATH_ADC_A_A 0x8F
#define OP_MATH_ADC_B_A 0x88
#define OP_MATH_ADC_C_A 0x89
#define OP_MATH_ADC_D_A 0x8A
#define OP_MATH_ADC_E_A 0x8B
#define OP_MATH_ADC_H_A 0x8C
#define OP_MATH_ADC_L_A 0x8D

#define OP_MATH_ADC_N_A 0xCE
#define OP_MATH_ADC_HL_A 0x8E

#define OP_MATH_SUB_A_A 0x97
#define OP_MATH_SUB_A_B 0x90
#define OP_MATH_SUB_A_C 0x91
#define OP_MATH_SUB_A_D 0x92
#define OP_MATH_SUB_A_E 0x93
#define OP_MATH_SUB_A_H 0x94
#define OP_MATH_SUB_A_L 0x95

#define OP_MATH_SUB_N_A 0xD6
#define OP_MATH_SUB_HL_A 0x96

#define OP_MATH_SBC_A_A 0x9F
#define OP_MATH_SBC_A_B 0x98
#define OP_MATH_SBC_A_C 0x99
#define OP_MATH_SBC_A_D 0x9A
#define OP_MATH_SBC_A_E 0x9B
#define OP_MATH_SBC_A_H 0x9C
#define OP_MATH_SBC_A_L 0x9D

#define OP_MATH_SBC_N_A 0xDE
#define OP_MATH_SBC_HL_A 0x9E

#define OP_MATH_AND_A_A 0xA7
#define OP_MATH_AND_A_B 0xA0
#define OP_MATH_AND_A_C 0xA1
#define OP_MATH_AND_A_D 0xA2
#define OP_MATH_AND_A_E 0xA3
#define OP_MATH_AND_A_H 0xA4
#define OP_MATH_AND_A_L 0xA5

#define OP_MATH_AND_N_A 0xE6
#define OP_MATH_AND_HL_A 0xA6

#define OP_MATH_OR_A_A 0xB7
#define OP_MATH_OR_A_B 0xB0
#define OP_MATH_OR_A_C 0xB1
#define OP_MATH_OR_A_D 0xB2
#define OP_MATH_OR_A_E 0xB3
#define OP_MATH_OR_A_H 0xB4
#define OP_MATH_OR_A_L 0xB5

#define OP_MATH_OR_N_A 0xF6
#define OP_MATH_OR_HL_A 0xB6

#define OP_MATH_XOR_A_A 0xAF
#define OP_MATH_XOR_A_B 0xA8
#define OP_MATH_XOR_A_C 0xA9
#define OP_MATH_XOR_A_D 0xAA
#define OP_MATH_XOR_A_E 0xAB
#define OP_MATH_XOR_A_H 0xAC
#define OP_MATH_XOR_A_L 0xAD

#define OP_MATH_XOR_N_A 0xEE
#define OP_MATH_XOR_HL_A 0xAE

#define OP_MATH_CP_A_A 0xBF
#define OP_MATH_CP_A_B 0xB8
#define OP_MATH_CP_A_C 0xB9
#define OP_MATH_CP_A_D 0xBA
#define OP_MATH_CP_A_E 0xBB
#define OP_MATH_CP_A_H 0xBC
#define OP_MATH_CP_A_L 0xBD

#define OP_MATH_CP_N_A 0xFE
#define OP_MATH_CP_HL_A 0xBE

#define OP_MATH_INC_A_A 0x3C
#define OP_MATH_INC_A_B 0x04
#define OP_MATH_INC_A_C 0x0C
#define OP_MATH_INC_A_D 0x14
#define OP_MATH_INC_A_E 0x1C
#define OP_MATH_INC_A_H 0x24
#define OP_MATH_INC_A_L 0x2C

#define OP_MATH_INC_HL_A 0x34

#define OP_MATH_DEC_A_A 0x3D
#define OP_MATH_DEC_A_B 0x05
#define OP_MATH_DEC_A_C 0x0D
#define OP_MATH_DEC_A_D 0x15
#define OP_MATH_DEC_A_E 0x1D
#define OP_MATH_DEC_A_H 0x25
#define OP_MATH_DEC_A_L 0x2D

#define OP_MATH_DEC_HL_A 0x35

#define OP_MATH_ADD_BC_HL 0x09
#define OP_MATH_ADD_DE_HL 0x19
#define OP_MATH_ADD_HL_HL 0x29
#define OP_MATH_ADD_SP_HL 0x39

#define OP_MATH_ADC_BC_HL 0x4A
#define OP_MATH_ADC_DE_HL 0x5A
#define OP_MATH_ADC_HL_HL 0x6A
#define OP_MATH_ADC_SP_HL 0x7A

#define OP_MATH_INC_BC 0x03
#define OP_MATH_INC_DE 0x13
#define OP_MATH_INC_HL 0x23
#define OP_MATH_INC_SP 0x33

#define OP_MATH_DEC_BC 0x0B
#define OP_MATH_DEC_DE 0x1B
#define OP_MATH_DEC_HL 0x2B
#define OP_MATH_DEC_SP 0x3B

#define OP_MATH_SBC_HL_BC 0x42
#define OP_MATH_SBC_HL_DE 0x52
#define OP_MATH_SBC_HL_HL 0x62
#define OP_MATH_SBC_HL_SP 0x72