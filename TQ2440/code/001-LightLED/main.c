#define REG(x) (*(volatile long long*)(x))

#define GPBCON 0x56000010
#define GPBDAT 0x56000014
#define GPBUP 0x56000014

void delay(int a)
{
	int i, j;
	for(i = 0; i < a; i++) {
		j = 0;
		while(j < a) {
			j++;
		}
	}
}

int InitGPBx(void)
{
	/* output config */
	REG(GPBCON) |= 0x00015400; 
	REG(GPBDAT) |= 0x000001e0; /* set high level */
	return 0;
}

void LED_ON(void)
{
	REG(GPBDAT) |= 0x000001e0; /* set high level */
	return;
}

void LED_OFF(void)
{
	REG(GPBDAT) &= ~(0x000001e0); /* set high level */
	return;
}

int main(void)
{
	InitGPBx();
	while (1) {
		LED_OFF();
		delay(1000);
		LED_ON();
		
	}
	return 0;
}
