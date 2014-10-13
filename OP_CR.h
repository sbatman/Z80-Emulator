#pragma once
static const int OP_CR_CALL = 0xCD;

static const int  OP_RST_00H = 0xC7;
static const int  OP_RST_08H = 0xCF;
static const int  OP_RST_10H = 0xD7;
static const int  OP_RST_18H = 0xDF;
static const int  OP_RST_20H = 0xE7;
static const int  OP_RST_28H = 0xEF;
static const int  OP_RST_30H = 0xF7;
static const int  OP_RST_38H = 0xFF;

static const int  OP_RET = 0xC9;
static const int  OP_RET_NZ = 0xC0;
static const int  OP_RET_Z = 0xC8;
static const int  OP_RET_NC = 0xD0;
static const int  OP_RET_C = 0xD8;
static const int  OP_RET_PO = 0xE0;
static const int  OP_RET_PE = 0xE8;
static const int  OP_RET_P = 0xF0;
static const int  OP_RET_N = 0xF8;