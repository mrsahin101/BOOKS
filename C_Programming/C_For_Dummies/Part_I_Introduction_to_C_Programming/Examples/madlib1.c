/*  madlib1.c Source code
    Written by mrsahin101
    21.12.2022
*/
#include <stdio.h>

int main()
{
    char adjective[20];
    char food[20];
    char chore[20];
    char furniture[20];
    
    /* Get the words to use in the madlib*/
    printf("Enter an adjective : ");       /* prompt */
    scanf("%s",&adjective);                /* input  */

    printf("Enter a food : ");              /* prompt */ 
    scanf("%s",&food);                     /* input  */

    printf("Enter a household chore (past tense) : ");      /* prompt */
    scanf("%s",&chore);                                     /* input  */

    printf("Enter an item of furniture : ");                /* prompt */
    scanf("%s",&furniture);                                 /* input  */

    /* Display the output */
    printf("\n\nDon't touch that %s %s!\n",adjective, food);
    printf("I just %s the %s!\n",chore, furniture);

    return(0);
}