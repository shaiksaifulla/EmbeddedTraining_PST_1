#include "common.h"
#include <stdio.h>
extern int arr_g[SIZE];

/*void init_array(double a, double b, double c) {

    for (int index = 0; index < SIZE; index++) {
        arr_g[index] = (a * index * index) + (b * index) + c;
        printf("%lf\t", arr_g[index]);

    }
}
    void process_array()
    {
        for (int index = 0; index < SIZE; index++) {
            if (arr_g[index] % 2!=0)  {
                printf("%lf\t is even\n", arr_g[index]);

                //printf("arr_g[%d")
            }
            else {
                printf("%lf\t is odd\n", arr_g[index]);
            }
        }
    }*/

void init_array(double a, double b, double c)
{
	// Initialization
	//ax^2 + bx + c
	int index = 0;
	int result = 0;
	for (index = 0; index < SIZE; index++) {
		arr_g[index] = (a) * (index * index) + (b * index) + c;
		result = arr_g[index];
		//printf("%d\t", arr_g[index]);
	}
}

void process_array()
{
	// Processing
	//iterate through array and report an element is even or odd
	int index = 0;
	
	
	for (index = 0; index < SIZE; index++) {
		if ((arr_g[index] % 2) != 0)
		{
			//printf("arr_g[%d] = %d is Odd\n", index, arr_g[index]);
			arr_g[index] = 0;
			printf("arr_g[%d] = %d is Odd\n", index, arr_g[index]);
		}
		else
		{
			//printf("arr_g[%d] = %d is Even\n", index, arr_g[index]);
			arr_g[index] = 1;
			printf("arr_g[%d] = %d is Even\n", index, arr_g[index]);
		}
		//printf("%d\t", arr_g[index]);
	}
	
}

void init_array_2(double a, double b, double c, int arr_g[SIZE])
{
	// Initialization
	//ax^2 + bx + c
	int index = 0;
	int result = 0;
	for (index = 0; index < SIZE; index++) {
		arr_g[index] = (a) * (index * index) + (b * index) + c;
		result = arr_g[index];
		//printf("%d\t", arr_g[index]);
	}
}

void process_array_2(int arr_g[SIZE])
{
	// Processing
	//iterate through array and report an element is even or odd
	int index = 0;


	for (index = 0; index < SIZE; index++) {
		if ((arr_g[index] % 2) != 0)
		{
			//printf("arr_g[%d] = %d is Odd\n", index, arr_g[index]);
			arr_g[index] = 0;
			printf("arr_g[%d] = %d is Odd\n", index, arr_g[index]);
		}
		else
		{
			//printf("arr_g[%d] = %d is Even\n", index, arr_g[index]);
			arr_g[index] = 1;
			printf("arr_g[%d] = %d is Even\n", index, arr_g[index]);
		}
		//printf("%d\t", arr_g[index]);
	}

}
