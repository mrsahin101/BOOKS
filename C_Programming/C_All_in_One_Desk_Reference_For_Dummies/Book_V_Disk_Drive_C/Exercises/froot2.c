#include <stdio.h>

int main()
{
    char froot[25][14];
    FILE *f;
    int x;

    if(!(f = fopen("froot.txt", "r")))
    {
        puts("Error creating file");
        return(1);
    }
    printf("After file opened, file pointer = %d\n", ftell(f));

    for(x = 0; x < 25; x++)
    {
        fread(froot[x], 14, 1, f);
        printf("Read record %d, Content : %s\n", x, froot[x]);
    }
    fclose(f);
    
    return(0);
}