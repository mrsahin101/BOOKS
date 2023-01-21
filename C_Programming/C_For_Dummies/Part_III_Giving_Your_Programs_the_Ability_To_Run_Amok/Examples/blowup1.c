#include <stdio.h>

int main()
{
    char c;

    printf("Would you like your computer to explode?");
    c = getchar();
    if(c == 'N')
    {
        printf("Okay. Whew!\n");
    }
    else
    {
        printf("OK: Configuring computer to explode now.\n");
        printf("Bye!\n");
    }
    return(0);
}