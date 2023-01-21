#include <stdio.h>

#define SPEED 55

int main()
{
    printf("Now, the speed limit here is %i. \n",SPEED);
    printf("But I clocked you doin' %i.\n", SPEED + 15);
    printf("Didn't you see that %i MPH sign?\n", SPEED);
    return(0);
}