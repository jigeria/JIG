#include <stdio.h>
#include <wiringPi.h>

#define GPIO18 1

int count = 0;

void interruptA()
{	
	count++;
	printf("count[%d]\n", count);
}

int main(void)
{
		wiringPiSetup();

		pinMode(GPIO18, INPUT);
			
		if(wiringPiISR(GPIO18, INT_EDGE_RISING, &interruptA) < 0)
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

