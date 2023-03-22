#include <stdio.h>
#include <string.h>
#include <ctype.h>

void showline(void);
void dashes(void);
void DisplayUpperCase(char* input);

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
    dashes();
    DisplayUpperCase(line);
    dashes();
}
void DisplayUpperCase(char* input)
{   
    int i = 0;
    while(input[i] != 0)
    {
        putchar(toupper(input[i]));
        i++;
    }
    putchar('\n');
}
void dashes(void)
{
    int x;

    for(x = 0; x < linelen; x++)
        putchar('-');
    putchar('\n');
}