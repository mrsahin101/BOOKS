#include <stdio.h>

int main()
{
    int age; 

    printf("Please enter your age in years:");
    scanf("%d", &age);
    if(age <= 18 || age >= 65)
        puts("Enjoy life while you can!");
    else
        puts("Get back to work!");
    return(0);
}