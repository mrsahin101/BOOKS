/* Theater lobby snack bar program */

#include <stdio.h>

int main()
{
    char c;
    int done;
    float total = 0;

    printf("Please make your treat selections:\n");
    printf("1 - Beverage.\n");
    printf("2 - Candy. \n");
    printf("3 - Hot dog.\n");
    printf("4 - Popcorn.\n");
    printf("= - Done.\n");
    printf("Your choices:\n");

    /* Figure out what they typed in */

    done = 0;
    
    while(!done)
    {
        //fflush(stdin);
        c = getchar();
        switch(c)
        {
            case '1':
                printf("Beverage\t$8.00\n");
                total += 8;
                break;
            case '2':
                printf("Candy\t\t$5.50\n");
                total += 5.5;
                break;
            case '3':
                printf("Hot dog\t\t$10.00\n");
                total += 10;
                break;
            case '4':
                printf("Popcorn\t\t$7.50\n");
                total += 7.5;
                break;
            case '=':
                printf("= Total of $%.2f\n",total);
                printf("Please pay the cashier.\n");
                done = 1;
                break;
            default:
                printf("Improper selection.\n");
        }   /* end switch*/
    }       /* end while */
    return(0);
}