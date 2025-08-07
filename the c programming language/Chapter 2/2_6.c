/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main()
{

    int res = setbits(172, 4, 3, 15);

    printf("res = %d\n", res);

    return 0;
}


int setbits(int x, int p, int n, int y)
{

    int mask = ((1 << n) - 1) << (p + 1 - n);

    x &= ~mask;

    y = (y & ((1 << n) - 1)) << (p + 1 - n);

    return x | y;
}