#include <stdio.h>
#include "common.h"

void process_add(int arr_1[SIZE], int arr_2[SIZE], int results[SIZE]) {


	for (int i = 0; i < SIZE; i++)
	{
		results[i] = arr_1[i] + arr_2[i];
		printf("result[%d]: %d\n", i, results[i]);

	}
}