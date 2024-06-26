#include <stdio.h>
#include "Stack_v2.h"

static int tos = -1;

int push(int* stackPtr, int* dataPtr)
{
	for (int i = 0; i < NUM_OF_ELEMENTS; i++)
	{
		if (tos == SIZE)
		{
			printf("Stack is full\n");
			return STACK_FULL;
		}
		else
		{
			tos++;
			*(stackPtr + tos) = *(dataPtr + i);
			printf("%d is pushed succesfully\n", dataPtr[i]);

		}

	}

}



int pop(int* stack)
{
	int temp = 0;
	if (tos == -1)
	{
		printf("Stack is Empty\n");
		return STACK_EMPTY;
	}
	else
	{
		temp = *(stack + tos);
		*(stack + tos) = 0;
		tos--;
		return temp;
	}


}