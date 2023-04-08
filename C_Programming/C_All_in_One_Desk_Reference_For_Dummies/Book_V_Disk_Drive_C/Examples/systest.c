#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Press Enter to see a list of files:");
    getchar();
    system("dir");
    puts("Done!");
    return(0);
}