#include <stdio.h>

int main()
{
    char ch;

    puts("Start typing");
    puts("Press ~ then Enter to stop");

    while(ch != '~')
    {
        ch = getchar();
    }
    printf("Thanks!\n");
    return(0);
}