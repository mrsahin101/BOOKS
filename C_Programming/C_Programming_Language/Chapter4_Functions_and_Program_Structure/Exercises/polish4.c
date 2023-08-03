#include <stdio.h>
#include <string.h> // for strlen()

/*
    Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?
*/

#define BUFSIZE 100 // buffer size for getch and ungetch

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void);
void ungetch(int c);
void ungets(char s[]);

int main()
{
    int i;
    char s[] = "Hello World";
    ungets(s);
    for (i = 0; i < 11; i++)
        printf("%c", getch());
    return 0;
}

// get a (possibly pushed back) character
// checks to see if there are any chars in buffer. If there are, get those and return it. If not, call getchar() from stdio.h to get next char from input
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
// if bufp is less than BUFSIZE, there is room to store more chars to be read by getch next and it stores c and updates the index for it
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// puts the reversed string on buffer so it comes out in the original order when getch is called
void ungets(char s[])
{
    int i = strlen(s);
    while (i >= 0)
        ungetch(s[i--]);
}