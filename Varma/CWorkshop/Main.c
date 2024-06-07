#include <stdio.h>
#define PI 3.14159265358979323846

double areaOfCircle(double radius) {
    return PI * radius * radius;
}


int main() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf_s("%lf", &radius);
    double area = areaOfCircle(radius);
    printf("The area of the circle with radius %.2lf is %.2lf\n", radius, area);
    return 0;
}
