#pragma once
#define OP_CR_CALL 0xCD


#define OP_RST_00H 0xC7
#define OP_RST_08H 0xCF
#define OP_RST_10H 0xD7
#define OP_RST_18H 0xDF
#define OP_RST_20H 0xE7
#define OP_RST_28H 0xEF
#define OP_RST_30H 0xF7
#define OP_RST_38H 0xFF

#define OP_RET 0xC9
#define OP_RET_NZ 0xC0
#define OP_RET_Z 0xC8
#define OP_RET_NC 0xD0
#define OP_RET_C 0xD8
#define OP_RET_PO 0xE0
#define OP_RET_PE 0xE8
#define OP_RET_P 0xF0
#define OP_RET_N 0xF8