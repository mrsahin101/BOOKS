#include <stdio.h>

int main()
{
    char name[20];
    char *name_pointer;

    puts("Enter your name :");
    scanf("%s", &name);

    name_pointer = name;
    printf("Welcome! ");

    while(putchar(*name_pointer++));

    return(0);
}