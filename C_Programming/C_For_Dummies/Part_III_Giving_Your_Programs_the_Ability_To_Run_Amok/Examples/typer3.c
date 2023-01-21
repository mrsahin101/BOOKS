#include <stdio.h>

int main()
{
    puts("Start typing");
    puts("Press ~ then Enter to stop");

    while(getchar() != '~');

    printf("Thanks!\n");
    return(0);
}