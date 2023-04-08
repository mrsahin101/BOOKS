#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[50];
    char command[100];
    printf("Welcome, What is your name ?\n");
    scanf("%s", &name);
    snprintf(command, sizeof(command), "beta %s", name);
    system(command);
    return(0);
}