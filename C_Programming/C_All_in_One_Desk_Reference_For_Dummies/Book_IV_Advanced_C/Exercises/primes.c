#include <stdio.h>

int main()
{
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    for(int i = 0; i < 10; i++)
        printf("%d\n", primes[i]);
    
    return(0);
}