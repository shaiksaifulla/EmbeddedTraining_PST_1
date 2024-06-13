#include"STACK.h"
#include<stdio.h>

int main()
{
	int stackInt[SIZE];
	int elements[NUM_OF_ELEMENTS] = { 10,20,30,40,50 };
	int element[NUM_OF_ELEMENTS] = {60,70,80,90,100};
	int out = 0;

	push(stackInt, elements);
	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	push(stackInt, element);
	out = pop(stackInt);
	printf( "%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);
}