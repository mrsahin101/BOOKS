#include <stdio.h>

main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
            printf("");
        else
            printf("%c", c);
    }
}

