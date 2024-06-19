#include <stdio.h>
#include "Stack.h"


int main() {
	
	int stackInt[SIZE];
	int deletedEle =  0;
	int arr1[5] = {10,20,30,40,50};
	
	push(stackInt, arr1);
	
	deletedEle = pop(stackInt);
	printf("Deleted element is:%d\n", deletedEle);
	
	deletedEle = pop(stackInt);
	printf("Deleted element is:%d\n", deletedEle);

	deletedEle = pop(stackInt);
	printf("Deleted element is:%d\n", deletedEle);
	
	int arr2[NUMBER_OF_ELEMENTS] = {70,50,60,80,90};
	push(stackInt, arr2);

	deletedEle = pop(stackInt);
	printf("Deleted element is:%d\n", deletedEle);

	deletedEle = pop(stackInt);
	printf("Deleted element is:%d\n", deletedEle);

	deletedEle = pop(stackInt);
	printf("Deleted element is:%d\n", deletedEle);

	for (int i = 0; i < SIZE;i++) {
		printf("%d\t", stackInt[i]);
	}
}