#include <stdio.h>

#define MAXLINE 1000        /* maximum input line size */

int mygetline(char s[], int lim);

/* printf longest input line */
main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* longest line saved here */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while((len = mygetline(line, MAXLINE)) > 0)
    {
        for(int i = len - 1; i >= 0; i--)
            printf("%c", line[i]);
    }
    return 0;
}
/* getline: read a line into s, return length*/
int mygetline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}