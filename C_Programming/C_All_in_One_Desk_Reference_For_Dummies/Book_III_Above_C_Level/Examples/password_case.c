#include <stdio.h>
#include <string.h>

int main()
{
    char string[16];
    char password[] = "please";

    printf("Enter your secret password:");
    gets(string);

    if(strcasecmp(string, password) == 0)
        puts("Entry granted!");
    else
        puts("Sorry. Wrong password.");
    return(0);
}