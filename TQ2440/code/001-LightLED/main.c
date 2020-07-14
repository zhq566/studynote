#include "s3c2440.h"

#define REG(x) (*(volatile unsigned long *)(x))

void delay(int a)
{
	int i;
	for(i = 0; i < a; i++) {
		;
	}
}

int InitGPBx(void)
{
	/* output config */
	GPBCON |= (1<<16|1<<14|1<<12|1<<10); 
	GPBDAT |= (1<<5|1<<6|1<<7|1<<8); /* set high level */
	return 0;
}

void LED_OFF(void)
{
	GPBDAT |= (1<<5|1<<8); /* set 5/8 light off */
}

void LED_ON(void)
{
	GPBDAT &= ~(1<<5|1<<8); /* set 5/8 light on */
}

int main()
{
	InitGPBx();
	while (1) {
		LED_OFF();
		delay(1000);
		LED_ON();
		delay(1000);
	}
	return 0;
}
