#pragma once
#include "Registers.h"
#include "Ram.h"
//Thought it might be worth moving stack related functionality into here

void Stack_Push_Byte(byte byteToPush)
{
 _RAM[--_RSP] = byteToPush;
}
void Stack_Push_Word(word wordToPush)
{
 byte highOrder = (wordToPush >> (8 * 1)) & 0xff;;
 byte lowOrder = (wordToPush >> (8 * 0)) & 0xff;;
 _RAM[--_RSP] = highOrder;
 _RAM[--_RSP] = lowOrder;
}

word Stack_Pop_Word()
{
 byte A = _RAM[_RSP++];
 byte B = _RAM[_RSP++];
 return B << 8 | A;
}