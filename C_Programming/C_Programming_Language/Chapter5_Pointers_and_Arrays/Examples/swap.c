#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x = 1, y = 2;
    printf("Before swap, x : %d, y : %d\n", x, y);
    swap(&x, &y);
    printf("After swap, x : %d, y : %d", x, y);
}