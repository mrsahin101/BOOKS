#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RNG_COUNT 3

void separator(void);
void randomGenerator(void);

int main()
{
    srand((unsigned)time(NULL));
    
    puts("Here are today's secret number values:");
    for(int i = 0; i < RNG_COUNT; i++)
        randomGenerator();
    return(0);
}
void randomGenerator(void)
{
    long int r;
    separator();
    r = rand();
    printf("%d\n",r);
}
void separator(void)
{
    int r;
    for(r = 0; r < 10; r++)
        putchar('*');
    putchar('\n');
}