#include <stdio.h>

int main()
{
    char P;

    puts("Welcome to our survey!");
    puts("Please enter your party :");
    puts("D -> Democrats");
    puts("C -> Conservative");
    puts("N -> Nationalist");
    puts("L -> Liberals");
    P = getchar();

    switch(P)
    {
        case 'D':
        case 'd':
            puts("Nice. So you are Democrat!");
            break;
        case 'c':
        case 'C':
            puts("Nice. So you are conservative.");
            break;
        case 'N':
        case 'n':
            puts("Nice. So you are Nationalist.");
            break;
        case 'L':
        case 'l':
            puts("Nice. So you are liberal.");
            break;
        default:
            puts("Nice. So you are a-politic person :)");
    }
    return(0);
}