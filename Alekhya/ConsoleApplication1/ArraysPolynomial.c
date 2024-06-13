/*
Write a function to declare and initialize an array of type double, size = 10 elements.
Initialize the array element with polynomial ax^2 + bx + c.
where x represent the array index for an element
a,b,c are 10,20,30 respectively.
use macros for a,b,c and SIZE.
print the array values in the following fashion

[	123.45		456.23		678.23		4578.23		1234.45	]
*/


#include <stdio.h>

	double arraydemo();
	double array[10];
#define size 10
#define a 10
#define b 20 
#define c 40
	
	
	double arraydemo()
	{
		int index;
		for (index = 0; index < size; index++)
		{

			array[index] = (a * index * index) + (b * index) + c;
			printf("%.2f\t", array[index]);
		}
	}


int main()
{
	
	arraydemo();
	
}

