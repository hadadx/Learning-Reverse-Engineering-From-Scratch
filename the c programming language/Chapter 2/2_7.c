/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/
#include <stdio.h>

ind invert(int x,int p,int n);

int main()
{

    invert(0b10101100, 4, 3);  // Expected: 0b10110000 = 176
    invert(0b11111111, 7, 8);  // Expected: 0b00000000 = 0
    invert(0b00000000, 7, 8);  // Expected: 0b11111111 = 255
    invert(0b00001111, 3, 4);  // Expected: 0b11110000 = 240
    invert(0b10000001, 7, 1);  // Expected: 0b00000001 = 1
    invert(0b11110000, 3, 4);  // Expected: 0b00001111 = 15
    




    return 0;
}


int invert(int x,int p,int n)
{
    int s2 = ~(~0 << n) << (p + 1 -n);
    x = x ^ s2;
    printf("res = %d\n",x);

   return x;
}