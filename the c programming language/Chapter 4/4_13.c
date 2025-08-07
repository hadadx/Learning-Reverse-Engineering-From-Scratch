#include <stdio.h>
#include <string.h>

void rReverse(char arr[], int start, int end);

int main(void)
{
    char s[] = "hello";
    int len = strlen(s);
    rReverse(s, 0, len - 1);
    printf("s = %s\n", s);
    return 0;
}

void rReverse(char arr[], int start, int end)
{
    if (start >= end)
        return;

    char tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;
    
    rReverse(arr, start + 1, end - 1);
}