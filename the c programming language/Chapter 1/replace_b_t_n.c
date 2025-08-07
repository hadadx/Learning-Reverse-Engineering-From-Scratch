#include <stdio.h>

int main()
{
    int c;
    int bs = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == 9)
        {
            putchar('\\');
            putchar('t');
        }

        else if (c == 127)
        {
             putchar('\\');
             putchar('b');
        }

         else if (c == 92)
        {
            putchar('\\');
            putchar('\\');
        }
        

        else
        {
            putchar(c);
        }
    }

    return 0;
}
