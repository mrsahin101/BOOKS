#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[20];
    int age;
    float height;

    printf("Enter you age in years :");
    gets(input);
    age = atoi(input);

    printf("Enter your height in inches:");
    gets(input);
    height = atof(input);

    printf("You are %d years old\n", age);
    printf("and %f inches tall.\n", height);
    return(0);
}