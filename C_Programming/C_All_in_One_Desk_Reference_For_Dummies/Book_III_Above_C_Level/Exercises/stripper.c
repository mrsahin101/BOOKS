#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[128];
    int x = 0;
    printf("Enter your poem phrase :");
    gets(input);

    while(input[x])
    {
        if(isalpha(input[x]))
            input[x] = tolower(input[x]);
        else
            input[x] = ' ';
        x++;
    }
    puts(input);
    return(0);
}