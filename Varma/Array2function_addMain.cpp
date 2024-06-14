#include <stdio.h>
#include "common.h"





void process_add(int [SIZE], int[SIZE], int[SIZE]);


int main()
{
	int arr_1[SIZE] = { 1,2,3,4,5 };
	int arr_2[SIZE] = { 1,2,3,4,5 };

	int results[SIZE];
	process_add(arr_1, arr_2, results);
}
