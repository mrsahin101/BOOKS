#include <stdio.h>

#define ALLOCSIZE       10000       /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n)                  /* return pointer to n characters */
{
    if(allocbuf + ALLOCSIZE - allocp >= n)      /* if it fits*/
    {
        allocp += n;
        return allocp - n;           /* old p*/
    }
    else
        return 0;                   /* not enough room */
}
void afree(char *p)                 /* free storage pointed to by p*/
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
int main()
{
    char *mypointer = alloc(6);
    if(mypointer != 0)
    {
        *mypointer = 'H';
        *(mypointer + 1) = 'E';
        *(mypointer + 2) = 'L';
        *(mypointer + 3) = 'L';
        *(mypointer + 4) = 'O';
        *(mypointer + 5) = '\0';

    }
    printf("%s", mypointer);
    afree(mypointer);
}