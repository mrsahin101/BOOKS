#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    DIR *dhandle;
    struct dirent *drecord;
    struct stat sbuf;
    int filecount = 0;
    int totalsize = 0;
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
        {
            printf("%-16s %9d\n", drecord->d_name, sbuf.st_size);
            filecount++;
            totalsize += sbuf.st_size;
        }
    }
    printf("%d files are total size of : %d bytes", filecount, totalsize);
    closedir(dhandle);
    return(0);
}