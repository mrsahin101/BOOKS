#include <stdio.h>

#define BIG         2468000000000.0     /*9 Zeros before the .*/
#define TEENSY      0.00000000097531    /*9 Zeros after the .*/

int main()
{
    puts("Using %f:");
    printf("Big %f\tTeensy %f\n",BIG,TEENSY);
    puts("Using %E:");
    printf("Big %E\tTeensy %E\n",BIG,TEENSY);
    puts("Using %G:");
    printf("Big %G\tTeensy %G\n",BIG, TEENSY);
    return(0);
}