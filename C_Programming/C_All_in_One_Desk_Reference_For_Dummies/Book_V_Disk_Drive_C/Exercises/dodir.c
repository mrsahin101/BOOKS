#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

int main()
{
    DIR *dhandle;
    struct dirent *drecord;
    struct stat fbuf;

    dhandle = opendir(".");
    if(dhandle == NULL)
    {
        puts("Error opening directory:");
        return(1);
    }

    while((drecord = readdir(dhandle)) != NULL)
    {
        int x = stat(drecord->d_name, &fbuf);
        if(x != 0)
        {
            printf("Error reading file!\n");
            return(1);
        }
        printf("%s is %d bytes and last modified %s\n", drecord->d_name, fbuf.st_size, ctime(&fbuf.st_mtime));
    }
        

    closedir(dhandle);
    return(0);
}