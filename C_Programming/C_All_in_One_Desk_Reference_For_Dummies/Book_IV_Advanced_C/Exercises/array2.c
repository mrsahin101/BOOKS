#include <stdio.h>

void showArray(int *array);

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13};

    showArray(primes);

    return(0);
}

void showArray(int *array)
{
    int x;
    int size = sizeof(array);

    for(x = 0; x < size; x++)
        printf("Element %d : %d\n", x, *(array + x));
}