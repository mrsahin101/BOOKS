#include <stdio.h>

int main()
{
    float iq[] = {120.25, 139.50, 110.0, 143.1, 95.3};
    char* names[] = {"Ali", "Veli", "Mehmet", "Ahmet", "Cabbar"};

    for(int i = 0; i < 5; i++)
    {
        printf("%s IQ : %.2f\n",names[i],iq[i]);
    }
    return(0);
}