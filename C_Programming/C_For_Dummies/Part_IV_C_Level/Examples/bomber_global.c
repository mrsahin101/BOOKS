#include <stdio.h>

#define COUNT 20000000          /* 20,000,000*/

void dropBomb(void);            /* prototypes*/
void delay(void);               

int deaths;                     /*global variable*/

int main()
{
    char x;

    deaths = 0;
    for(;;)
    {
        printf("Press ~ then Enter to quit\n");
        printf("Press Enter to drop the bomb:");
        x = getchar();
        fflush(stdin);          /* clear input buffer */

        if(x == '~')
            break;
        dropBomb();
        printf("%d people killed!\n",deaths);
    }
    return(0);
}

void dropBomb()
{
    int x;

    for(x = 20; x > 1; x--)
    {
        puts("         *");
        delay();
    }
    puts("         BOOM!");
    deaths += 1500;
}

void delay()
{
    long int x;
    
    for(x = 0; x < COUNT; x++);
}