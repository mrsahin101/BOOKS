#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int hat;

    hat = rand();     /* alt: use rand() */
    printf("%d is a random number.\n",hat);
    return(0);
}