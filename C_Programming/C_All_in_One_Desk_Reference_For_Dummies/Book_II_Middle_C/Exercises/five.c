#include <stdio.h>
#include <math.h>

int main()
{
    double sqrt_result;
    double pow_result;

    sqrt_result = sqrt(5.0);
    pow_result = pow(5.0, 0.5);

    printf("Square root result : %f\n",sqrt_result);
    printf("Pow Result : %f",pow_result);
    
    return(0);
}