#include <stdio.h>

#include <wiringPi.h>

#define GPIO18 1
#define GPIO24 5    

#define DELAY 100
int handlingI();
int handlingA();

int main()
{
    int Ivalue = 0, Icount = 0;
    int Avalue[2];
    int i = 0, check = 0;
    int pulseCount = 0;

    wiringPiSetup();
    
    pinMode(GPIO18, INPUT);
    pinMode(GPIO24, INPUT);
   
    while(1)
    {
        if(handlingI())
        {
            Icount += handlingA();
        }
        
    }
#if 0
    while(1)
    {
        Ivalue = digitalRead(GPIO24);
       
        if(Ivalue == 0)
        {
           if(handlingI() == 1)
           { 
               countI++; 
               printf("[%d]\n", countI);

               getchar();
           }
        }

 00  //     printf("%d\n", countI);
        delayMicroseconds(30);
    }
#endif

    return 0;
}

int handlingA()
{
    int Avalue[2];
    int pulseCount = 0;
    int Ivalue = 0;
    int i = 0;

    while(1)
    {
        if(255 == pulseCount)
            break;
        
        for(i=0; i<2; i++)
        {
            Avalue[i] = digitalRead(GPIO18);
         
            if(Ivalue = digitalRead(GPIO24))
            {
                 printf("------------[%d] [%d]\n", pulseCount, Ivalue); 
                 
                 getchar();
                 return Ivalue;
            }

            delayMicroseconds(DELAY);
        }
            
        if(1 == Avalue[0] && 0 == Avalue[1]) // && 1 == Avalue[2]
            pulseCount++;    
        else if(0 == Avalue[0] && 1 == Avalue[1] ) // && 0 == Avalue[2]
            pulseCount++;

#if 0
        if(!(pulseCount % 10) && 0 != pulseCount)
            printf("pulseCount[%d]\n", pulseCount);

#endif
    }
    
    Ivalue = digitalRead(GPIO24);
    
    printf("[%d] [%d]\n", pulseCount, Ivalue);
    getchar();

    return Ivalue;
}

int handlingI()
{
    int i = 0;
    int value = 0;
    int countZero = 0;

#if 1

    while(1)
    {
        value = digitalRead(GPIO24); // I 
        
        printf("[%d]\n", value);
        if(!value) 
            countZero++;
            
        else if(value && countZero > 100)
        {
            return 1;
        }
        
        delayMicroseconds(DELAY);
    }
    
#endif

#if 0
    for(i=0; i<256*3; i++)
    {
        value = digitalRead(GPIO24);
        
        if(value)
            return 0;
        
        delayMicroseconds(30);
    }

    while(1)
    {
        value = digitalRead(GPIO24);
    
        if(value)
        {
            return 1;
        }

        delayMicroseconds(30);
    } 

#endif

    return 0;
}   
