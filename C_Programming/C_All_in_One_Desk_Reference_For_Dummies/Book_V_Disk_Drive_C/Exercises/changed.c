#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 128

int main()
{
    char orgdir[BUFSIZE];
    char newdir[BUFSIZE];
    int x;

    getcwd(orgdir, BUFSIZE);
    printf("The current working directory is :\n\n%s\n", orgdir);

    puts("Changing to the root directory...");
    x = chdir("\\");            /*x = chdir("/");*/

    if(x != 0)
    {
        puts("Error changing directories");
        return(1);
    }

    getcwd(newdir,BUFSIZE);
    printf("\n\nThe current working directory is :\n\n%s\n", newdir);

    puts("Changing back to original directory...");

    x = chdir(orgdir);            /*x = chdir("/");*/

    if(x != 0)
    {
        puts("Error changing directories");
        return(1);
    }

    getcwd(newdir,BUFSIZE);
    printf("\n\nThe current working directory is :\n\n%s\n", newdir);
    
    return(0);
}