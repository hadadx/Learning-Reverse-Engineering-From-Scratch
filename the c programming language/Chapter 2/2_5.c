/*
Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/

#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100
#define FOUND 1
#define NOT_FOUND 0

int any(char s1[], char s2[]);

int main(void)
{
    char buff[BUFF_SIZE];
    char buff2[BUFF_SIZE];

    printf("enter string 1:\n");
    fgets(buff, sizeof(buff), stdin);

    printf("\n");

    printf("enter string 2:\n");
    fgets(buff2, sizeof(buff2), stdin);
    int res = any(buff, buff2);

    printf("res = %d\n", res);

    return 0;
}

int any(char s1[], char s2[])
{
    int t = -1;
    int status = NOT_FOUND;
    int size = strlen(s1);

    for (int i = 0; s2[i] != '\0' ; i++)
    {
        char di = s2[i];
        status = NOT_FOUND;
        for (int j = 0; j < size; j++)
        {
            char dj = s1[j];

            if (s2[i] == s1[j] && s2[i] != '\n')
            {
                if (status == FOUND)
                {
                    ;
                   
                }
                else
                {
                     t = j;
                     status = FOUND;
                }
                
            }
        }
    }

    return t;
}