#include <stdio.h>
#define LENGTH 1000
#define START 0
#define END 1

int getText(char dest[]);
int removeBlanksAndTabs(char form[], char dest[], int size);

int main()
{
    char holdline[LENGTH];
    char fixline[LENGTH];

    int res = getText(holdline);

    removeBlanksAndTabs(holdline, fixline, res);

    printf("\n");
    printf("%s\n", fixline);
    return 0;
}

int getText(char dest[] /*get destention*/)
{
    // get line
    //  count line
    // if(line counter > 80 sent to print)
    int c;
    int i = 0;

    while ((c = getchar()) != EOF)
    {
        dest[i] = c;
        i++;
    }

    dest[i] = '\0';

    return i;
    /*return length*/
}

int removeBlanksAndTabs(char form[], char dest[], int size)
{
    // run on dest and cheack if have more than 1 space and if tabs and spase in the end

    // if dest[i] == char and dest[i++] == cher good
    // if dest[i] == spase and dest[i++] == space not good
    // if dest[i] == spase and dest[i++] == tab not good
    // if dest[i] == tab and dest[i++] == '\n' not good
    // if dest[i] == space and dest[i++] == '\n' not good

    // flag = 0
    // c = char
    // if char == ' ' flag 1 if char not ' ' flag == 0
    //  if flag 1 char == array[i]

    int c;
    int i = 0;
    int id = 0;
    int spacewrite = 0;
    int enterwrite = 0;

    while (form[i] != '\0')
    {
        c = form[i];

        if (c == ' ')
        {
            spacewrite = 0;
            if (id == 0)
            {
                ;
            }
            else if (form[i + 1] == ' ' ||form[i + 1] == '\0' ||  form[i + 1] == '\n' || form[i + 1] == '\t')
            {
                spacewrite = 1;
            }

            else if (spacewrite == 0)
            {
                dest[id] = c;
                spacewrite = 1;
                id++;
            }
            else
            {
                ;
            }
        }

        else if (c == '\t')
        {

            if (id == 0)
            {
                ;
            }
            else if (form[i] != ' ' || form[i] != '\n' || form[i] != '\t' || form[i] != '\0')
            {
                ;
            }
            

            else if (dest[id] != ' ' || dest[id] != '\n' || dest[id] != '\t' || dest[id] != '\0')
            {
                dest[id] = ' ';
                spacewrite = 1;
                enterwrite = 0;
                id++;
            }
            else
            {
                ;
            }
        }

        else if (c == '\n')
        {
             enterwrite = 0;
             if (id == 0)
            {
                ;
            }
            else if (form[i + 1] == ' ' ||form[i + 1] == '\0' ||  form[i + 1] == '\n' || form[i + 1] == '\t')
            {
                enterwrite = 1;
            }

            else if (enterwrite == 0)
            {

                dest[id] = c;
                enterwrite = 1;
                id++;
            }
            else
            {
                ;
            }
        }

        else
        {
            dest[id] = c;
            id++;
        }

        i++;
    }
    dest[id++] = '\0';
}
