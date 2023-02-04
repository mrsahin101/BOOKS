#include <stdio.h>

int main()
{
    /* keep values small with short */
    int a, b, u, s;

    a = 150;
    b = 300;
    u = a - b;
    s = a - b;
    
    printf("Unsigned variable u = %u\n", u);
    printf("Signed variable s = %d\n",s);
    return(0);
}