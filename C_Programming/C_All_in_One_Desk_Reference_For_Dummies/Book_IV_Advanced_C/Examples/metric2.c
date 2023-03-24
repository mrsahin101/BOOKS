#include <stdio.h>

#define KPM 1.609344

int main()
{
    float miles, kilometers;
    float* pmiles;
    
    printf("Enter a value in miles:");
    scanf("%f", &miles);

    kilometers = miles * 1.609;

    printf("%.2f miles works out to %.2f kilometers.\n", miles, kilometers);

    pmiles = &miles;        /* initialize pointer */

    printf("Variable 'miles' is %d bytes long at %p address\n", sizeof(miles), pmiles);
    return(0);
}