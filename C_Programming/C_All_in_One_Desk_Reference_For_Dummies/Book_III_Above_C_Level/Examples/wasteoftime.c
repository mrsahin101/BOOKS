#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char input[128];
    int x = 0, digits = 0;

    printf("Please enter your street adress:");
    gets(input);

    while(input[x])
    {
        if(isdigit(input[x]))
            digits++;
        x++;
    }
    printf("There is %d digits in your street adress.\n", digits);
    return(0);
}