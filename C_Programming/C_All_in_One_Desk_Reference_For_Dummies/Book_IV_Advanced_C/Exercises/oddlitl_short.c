#include <stdio.h>

int main()
{
    char c;
    short int i;
    long x;
    float f;
    double d;
    short int temp[8];

    puts("Variable sizes:");
    printf("Memory location of char variable c = %p\n", &c);
    printf("Memory location of int variable i = %p\n", &i);
    printf("Memory location of long variable x = %p\n", &x);
    printf("Memory location of float variable f = %p\n", &f);
    printf("Memory location of double variable d = %p\n", &d);
    for(i = 0; i < 8; i++)
        printf("Memory location of temp[%d] = %p\n", i, &temp[i]);
    return(0);
}