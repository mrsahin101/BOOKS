#include <stdio.h>

extern int age;

void show(void)
{
    printf("You're %d years old!", age);
}