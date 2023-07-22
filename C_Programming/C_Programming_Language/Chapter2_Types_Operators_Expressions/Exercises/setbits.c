#include <stdio.h>
#include <math.h>

#define MY_32BIT_ONE        0x00000001

int my_setbits(int x, int p, int n, int y)
{
    int result = x;
    int rightmost = 0;
    /* Get Right most bits of y */
    for(int i = 0; i < n; i++)
    {
        rightmost += ((y >> i + 1) & MY_32BIT_ONE) * (int)(pow(2.0, (double)i)); 
    }
    /* Set right most bits in x from y to n*/
    for(int i = 0; i < n; i++)
    {
        int fromy = (rightmost & (MY_32BIT_ONE << i));
        result = (result | (fromy << p));
    }
    return result;
}  

int main()
{
    printf("%d\n", my_setbits(0xF0, 0x1, 0x2, 0xFF));
    printf("%X\n", my_setbits(0xF0, 0x1, 0x2, 0xFF));
}