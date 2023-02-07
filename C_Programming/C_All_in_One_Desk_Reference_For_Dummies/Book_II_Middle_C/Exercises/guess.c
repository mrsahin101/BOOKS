#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100
#define TRY_CHANCE  5
int main()
{
    int guess, number, try = 1;

    srand((unsigned)time(NULL));
    
    puts("Guessing Game!");
    number = rand() % RANGE + 1; /* value from 1 to RANGE */

    printf("I'm thinking of a number from 1 to %d.\n", RANGE);
    printf("Can you guess what it is?\n");

    while(1)
    {
        if(try > TRY_CHANCE)
        {
            printf("Failed. You run out of try chance.!\n");
            break;
        }
        printf("Enter guess:");
        scanf("%d", &guess);
        if(guess == number)
        {
            puts("You got it!");
            break;
        }
        else if(guess < number)
            puts("Too Low!");
        else
            puts("Too high!");
        try++;
    }
    printf("The number was %d\n", number);
    return(0);
}