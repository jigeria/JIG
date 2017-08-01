#include <wiringPi.h>
#include <stdio.h>

#define GPIO18 1
#define GPIO24 5

#define DELAY 1000
int count = 0;

int main()
{
    int i = 0;
    int interruptI = 0;

    wiringPiSetup();

    pinMode(GPIO18, OUTPUT);
    pinMode(GPIO24, OUTPUT);

    getchar();

    while(1)
    {
        if(!(i % 10000) && i != 0)
           printf("-------count : %d\n", i);
        
        if(i == 200000)
            return 0;
#if 1
        if(interruptI == 256)
        {
            digitalWrite(GPIO24, HIGH);
            delayMicroseconds(DELAY);

            digitalWrite(GPIO24, LOW);
            delayMicroseconds(DELAY);

            printf("%d  %d\n", i, interruptI);
            interruptI = 0;
        }
#endif

        digitalWrite(GPIO18, HIGH);
        delayMicroseconds(DELAY);

        digitalWrite(GPIO18, LOW);
        delayMicroseconds(DELAY);

        i++;
        interruptI++;
    }

    return 0;
}

