#include <stdio.h>

int main()
{
    char yours[25];
    char mine[] = "Henry";

    printf("What is your name?");
    gets(yours);
    if(mine == yours)
        printf("We both have the same name!\n");
    return(0);
}