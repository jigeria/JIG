#include <stdio.h>
#include <wiringPi.h>

#define GPIO23 4
#define GPIO24 5

int main()
{
    int i = 0;
    int Avalue[2], Bvalue[2];
    int ApulseCount = 0, BpulseCount = 0;
    int Acount = 0, Bcount = 0;

    wiringPiSetup();

    pinMode(GPIO23, INPUT);
    pinMode(GPIO24, INPUT);

    while(1)
    {
        for(i=0; i<2; i++)
        {
            Avalue[i] = digitalRead(GPIO23);
            Bvalue[i] = digitalRead(GPIO24);
        }
        
        if(1 == Avalue[0] && 0 == Avalue[1]) // && 1 == Avalue[2]
            ApulseCount++;    
        else if(0 == Avalue[0] && 1 == Avalue[1] ) // && 0 == Avalue[2]
            ApulseCount++;

        if(1 == Bvalue[0] && 0 == Bvalue[1]) // && 1 == Avalue[2]
            BpulseCount++;    
        else if(0 == Bvalue[0] && 1 == Bvalue[1] ) // && 0 == Avalue[2]
            BpulseCount++;
              
        if(ApulseCount == 255)
        {
            printf("ApulseCount[%d]  ", ApulseCount);
            ApulseCount = 0;
           
            Acount++;
            printf("Acount[%d]\n", Acount);
        }
        
        if(BpulseCount == 255)
        {
             printf("BpulseCount[%d]  ", BpulseCount);
             BpulseCount = 0;

             Bcount++;
             printf("Bcount[%d]\n", Bcount);
        }

        delayMicroseconds(25);
    }

    return 0;
}

