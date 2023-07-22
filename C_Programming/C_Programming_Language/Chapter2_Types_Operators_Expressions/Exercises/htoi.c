#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[10];
    char hex_characteres[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C', 'D', 'E', 'F'};
    int result = 0;

    printf("Enter hexadecimal : ");
    scanf("%s", &input);

    for(int i = 0; i < strlen(input); i++)
    {
        input[i] = toupper(input[i]);
    }

    for(int i = strlen(input) - 1, k = 0; i >= 0; i--, k++)
    {
        int number;
        if(input[i] == 'X')
            break;
        for(int j = 0; i < 16; j++)
        {
            if(input[i] == hex_characteres[j])
            {
                number = j;
                break;
            }
        }

        result += (int)(number * (int)(pow((double)16, (double)k)));
    }
    printf("%d", result);
}