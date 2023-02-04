#include <stdio.h>

int main()
{
    /* keep values small with short */
    short unsigned int a, b, u;
    short int s;

    a = 150;
    b = 300;
    u = a - b;
    s = a - b;

    printf("Unsigned variable u = %d\n", u);
    printf("Signed variable s = %d\n",s);
    return(0);
}