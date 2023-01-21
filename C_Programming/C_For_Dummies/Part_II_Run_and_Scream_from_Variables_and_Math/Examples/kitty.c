#include <stdio.h>

int main()
{
    char kitty[20];
    printf("What would you like to name your cat? :");
    gets(kitty);
    printf("\n%s is a nice name.What else you have in mind? : ",kitty);
    gets(kitty);
    printf("%s is nice, too\n",kitty);
    return(0);
}