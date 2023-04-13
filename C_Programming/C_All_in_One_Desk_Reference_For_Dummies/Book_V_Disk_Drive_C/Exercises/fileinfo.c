#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main()
{
    struct stat fbuf;
    int x;
    char filename[50];
    
    printf("Enter file name with extension:");
    scanf("%s", &filename);

    x = stat(filename, &fbuf);
    if(x != 0)
    {
        puts("Error reading file");
        return(1);
    }

    puts("Some file stats on FILEINFO.c");
    printf("File size is %d bytes\n", fbuf.st_size);
    printf("File last modified %s\n", ctime(&fbuf.st_mtime));

    return(0);
}