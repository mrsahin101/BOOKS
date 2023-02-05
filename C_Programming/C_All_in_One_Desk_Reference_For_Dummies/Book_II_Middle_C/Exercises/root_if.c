#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int value;
    double root;

    printf("Enter a value:");
    scanf("%d",&value);
    if(value < 0)
        value = value * -1;
    root = sqrt((double)value);
    printf("The square root of %d is %f.\n",value,root);
    return(0);
}