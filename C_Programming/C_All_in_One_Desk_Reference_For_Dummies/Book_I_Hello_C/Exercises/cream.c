#include <stdio.h>

#define OLD_CREMATORIUM     13.5
#define NEW_CREMATORIUM     19.2

int main ()
{
    printf("New crematorium is %.2f miles away from old one!", NEW_CREMATORIUM - OLD_CREMATORIUM);
    return(0);
}