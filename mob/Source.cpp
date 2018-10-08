#include "f0700.h"
#include <iostream>

int main()
{
	int a1 = 64;
	int a2[1408];
	for (int i = 0; i < 1408; i++)
	{
		a2[i] = i;
	}
	a2[20] = 10;
	int a3 = 2;
	int a4[116];
	for (int a = 0; a < 116; a++)
	{
		a4[a] = 0;
	}

	int test = f0700(a1, a2, a3, a4);

	printf("%d", test);

	system("pause");
	return 0;
}