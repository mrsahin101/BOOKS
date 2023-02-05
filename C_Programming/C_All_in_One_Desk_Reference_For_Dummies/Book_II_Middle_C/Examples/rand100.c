#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int hat;
    for(int i = 0; i < 100; i++)
    {    
        hat = rand();     /* alt: use rand() */
        printf("%d is a random number.\n",hat);
    }
    return(0);
}