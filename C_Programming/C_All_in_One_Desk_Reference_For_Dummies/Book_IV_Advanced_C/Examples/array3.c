#include <stdio.h>

void showArray(int *array, int size);
void modArray(int *array, int size);

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13};

    puts("Original Array:");
    showArray(primes, 6);
    modArray(primes, 6);
    puts("Modified Array:");
    showArray(primes, 6);

    return(0);
}

void showArray(int *array, int size)
{
    int x;

    for(x = 0; x < size; x++)
        printf("Element %d : %d\n", x, *(array + x));
}

void modArray(int *array, int size)
{
    int x;

    for(x = 0; x < size; x++)
        *(array + x ) *= 2;         /* double the value */
}