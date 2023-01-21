#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int range);
void seedrnd(void);

int main()
{
    int x;

    seedrnd();
    for(x = 0; x < 100; x++)
        printf("%i\t",rnd(10));
    return(0);
}
int rnd(int range)
{
    int r;

    r = rand() % range;
    return(r);
}
void seedrnd(void)
{
    srand((unsigned)time(NULL));
}