#include <stdio.h>

#define PC_FAV_NUMBER 7
int main()
{
    int number;
    printf("Please enter your favorite number (1 - 10) :");
    scanf("%d",&number);

    if(PC_FAV_NUMBER == number)
        printf("Your favorite number is same as computer favorite number!");
    return(0);
}