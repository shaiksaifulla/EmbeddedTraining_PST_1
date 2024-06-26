#include <stdio.h>


#define MAX 10		// Macro

/*Data Types*/
// char, int, float, double, bool, void

/*Storage Class Specifiers*/
// Auto, Extern, Static, Register

/*Modifiers*/
// const, volatile

/*Data type modifiers*/
//short, long


/*MISRA - */

// short int.... 2 bytes
// long int..... 4 bytes

#include <stdint.h>
#if 0
typedef signed long int int32_t;
typedef signed short int int16_t;
typedef unsigned char uint8_t;
typedef signed short int* int16_t_ptr;
#endif
struct node {
	double data;
	struct node* next;
};

typedef struct node Node;
typedef struct node* NodePtr;


NodePtr head;
NodePtr tail;

typedef struct student {
	char name[25];
	int id;
	char gender;
} Student;

#if 0
int32_t main()
{
	//struct student saif;
	Student saif;

	//signed short int i = 10;
	int16_t i = 10;

	//signed short int* siPtr;
	int16_t_ptr siPtr;

	//struct node var1;
	Node var1;
}
#endif

void fun();
void myFun1(int32_t i);
void myFun2(int32_t i);

int main()
{
	//fun();
	//fun();
	//fun();

#if 0
	static int i = 0;
	i++;
	printf("i = %d\n", i);
	if(i != 3)
		main();
#endif

	myFun2(10);
}


void myFun1(int32_t i)
{
	printf("i = %d\n", i);
	if (i != 0) {
		i--;
		myFun1(i);
	}
}

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

void fun()
{
	static int i = 10;
	static int j = 0;
#if 0
	j = i + 1; // j=11, i = 10
	j = i++;	// j=10 - post increment
	// i will be 11
	j = ++i; // j=12, i=12 - pre increment
#endif
	i++; 
	j++;
	printf("i = %d\t j = %d\n", i, j);
}



//1 2 3 5 8 13 21