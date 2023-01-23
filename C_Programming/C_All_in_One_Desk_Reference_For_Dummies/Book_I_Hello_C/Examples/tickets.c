#include <stdio.h>

int main()
{
    int total,  fine, speeding;

    puts("Speeding Tickets\n");

    /* first ticket */
    speeding = 85 - 55;                 /* mph over limit */
    fine = speeding * 15;               /* fine per mph over limit */
    total = total + fine;
    printf("For going 85 in a 55 zone : $%d\n",fine);

    /* second ticket */
    speeding = 95 - 55;                 /* mph over limit */
    fine = speeding * 15;               /* fine per mph over limit */
    total = total + fine;
    printf("For going 95 in a 55 zone : $%d\n",fine);

    /* third ticket */
    speeding = 100 - 55;                /* mph over limit */
    fine = speeding * 15;               /* fine per mph over limit */
    total = total + fine;
    printf("For going 100 in a 55 zone: $%d\n",fine);

    /* Display total */
    printf("\nTotal in fines $%d\n",total);
    return(0);
}