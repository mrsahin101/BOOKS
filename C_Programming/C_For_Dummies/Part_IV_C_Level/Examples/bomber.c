#include <stdio.h>

void dropBomb(void);     /* prototype */

int main()
{
    printf("Press Enter to drop the bomb:");
    getchar();
    dropBomb();
    printf("Yikes!\n");
    return(0);
}
void dropBomb()
{
    int x;
    for(x = 20; x > 1; x--)
    {
        puts("      *");
    }
    puts("      BOOM!");
}