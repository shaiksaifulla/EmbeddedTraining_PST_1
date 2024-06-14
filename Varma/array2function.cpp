#include <stdio.h>
#include "common.h"
int arr_g[SIZE];


void initializeAndPrintArray1(double a, double b, double c) {
    
    for (int x = 0; x < SIZE; x++) {
        arr_g[x] = ((a * x * x) + (b * x) + c);
    }

    
    for (int i = 0; i < SIZE; i++) {
        if (arr_g[i] % 2 == 0) {
            printf("even\t");
        }
        else {
            printf("odd\t");
        }
    }
    
}
