#include <stdio.h>

int main()
{
    char input[10];

    struct stuff
    {
        char letter;
        int number;
    }my, his, her;

    /* Here is his info */
    his.letter = 'Y';
    his.number = 199;
    her.letter = 'A';
    her.number = 21;
    puts("Your Own Stuff");
    printf("Enter your favorite letter:");
    my.letter = getchar();

    printf("Enter your favorite number:");
    scanf("%d", &my.number);

    printf("Your favorite letter is %c\n", my.letter);
    printf("and your favorite number is %d\n", my.number);
    printf("His favorite letter is %c\n", his.letter);
    printf("and his favorite number is %d.\n", his.number);
    printf("Her favorite letter is %c\n.", her.letter);
    printf("and her favorite number is %d\n.", her.number);
    
    return(0);
}