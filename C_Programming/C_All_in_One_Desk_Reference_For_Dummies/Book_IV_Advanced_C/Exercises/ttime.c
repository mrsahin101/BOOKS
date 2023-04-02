#include <stdio.h>
#include <time.h>

int main()
{
    struct tm *t;
    time_t now;

    time(&now);             /* get the current time */
    t = localtime(&now);    /* get the tm structure */
    if(t->tm_hour > 12)
        printf("It is now A.M %d:%02d:%02d\n", (t->tm_hour - 12), t->tm_min, t->tm_sec);
    else
        printf("It is now P.M %d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);
    return(0);
}