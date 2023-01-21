/* Theater lobby snack bar program */
#include <stdio.h>

int main()
{
    char c;

    printf("Please make your treat selection:\n");
    printf("1 - Beverage.\n");
    printf("2 - Candy\n");
    printf("3 - Hot dog\n");
    printf("4 - Pop corn");
    printf("Your choice:");

    /* Figure out what they typed in. */

    c = getchar();
    switch (c)
    {
        case '1':
            printf("Beverage\nThat will be $8.00\n");
            break;
        case '2':
            printf("Candy\nThat will be $5.50\n");
            break;
        case '3':
            printf("Hot dog\nThat will be $10.00\n");
            break;
        case '4':
            printf("Popcorn\nThat will be $7.50\n");
        default:
            printf("That is not proper selection.\n");
            printf("I'll assume you're just not hungry.\n");
            printf("Can I help whoever's next?\n");
            break;
    }
    return(0);
}