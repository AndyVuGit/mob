#include "f0700.h"
#include <iostream>

int main()
{
	//Sample Input
	int a1 = 128;
	int a2[1408];
	for (int i = 0; i < 1408; i++)
	{
		a2[i] = i;
	}
	a2[20] = -400;
	a2[30] = 400;
	a2[500] = 0;
	int a3 = 4;
	int a4[116];
	for (int a = 0; a < 116; a++)
	{
		a4[a] = 0;
	}

	int test = f0700(a1, a2, a3, a4);

	printf("test = %d\n", test);

	return 0;
}