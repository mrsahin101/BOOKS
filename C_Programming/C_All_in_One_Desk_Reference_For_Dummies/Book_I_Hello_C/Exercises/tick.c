#include <stdio.h>

int main()
{
    int tick;

    printf("Variable tick is uninitialized.\n");
    for(tick = 1; tick < 11; tick = tick + 1)
    {
        printf("\tIn the loop, tick = %d\n", tick);
    }
    printf("After the loop, tick = %d\n",tick);
    return(0);
}