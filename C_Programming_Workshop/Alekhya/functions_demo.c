#include <stdio.h>
double sum(double, double);

int main()
{
	double res = sum(10, 20);
	printf("%lf\n", res);
}

double sum(double x, double y)
{
	return (x + y);
}