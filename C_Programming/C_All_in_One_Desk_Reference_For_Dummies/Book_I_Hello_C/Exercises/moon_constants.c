#include <stdio.h>

#define DISTANCE        3778921.46
#define SPEED           140
int main()
{
    float duration;

    duration = DISTANCE / SPEED;
    printf("It would take %f hours to drive to the moon.\n",duration);
    return(0);
}