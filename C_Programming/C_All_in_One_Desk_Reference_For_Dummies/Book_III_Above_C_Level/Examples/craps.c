#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int throw(void);

int main()
{
    int bet, roll, point;
    char c;

    srand((unsigned)time(NULL));
    printf("Enter your bet: $");
    scanf("%i", &bet);

    puts("Rolling them bones....!");
    roll = throw();

    printf("%d", roll);

    switch(roll)
    {
        case 7:
        case 11:
            printf("- You win!\n");
            bet *= 2;
            break;
        case 2:
        case 3:
        case 12:
            printf("- Craps! You lose!\n");
            bet = 0;
            break;
        default:
            point = roll;
            printf("- Your point is now %d.\n", point);
            while(1)
            {
                roll = throw();
                printf("\tYou rolled %d, point is %d.\n", roll, point);
                if(roll == point)
                {
                    printf("\tYou win!\n");
                    bet *= 2;
                    break;
                }
                if(roll == 7)
                {
                    printf("\tSeven out, you lose!\n");
                    bet = 0;
                    break;
                }
            }
    }
    printf("You now have $%d.\n", bet);
    return(0);
}

int throw(void)
{
    int die1, die2, total;
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    total = die1 + die2;
    return(total);
}
