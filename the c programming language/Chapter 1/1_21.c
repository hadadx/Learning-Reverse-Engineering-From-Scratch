#include <stdio.h>
#define BUFFER_SIZE 1000
#define STOP 8

void entab(char string[], char dest[], int size);

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

    entab(buff, dest, i);

    for (int i = 0; dest[i] != '\0'; i++)
    {
        printf("%c", dest[i]);
    }
    printf("\n");

    return 0;
}

void entab(char string[], char dest[], int size)
{
   int i = 0;
    int saveStates = i;

    int countChars = 0;

    while (string[i] != '\0')

    {
        char c = string[i];

        if (string[i] == '\n')
        {
            dest[saveStates] = string[i];
            i++;
            saveStates++;
            countChars = 0;
        }

        else if (string[i] == ' ')
        {
            int sum = 0;

            for (int s = i; string[s] == ' '; s++)
            {
                sum++;
            }

            if (sum + countChars == STOP)
            {
                dest[saveStates++] = '\t';
            }

            else if (STOP % sum % 2 == 0)
            {
                for (int z = 0; z < sum  / STOP ; z++)
                {
                    dest[saveStates++] = '\t';

                }
                
            }
            
            else if (STOP < sum)
            {
                int t = sum;
                for (int y = 0; y <= STOP % t; y++)
                {
                    dest[saveStates++] = '\t';
                    t -= STOP;
                }

                for (int d = 0; d < t; d++)
                {
                    dest[saveStates++] = ' ';
                     
                }
            }
            else if (STOP > sum)
            {
                for (int p = 0; p < sum; p++)
                {
                    dest[saveStates++] = ' ';
                }
            }

            i += sum;
            countChars = 0;
        }

        else
        {
            dest[saveStates] = string[i];
            i++;
            saveStates++;
            countChars++;
        }
    }
}