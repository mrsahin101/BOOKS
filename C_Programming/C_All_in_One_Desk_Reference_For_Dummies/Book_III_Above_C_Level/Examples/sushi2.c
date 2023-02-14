#include <stdio.h>

int main()
{
    char phrase[] = "sushi is mooshi";
    char ch;
    int x = 0;

    while(ch = phrase[x])
    {
        putchar(ch);
        x++;
    }
    putchar('\n');
    return(0);
}