#include <stdio.h>

void peasoup(int *green);

int main()
{
    int turn;

    turn = 13;
    peasoup(&turn);
    printf("Oh, no, it's %d\n", turn);
    
    return(0);
}

void peasoup(int *green)
{
    while((*green)--)
        printf("Blech!\n");
    *green = 13 * 51 + 3;
}