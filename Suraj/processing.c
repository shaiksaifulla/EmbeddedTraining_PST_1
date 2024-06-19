#include "common.h"
#include <stdio.h>

void process_add(int arr1[], int arr2[], int result[]) {
	for (int i = 0; i < SIZE;i++) {
		result[i] = arr1[i] + arr2[i];
	}
}