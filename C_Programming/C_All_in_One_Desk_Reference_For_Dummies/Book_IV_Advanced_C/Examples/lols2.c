#include <stdio.h>

int main()
{
    int start, finish;
    int *examine;

    examine = &start;
    *examine = 100;
    printf("%d little old ladies started the race.\n", start);
    examine = &finish;
    *examine = 9;
    printf("But only %d little old laides finished.\n", finish);
    
    return(0);
}