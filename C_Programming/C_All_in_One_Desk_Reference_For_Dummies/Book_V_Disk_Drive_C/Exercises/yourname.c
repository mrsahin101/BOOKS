#include <stdio.h>

int main()
{
    FILE* logfile;
    char name[50];

    printf("Tell me your name :");
    scanf("%s", &name);
    
    logfile = fopen("yourname.txt", "w");
    fprintf(logfile, name);
    fclose(logfile);

    return(0);
}