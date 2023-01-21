#include <stdio.h>

int main()
{
    int count;

    for(count = 10; count > 0; count = count -1)
        printf("%d\n",count);

    printf("Ready or not, here I come!\n");
    return(0);
}