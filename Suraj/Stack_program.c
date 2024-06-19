#include "Stack.h"
#define STACK_FULL -1;
#define STACK_EMPTY -2;

static int top = -1;


int push(int arr[SIZE],int arr2[5]) {
	
	for (int i = 0; i < NUMBER_OF_ELEMENTS;i++) {
		if (top == SIZE-1) {
			printf("Stack is full");
			return STACK_FULL;
		}
		else {
			top++;
			arr[top] = arr2[i];
			printf("%d is push to stack\n", arr[top]);
		}
	}
	
	
}

int pop(int arr[]) {
	
	if (top == -1) {
		printf("Stack is empty\n");
		return STACK_EMPTY;
	}
	else {
		int temp = arr[top];
		top--;
		return temp;
	}
}