#pragma once
#include "Registers.h"
#include "Ram.h"

void Stack_Push_Byte(const byte byteToPush);

void Stack_Push_Word(const word wordToPush);

word Stack_Pop_Word();