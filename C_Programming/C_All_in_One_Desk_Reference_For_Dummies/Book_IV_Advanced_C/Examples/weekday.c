#include <stdio.h>
#include <time.h>

int main()
{
    char *wdays[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    struct tm *t;
    time_t now;

    time(&now);             /*get the current time */
    t = localtime(&now);    /*get the tm structure */
    printf("Today is %s.\n", wdays[t->tm_wday]);

    return(0);
}