#include <stdio.h>

#define FALSE       0
#define TRUE        !FALSE

int main()
{
    int done;
    char ch;
    
    done = FALSE;
    printf("Would you like me to send your password to the bad guys?\n");
    while(!done)
    {
        printf("Enter Y or N (Y/N)?");
        ch = getchar();
        switch(ch)
        {
            case 'N':
            case 'n':
                printf("Well, then: your password is safe!\n");
                done = TRUE;
                break;
            case 'Y':
            case 'y':
                printf("Okay, Sending your password!\n");
                done = TRUE;
                break;
            default:
                printf("You must enter a Y or N!\n");
                fflush(stdin);    
        } /* end switch */
    }/* end while */
    return(0);
}