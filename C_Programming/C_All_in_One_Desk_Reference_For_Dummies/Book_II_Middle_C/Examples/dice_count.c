#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 1000

int main()
{
    int d1, d2, total, loop;
    int runing_total = 0;
    float average;

    srand((unsigned)time(NULL));

    for(loop = 1; loop <= ROLLS; loop++)
    {
        d1 = rand() % 6 + 1;
        d2 = rand() % 6 + 1;
        total = d1 + d2;
        runing_total += total;
        printf("You rolled %d and %d: Total %d\n",d1,d2,total);
    }
    average = (float) runing_total / ROLLS;
    printf("The average roll for %d rolls was %3.1f\n",ROLLS, average);
    return(0);
}