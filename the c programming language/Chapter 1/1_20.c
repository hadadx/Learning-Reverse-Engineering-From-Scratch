#include <stdio.h>
#define BUFFER_SIZE 1000
#define STOP 8

void detab(char string[], char dest[], int size);

int main(void)
{
    int c;
    char buff[BUFFER_SIZE];
    char dest[BUFFER_SIZE];

    int i = 0;

    while ((c = getchar()) != EOF)
    {
        buff[i] = c;
        i++;
    }
    buff[i] = '\0';
    printf("\n");

    detab(buff, dest, i);

    for (int i = 0; dest[i] != '\0'; i++)
    {
        printf("%c", dest[i]);
    }
    printf("\n");

    return 0;
}

void detab(char string[], char dest[], int size)
{
    int newline = 0;
    int conuntC = 0;
    int i = 0;
    int saveStats = 0;

    while (string[i] != '\0')
    {
        // count till stop if '\t' | stop - count; for

        if (conuntC > STOP)
        {
            conuntC = 0;
        }

        else if (string[i] == '\t')
        {
            for (int g = 0; g <= STOP - conuntC; g++)
            {
                dest[saveStats++] = ' ';
            }

            conuntC = 0;
            i++;
        }
        else
        {
            if (string[i] == '\n')
            {
                dest[saveStats] = string[i];
                i++;
                saveStats++;
                conuntC = 0;

            }
            else
            {
                dest[saveStats] = string[i];
                i++;
                saveStats++;
                conuntC++;
            }
        }
    }

    dest[saveStats] = '\0';
}