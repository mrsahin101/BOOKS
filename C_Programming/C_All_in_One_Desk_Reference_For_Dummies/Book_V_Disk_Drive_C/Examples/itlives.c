#include <stdio.h>

int main()
{
    FILE *myfile;
    char c;

    myfile = fopen("alive.txt", "r");
    if(!myfile)
    {
        puts("ALIVE.TXT not found!");
        return(1);
    }
    do
    {
        c = fgetc(myfile);
        putchar(c);
    } while (c != EOF);
    
    return(0);
}