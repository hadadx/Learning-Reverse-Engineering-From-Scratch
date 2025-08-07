
#include <stdio.h>
#include <string.h>
void ritoa(char var[], int num);
void reverse(char arr[]);

int main(void)
{
    int n = -1230;
    char ar[20];
    ritoa(ar, n);
    printf("ar = %s\n", ar);


    int n2 = 12300;
    char ar2[20];
    ritoa(ar2, n2);
    printf("ar2 = %s\n", ar2);
    return 0;
}

void ritoa(char var[], int num)
{
    static int i = 0;
    static int negative_flag = 0;

    if (num < 0 && negative_flag == 0)
    {
        negative_flag = 1;
       num = ~num + 1;
    }

    if (num <= 0)
    {
        if (negative_flag == 1)
        {
            var[i++] = '-';
            var[i++] = '\0';
            reverse(var);
            negative_flag = 0;
            i = 0;
        }
        else
        {
            var[i++] = '\0';
            reverse(var);
            negative_flag = 0;
            i = 0;
        }
    }

    else
    {
        var[i++] = (num % 10) + '0';
        ritoa(var, (int)(num / 10));
    }
}

void reverse(char arr[])
{
    int start = 0;
    int last = strlen(arr) - 1;

    for (; start < last; start++, last--)
    {
        char t = arr[start];
        arr[start] = arr[last];
        arr[last] = t;
    }
}