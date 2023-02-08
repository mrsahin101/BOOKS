#include <stdio.h>

int main()
{
    int x = 1;
    char a;

    while(x < 10)
    {
        a = 'A';
        while(a < 'J')
        {
            printf("%d%c\t", x, a);
            a++;
            if(x == 5 && a == 'F')
                goto end;
        }
        putchar('\n');
        x++;
    }
    end:
    return(0);
}