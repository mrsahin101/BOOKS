#include <stdio.h>

int main()
{
    int a,b;

    printf("Here is your two's table:\n\n");
    for(a = 1, b = 2; b <= 20; a = a + 1, b = b + 2)
        printf("2 * %d = %d\n", a, b);
    return(0);
}