#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE   0
#define TRUE    !FALSE
#define OMEGA   ('Z' - 'A') 

int main()
{
    int done;
    long int r;
    char alpha;

    srand((unsigned)time(NULL));
    done = FALSE;

    while(!done)
    {
        r = rand() % OMEGA;
        alpha = 'A' + (char) r;
        
        if(alpha == 'Q') 
            done = TRUE;
        putchar(alpha);
    }
    putchar('\n');
    return(0);
}