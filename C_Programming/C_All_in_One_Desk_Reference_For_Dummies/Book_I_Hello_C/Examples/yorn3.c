#include <stdio.h>

int main()
{
    char ch;

    printf("Would you like me to send your password to the bad guys?\n");
    for(;;)
    {
        printf("Enter Y o N (Y/N)?");
        ch = getchar();

        if(ch == 'N')
        {
            printf("Well, then : your password is safe!\n");
            break;
        }
        else if(ch == 'n')
        {
            printf("Well, then : your password is safe\n");
            break;
        }
        else if (ch == 'Y')
        {
            printf("Okay. Sending your password!\n");
            break;
        }
        else if(ch == 'y')
        {
            printf("Okay. Sending your password!\n");
            break;
        }
        else
        {
            printf("You must enter Y or N!\n");
            fflush(stdin);              /* Eliminate other keys */
            /* no break here; keep looping */
        }
    }
    return(0);
}