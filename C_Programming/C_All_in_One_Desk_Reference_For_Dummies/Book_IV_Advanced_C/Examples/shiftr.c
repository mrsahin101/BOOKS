#include <stdio.h>

int main()
{
    int v, r;

    printf("Enter an integer value:");
    scanf("%d", &v);
    r = v >> 1;         /* shift bits one notch right */
    printf("%d cut in half is %d\n", v, r);
    
    return(0);
}