#include <stdio.h>
int main()
{
    int blanks = 0, tabs = 0, newlines = 0;

    int c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t')
            printf(" ");
        else
            printf("%c", c);
    }
}