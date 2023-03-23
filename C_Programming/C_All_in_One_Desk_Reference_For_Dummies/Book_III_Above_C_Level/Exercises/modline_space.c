#include <stdio.h>
#include <string.h>

void showline(void);
void dashes(char c);

char line[81];
int linelen;

int main()
{
    puts("Enter a line of text:");
    gets(line);
    linelen = strlen(line);

    puts("Here is the line you entered:");
    showline();
    return(0);
}

void showline(void)
{
    dashes('*');
    puts(line);
    dashes('*');
}

void dashes(char c)
{
    int x;

    if(c == ' ')
    {
        putchar('\n');
        return;
    }
    for(x = 0; x < linelen; x++)
        putchar('-');
    putchar('\n');
}