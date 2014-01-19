#define OP_SK_PUSH_BC 0xC5
#define OP_SK_PUSH_DE 0xD5
#define OP_SK_PUSH_HL 0xE5
#define OP_SK_PUSH_AF 0xF5

#define OP_SK_POP_BC 0xC1
#define OP_SK_POP_DE 0xD1
#define OP_SK_POP_HL 0xE1
#define OP_SK_POP_AF 0xF1

#define OP_SK_JR_E 0x18
#define OP_SK_JR_Z 0x28
#define OP_SK_JR_NC_E 0x30
#define OP_SK_JR_C_E 0x38
#define OP_SK_JR_NZ_E 0x20
#define OP_SK_JP 0xC3
#define OP_SK_JP_NZ 0xC2
#define OP_SK_JP_Z 0xCA
#define OP_SK_JP_NC 0xD2
#define OP_SK_JP_C 0xDA
#define OP_SK_JP_PO 0xE2
#define OP_SK_JP_PE 0xEA
#define OP_SK_JP_P 0xF2
#define OP_SK_JP_N 0xFA