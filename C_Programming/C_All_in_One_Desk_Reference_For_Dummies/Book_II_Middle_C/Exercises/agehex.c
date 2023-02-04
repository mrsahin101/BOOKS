#include <stdio.h>

int main()
{
    int age;

    printf("Please enter your age :");
    scanf("%d",&age);

    printf("You age in hexadecimals is : %#X.\n",age);
    return(0);
}