static const int OP_SK_PUSH_BC = 0xC5;
static const int OP_SK_PUSH_DE = 0xD5;
static const int OP_SK_PUSH_HL = 0xE5;
static const int OP_SK_PUSH_AF = 0xF5;

static const int OP_SK_POP_BC = 0xC1;
static const int OP_SK_POP_DE = 0xD1;
static const int OP_SK_POP_HL = 0xE1;
static const int OP_SK_POP_AF = 0xF1;

static const int OP_SK_JR_E = 0x18;
static const int OP_SK_JR_Z = 0x28;
static const int OP_SK_JR_NC_E = 0x30;
static const int OP_SK_JR_C_E = 0x38;
static const int OP_SK_JR_NZ_E = 0x20;
static const int OP_SK_JP = 0xC3;
static const int OP_SK_JP_NZ = 0xC2;
static const int OP_SK_JP_Z = 0xCA;
static const int OP_SK_JP_NC = 0xD2;
static const int OP_SK_JP_C = 0xDA;
static const int OP_SK_JP_PO = 0xE2;
static const int OP_SK_JP_PE = 0xEA;
static const int OP_SK_JP_P = 0xF2;
static const int OP_SK_JP_N = 0xFA;

static const int OP_SK_DJNZ = 0x10;