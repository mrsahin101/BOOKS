#include <stdio.h>

int main()
{
    enum days
    {
        Monday = 100,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    
    int x;

    for(x = Monday; x <= Sunday; x++)
        printf("X = %d\n", x);
    return(0);
}