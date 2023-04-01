#include <stdio.h>

void underline(char *string);

int main()
{
    underline("This Year's Starting Line-Up");
    return(0);
}

void underline(char *string)
{
    puts(string);
    while(*string)
    {
        putchar('=');
        string++;
    }
    putchar('\n');
}