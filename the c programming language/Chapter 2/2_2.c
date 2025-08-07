/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. 
*/

#define TRUE 1
#define FALSE 0

int main(void)
{

    int flag = TRUE;
    int i = 0;

    while (flag == TRUE)
    {
        if (i >= lim - 1)
        {
            flag = FALSE;
        }

        else
        {
            c = getchar();

            if (c == '\n')
            {
                flag = FALSE;
            }

            else if (c == EOF)
            {
                flag = FALSE;
            }
            else
            {
               s[i] = c;
               i++;
            }
        }
    }

    return 0;
}
