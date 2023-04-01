#include <stdio.h>

int main()
{
    const char *seven[] = {
        "bashful",
        "doc",
        "dopey",
        "grumpy",
        "happy",
        "sneezy",
        "sleepy"
    };
    int x;

    for(x = 0; x < 7; x++)
    {
        printf("%s\n", *(seven + x));
    }
    return(0);
}