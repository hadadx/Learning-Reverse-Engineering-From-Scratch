#include <stdio.h>
#define BUFFER_SIZE 1000
#define SPACES_SIZE 4

void flod(char source[], char dest[], int size);

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

    flod(buff, dest, i);

    for (int i = 0; dest[i] != '\0'; i++)
    {
        printf("%c", dest[i]);
    }
    printf("\n");

    return 0;
}

void flod(char source[], char dest[], int size)
{
    int index_source = 0;
    int count_spaces = 0;
    int lest_pos = 0;
    

    while (source[index_source] != '\0')
    {
        // word identefide between spaces
        // if ['\n'] && spaces < 8 == '\n' if  spaces > 8 == replace the space with '\n'

        if (source[index_source] == '\n')
        {

            dest[index_source] = source[index_source];
            index_source++;
            count_spaces = 0;
            lest_pos = count_spaces;
        }

        else if (source[index_source] == ' ')
        {
            if (count_spaces == SPACES_SIZE)
            {
                dest[index_source] = '\n';
                index_source++;
                count_spaces = 0;
            }

            else
            {
                dest[index_source] = source[index_source];
                index_source++;
                count_spaces++;
            }
        }

        else
        {
            dest[index_source] = source[index_source];
            index_source++;
        }
    }
}