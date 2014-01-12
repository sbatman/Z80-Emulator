#pragma once
#include "Ram.h"
#include "Registers.h"
#include <stdio.h>

void PrepTest()
{
	int x = 0;
	_RAM[x++] = 0x3e;
	_RAM[x++] = 0x01;
	_RAM[x++] = 0x47;
	_RAM[x++] = 0x06;
	_RAM[x++] = 0x10;
	_RAM[x++] = 0x0E;
	_RAM[x++] = 0x10;
	_RAM[x++] = 0x02;
	_RAM[x++] = 0x3e;
	_RAM[x++] = 0x00;
	_RAM[x++] = 0x0A;
}

void PostTest()
{
	printf("_A%*i\n", 8, _RA_A);
	printf("_B%*i\n", 8, _RB_A);
	printf("_C%*i\n", 8, _RC_A);
	printf("_D%*i\n", 8, _RD_A);
	printf("_E%*i\n", 8, _RE_A);
	printf("_H%*i\n", 8, _RH_A);
	printf("_L%*i\n", 8, _RL_A);
	printf("_Test%*i\n", 8, _RAM[0x1010]);
}
