#include <stdio.h>

int temperature(float start, float till , float rise);


int main()
{
    temperature(0,60,1);
    
    return 0;
}

int temperature(float start, float till , float rise)
{
    float fahr;
    printf("  Celsius\t|\t Fahrenhet\n");
    printf("----------------|---------------------\n");
    while (start <= till)
    {
        fahr = (9.0 / 5.0 * start) + 32;
        printf("\t%d\t|\t %3.1f\n", (int)start, fahr);
        start += rise;
    }

    return 0;
}