#include <stdio.h>
#include <wiringPi.h>

#define GPIO18 1
#define GPIO23 4

int count = 0;
int count1 = 0;

void Interrupt();

int main(){
	wiringPiSetup();

	pinMode(GPIO18, OUTPUT);
	
	if(wiringPiISR(GPIO18, INT_EDGE_RISING, &Interrupt) < 0){
		printf("end count[%d]\n", count);
		return 0;
	}

	while(1){
		;
	}
}

void Interrupt(){
	count++;
	printf("count[%d]\n", count);
}
