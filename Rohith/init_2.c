#include<stdio.h>
#include "commom.h"
//extern int arr_g[SIZE];

void init_array(double a, double b, double c, int arr_g[SIZE])
{

	int index = 0;
	for (index = 0; index < SIZE; index++) {
		arr_g[index] = (a) * (index * index) + (b * index) + c;

	}
}

void process_array(int arr_g[SIZE])
{

	int index = 0;
	int res = 0;
	for (index = 0; index < SIZE; index++) {
		if ((arr_g[index] % 2) == 0)
		{
			res = 0;
			printf("arr_g[%d] = %d is even\n and reult is %d\n", index, arr_g[index], res);
		}
		else
		{
			res = 1;
			printf("arr_g[%d] = %d is odd\n and result is %d\n", index, arr_g[index], res);
		}

	}
}
