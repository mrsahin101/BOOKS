#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *input;
    int size;

    /* Allocate "enough" memory */
    input = (char *) malloc(4069);       /* 4K Input Buffer */

    printf("Enter some text:");
    gets(input);

    /* resize input buffer to save space */
    size = strlen(input) + 1;           /* +1 for NULL */
    if(!realloc(input, size))
    {
        puts("Unable to reallocate memory");
        return(0);
    }
    puts("Memory reallocation succesfull.");
    printf("String is : \n\"%s\"\n",input);
    free(input);
    puts("Memory has been released.");
    printf("String is : \n\"%s\"\n",input);
    return(0);
}