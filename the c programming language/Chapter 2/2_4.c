#include <stdio.h>

#define BUFF_SIZE 100
#define FOUND 1
#define NOT_FOUND 0

void squeeze(char s1[], char s2[]);

int main(void)
{
    char buff[BUFF_SIZE];
    char buff2[BUFF_SIZE];

    printf("enter string 1:\n");
    fgets(buff,sizeof(buff),stdin);
    
    printf("\n");

    printf("enter string 2:\n");
    fgets(buff2,sizeof(buff2),stdin);
    squeeze(buff, buff2);
    
    printf("clean from  char that show in string 2: %s \n", buff);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    char tmp_array[BUFF_SIZE];
    int t = 0;
    int status = NOT_FOUND;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        status = NOT_FOUND;

         for (int p = 0; s2[p] != '\0'; p++)
        {
            if (s1[i] == s2[p])
            {
                status = FOUND;
            }
        }

        if (status == NOT_FOUND)
        {
            tmp_array[t] = s1[i];
            t++;
        }
    }
    tmp_array[t++] = '\0';



    int j = 0;
    for (; tmp_array[j] != '\0'; j++)
    {
        s1[j] = tmp_array[j];
    }
    s1[j++] = '\0';
}