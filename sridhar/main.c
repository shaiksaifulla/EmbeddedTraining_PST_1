#include <stdio.h>
# define SIZE 5
int main() {
	int arr_1[SIZE] = { 1,2,3,4,5 };
	int arr_2[SIZE] = { 1,2,3,4,5 };
	int result[SIZE];
	process_add(arr_1, arr_2, result);
	for (int i = 0; i < SIZE; i++) {
		printf("result[%d]: %d\n", i, result[i]);
	}
}

int  process_add(int arr_1[], int arr_2[], int result[]) {
	
	for ( int i = 0; i < SIZE; i++) {
		result[i] = arr_1[i] + arr_2[i];
	}
}