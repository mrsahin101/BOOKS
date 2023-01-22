#include <stdio.h>

int main()
{
    char name[20], surname[20];

    printf("What is your name?");
    gets(name);
    printf("What is your surname? ");
    gets(surname);
    printf("Pleased to meet you, %s %s!\n",name, surname);
    return(0);
}