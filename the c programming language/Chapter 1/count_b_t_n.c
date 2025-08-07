#include <stdio.h>





int main()
{
    int c;

    int tab = 0, blanks = 0, newLine = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            tab++;   
        }
        else if (c == ' ')
        {
            blanks++;
        }
        else if (c == '\n')
        {
            newLine++;
        } 
    }
    printf ("blanks = %d, tabs = %d, newlines = %d\n",blanks,tab,newLine);
    
    return 0;
}
