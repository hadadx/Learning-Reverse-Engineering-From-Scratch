#include <stdio.h>

#define START 0
#define END 1

main()
{

    int c;
    int newLine = 0, newWord = 0, newChar = 0;
    int countC = 0;

    int status = START;

    while ((c = getchar()) != EOF)
    {

        if (c == '\n')
        {
            countC = 0;
            newLine++;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            status = START;
            countC = 0;
        }

        else if (status == START && countC >= 2)
        {
            newWord++;
            status = END;
            newChar++;
            countC = 0;
        }
        else
        {
            countC++;
            newChar++;
        }
    }

    printf("new line = %d, new word = %d, new c = %d\n", newLine, newWord, newChar);
}