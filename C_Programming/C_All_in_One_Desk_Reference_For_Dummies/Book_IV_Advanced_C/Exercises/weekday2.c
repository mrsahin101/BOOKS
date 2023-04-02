#include <stdio.h>
#include <time.h>

int main()
{

    struct tm *t;
    time_t now;

    time(&now);             /*get the current time */
    t = localtime(&now);    /*get the tm structure */
    printf("%i",t->tm_yday);
    return(0);
}