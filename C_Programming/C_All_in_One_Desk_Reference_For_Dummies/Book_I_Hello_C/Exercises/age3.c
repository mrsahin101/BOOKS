#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age :");
    scanf("%d", &age);
    printf("You'll be %d years old in 25 years!\n",age + 25);
    
    if(age + 25 > 100)
    {
        printf("You'll probably dead :(\n");
    }
    return(0);
}