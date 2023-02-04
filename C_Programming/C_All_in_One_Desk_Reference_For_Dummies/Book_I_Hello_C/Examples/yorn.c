#include <stdio.h>

int main()
{
    char ch;

    printf("Would you like me to send your password to the bad guys?\n");
    ch = getchar();
    
    if(ch == 'N')
    {
        printf("Well, then : your password is safe!\n");
    }
    else
    {
        printf("Okay. Sending your password!\n");
    }
    return(0);
}