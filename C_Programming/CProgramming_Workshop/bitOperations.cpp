#include <stdio.h>
#include <stdint.h>

#if 0
#define MASK	0x01

#define LED_0	0x00
#define LED_1	0x01
#define LED_2	0x02
#define LED_3	0x03
#define LED_4	0x04
#define LED_5	0x05
#define LED_6	0x06
#define LED_7	0x07
int main()
{
	unsigned char REG_0 = 0x00;
#if 0 
	REG_0 = 0x01;		//LED_0
	REG_0 = 0x02;		//LED_1
	REG_0 = 0x04;		//LED_2
	REG_0 = 0x07;	
	REG_0 = 0x05;

	REG_0 = 0x00;
	REG_0 = 0x01 << 0;
	REG_0 = MASK << LED_0;
	REG_0 = 0x01 << 1;
	REG_0 = MASK << LED_1;
	REG_0 = 0x01 << 2;
	REG_0 = MASK << LED_2;
#endif
	REG_0 = 
		(MASK << LED_0) |
		(MASK << LED_1) |
		(MASK << LED_2) |
		(MASK << LED_3) |
		(MASK << LED_4) |
		(MASK << LED_5) |
		(MASK << LED_6) |
		(MASK << LED_7);
	
	printf("REG_0 = %x\n", REG_0);

	REG_0 = ~(MASK << LED_5) & REG_0; //RESET
	printf("REG_0 = %x\n", REG_0);

	REG_0 = (MASK << LED_5) | REG_0;  // SET
	printf("REG_0 = %x\n", REG_0);

	REG_0 = 0x00;

	REG_0 |=
		(MASK << LED_0) |
		(MASK << LED_4) |
		(MASK << LED_7);


	REG_0 &=
			~(
			(MASK << LED_0) |
			(MASK << LED_4) |
			(MASK << LED_7)
			);


	REG_0 &=
			~(MASK << LED_0) &
			~(MASK << LED_4) &
			~(MASK << LED_7);

	printf("REG_0 = %x\n", REG_0);
	


}

//Logical AND	&&
//Logical OR	||
/*
unsigned char a = 3;
unsigned char b = 2;
unsigned char  i1 = a && b;	//1 = TRUE
unsigned char  i2 = a || b;	//1 = TRUE

unsigned char  i3 = a & b;	//2
unsigned char  i4 = a | b;	//3
*/
//bitwise AND	&
//bitwise OR	|

#endif

#define LED_0	0x00
#define LED_1	0x01
#define LED_2	0x02
#define LED_3	0x03
#define LED_4	0x04
#define LED_5	0x05
#define LED_6	0x06
#define LED_7	0x07

#define MASK(BIT_POS)	(0x01 << BIT_POS)


int32_t main()
{
	uint8_t REG = 0x00;
	REG |= (MASK(LED_5) | MASK(LED_6) | MASK(LED_7) |MASK(LED_0));

	REG &= ~(MASK(LED_6) | MASK(LED_0));

	REG ^= (MASK(LED_5) | MASK(LED_7) | MASK(LED_0)); //XOR

	printf("REG = %x\n", REG);



	
}