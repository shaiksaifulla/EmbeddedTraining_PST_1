/*
Register
Pass by Value
Pass by reference
Const
Volatile
*/



#if 0
int k;	//global or extern

int main()
{
	int i;	// local or auto
	static int j; // static
	register int l; // register
}
#endif
#include <stdio.h>


#if 0
int fun(int a);
int main()
{
	int a = 10;
	fun(a);
	printf("a = %d\n", a);
}

int fun(int a)
{
	a++;
	return a;
}
#endif

#if 0
int fun(int a);
int main()
{
	int a = 10;
	a = fun(a);
	printf("a = %d\n", a);
}

int fun(int a)	// pass by value
{
	a++;
	return a;
}
#endif

#if 0
void fun(int* iPtr);
void fun1(struct myStruct*);
void fun2(struct myStruct);

struct myStruct {
	int a;
	int b;
	int arr[10];
};
int main()
{
	struct myStruct var;
	int loc = 10;
	fun(&loc);
	printf("loc = %d\n", loc);
}

void fun(int* iPtr)	// Pass by address/reference
{
	*iPtr = 100;
	//int b = *iPtr;
}
#endif

volatile int i = 10;
//hint to the compiler not to optimize the code.

int main()
{
	//....
	//....
	while (1)
	{

		if (i == 10) {
			//if
		}
		else
		{
			//else
		}
	}
}


extern int i;
//interrupt service routing
void ISR()
{
	i++;
}