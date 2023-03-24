#include <stdio.h>

int main()
{
    float duration;
    float distance = 378921.46;
    float speed = 140;
    float *d_pointer;

    duration = distance / speed;
    
    d_pointer = &distance;
    printf("The moon is %f km away.\n", *d_pointer);
    d_pointer = &speed;
    printf("Traveling at %f kph, ", *d_pointer);
    d_pointer = &duration; 
    printf("it would take %f hours to drive to the moon.\n", *d_pointer);
    
    return(0);
}