#include <stdio.h>
#include <ctype.h>

char ask(void);

int main()
{
    char key;

    printf("Would you like to see the menu?");
    key = ask();

    if(key == 'Y')
    {
        puts("Someday the menu will appear here");
        /* finish this later */
    }
    return(0);
}

char ask(void)
{
    char c;
    printf(" (Y/N)? ");
    fflush(stdin);
    c = toupper(getchar());
    if(c == 'Y')
        return(c);
    else
        return('N');
}