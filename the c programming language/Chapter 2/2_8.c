/*
Exercise 2-7. Write a fu nction invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/
#include <stdio.h>

int rightrot(int x, int n);

int main()
{

    printf("%d\n", rightrot(0b10101100, 3)); // Expected: 0b10110000 = 176
    // invert(0b11111111, 7, 8);  // Expected: 0b00000000 = 0
    // invert(0b00000000, 7, 8);  // Expected: 0b11111111 = 255
    // invert(0b00001111, 3, 4);  // Expected: 0b11110000 = 240
    // invert(0b100000001, 7, 1);  // Expected: 0b00000001 = 1
    printf("%d\n", rightrot(129, 7));
    // invert(0b11110000, 3, 4);  // Expected: 0b00001111 = 15

    /*
   x >> 3 =  00010101
   bits =    10010101
    
    00000001 10000001
    00000001


    */

    return 0;
}

int rightrot(int x, int n)
{
    if (x == 0) return 0;

    int d = 0;
    int t = x;
    while (t != 0)
    {
        t >>= 1;
        d++;
    }

    n = n % d;

    int right_bits = x & ~(~0 << n);
    right_bits <<= (d - n);
    x >>= n;

    return x | right_bits;
}