/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.
*/
#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 100
#define FLAG_ON 1
#define FLAG_OFF 0

void expand(char s1[], char s2[]);

int main(void)
{
    char buff_1[BUFF_SIZE];
    char buff_2[BUFF_SIZE];

    puts("Enter range of ascii: ");
    fgets(buff_1, sizeof(buff_1), stdin);

    expand(buff_1, buff_2);

    int i = 0;
    while (buff_2[i] != '\0')
        printf("%c", buff_2[i++]);

    puts("");
    return 0;
}

void expand(char s1[], char s2[])
{
    int s1_i = 0;
    int s2_i = 0;

    while (s1[s1_i] != '\0')
    {
        int check_1 = s1[s1_i - 1] == 'a' && s1[s1_i + 1] == 'z';
        int check_2 = s1[s1_i - 1] == 'A' && s1[s1_i + 1] == 'Z';
        int check_3 = s1[s1_i - 1] == '0' && s1[s1_i + 1] == '9';
        if (s1[s1_i] == '-')
        {
            if (check_1 || check_2 || check_3)
            {
                char tmp_1 = s1[s1_i - 1];
                for (; tmp_1 != s1[s1_i + 1]; s2_i++)
                {
                    s2[s2_i] = tmp_1;
                    tmp_1++;
                }
                s2[s2_i++] = tmp_1++;
                s1_i += 2;
            }
            else
            {
               s1_i++;
            }
        }
        else
        {
            s1_i++;
        }
    }
    if (s2_i == 0)
    {
        printf("EROR!");
    }
    
    s2[s2_i++] = '\0';
}
