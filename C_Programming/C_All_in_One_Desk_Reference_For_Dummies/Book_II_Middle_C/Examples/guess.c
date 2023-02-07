#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100

int main()
{
    int guess, number;

    srand((unsigned)time(NULL));
    
    puts("Guessing Game!");
    number = rand() % RANGE + 1; /* value from 1 to RANGE */

    printf("I'm thinking of a number from 1 to %d.\n", RANGE);
    printf("Can you guess what it is?\n");

    while(1)
    {
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
    }
    printf("The number was %d\n", number);
    return(0);
}