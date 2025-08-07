#include <stdio.h>
#define SIZE_BUFF 1000

void escape(char s[], char t[]);

int main(void)
{
    char buff[SIZE_BUFF];
    char buff2[SIZE_BUFF];
    int c;
    int i = 0;

    puts("Enter string to replace space and tabs: ");

    while ((c = getchar()) != EOF)
    {
        buff[i] = c;
        i++;
    }

    buff[i++] = '\0';
    puts("");

    escape(buff, buff2);

    puts("");

    return 0;
}

void escape(char s[], char t[])
{
    int index = 0;
    int indexS = 0;
    while (s[indexS] != '\0')
    {
        switch (s[indexS])
        {
        case '\n':
            t[index++] = '\\';
            t[index++] = '\\';
            t[index++] = 'n';
            indexS++;
            break;

        case '\t':
            t[index++] = '\\';
            t[index++] = '\\';
            t[index++] = 't';
            indexS++;
            break;
        
         case ' ':
            t[index++] = '\\';
            t[index++] = '\\';
            t[index++] = 's';
            indexS++;
            break;
        

        default:
            t[index++] = s[indexS];
            indexS++;
            break;
        }
    }
    t[index++] = '\0';

    for (int j = 0; j < index; j++)
    {
        printf("%c", t[j]);
    }
}