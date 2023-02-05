#include <stdio.h>
#include <math.h>

int main()
{
    double result;

    result = pow(5.0,399.0);
    printf("5 to the power 399 is : %.0f\n",result);
    printf("Result with scientific notation is : %E\n",result);
    return(0);
}