#include <stdio.h>

int main()
{
    /* This program is wrong. Just to demonstrate that bit shifting doesnt work on floats. */
    float my_float = 3.1415;
    float shifted;

    shifted = (int)my_float >> 1;

    printf("My number is : %f and divied by 2 is %f", my_float, shifted);

    return(0);
}