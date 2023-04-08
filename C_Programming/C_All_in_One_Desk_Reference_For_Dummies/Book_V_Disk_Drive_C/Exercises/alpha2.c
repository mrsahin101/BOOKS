#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[64];
    char command[64];
    
    printf("Please enter your name: ");
    gets(name);
    
    strcpy(command,"beta \"");
    strcat(command,name);
    strcat(command,"\"");
    system(command);
    
    return(0);
}