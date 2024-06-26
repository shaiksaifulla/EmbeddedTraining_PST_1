#include "Stack_v2.h"

static int tos = -1; // scope of TOS is limited to this file only

int push(int* stackPtr, int* dataPtr)
{
	for (int i = 0; i < NUM_OF_ELEMENTS; i++)
	{
		if (tos == SIZE)
		{
			printf("STACK is FULL\n");
			return STACK_FULL;
		}
		else
		{
			tos++;
			*(stackPtr + tos) = *(dataPtr + i);
			printf("%d is pushed successfully\n", dataPtr[i]);
			//return SUCCESS;
		}
	}
}

int pop(int* stack)
{
	int temp = 0;

	if (tos == -1)
	{
		printf("STACK is Empty\n");
		return STACK_EMPTY;
	}
	else
	{
		temp = *(stack+tos);
		*(stack + tos) = 0;
		tos--;
		return temp;
	}
}