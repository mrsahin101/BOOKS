#include <stdio.h>

int main()
{
    const char *seven[] = 
    {
        "bashful",
        "doc",
        "dopey",
        "grumpy",
        "happy",
        "sneezy",
        "sleepy"
    };
    int x, c;

    for(x = 0; x < 7; x++)
    {
        c = 0;
        while(putchar(*(*(seven + x) + c++)));
        putchar('\n');
    }   
    return(0);
}