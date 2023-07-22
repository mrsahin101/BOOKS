#include <stdio.h>

int my_atoi(char s[])
{
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main()
{
    char my_string[5] = "1234";

    printf("%d", my_atoi(my_string));
}