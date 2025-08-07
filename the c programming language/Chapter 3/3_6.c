#include <stdio.h>
#include <string.h>
#include <inttypes.h>

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main(void)
{
    char st[20];
    itoa(-100, st,5);

    for (int i = 0; i < strlen(st); i++)
    {
        printf("%c", st[i]);
    }
    printf("\n");

    return 0;
}

void itoa(int n, char s[],int width)
{
    int i, sign;
    int flag = 0;
    if ((sign = n) < 0)
    {
        if (n == INT32_MIN || n == INT64_MIN)
        {
            n = ~n;
            flag = 1;
        }
        else
        {
            n = ~n + 1;
        }
    }

    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (flag)
    {
        s[0]++;
    }

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

    if (i < width)
    {
      while (i < width)
      {
        s[i] = ' ';
        i++;
      }
      s[i++] = '\0';
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