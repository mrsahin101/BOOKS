/* An important program for NASA to properly launch America's spaceraft.*/

#include <stdio.h>

int main()
{
    int start; 
    unsigned long delay;

    do
    {    
        printf("Please enter the number to start\n");
        printf("the countdown (1 to 100):");
        scanf("%d",&start);
    } while (start < 1 || start > 100);

    /* The countdown loop */

    do
    {
        printf("T-minus %d\n",start);
        start--;
        //for(delay = 0; delay < 40000000; delay++);
        sleep(1);
    } while (start > 0);
    
    printf("Zero!\nBlast off!\n");
    return(0);
}