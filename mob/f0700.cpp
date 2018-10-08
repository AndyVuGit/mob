#include "f0700.h"

signed int __cdecl f0700(int a1, int *a2, int a3, int *a4)
{
	// Pre-Condition:
	//    a1: possible input value = [64, 128, 256]
	//    a2: is an int[1408] array
	//        possible input value for each element = [-4095 ... 4095]
	//    a3: possible input value = [2, 3, 4, 5, 6]
	//    a4: is an int[116] array
	//        possible input value for each element = [0]
	//
	// Post-Condition:
	//    a1: value shouldn't change
	//    a2: value shouldn't change
	//    a3: value shouldn't changed
	//    a4: value can changed

	int *v4;
	int v5;
	int v6;	
	int v7;
	int o1;
	int v9;
	int *v10;
	int v11;
	int v12;
	int v13;
	int v14;
	int v15;
	int a2a;

	v4 = a2; //array
	v5 = a1;
	v6 = 0;
	v7 = a2[a1];
	v14 = a2[a1 - 1];
	o1 = 0;
	v9 = -1;
	a2[a1 - 1] = 10000;
	v15 = v7; //a2[a1] before change
	a2[a1] = -10000;
	a2a = 0;

	//if (a1 > 0) //redundant
	//{
		v10 = a4;
		do
		{
			v11 = (int)&v4[v6++]; //points to the first index of v4
			*v10 = v11; //current index of v10 is v11
			v12 = (int)&v4[v6]; //points to the 2nd index of v4
			if (v9 * (*(int *)v11 - *(int *)v12) < a3) // (-1 * v4[v6] - v4[v6 + 1]) < 2
			{
				do
				{
					if (v9 * *(int *)v12 > v9 * *(int *)*v10) // -1 * v4[v6 + 1] > -1 * v4[v6]
						*v10 = v12;
					v13 = *(int *)(v12 + 4); // v13 = v4[v6 + 2]
					v12 += 4; // v12 = third index of v4
					++v6;
				} while (v9 * (*(int *)*v10 - v13) < a3); // -1 * (a2[0] - (a2[v + 1]) < 2 
				//v5 = a1; //redundant
			}
			++v10; //2nd index of v4
			v9 = -v9; //v9 = 1
			o1 = a2a++ + 1; // o1 = a2a + 1; a2a++;
		} while (v6 < v5); // v6 increases 2 each time. v5 is always a1
	//}
	if (o1 % 2)
		--o1;
	v4[v5 - 1] = v14; //redundant?
	v4[v5] = v15; //redundant?
	return o1;
}