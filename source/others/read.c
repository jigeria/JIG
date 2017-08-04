#include <stdio.h>
#include <wiringPi.h>

#define GPIO24 1

int count =0;
int countI =0;

void InterruptA();

int main(void)
{
	wiringPiSetup();
	pinMode(GPIO24, INPUT);

	if(wiringPiISR(GPIO24, INT_EDGE_RISING, &InterruptA)<0)
	{
		printf("end count[%d]\n", count);
		return 0;
	}
	
	while(1)
	{
		;
	}

	return 0;
}

void InterruptA()
{
	count++;
	printf("count[%d]\n", count);
}

