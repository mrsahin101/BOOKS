#include <stdio.h>

int strlength(char *string);

int main()
{
    char myName[] = "mrsahin101";

    printf("Your name is %d characters long!\n", strlength(myName));

    return(0);
}

int strlength(char *string)
{
    int x = 0;
    while(*string++)
        x++;
    return x;
}