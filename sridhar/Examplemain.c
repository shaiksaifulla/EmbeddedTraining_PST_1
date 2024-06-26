#include <stdio.h>
#include <stdint.h>

void myFun2(int32_t i)
{
	static int32_t cur = 1;
	//int32_t cur = 1;
	static int32_t prev = 1;
	static int32_t prev_prev = 0;
	cur = prev_prev + prev;
	printf("%d\t", cur);
	if (i != 1) {
		prev_prev = prev;
		prev = cur;
		i--;
		myFun2(i);
	}
	//printf("%d\t", cur);
}

int main() {
	int32_t n = 10; // Number of terms to print starting from the 4th Fibonacci number

	printf("Fibonacci Series starting from the 4th number: ");
	myFun2(n);
	printf("\n");

	return 0;
}
