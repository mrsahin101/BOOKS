#include <stdio.h>

int main()
{
    short int array[] = {2, 3, 5, 7, 9};
    int *pa;
    int x;

    pa = array;
    for(x = 0; x < 5; x++)
    {
        printf("array[%d] at %p = %d\n", x, pa, array[x]);
        pa++;
    }
    return(0);
}