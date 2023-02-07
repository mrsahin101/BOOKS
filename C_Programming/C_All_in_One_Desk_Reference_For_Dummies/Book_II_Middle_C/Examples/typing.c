#include <stdio.h>

int main()
{
    char ch;

    puts("Press ~ and Enter to stop");
    while(ch != '~')
    {
        ch = getchar();
    }
    return(0);
}