#include <stdio.h>

int main()
{
    float duration;
    float distance = 378921.46;
    float speed = 140;

    duration = distance / speed;

    printf("The moon is %f km away.\n",distance);
    printf("Traveling at %f kph,", speed);
    printf("it would take %f hours to drive to the moon.\n",duration);
    printf("It would take %f days to travel this time.", duration / 24);
    return(0);
}