#include "stack.h"

static int tos = -1;
int push(int* stackPtr, int* dataPtr)
{
    {
        for (int i = 0; i < NUM_OF_ELEMENTS; i++)
        {
            if (tos == SIZE)
            {
                printf("stack is full\n");
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
}

int pop(int* stackPtr)
{
    int temp = 0;

    if (tos == -1)
    {
        printf("stack is empty\n");
        return STACK_EMPTY;
    }
    else
    {
        temp = *(stackPtr+tos);
        *(stackPtr + tos) = 0;
            tos--;
        return temp;
    }
}
