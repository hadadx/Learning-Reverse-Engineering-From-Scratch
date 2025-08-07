#include <stdio.h>
#define BUFF_SIZE 1000
int reverse(char string[], int size);

int main(int argc, char const *argv[])
{
    char hold_string[BUFF_SIZE];
    int c;
    int i = 0;

    while ((c = getchar()) != EOF)
    {
        hold_string[i] = c;
        i++;
    }
    hold_string[i] = '\0';
    printf("\n");
    reverse(hold_string, i);

    return 0;
}

int reverse(char string[], int size)
{
    char buff[size];
    int t = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        buff[t] = string[i];
        t++;
    }
    buff[t] = '\0';


    for (int f = 0; f < t; f++)
    {
       printf("%c",buff[f]);
    }

    printf("\n");
    
}