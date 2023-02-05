/* convert radians to degrees */
#include <stdio.h>

#define RAD     57.2957795

int main()
{
    float radians, degrees;

    puts("Convert degrees to radians");
    printf("Enter a value in degrees:");
    scanf("%f",&degrees);

    radians = degrees / RAD;

    printf("%.3f degrees is %.5f radians.",degrees,radians);
    return(0);
}