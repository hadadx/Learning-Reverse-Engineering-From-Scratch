#include <stdio.h>
#define LENGTH 1000

int getlinee(char dest[]);
int checkToCountine();

int main()
{
    char holdline[LENGTH];

    while (1)
    {
        int tocuntinue = checkToCountine();
        if (tocuntinue != 0)
        {
            break;
        }

        printf("Enter Line To check: \n");
        
        int res = getlinee(holdline);

        if (res > 80)
        {
            printf("Line: %s\n", holdline);
        }
    }

    return 0;
}

int getlinee(char dest[] /*get destention*/)
{
    // get line
    //  count line
    // if(line counter > 80 sent to print)
    int c;
    int i = 0;

    while ((c = getchar()) != EOF)
    {

        if (c == '\n')
        {
            i++;
            break;
        }

        dest[i] = c;
        i++;
    }
    dest[i] = '\0';

    return i;
    /*return length*/
}

int checkToCountine()
{
    int c;
    printf("to check if string bigger than 80 press [ENTER] to quit press [Q]: \n");
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            return 0;
        }

        else if (c == 'q' || c == 'Q')
        {
           return 1;
        }
        else printf("to check if string bigger than 80 press [ENTER] to quit press [Q]: \n");
    };

    /*return length*/
}