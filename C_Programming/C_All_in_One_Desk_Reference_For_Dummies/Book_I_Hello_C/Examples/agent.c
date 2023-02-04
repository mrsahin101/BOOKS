#include <stdio.h>

int main()
{
    int agent;
    char code;

    printf("Enter your agent number: ");
    scanf("%d", &agent);
    fflush(stdin);
    printf("Enter your single-digit code key:");
    scanf("%c", &code);
    if(agent == 7 && code == 'B')
    {
        puts("Welcome aboard, James Bond.");
        puts("You may commence with operation FreeCell.");
    }
    else
    {
        puts("The authorities have been notified");
        puts("of this illegal access.");
    }
    return(0);
}