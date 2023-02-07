#include <stdio.h>

int main()
{
    puts("Press ~ and Enter to stop");
    while(getchar() != '~');
    return(0);
}