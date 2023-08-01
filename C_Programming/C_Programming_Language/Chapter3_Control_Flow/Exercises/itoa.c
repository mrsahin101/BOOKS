#include <stdio.h>
#include <string.h>
#include <math.h>
/* Let's think of a signed char, just because it's 8-bits long. The number -128
 * in binary is 10000000 (in a two's complement machine). To obtain its positive
 * counterpart (128) you find the two's complement of 10000000. You'll end-up
 * finding that the two's complement of 10000000 is exactly 10000000. The
 * computer cannot tell the difference, and it'll rekon this binary as -128
 * still, as MSB = 1. And that's why what tells a negative from a positive
 * number in a computer is the MSB (1 for negative, 0 for positive).
 *
 * The original "itoa" tries to convert the number to positive (i.e., calcs the
 * two's complement of the number), and that's not possible (that's why INT_MAX
 * equals |INT_MIN| - 1). */

/* reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for(i = 0; j = strlen(s) - 1, i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa : convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if((sign = n) < 0)              /* record sign */
        n = -n;
    i = 0;
    
    do                              /* generate digits in reverse order */
    {
        s[i++] = n % 10 + '0';      /* get next digit */
    }while((n /= 10) > 0);           /* delete it*/

    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int number = (int) (pow(2.00, 6.00) -1 ) ;
    char strnumber[20];

    itoa(number, strnumber);

    printf("%s", strnumber);
}