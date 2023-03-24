#include <stdio.h>

#define KPM 1.609344

int main()
{
    float miles, kilometers;

    printf("Enter a value in miles:");
    scanf("%f", &miles);

    kilometers = miles * 1.609;

    printf("%.2f miles works out to %.2f kilometers.\n", miles, kilometers);
    return(0);
}