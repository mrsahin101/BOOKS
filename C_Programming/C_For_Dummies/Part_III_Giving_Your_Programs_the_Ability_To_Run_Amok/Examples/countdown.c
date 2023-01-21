/* An important program for NASA to properly launch America's spacecraft */
#include <stdio.h>

int main()
{
    int start;

    printf("Please enter the number to start\n");
    printf("the countdown (1 to 100):");
    scanf("%d",&start);

    /* The countdown loop*/

    do
    {
        printf("T-minus %d\n",start);
        start--;
    } while (start > 0);
    
    printf("Zero!\nBlast off!\n");
    return(0);
}