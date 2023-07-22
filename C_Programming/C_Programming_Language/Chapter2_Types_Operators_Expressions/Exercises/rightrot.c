#include <stdio.h>

int rightrot(int x, int n)
{
    int result = x;

    for(int i = 0; i < n; i++)
    {
        int mybit = result & 0x00000001;
        result = result >> 1;
        int temp = 0x00000001 & mybit;
        result += ((temp) << ((sizeof(int) * 8) - 1));
    }
    return result;
}

int main()
{
    printf("%X", rightrot(0x02, 0x1));
}