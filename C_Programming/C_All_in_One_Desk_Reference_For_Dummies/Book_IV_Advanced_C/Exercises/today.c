#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;

    now = time(NULL);
    printf("It is now %d\n", now);

    return(0);
}