#include <stdio.h>

#define ROLL    3200000
#define SPACES  40          /* 40 spaces on the Monopoly board */

int main()
{
    int dice;
    int money = 0;
    
    puts("Monopoly Money Calculator");
    
    for(dice = 0; dice < ROLL; dice += SPACES)
    {
        money += 200;
        printf("Roll %d\r",dice);       /* display on one line */
    }
    putchar('\n');                      /* add newline for last roll */
    printf("You made a total of $%d!\n",money);
    return(0);
}