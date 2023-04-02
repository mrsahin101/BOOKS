#include <stdio.h>
#include <time.h>

int main()
{
    struct tm *t;
    time_t now;

    time(&now);             /* get the current time */
    t = localtime(&now);    /* get the tm structure */
    printf("It is now %02d/%02d/%02d\n", t->tm_mon + 1, t->tm_mday, t->tm_year - 100) ;
    return(0);
}