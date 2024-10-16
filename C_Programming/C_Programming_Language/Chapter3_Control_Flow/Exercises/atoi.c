#include <stdio.h>
#include <ctype.h>

/* atoi : convert s to integer; version 2*/
int my_atoi(char s[])
{
    int i, n, sign;

    for(i = 0; isspace(s[i]); i++);      /* skip white space */

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '+' || s[i] == '-')      /* skip sign */
        i++;

    for(n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n; 
}



int main()
{
    char string[5] = "123";

    printf("%d", 5 + my_atoi(string));
}