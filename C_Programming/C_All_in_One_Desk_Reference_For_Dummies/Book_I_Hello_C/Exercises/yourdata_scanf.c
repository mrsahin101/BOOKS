#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    float height;

    printf("Enter you age in years :");
    scanf("%d",&age);

    printf("Enter your height in inches:");
    scanf("%.f",&height);

    printf("You are %d years old\n", age);
    printf("and %f inches tall.\n", height);
    return(0);
}