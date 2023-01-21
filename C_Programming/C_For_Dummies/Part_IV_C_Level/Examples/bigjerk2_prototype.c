#include <stdio.h>

void jerk(void);

int main()
{
    printf("He calls me on the phone with nothing say\n");
    printf("Not once, or twice, but three times a day!\n");
    jerk();
    printf("He insulted my wife, my cat, my mother\n");
    jerk();
    printf("He chuckles it off, his big belly a-heavin\n");
    jerk();
    return(0);
}

/* This is the jerk() function */
void jerk()
{
    printf("Bill is a jerk\n");
}