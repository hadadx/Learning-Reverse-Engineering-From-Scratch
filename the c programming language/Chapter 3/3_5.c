#include <stdio.h>
#include <string.h>
#include <inttypes.h>

void itob(int n, char s[], int base);
void reverse(char s[]);
int main(void)
{
    char st[20];
    itob(900, st, 16);

    for (int i = 0; i < strlen(st); i++)
    {
        printf("%c", st[i]);
    }
    printf("\n");

    return 0;
}

void itob(int n, char s[], int base)
{
    int i = 0;
    if (base == 16)
    {
       
        do
        {
            int rm = n % 16;

            if (rm < 10)
            {
                s[i++] = rm + '0';
            }
            else
            {
                s[i++] = rm + 'a';
            }
            n /= 16;

        } while (n > 0);
        s[i++] = 'x';
        s[i++] = '0';
        s[i++] = '\0';
        reverse(s);
    }
}

void reverse(char s[])
{
   int start = 0;
   int end = strlen(s) -1;

   while (start < end)
   {
    char tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
    start++;
    end--;

   }
}