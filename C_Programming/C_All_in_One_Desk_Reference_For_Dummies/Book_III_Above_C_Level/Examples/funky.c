#include <stdio.h>

/* This program shows that uninitialized variables content garbage content.*/
void a(void)
{
    int a;
    a = 5;
}

void b(void)
{
    int b;
    printf("B is %d\n", b);
}

int main()
{
    a();
    b();
    return(0);
}