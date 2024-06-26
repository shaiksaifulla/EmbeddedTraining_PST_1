#include "common.h"
//extern int arr_g[SIZE];

void init_array_v2(double a, double b, double c, int arr_g[SIZE])
{
	// Initialization
	//ax^2 + bx + c
	int index = 0;
	for (index = 0; index < SIZE; index++) {
		arr_g[index] = (a) * (index * index) + (b * index) + c;
		//printf("%d\t", arr_g[index]);
	}
}

void process_array_v2(int arr_g[SIZE])
{
	// Processing
	//iterate through array and report an element is even or odd
	int result_arr[SIZE];
	int index = 0;
	for (index = 0; index < SIZE; index++) {
		if ((arr_g[index] % 2) != 0)
		{
			printf("arr_g[%d] = %d is Odd\n", index, arr_g[index]);
			//1
		}
		else
		{
			printf("arr_g[%d] = %d is Even\n", index, arr_g[index]);
			//0
		}
		//printf("%d\t", arr_g[index]);
		//TODO: print the result array.
	}
}

/*
* arr_g[5] = [ 3  7 10 15 20 ]
* result[5] = [ 1 1 0 1 0 ]
*/