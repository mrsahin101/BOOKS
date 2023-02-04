#include <stdio.h>

int main()
{
    long int humongous;
    char chuck;
    for(humongous = 65; humongous < 91; humongous++)
    {
        chuck = (char)humongous;
        putchar(chuck);
    }
    return(0);
}