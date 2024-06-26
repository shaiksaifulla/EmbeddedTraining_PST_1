/*** ARRAYS ***/

#include <stdio.h>

//int g1 = 100;// Global variable, 0
int g2 = 10;

//definition
void Array_demo()
{
#if 0
	int x;			// local variables, garbage
	int g1;	
	int y = 10;
	g1 = 1000;
	int x1 = x + 1;
#endif
#define SIZE 5
	int i;
	printf("sizeof(i) = %x\n", sizeof(i));

	//int arr1[];	//ERROR
	int arr1[SIZE];
	int arr2[] = {1,2,3,4,5};

	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;
	arr1[3] = 40;
	arr1[4] = 50;

	for (i = 0; i < SIZE; i++)
	{
		arr1[i] = i * 100;
	}


}

void dummy()
{
	
}


/*
Write a function to declare and initialize an array of type double, size = 10 elements.
Initialize the array element with polynomial ax^2 + bx + c.
where x represent the array index for an element
a,b,c are 10,20,30 respectively.
use macros for a,b,c and SIZE.
print the array values in the following fashion

[	123.45		456.23		678.23		4578.23		1234.45	]
*/
