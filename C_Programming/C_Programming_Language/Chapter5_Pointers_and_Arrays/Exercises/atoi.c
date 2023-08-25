#include <stdio.h>
#include <string.h>
#include <math.h>

int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}
int atoi(const char *string)
{
    // this function doesnt make sure if errorenous string passed. User must pass proper value to this function
    int number = 0;

    for(int i = 0, j = strlen(string) - 1; i < strlen(string); i++, j--)
    {
        number += (((int)(*(string + j))) - 0x30) * ipow(10, i);
    }
    return number;
}

int main()
{
    char *string = "1342";

    printf("%d", atoi(string));
}