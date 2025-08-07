#include <stdio.h>

main()
{

    float cels, limit, jumps, fahr;

    cels = 0;
    limit = 60;
    jumps = 1;
    printf("  Celsius\t|\t Fahrenhet\n");
    printf("----------------|---------------------\n");
    while (cels <= limit)
    {
        fahr = (9.0 / 5.0 * cels) + 32;
        printf("\t%d\t|\t %3.1f\n", (int)cels, fahr);
        cels += jumps;
    }
}
