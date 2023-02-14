#include <stdio.h>

int main()
{
    char phrase[] = "sushi is mooshi";
    char ch;
    int x = 0;

    puts(phrase);
    phrase[9] = 's';
    puts(phrase);
    return(0);
}