#include <stdio.h>
#include <wiringPi.h>

#define GPIO18 1
#define GPIO24 5

int count = 0;
int countI = 0;

void InterruptA();
void InterruptI();

int main()
{
    wiringPiSetup();

    pinMode(GPIO18, INPUT);
    pinMode(GPIO24, INPUT);

#if 1
    if( wiringPiISR(GPIO18, INT_EDGE_RISING, &InterruptA) < 0)
    {
        printf("end count[%d]\n", count);
        return 0;
    }
#endif

#if 1 
    if( wiringPiISR(GPIO24, INT_EDGE_RISING, &InterruptI) < 0)
    {
        printf("end countI[%d]\n", count);

        return 0;
    }
#endif

    while(1)
    {
       // InterruptA();
       ;
    }
    
#if 0
    while(1)
    {
        Interrupt();
    }
#endif


    return 0;

}

void InterruptI()
{
   countI++;

   printf("I : %d\n", countI);
   printf("A : %d\n", count);
}

void InterruptA()
{

    int value, value1;
#if 0   
    value = digitalRead(GPIO18);
    delayMicroseconds(1);
    value1 = digitalRead(GPIO18);
 

    if(value == 1 && value==0)
       count++;
//   printf(".");
    printf("count[%d]\n", count);
//    printf("count : %d\n", count);
#endif

#if 1
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
}
