#include <stdio.h>

int strlength(char *string);
char *reversing(char *string, int len);

int main()
{
    char *myInput = "Hello World";
    printf("Input : %s\nReversed : %s\n", myInput, reversing(myInput, strlength(myInput)));
    
    return(0);
}

char *reversing(char *string, int len)
{
    static char reversed[64];
    int x = 0;
    while(*(string + x))
    {
        reversed[len - x - 1] = *(string + x); 
        x++; 
    }
    return reversed;
}

int strlength(char *string)
{
    int x = 0;
    while(*string++)
        x++;
    return x;
}