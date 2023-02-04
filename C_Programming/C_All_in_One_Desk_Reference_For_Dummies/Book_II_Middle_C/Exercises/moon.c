#include <stdio.h>

#define DISTANCE        378921.46       /* in kilometers */
#define PI              3.14159265358979
#define KM_TO_MILES     0.621371192     /* Kilometers to miles conversion ratio */
int main()
{
    double orbit;

    orbit = DISTANCE * 2 * PI * KM_TO_MILES;
    printf("The moon travels %f miles in one orbit.\n",orbit);
    return(0);
}