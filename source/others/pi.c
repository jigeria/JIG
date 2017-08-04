#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>

#define GPIO18 1
#define GPIO24 5

int count = 0;
int countI = 0;

void InterruptA();
void InterruptI();
void (*old_fun)(int);
void handler(int signo);

int main()
{
    old_fun = signal(SIGINT, handler);
    wiringPiSetup();
 
    int valueA = 0;
    int valueI = 0;

    pinMode(GPIO18, OUTPUT);
    pinMode(GPIO24, OUTPUT);
    
    digitalWrite(GPIO18, LOW);
    digitalWrite(GPIO24, LOW);

    pinMode(GPIO18, INPUT);
    pinMode(GPIO24, INPUT);
    
#if 0 
    if( wiringPiISR(GPIO18, INT_EDGE_RISING, &InterruptA) < 0)
    {
        printf("end count[%d]\n", count);
        return 0;
    }
#endif

#if 0
    if( wiringPiISR(GPIO24, INT_EDGE_FALLING, &InterruptI) < 0)
    {
        printf("end countI[%d]\n", count);

        return 0;
    }
#endif

    while(1)
    {
        value = digitalRead(GPIO18);
        valueI = digitalRead(GPIO24);
        printf("value : [%d] [%d]\n", value, valueI);
         
        delayMicroseconds(50);
    }
    
#if 0
    while(1)
    {
        Interrupt();
    }
#endif


    return 0;

}

void handler(int signo)
{
   printf("count[%d]\n", count);
   printf("countI[%d]\n", countI);
   printf("[%d]\n", signo);
    
    exit(0);
}
void InterruptI()
{
   countI++;
#if 1
 //  printf("I : %d\n", countI);
 //  printf("A : %d\n", count);
  // printf("#");
#endif 
    printf("I : %d\n", countI);
 // printf("#\n");
}

void InterruptA()
{
//    int value;
    
//    value = digitalRead(GPIO18);
   
      printf("count[%d]\n", count);
//    printf("count : %d\n", count);
  
#if 0
    if(!(count % 10000) && count != 0)
    {
        printf("count[%d]\n", count);
    }
#endif

#if 0
    if(countI == 10)
    {
        printf("count[%d]\n", count);
        printf("countI[%d]\n", countI);
    }
#endif 
//    printf(".");
    count++;
}
