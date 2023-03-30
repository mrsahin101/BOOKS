#include <stdio.h>
#include <math.h>

int main()
{
    int x, r;
    unsigned short int v = 0;
    
    for(x = 0; x < 16; x++)
    {
        r = v | (int)(pow(2,x));
        printf("0x%04X | %5d = 0x%04X\n", v, (int)(pow(2,x)), r);
    }
    return(0);
}