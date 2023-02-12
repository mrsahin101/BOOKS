#include <stdio.h>

int main()
{
    float temperatures[5] = {0};
    float average = 0;
    puts("Please enter temperatures of the days :");
    for(int i = 0; i < 5; i++)
    {
        printf("Enter day %d temperature :", i +1);
        scanf("%f", &temperatures[i]);
        average += temperatures[i];
    }
    puts("Calculating average...");
    average = average / 5;
    printf("Average of 5 day is : %.2f",average);
    return(0);
}