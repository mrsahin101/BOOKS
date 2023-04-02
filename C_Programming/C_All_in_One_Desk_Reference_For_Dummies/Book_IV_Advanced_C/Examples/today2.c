#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;
    
    time(&now);
    printf("It is now %s\n", ctime(&now));

    return(0);
}