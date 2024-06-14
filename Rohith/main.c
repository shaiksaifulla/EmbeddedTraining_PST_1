#include<stdio.h>
#include"commom.h"
//int arr_g[SIZE];

void init_array(double a, double b, double c, int arr_g[SIZE]);
void process_array(int arr_g[SIZE]);
int main()
{
	int arr_g[SIZE];
	double a = 1, b = 2, c = 3;
	
	init_array(a, b, c, arr_g);
	process_array(arr_g);
	return 0;
}