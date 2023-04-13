#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    DIR *dhandle;
    struct dirent *drecord;
    struct stat sbuf;

    dhandle = opendir(".");
    if(dhandle == NULL)
    {
        puts("Error opening directory");
        return(1);
    }

    while((drecord = readdir(dhandle)) != NULL)
    {
        stat(drecord->d_name, &sbuf);
        if(S_ISDIR(sbuf.st_mode))
            printf("%-16s %-9s\n", drecord->d_name, "<DIR>");
        else
            printf("%-16s %9d\n", drecord->d_name, sbuf.st_size);
    }
    closedir(dhandle);
    return(0);
}