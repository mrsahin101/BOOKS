#include <stdio.h>

int main()
{
    float duration;
    float distance;
    float speed;

    distance = 378921.46;
    speed = 140;
    duration = distance / speed;
    printf("It would take %f hours to drive to the moon.\n",duration);
    return(0);
}