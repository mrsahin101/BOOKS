#include <stdio.h>

int bitcount(unsigned x)
{
    int b;

    for(b = 0; x != 0; x >>= 1)
        if(x & 0x1)
            b++;
    return b;
}

int main()
{
    printf("%d", bitcount(6));
}