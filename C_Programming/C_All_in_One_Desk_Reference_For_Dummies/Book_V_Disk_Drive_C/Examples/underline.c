#include <stdio.h>

#define SPACE ' '

int main()
{
    char ch;

    while(ch = fgetc(stdin) != EOF)
    {
        if(ch == SPACE)
            fputc('_', stdout);
        else
            fputc(ch, stdout);
    }
    return(0);
}