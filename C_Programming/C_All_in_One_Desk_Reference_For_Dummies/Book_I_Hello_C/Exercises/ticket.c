#include <stdio.h>

int main()
{
    int total,  fine, speeding;
    int speedlimit = 55, rate = 15, first_ticket = 85, second_ticket = 95, third_ticket = 100;
    puts("Speeding Tickets\n");

    /* first ticket */
    speeding = first_ticket - speedlimit;                 /* mph over limit */
    fine = speeding * rate;               /* fine per mph over limit */
    total = total + fine;
    printf("For going 85 in a 55 zone : $%d\n",fine);

    /* second ticket */
    speeding = second_ticket - speedlimit;                 /* mph over limit */
    fine = speeding * rate;               /* fine per mph over limit */
    total = total + fine;
    printf("For going 95 in a 55 zone : $%d\n",fine);

    /* third ticket */
    speeding = third_ticket - speedlimit;                /* mph over limit */
    fine = speeding * rate;               /* fine per mph over limit */
    total = total + fine;
    printf("For going 100 in a 55 zone: $%d\n",fine);

    /* Display total */
    printf("\nTotal in fines $%d\n",total);
    return(0);
}