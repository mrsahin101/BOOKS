#include <stdio.h>

int main(int argc, char* argv[])
{
    int x;
    puts("Command Line Arguments");
    for(x = 0; x < argc; x++)
        printf("Argument #%d: %s\n", x, argv[x]);
    return(0);
}