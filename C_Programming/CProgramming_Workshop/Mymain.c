#include "Stack_v2.h"
#include <stdlib.h>
#if 0
int main()
{
	int stackInt[SIZE];
	int elements_tobe_pushed[NUM_OF_ELEMENTS] = { 10, 20, 30, 40, 50 };
	int out = 0;

	push(stackInt, elements_tobe_pushed);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	//push(stackInt, 60, 70, 80, 90, 100);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	if (out == STACK_EMPTY)
	{
		printf("Pop failed with error %d\n", STACK_EMPTY);
	}
	
}

#endif

#if 0
int main()
{
	int stackInt[SIZE];
	int elements_tobe_pushed[NUM_OF_ELEMENTS] = { 10, 20, 30, 40, 50 };
	int out = 0;

	push(stackInt, elements_tobe_pushed);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	//push(stackInt, 60, 70, 80, 90, 100);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	printf("%d\n", out);

	out = pop(stackInt);
	if (out == STACK_EMPTY)
	{
		printf("Pop failed with error %d\n", STACK_EMPTY);
	}

}
#endif



int main()
{
	int arr[10];

	//Dynamic Memory Allocation
	// malloc, calloc, realloc....these functions return address
	// free

	//int *p = malloc(20);
	int* p = malloc(5 * sizeof(int));
	*p = 10;
	*(p + 1) = 20;
	*(p + 2) = 30;
	//....
	//....
	//....
	free(p);
	p = malloc(50);
	//....
	//....
}