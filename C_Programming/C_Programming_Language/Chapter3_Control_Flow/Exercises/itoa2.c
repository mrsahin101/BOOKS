/* Question : Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width;
 * the converted number must be padded with blanks on the left if necessary to make it wide enough 
 */
#include <stdio.h>
#include <string.h>

#define WIDTH_SIZE  10

/* reverse string s in place */
void padding_func(char s[], int padding)
{
    for(int i = strlen(s) - 1; i >= 0; i--)
    {
        for(int j = 0; j < padding; j++)
        {
            s[i + j + 1] = s[i + j];
        }
    }
    for(int i = 0; i < padding; i++)
        s[i] = ' ';
    s[padding + strlen(s) -1 ] = '\0';
}

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
void itoa(int n, char s[], int padding)
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
    //printf("%s", s);
    padding_func(s, padding);
}

int main()
{
    int number = 1514;
    char strnumber[20];

    itoa(number, strnumber, 3);

    printf("%s", strnumber);
}