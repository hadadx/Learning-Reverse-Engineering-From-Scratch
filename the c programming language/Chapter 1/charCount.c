#include <stdio.h>

#define SIZE 25

int main()
{
    int c; // init the char var

    int data[SIZE]; // contin the char amount for 0 = a tile 25 = z
    char symbols[SIZE];

    int count = 0x41; // array counter

    for (int i = 0; i < SIZE; i++)
        data[i] = 0; // init all the arry to 0

    for (int i = 0; i < SIZE; i++)
    {
        symbols[i] = count;
        count++;
    }

    while ((c = getchar()) != EOF) // get char tiil input = -1
    {
        if (c == 'a' || c == 'A')
        {
            data[0]++;
        }
        else if (c == 'b' || c == 'B')
        {
            data[1]++;
        }
        else if (c == 'c' || c == 'C')
        {
            data[2]++;
        }
        else if (c == 'd' || c == 'D')
        {
            data[3]++;
        }
        else if (c == 'e' || c == 'E')
        {
            data[4]++;
        }
        else if (c == 'f' || c == 'F')
        {
            data[5]++;
        }
        else if (c == 'g' || c == 'G')
        {
            data[6]++;
        }
        else if (c == 'h' || c == 'H')
        {
            data[7]++;
        }
        else if (c == 'i' || c == 'I')
        {
            data[8]++;
        }
        else if (c == 'j' || c == 'J')
        {
            data[9]++;
        }
        else if (c == 'k' || c == 'K')
        {
            data[10]++;
        }
        else if (c == 'l' || c == 'L')
        {
            data[11]++;
        }
        else if (c == 'm' || c == 'M')
        {
            data[12]++;
        }
        else if (c == 'n' || c == 'N')
        {
            data[13]++;
        }
        else if (c == 'o' || c == 'O')
        {
            data[14]++;
        }
        else if (c == 'p' || c == 'P')
        {
            data[15]++;
        }
        else if (c == 'q' || c == 'Q')
        {
            data[16]++;
        }
        else if (c == 'r' || c == 'R')
        {
            data[17]++;
        }
        else if (c == 's' || c == 'S')
        {
            data[18]++;
        }
        else if (c == 't' || c == 'T')
        {
            data[19]++;
        }
        else if (c == 'u' || c == 'U')
        {
            data[20]++;
        }
        else if (c == 'v' || c == 'V')
        {
            data[21]++;
        }
        else if (c == 'w' || c == 'W')
        {
            data[22]++;
        }
        else if (c == 'x' || c == 'X')
        {
            data[23]++;
        }
        else if (c == 'y' || c == 'Y')
        {
            data[24]++;
        }
        else if (c == 'z' || c == 'Z')
        {
            data[25]++;
        }
    }
    printf("\n");
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (data[i] == 0)
        {
            
        }
        else
        {
            printf("[");
            for (int g = 0; g <= data[i]; g++)
            {

                if (g == data[i])
                {
                    printf("] '%c'\n", symbols[i]);
                }
                else
                {
                    printf("#");
                }
            }
        }
    }

    // for (int i = 0; i < SIZE; i++)
    // {
    //     printf("data[%d] = %d\n",i,data[i]);
    // }

    return 0;
}
