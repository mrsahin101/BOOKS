#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prompt(void);
void draw(int count);
int rollDice(void);

int main()
{
    int count;
    srand((unsigned)time(NULL));
    prompt();
    scanf("%d", &count);
    printf("Rolling %d...\n", count);
    printf("Here they come!\n");
    draw(count);
        
}
void draw(int count)
{
    int total = 0;

    printf(" ");
    for(int i = 0; i < count; i++)
    {
        printf("  %d   ", i + 1);
    }
    printf("\n+");
    for(int i = 0; i < count; i++)
    {
        printf("-----+");
    }
    printf("\n|");
    for(int i = 0; i < count; i++)
    {
        int x = rollDice();
        printf("  %d  |", x);
        total += x;
    }
    printf("\n+");
    for(int i = 0; i < count; i++)
    {
        printf("-----+");
    }
    printf("\n");
    printf("Total = %d", total);
}
int rollDice(void)
{
    return rand() % 6 + 1;
}

void prompt(void)
{
    printf("ROLL'EM!\n");
    printf("How many dice would you like to roll(1 to 12)?");
}