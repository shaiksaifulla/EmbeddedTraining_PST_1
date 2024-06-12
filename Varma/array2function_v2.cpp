#include <stdio.h>
#include "common.h"



void initializeAndPrintArray1_v2(double a, double b, double c,int arr_g[SIZE])
{

    for (int x = 0; x < SIZE; x++)
    {
        arr_g[x] = ((a * x * x) + (b * x) + c);
    }


    for (int i = 0; i < SIZE; i++)
    {
        if (arr_g[i] % 2 == 0)
        {
            printf("even\t");
        }
        else
        {
            printf("odd\t");
        }
    }

}