#include <stdio.h>

int main()
{
    char yours[25];
    char mine[25];
    int x = 0;
    printf("What is your name?");
    gets(yours);
    while(yours[x] != 0)
    {
        mine[x] = yours[x];
        x++;
    }
    mine[x] = '\0';
    printf("My name is %s just like your name is %s!\n", mine, yours);
    return(0);
}