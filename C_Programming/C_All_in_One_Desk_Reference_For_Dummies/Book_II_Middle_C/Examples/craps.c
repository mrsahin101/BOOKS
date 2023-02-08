#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int bet, roll, point;
    char c;

    srand((unsigned)time(NULL));
    printf("Enter your bet: $");
    scanf("%i", &bet);

    puts("Rolling them bones....!");
    roll = rand() % 11 + 2;

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
            printf(" - Your point is now %d.\n", point);
            while(1)
            {
                roll = rand() % 11 + 2;
                printf("\t You rolled %d, point is %d.\n", roll, point);
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
    printf("You now have $%d\n",bet);
    return(0);
}