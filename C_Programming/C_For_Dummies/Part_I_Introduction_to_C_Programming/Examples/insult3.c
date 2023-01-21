#include <stdio.h>

int main()
{
    char jerk[20];
    puts("Name some jerk you know :");
    gets(jerk);
    // wrong way of doing it. puts only takes string. no place holders
    // puts("Yeah, I think %s is a jerk, too",jerk);
    // right way of doing it
    printf("Yeah, I think %s is a jerk, too",jerk);
    return(0);
}