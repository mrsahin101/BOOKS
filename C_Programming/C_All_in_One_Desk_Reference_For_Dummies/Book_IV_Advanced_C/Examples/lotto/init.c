/* Init Module */
#include "lotto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(void)
{
    /* seed the randomizer */
    seedRandomizer();

    /* Display Start-Up text */
    puts("L O T T O   P I C K E R\n");
    puts("Press Enter to pick this week's numbers:");
    getchar();
}

void seedRandomizer(void)
{
    srand((unsigned)time(NULL));
}