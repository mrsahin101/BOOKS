#include <stdio.h>

#define BUFSIZE     50

void ungetch(char c)
{
    static int bufp = 0;
    static int buf[BUFSIZE];

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
int main()
{
    printf("Hello world");
}