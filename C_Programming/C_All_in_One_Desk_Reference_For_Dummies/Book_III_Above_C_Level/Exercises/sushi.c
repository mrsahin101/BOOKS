#include <stdio.h>

int main()
{
    char phrase[] = "sushi is mooshi";
    char ch;
    int x = 0;

    puts(phrase);
    phrase[5] = '_';
    phrase[8] = '_';
    puts(phrase);
    return(0);
}