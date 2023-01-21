#include <stdio.h>
#include <stdlib.h>

int rnd(void);
void seedrnd(void);

int main()
{
    int x;

    seedrnd();
    puts("Behold! 100 Random Numbers!");
    for(x = 0; x < 100; x++)
        printf("%d\t",rnd());
    return(0);
}
int rnd(void)
{
    int r;

    r = rand();
    return(r);
}

/* seed the random number */
void seedrnd(void)
{
    int seed;
    char s[6];

    printf("Enter a random number seed (2 - 65000):");
    seed = (unsigned)atoi(gets(s));
    srand(seed);
}