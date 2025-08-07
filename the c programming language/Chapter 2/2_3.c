#include <stdio.h>
#include <string.h>

void htoi(char hex[]); 

int main()
{
    char hex[19];
    

    printf("Enter Hex Value to convert to integer: \n");
    scanf("%s", hex);

    htoi(hex);

    return 0;
}






void htoi(char hex[])
{
    if (hex[0] != '0' || hex[1] != 'x' &&  hex[1] != 'X')
    {
        return;
    }

    long convert = 0;
    long pose = 1;

    

    for (int i = strlen(hex)-1 ; i > 0; i--)
    {
        char t = hex[i];

        if (hex[i] == 'x' || hex[i] == 'X')
        {
            break;
        }
        else
        {
            if (hex[i] >= '0' && hex[i] <='9')
            {
                if (hex[i] == '0')
                {
                    convert += 0 * pose;
                    pose *= 16;
                }

                else if (hex[i] == '1' )
                {
                    convert += 1 * pose;
                    pose *= 16;
                }
                else if (hex[i] == '2' )
                {
                    convert += 2 * pose;
                    pose *= 16;
                }
                else if (hex[i] == '3')
                {
                    convert += 3 * pose;
                    pose *= 16;
                }
                else if (hex[i] == '4' )
                {
                    convert += 4 * pose;
                    pose *= 16;
                }
                  else if (hex[i] == '5' )
                {
                    convert += 5 * pose;
                    pose *= 16;
                }  else if (hex[i] == '6' )
                {
                    convert += 6 * pose;
                    pose *= 16;
                }  else if (hex[i] == '7' )
                {
                    convert += 7 * pose;
                    pose *= 16;
                }  else if (hex[i] == '8' )
                {
                    convert += 8 * pose;
                    pose *= 16;
                }
                else
                {
                    convert += 15 * pose;
                    pose *= 16;
                }
                
            }

            else if (hex[i] >= 'A' && hex[i] <= 'F' || hex[i] >= 'a' && hex[i] <= 'f')
            {
                if (hex[i] == 'a' || hex[i] == 'A')
                {
                    convert += 10 * pose;
                    pose *= 16;
                }

                else if (hex[i] == 'b' || hex[i] == 'D')
                {
                    convert += 11 * pose;
                    pose *= 16;
                }
                else if (hex[i] == 'c' || hex[i] == 'C')
                {
                    convert += 12 * pose;
                    pose *= 16;
                }
                else if (hex[i] == 'd' || hex[i] == 'D')
                {
                    convert += 13 * pose;
                    pose *= 16;
                }
                else if (hex[i] == 'e' || hex[i] == 'E')
                {
                    convert += 14 * pose;
                    pose *= 16;
                }
                else
                {
                    convert += 15 * pose;
                    pose *= 16;
                }
            }

            else
            {
                return;
            }
        }
       
    }
     printf("%s = %ld\n", hex, convert);
}
