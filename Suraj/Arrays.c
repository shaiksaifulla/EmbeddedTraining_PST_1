#include <stdio.h>
#define a 10
#define b 20
#define c 30
#define SIZE 5
/*
Write a function to declare and initialize an array of type double, size = 10 elements.
Initialize the array element with polynomial ax^2 + bx + c.
where x represent the array index for an element
a,b,c are 10,20,30 respectively.
use macros for a,b,c and SIZE.
print the array values in the following fashion

[	123.45		456.23		678.23		4578.23		1234.45	]
*/


void polynomial(){
   double array[SIZE] = {};
   for(int index=0;index<SIZE;index++){
       array[index] = (a) * (index*index) + (b*index) +c;
       printf("%lf\t", array[index]);
   }
}

int main()
{
  polynomial();
}
