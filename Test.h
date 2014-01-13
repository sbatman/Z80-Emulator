#pragma once
#include "Ram.h"
#include "Registers.h"
#include <stdio.h>

void PrepTest()
{
	int x = 0;
	FILE * f = fopen("test.bin", "rb");
	fread(_RAM, 10000, 1, f);
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
	FILE * f = fopen("out.bin", "wb");
	fwrite(_RAM, 1, RAMLENGTH, f);
	fclose(f);
}
