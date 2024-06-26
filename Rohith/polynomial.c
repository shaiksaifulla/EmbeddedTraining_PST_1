/* Online C Compiler and Editor */
#include <stdio.h>
#define a 10
#define b 20
#define c 30
#define size 10

double poly()
{
    double ele[size];

    for (int x = 0;x < size;x++)
    {
        ele[x] = (a * pow(x, 2) + (b * x) + c);
        printf("%lf\t", ele[x]);

    }

}

int main()
{

    poly(size);
    return 0;
}