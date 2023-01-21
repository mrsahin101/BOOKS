#include <stdio.h>

#define COUNT 20000000      /* 20,000,000 */

/* Prototypes*/
void dropBomb(void);        
void delay(void);       

int main()
{
    char x;

    printf("Press Enter to drop the bomb:");
    x = getchar();
    dropBomb();
    printf("Key code %d used to drop bomb.\n",x);
    return(0);
}
void dropBomb()
{
    int x;

    for(x = 20; x > 1; x--)
    {
        puts("     *");
        delay();
    }
    puts("     BOOM!");
}
void delay()
{
    long int x;
    for(x = 0; x < COUNT; x++);
}