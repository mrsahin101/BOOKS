#include <stdio.h>

int main()
{
    char text[] = "Going! Going! Gone!";
    char *t;

    /* initialize the pointer */
    t = text;
    
    while(*t)
    {
        puts(t);
        t++;
    }
    return(0);
}