#include <stdio.h>

int main()
{
    FILE* myself;
    char c;

    myself = fopen("consume.c", "r");
    while((c = fgetc(myself)) != EOF)
        putchar(c);

    return(0);
}