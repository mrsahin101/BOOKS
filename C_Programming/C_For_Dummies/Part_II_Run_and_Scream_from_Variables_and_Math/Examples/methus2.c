#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    char years[8];

    printf("How old was Methusalah? :");
    gets(years);
    age = atoi(years);
    printf("Methusalah was %d years old.\n",age);
    return(0);
}