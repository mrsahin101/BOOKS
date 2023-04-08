#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Press Enter to see a list of files:");
    getchar();
    int exit_status = system("dir");
    printf("System returned %d value from your command\n", exit_status);
    puts("Done!");
    return(0);
}