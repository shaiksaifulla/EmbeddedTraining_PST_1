#include<stdio.h>
extern double areaOfCircle(double radius);

int main()
{
	double area = areaOfCircle(4.2);
	printf("area of circle is %lf", area);
	return area;
}