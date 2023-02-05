#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLIPS 1000

int main()
{
    int coin, loop;
    int total_heads = 0;
    float hpercent, tpercent;

    srand((unsigned)time(NULL));

    for(loop = 1; loop <= FLIPS; loop++)
    {
        coin = rand() % 2;
        /* assume 1 is heads, 0 is tails */
        total_heads += coin;
        if(coin)
            printf("Heads\t");
        else
            printf("Tails\t");
    }
    hpercent = (float)total_heads / FLIPS * 100;
    tpercent = 100.0 - hpercent;
    printf("Total Flips: %d\nHeads: %.2f\nTails: %.2f\n",FLIPS,hpercent,tpercent);
    return(0);
}