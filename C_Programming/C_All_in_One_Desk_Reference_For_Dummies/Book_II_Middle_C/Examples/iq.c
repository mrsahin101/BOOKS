
#include <stdio.h>

int main()
{
    int number;
    float iq;
    char first;

    puts("IQ Calculator");
    printf("Enter your house or apartment number:");
    scanf("%d", &number);
    fflush(stdin);      /* use fpurge(stdin) in Unix */
    printf("Enter the first letter of your last name :");
    scanf("%c",  &first);
    puts("Calculating your IQ....");
    iq = number / first;
    printf("This computer guesses your IQ to be %f.\n",iq);
    return(0);
}