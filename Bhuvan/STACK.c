#include "stack.h"

static int tos = -1;
int push(int stack[SIZE], int data[NUM_OF_ELEMENTS])
{
    {
        for (int i = 0; i<NUM_OF_ELEMENTS; i++)
        {
            if (tos == SIZE)
            {
                printf("stack is full\n");
                return STACK_FULL;
            }
            else
            {
                tos++;
                stack[tos] = data[i];
                printf("%d is pushed successfully\n", data[i]);
                //return SUCCESS;
            }
        }
    }
}

int pop(int stack[SIZE])
{
    int temp = 0;

    if (tos == -1)
    {
        printf("stack is empty\n");
        return STACK_EMPTY;
    }
    else
    {
        temp = stack[tos];
        tos--;
        return temp;
    }
}
