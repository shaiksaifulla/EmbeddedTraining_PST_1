#include<stdio.h>
#define SIZE 10
#define a 10
#define b 20
#define c 30

void initializeAndPrintArray()
{
    double arr[SIZE];

    
    for (int x = 0; x < SIZE; x++) 
    {
        arr[x] = (a * x * x) + (b * x) + c;
        

    
    printf("[\t");
    for (int i = 0; i < SIZE; i++) 
    {
        printf("%0.2f\t\t", arr[i]);
    }
    printf("]\n");
}



