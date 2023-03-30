#include <stdio.h>

int main()
{
    int primes[] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29};
    int* pointer = primes;
    pointer += 4;
    printf("The fifth prime number is %d\n", *pointer);
    pointer += 2;
    printf("and the seventh is %d\n", *pointer);

    return(0);
}