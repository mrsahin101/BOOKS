#include <stdio.h>

int main()
{
    int a, b;
    printf("Here is your two's table:\n\n");
    a = 1;
    for(b = 2; b <= 20; b = b+2)
    {
        printf("2 * %d = %d\n",a, b);
        a = a + 1;
    }
    return(0);
}