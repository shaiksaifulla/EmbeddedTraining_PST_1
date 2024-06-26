#include <stdio.h>
#if 0
union myUnion {
	unsigned char c;
	unsigned int i;
};

// Structure Padding
struct myStruct {
	unsigned char c1;
	double d;
	int i;
};

int main()
{
	struct myStruct var;
	union myUnion u_var;
	printf("%d\n", sizeof(var)); 
	var.c1 = 'x';
	var.d = 10.20;
	var.i = 123;
	printf("var.c1 = %c\n", var.c1);
	printf("var.d = %lf\n", var.d);
	printf("var.i = %d\n", var.i);


	printf("%d\n", sizeof(u_var));
	u_var.c = 'A';
	u_var.i = 0xFFFFFFFF;
	u_var.c = 'A';
	printf("u_var.c = %x\n", u_var.c);	//0x41
	printf("u_var.i = %x\n", u_var.i);	//0xFFFFFFFF
}

#endif
// Little Endian
// Big Endian

union PSW {
	unsigned int REG;
	unsigned char STATUS_FLAG;
	unsigned char RESERVED_1;
	unsigned char RESERVED_2;
	unsigned char ERROR_FLAG;
};

int main()
{
	union PSW psw;
	psw.REG = 0xFFFFABCD;
	psw.STATUS_FLAG = 0x55;

	printf("%x\n", psw.REG);

	if (psw.REG == 0x55FFABCD)
	{
		//BE
	}
	else if (psw.REG == 0xFFFFAB55)
	{
		//LE
	}

	int i = 0xABCDEF55;
	char* p = (char*)&i;
	printf("%x\n", *p);

	//AB 8000 55
	//CD 8001 EF
	//EF 8002 CD
	//55 8003 AB



}