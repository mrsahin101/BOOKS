#include <stdio.h>

int main()
{
    int blanks = 0, tabs = 0, newlines = 0;

    int c;
    while((c = getchar()) != EOF)
    {
        if(c == '\n')
            newlines++;
        if(c == ' ')
            blanks++;
        if(c == '\t');
            tabs++;
    }
    printf("Blanks : %d, Tabs : %d, NewLines : %d", blanks, tabs, newlines);
}