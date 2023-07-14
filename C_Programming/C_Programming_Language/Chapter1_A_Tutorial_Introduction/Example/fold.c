#include <stdio.h>

#define MAXLINE     1000        /* maximum input line size */
#define LINE_SIZE   40

int mygetline(char s[], int lim);

/* printf longest input line */
main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* longest line saved here */
    char longest[MAXLINE];  /* longest line saved here */
    int counter = 0;
    max = 0;

    while((len = mygetline(line, MAXLINE)) > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if((counter > LINE_SIZE))
            {
                if(line[i] == ' ' || line[i] == '\t')
                {
                    printf("\n");
                    counter = 0;
                }
                else
                    printf("%c", line[i]);
            } 
            else
                printf("%c", line[i]);
            counter++;
        }
            
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