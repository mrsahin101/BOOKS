#include <stdio.h>

#define PODS        50
#define LOCATIONS   0xBA3C

int main()
{
    puts("Base 10:");
    printf("I must deliver %d pods to %d locations.\n",PODS, LOCATIONS);
    puts("Base 16:");
    printf("I must deliver 0x%X pods to 0x%X locations.\n",PODS,LOCATIONS);
    return(0);
}