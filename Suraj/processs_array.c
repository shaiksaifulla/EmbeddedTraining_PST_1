/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define SIZE 5

int array1[SIZE];

void init_array(double a, double b, double c) {
  
	for (int i = 0; i < SIZE;i++) {
		array1[i] = (a * (i) * (i)) + (b * i) + c;
	}
	
	
}
void process_array() 
{
	for (int i = 0; i < SIZE; i++) {
	    printf("%d\t",array1[i]);
		if (array1[i] % 2 == 0) {
			printf("Even\n");
		 }
		else {
			printf("Odd\n");
		}
	}
}
int main()
{
    double a = 1, b = 2, c = 3;
    init_array(a,b,c);
    process_array();
}
