#include "Stack.h"

void Stack_Push_Byte(const byte byteToPush)
{
	_RAM[--_RSP] = byteToPush;
}

void Stack_Push_Word(const word wordToPush)
{
	byte highOrder = (wordToPush >> BYTEWIDTH) & MAXBYTE;
	byte lowOrder = (wordToPush) & MAXBYTE;
	_RAM[--_RSP] = highOrder;
	_RAM[--_RSP] = lowOrder;
}

word Stack_Pop_Word()
{
	byte A = _RAM[_RSP++];
	byte B = _RAM[_RSP++];
	return B << BYTEWIDTH | A;
}