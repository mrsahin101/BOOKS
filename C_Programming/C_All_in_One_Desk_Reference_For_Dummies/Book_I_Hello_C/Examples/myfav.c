#include <stdio.h>

int main()
{
    char fav;

    printf("Enter your favorite character:");
    fav = getchar();
    if(fav == 'Q')
    {
        printf("That's my favorite character, too!");
    }
    return(0);
}