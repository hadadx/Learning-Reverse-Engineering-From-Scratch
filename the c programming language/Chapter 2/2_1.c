/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>



int main(void)
{
    printf("the range of types signed:\n");
    printf("char: %d - %d \n",CHAR_MIN,CHAR_MAX);
    printf("short: %d - %d \n",SHRT_MAX,SHRT_MAX);
    printf("int: %d - %d \n",INT_MIN,INT_MAX);
    printf("long: %ld - %ld \n",LONG_MIN,LONG_MAX);
    printf("flot: %.10e - %10e \n",FLT_MIN,FLT_MAX);
    
   


    printf("the range of types unsigned:\n");
    printf("char: 0 - %d \n",UCHAR_MAX);
    printf("short: 0 - %d \n",USHRT_MAX);
    printf("int: 0 - %u \n",UINT_MAX);
    printf("long: 0 - %lu \n",ULONG_MAX);
   





    



    
    return 0;
}



