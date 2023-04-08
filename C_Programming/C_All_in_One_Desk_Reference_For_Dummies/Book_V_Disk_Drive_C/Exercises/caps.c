#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    while(ch = fgetc(stdin) != EOF)
    {
        fputc(toupper(ch), stdout);
    }
    return(0);
}