#include <stdio.h>

#define MAX_LENGTH 11
#define START 0
#define END 1

int main()
{
    int length[MAX_LENGTH];

    int c;
    int countC = 0;

    int status = START;

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        length[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '\t')
        {

            if (status == START)
            {

                if (countC > 10)
                {
                    length[10]++;
                    countC = 0;
                    status = END;
                }

                else
                {
                    length[countC]++;
                    countC = 0;
                    status = END;
                }
            }

            else if (countC == 0)
            {
                length[0]++;
            }
        }

        else
        {
            countC++;
            status = START;
        }
    }

  for (int i = 0; i < MAX_LENGTH; i++)
  {
    printf("length of word: [%d], repetition: [%d]\n",i, length[i]);
  }
  

    

    return 0;
}
