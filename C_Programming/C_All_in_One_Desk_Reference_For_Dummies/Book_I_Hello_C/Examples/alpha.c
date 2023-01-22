#include <stdio.h>

int main()
{
    char alpha = 'A';

    printf("Character %c has code %d.\n", alpha, alpha);
    alpha = alpha + 1;
    printf("Character %c has code %d.\n", alpha, alpha);
    alpha = alpha + 1;
    printf("Character %c has code %d.\n", alpha, alpha);
    return(0);
}