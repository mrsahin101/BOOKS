#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    for(int i = n / 2; i >= 0;)
    {
        if(v[i] == x)
            return x;
        else if(i == 0)
            break;
        else if(i >= n)
            break;
        else if (v[i] != x && v[i - 1] < x && v[i + 1] > x)
            return -1;
        else if(v[i] > x)
            i -= i / 2;
        else if(v[i] < x)
            i += i / 2;
    }
    return -1;
}

int main()
{
    int array[10] = {1, 5, 11, 44, 66, 71, 83, 99, 113, 180};

    if(binsearch(44, array, 10) > 0)
        printf("Match found! Index : %d", binsearch(44, array, 10));
    else
        printf("Failed to find match!\n");
}