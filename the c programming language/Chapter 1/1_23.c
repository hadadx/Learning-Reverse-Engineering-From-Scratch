#include <stdio.h>
#define BUFFER_SIZE 1000
#define IN_FLAG 1
#define OUT_FLAG 0

void clear_comments(char source[], char dest[], int size);

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

    clear_comments(buff, dest, i);

    for (int i = 0; dest[i] != '\0'; i++)
    {
        printf("%c", dest[i]);
    }
    printf("\n");

    return 0;
}

void clear_comments(char source[], char dest[], int size)
{
    int commend_astrich = OUT_FLAG;
    int commend_single = OUT_FLAG;

    int source_i = 0;
    int dest_i = 0;

    while (source[source_i] != '\0')
    {
        char ins = source[source_i];

        if (commend_single == IN_FLAG)
        {
            if (source[source_i] == '\n')
            {
                commend_single = OUT_FLAG;
                
            }
            else
            {
                source_i++;
            }
        }

        else if (commend_astrich == IN_FLAG)
        {
            if (source[source_i] == '/')
            {
                commend_astrich = OUT_FLAG;
                source_i++;
        
            }
            else
            {
                source_i++;
            }
        }

        else if (source[source_i] == '/' && source[source_i + 1] == '*')
        {
            commend_astrich = IN_FLAG;
            source_i++;
        }

        else if (source[source_i] == '/' && source[source_i + 1] == '/')
        {

            commend_single = IN_FLAG;
            source_i++;
        }
        else
        {
            dest[dest_i] = source[source_i];
            source_i++;
            dest_i++;
        }
    }
    dest[dest_i++] = '\0';
}
