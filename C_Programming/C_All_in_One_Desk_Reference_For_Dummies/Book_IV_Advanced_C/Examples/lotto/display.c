/* Display module */
#include "lotto.h"
#include <stdio.h>

extern int ball[BALLS];

void display(void)
{
    int c;

    for(c = 0; c < BALLS; c++)
        printf("%2d ", ball[c]);
    puts("\nGood luck in the drawing!\n");
}