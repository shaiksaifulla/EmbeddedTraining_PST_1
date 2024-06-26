#include <stdio.h>

#if 0
//main(3,"pi","square","india")
int main(int argc, char* argv[])
{
	//argc = number of arguments passed to main
	//argv = array of strings

	//printf("argc = %d\n", argc);
	//printf("argv[0] = %s\n", argv[0]);
	//printf("argv[1] = %s\n", argv[1]);

	//1....declare a Integer stack of SIZE=10 on Heap
	// stackPtr = malloc(SIZE*sizeof(int))
	//2....
	int sum = 0;
	for (int i = 1; i < argc; i++)
	{
		//printf("%c:<%d>[%x]\t", *argv[i], *argv[i], *argv[i]);
		//sum = sum + atoi(argv[i]);
		push(stackPtr, atoi(argv[i]));
	}
	//3.elevate(stackPtr, factor)
	//factor is the last command argument
	//4.pop(stackPtr) and print the values.
	//5. frre the memory
	printf("sum = %d\n", sum);

#if 0
	char name1[] = "SAIF";
	char name2[] = { 'S', 'A', 'I', 'F' };

	printf("%c\n", *name1);
	printf("%c\n", name1[0]);

	printf("%s\n", name1);
	printf("%s\n", name2);

	char* names1[] = {&name1, &name2};
	char* names2[] = {name1, name2 };
	char* names3[] = {"Maheedar", "Verma", "Suraj"};
	printf("%c\n", names3[0][0]); //M
	printf("%c\n", **names3); //M
	printf("%s\n", *names3);//Maheedar

	printf("%c\n", names3[0][2]); //h
	printf("%c\n", *(*(names3+1)+4)); //a
#endif
}
#endif


#include "stack.h"
int main(int argc, char* argv[])
{
    // Declare and allocate memory for an integer stack of size 10 on the heap
    int* stackInt = (int*)malloc(SIZE * sizeof(int));


    // Push command-line arguments onto the stack
    for (int i = 1; i < argc - 1; i++)
    {
        push(stackInt, atoi(argv[i]));
    }

    // Elevate stack values by the last command argument
    int factor = atoi(argv[argc - 1]);
    elevate(stackInt, factor);

    // Pop and print values from the stack
    int out;
    while ((out = pop(stackInt)) != STACK_EMPTY)
    {
        printf("%d\n", out);
    }

    // Free the allocated memory
    free(stackInt);

    return 0;
}

//stack.c
#include "stack.h"
static int tos = -1;
int push(int* stack, int element)
{
    if (tos >= SIZE - 1)
    {
        printf("Stack is full\n");
        return STACK_FULL;
    }
    else
    {
        tos++;
        stack[tos] = element;
        printf("%d is pushed successfully\n", stack[tos]);
        return SUCCESS;
    }
}

int pop(int* stack)
{
    if (tos == -1)
    {
        printf("Stack is Empty\n");
        return STACK_EMPTY;
    }
    else
    {
        int temp = stack[tos];
        tos--;
        return temp;
    }
}

void elevate(int* stack, int factor)
{
    for (int i = 0; i <= tos; i++)
    {
        stack[i] *= factor;
    }
}

//stack.h
#pragma once
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define STACK_FULL -1
#define STACK_EMPTY -2
#define SUCCESS 0

int push(int* stack, int element);
int pop(int* stack);
void elevate(int* stack, int factor);

