#include <stdio.h>

int main()
{
    char prompt[] = "Please enter your first name:";
    char promptLastname[] = "Please enter your lastname:";
    char gratis[] = "Thanks!";
    char first[25];
    char lastname[25];
    printf(prompt);
    gets(first);
    puts(gratis);
    printf(promptLastname);
    gets(lastname);
    puts(gratis);
    printf("Pleased to meet you, %s %s!\n", first, lastname);
    return(0);
}