#include <stdio.h>

int main()
{
    int cent[8];
    int x;
    int* pointer = cent;

    for(x = 0; x < 8; x++)
    {
        *pointer = (x + 1) * 100;
        printf("cent[%d] = %d\n", x, *pointer++);
    }
    return(0);
}
