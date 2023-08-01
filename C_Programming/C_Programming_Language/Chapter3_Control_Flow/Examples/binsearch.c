#include <stdio.h>

/* binsearch : find x in v[0] <= v[1] <= ... <= v[n-1]*/
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else    /* found match*/
            return mid;
    }
    return -1;  /* no match */
}
int main()
{
    int array[10] = {1, 5, 11, 44, 66, 71, 83, 99, 113, 180};

    if(binsearch(44, array, 10) > 0)
        printf("Match found! Index : %d", binsearch(44, array, 10));
    else
        printf("Failed to find match!\n");
}