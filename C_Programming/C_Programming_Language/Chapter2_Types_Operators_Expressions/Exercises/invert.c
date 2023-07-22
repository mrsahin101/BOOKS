#include <stdio.h>

#define MY_32BIT_ONE        0x00000001

int invert(int x, int p, int n)
{
    int temporary = 0;
    /* inverting n bits from p in x*/
    for(int i = 0; i < 32; i++)
    {
        if(i >= p && i < p + n)
            continue;
        temporary += ((x >> i) & 0xFFFFFFFE) * (int)(pow(2.0, (double)i));
    }
    for(int i = 0; i < n; i++)
    {
        int mybit = (MY_32BIT_ONE) & (~((x >> p) & MY_32BIT_ONE));  
        temporary += (mybit << (p + i));
    }
    return temporary;
}

int main()
{
    printf("%d", invert(0xF7,0x00,0x2));
}