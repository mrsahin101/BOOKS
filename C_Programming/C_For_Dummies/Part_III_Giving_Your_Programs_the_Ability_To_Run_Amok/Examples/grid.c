#include <stdio.h>

int main()
{
    int a;
    char b;

    printf("Here is the grid...\n");

    for(a = 1; a < 10; a++)
    {
        for(b = 'A'; b < 'K'; b++)
        {
            printf("%d-%c ", a, b);
        }
        putchar('\n');      /* end of line */
    }
    return(0);
}