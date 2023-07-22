#include <stdio.h>

unsigned long int next = 1;

int my_rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}
void my_srand(unsigned int seed)
{
    next = seed;
}

int main()
{
    my_srand(100);
    printf("%d", my_rand());
}