#include <stdio.h>
#define LOWER 0/* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */


main()
{
    float celsius;
    int fahr;
    
    fahr = LOWER;
    printf("  Fahrenhet\t|\tCelsius\n");
    printf("----------------|---------------------\n");
    
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("\t%3.0f\t|\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}