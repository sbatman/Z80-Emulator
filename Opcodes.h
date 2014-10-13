#pragma once
#include "OP_LD.h"
#include "OP_Stack.h"
#include "OP_ETS.h"
#include "OP_Math.h"
#include "OP_CR.h"
#include "OP_RaS.h"
#include "OP_IO.h"

static const int  OP_NOP = 0x00;

static const int  OP_CPL = 0x2F;
static const int  OP_NEG = 0x44;
static const int  OP_CCF = 0x3F;
static const int  OP_SCF = 0x37;

static const int  OP_DI = 0xF3;
static const int  OP_EI = 0xFB;

static const int  OP_ED_IM_1 = 0x56;