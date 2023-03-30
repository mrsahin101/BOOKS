#include <stdio.h>

int main()
{
    int number;
    int multiple_of_8, multiple_of_2;
    
    printf("Please enter the number you want to multiply by 10 : ");
    scanf("%d", &number);
    
    multiple_of_8 = number << 3;
    multiple_of_2 = number << 1;
    printf("%d times 10 is equal : %d ", number, multiple_of_2 + multiple_of_8);
    
    return(0);
}