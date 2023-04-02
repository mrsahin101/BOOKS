#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char name[50];
    printf("Enter your name:");
    scanf("%s", &name);

    char *string;

    string = (char *) malloc(50);

    if(string == NULL)
    {
        puts("Not enough memory");
        return(0);
    }

    strcpy(string, name);
    printf("%s\n", string);

    return(0);
}
