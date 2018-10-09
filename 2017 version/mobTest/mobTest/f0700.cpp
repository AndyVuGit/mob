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


	int index, count, negative;
	int *current, *next;

	index = 0;
	count = 0;
	negative = -1;
	a2[a1 - 1] = 10000; //Limit used to break out of the loop
	a2[a1] = -10000; //Limit used to break out of the loop

	do
	{
		current = &a2[index]; //points to the first index of v4cx 
		++index;
		next = &a2[index]; //points to the 2nd index of v4 
		int diffCheck = negative * (*current - *next);
		if (a3 > diffCheck)
		{
			do
			{
				int currentIndex = negative * (*current);
				int nextIndex = negative * (*next);
				if (nextIndex > currentIndex)
					current = next;
				next += 1; //Points next to the next index
				++index;
				diffCheck = negative * (*current - *next);
			} while (a3 > diffCheck);
		}
		negative = -negative;
		count += 1;
	} while (index < a1);
	return count;
}

signed int __cdecl f0700Original(int a1, int *a2, int a3, int *a4)
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

	v4 = a2;
	v5 = a1;
	v6 = 0;
	v7 = a2[a1];
	v14 = a2[a1 - 1];
	o1 = 0;
	v9 = -1;
	a2[a1 - 1] = 10000;
	v15 = v7;
	a2[a1] = -10000;
	a2a = 0;

	if (a1 > 0)
	{
		v10 = a4;
		do
		{
			v11 = (int)&v4[v6++];
			*v10 = v11;
			v12 = (int)&v4[v6];
			if (v9 * (*(int *)v11 - *(int *)v12) < a3)
			{
				do
				{
					if (v9 * *(int *)v12 > v9 * *(int *)*v10)
						*v10 = v12;
					v13 = *(int *)(v12 + 4);
					v12 += 4;
					++v6;
				} while (v9 * (*(int *)*v10 - v13) < a3);
				v5 = a1;
			}
			++v10;
			v9 = -v9;
			o1 = a2a++ + 1;
		} while (v6 < v5);
	}
	if (o1 % 2)
		--o1;
	v4[v5 - 1] = v14;
	v4[v5] = v15;
	return o1;
}



