#include <stdio.h>
#include "stack.h"

static int tos = -1;

int push(int stack[SIZE], int elements[NUM_OF_ELEMENTS])
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
				stack[tos] = elements[i];
			printf("%d is pushed succesfully\n", stack[tos]);
			
		}

	}
	
}



int pop(int stack[SIZE])
{
	int temp = 0;
		if (tos == -1)
		{
			printf("Stack is Empty\n");
			return STACK_EMPTY;
		}
		else
		{
			temp = stack[tos];
			stack[tos] = 0;
			tos--;
			return temp;
		}


}