#include <stdio.h>

int main()
{
    char ch;

    printf("Would you like me to send your password to the bad guys?\n");

    for(;;)
    {
        printf("Enter Y or N (Y/N)?");
        ch = getchar();

        if(ch == 'N' || ch == 'n')
        {
            printf("Well, then : your password is safe!\n");
            break;
        }
        else if(ch == 'Y' || ch == 'y')
        {
            printf("Okay. Sending your password!\n");
            break;
        }
        else
        {
            printf("You must enter Y or N!\n");
            fflush(stdin);      /* eliminate other keys */
            /* no break here; keep looping */
        }
    }
    return(0);
}