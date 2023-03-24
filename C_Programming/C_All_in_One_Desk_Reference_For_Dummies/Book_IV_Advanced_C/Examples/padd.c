#include <stdio.h>

int main()
{
    short int array[] = {2, 3, 5, 7, 9};
    int *pa;
    int x;

    for(x = 0; x < 5; x++)
    {
        pa = &array[x];
        printf("array[%d] at %p = %d\n", x, pa, array[x]);
    }
    return(0);
}