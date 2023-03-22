#include <stdio.h>

struct stuff
{
    char letter;
    int number;
};
void showstuff(struct stuff the);

int main()
{
    char input[10];
    struct stuff my;

    puts("Your Own Stuff");
    
    printf("Enter your favorite letter:");
    my.letter = getchar();

    printf("Enter your favorite number:");
    scanf("%d", &my.number);

    showstuff(my);
    return(0);
}

void showstuff(struct stuff the)
{
    printf("Your favorite letter is %c\n", the.letter);
    printf("and your favorite number is %d\n", the.number);
}