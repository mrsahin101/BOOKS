#include <stdio.h>

int main()
{
    char c;
    short int i;
    long x;
    float f;
    double d;

    puts("Variable sizes:");
    printf("Size of charvariable c = %d\n", sizeof(c));
    printf("Size of int variable i = %d\n", sizeof(i));
    printf("Size of long variable x = %d\n", sizeof(x));
    printf("Size of float variable f = %d\n", sizeof(f));
    printf("Size of double variable d = %d\n", sizeof(d));
    return(0);
}