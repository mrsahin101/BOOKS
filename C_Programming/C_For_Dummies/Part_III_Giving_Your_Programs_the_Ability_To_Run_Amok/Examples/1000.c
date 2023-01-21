#include <stdio.h>

int main()
{
    int i;

    for(i = 5; i <= 1000; i = i + 5)
        printf("%d\t", i);
    return(0);
}