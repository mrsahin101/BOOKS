#include <stdio.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 10
void ungetch(int c);
int getch(void);
int getint(int *pn);

int main()
{
    int n, array[SIZE], getint(int *);

    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++);

    for(int i = 0; i < SIZE; i++)
        printf("%d", array[i]);
}
/* getint:  get next integer from input into *pn */

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))   /* skip white space */
            ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
            ungetch(c);  /* it is not a number */
            return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
            c = getch();
    for (*pn = 0; isdigit(c); c = getch())
            *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
            ungetch(c);
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push character back on input */
{
   if(bufp >= BUFSIZE)
      printf(" ungetch too many characters\n");

   else
      buf[bufp++] = c;
}