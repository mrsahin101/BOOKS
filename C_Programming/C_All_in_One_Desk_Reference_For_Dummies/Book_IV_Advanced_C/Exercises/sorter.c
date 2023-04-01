#include <stdio.h>
#include <string.h>

#define SIZE 10

int main()
{
    int input[SIZE];
    int *isort[SIZE];
    int *temp;
    int x, a, b;

    /* Get the SIZE number of strings */
    printf("Enter %d types of fruit:\n", SIZE);
    for(x = 0; x < SIZE; x++)
    {
        printf("#%d:", x + 1);
        scanf("%d", &input[x]);
        isort[x] = &input[x];
    }

    /* Sort the strings via pointers */
    for(a = 0; a < SIZE - 1; a++)
        for(b = a + 1; b < SIZE; b++)
        {
            if(*isort[a] > *isort[b])
            {
                temp = isort[a];
                isort[a] = isort[b];
                isort[b] = temp;
            }
        }
    
    /* print the result */
    printf("Sorted list:\tOriginal list:\n");
    for(x = 0; x < SIZE; x++)
        printf("%12d\t%12d\n", *isort[x],input[x]);
    
    return(0);
}