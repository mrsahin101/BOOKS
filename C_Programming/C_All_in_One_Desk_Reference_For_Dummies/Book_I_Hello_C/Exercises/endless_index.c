#include <stdio.h>

int main()
{
    int packet;

    printf("Processing 1000 packets:\n");
    for(packet = 1; packet < 1001; packet = packet + 1)
    {
        printf("Doing amazing this with packet#%d\n",packet);
    }
    return(0);
}