#include <stdio.h>

#define CENT_PER_INCH 2.54

int main()
{
    union measure
    {
        float centimeters;
        int inches;
    };

    union measure you;
    union measure paul;

    paul.inches = 70;
    printf("Paul is %d inches tall.\n", paul.inches);
    printf("How tall are you in inces? ");
    scanf("%d", &you.inches);

    you.centimeters = CENT_PER_INCH * (float)you.inches;
    paul.centimeters = CENT_PER_INCH * (float)paul.inches;
    printf("You are %.2f centimeters tall.\n", you.centimeters);
    printf("Paul is %.2f centimeters tall.\n", paul.centimeters);
    return(0);
}