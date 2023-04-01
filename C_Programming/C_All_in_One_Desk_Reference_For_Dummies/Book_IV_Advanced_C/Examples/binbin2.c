#include <stdio.h>

char *binString(int n);

int main()
{
    unsigned short int value;

    printf("Enter an integer value, 0 to 65,535: ");
    scanf("%d", &value);

    printf("Decimal value is %d\n", value);
    printf("Hexadecimal value is 0x%X\n", value);
    printf("Binary value is %s\n", binString(value));

    return(0);
}

char *binString(int n)
{
    static char bin[17];        /* must be static, in order to return local variable content.*/
    int x;

    for(x = 0; x < 16; x++)
    {
        bin[x] = n & 0x8000 ? '1' : '0';
        n <<= 1;
    }
    bin[16] = '\0';
    return(bin);
}