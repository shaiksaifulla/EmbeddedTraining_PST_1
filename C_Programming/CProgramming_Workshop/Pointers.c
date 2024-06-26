#define		NULL	(void*) 0

void pointers_demo()
{/*
 Danger here: never have uninitialized pointers
	int* p1;
	*p1 = 10;
*/

	int* p1 = NULL;
	// *p1 = 10;	/* Runtime error*/

	int i = 10;
	int j = 20;
	int* p2 = &i;
	p2 = &j;
	*p2 = 30;
}