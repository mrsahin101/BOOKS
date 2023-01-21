#include <stdio.h>
#include <stdlib.h>

int getval(void);

int main()
{
    int age, weight, area;
    float iq;

    printf("Program to calculate your IQ.\n");
    printf("Enter your age:");
    age = getval();
    printf("Enter your weight:");
    weight = getval();
    printf("Enter the your area code:");
    area = getval();

    iq = (age * weight) / area;
    printf("This computer estimates your IQ to be %f.\n", iq);
    return(0);
}

int getval(void)
{
    char input[20];
    int x;
    
    gets(input);
    x = atoi(input);
    return(x);
}