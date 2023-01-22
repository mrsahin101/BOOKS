#include <stdio.h>
#include <stdlib.h>

#define MONTHS_IN_YEAR          12
#define INCHES_TO_CM_CONSTANT   2.54
int main()
{
    char input[20];
    int age;
    float height;

    printf("Enter you age in years :");
    age = atoi(gets(input));

    printf("Enter your height in inches:");
    height = atof(gets(input));

    printf("You are %d monhts old\n", age * MONTHS_IN_YEAR);
    printf("and %f cm tall.\n", height * INCHES_TO_CM_CONSTANT);
    return(0);
}