#include <stdio.h>
#include "common.h"



#if 0
extern void init_array(double, double, double, int[SIZE]);
void process_array(int arr_g[SIZE]);
//extern void Array_demo();
//int arr_g[SIZE];

int main()
{
	double a = 1, b = 2, c = 3;
	int arr_g[SIZE];
	init_array(a, b, c, arr_g);
	process_array(arr_g);
	return 0;
}

int main()
{
	int* p; //xyz
	int a = 123;
	int a1[5];
	int b;

	p = &a;
	b = *p;	//derefrencing the pointer

	int arr_1[SIZE] = {1,2,3,4,5};
	int arr_2[SIZE] = {1,2,3,4,5};

	int* ptr_arr;
	ptr_arr = &arr_1;
	ptr_arr = arr_1;

	int result[SIZE];

	process_add(arr_1, arr_2, result); //[2,4,6,8,10];
	for (int i = 0; i < SIZE; i++)
	{
		printf("result[%d]: %d\n", i, result[i]);
	}
}

process_add(int arr_1[SIZE], int arr_2[SIZE], int result[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		result[i] = arr_1[i] + arr_2[i];
	}
}

process_add(int* arr_1_ptr, int* arr_2_ptr, int* result_ptr)
{
	for (int i = 0; i < SIZE; i++)
	{
		*(result_ptr+i) = *(arr_1_ptr+i) + *(arr_2_ptr+i);
	}
}


#endif






/*
Functions
Macros
Datatypes - char,int,float,double,void,bool
Arrays
Pointers
Structures

*/