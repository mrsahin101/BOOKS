#include <stdio.h>

/* shellsort : sort v[0]... v[n - 1] */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for(gap = n / 2; gap > 0; gap /= 2)
        for(i = gap; i < n; i++)
            for(j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

int main(void)
{
    int array[10] = {13, 5, 21, 1, 3, 41, 15, 2, 77, 11};

    printf("Unsorted array : \n");
    for(int i = 0; i < 10; i++)
        printf("%d, ", array[i]);
    printf("\n");
    
    shellsort(array, 10);

    printf("Sorted array : \n");
    for(int i = 0; i < 10; i++)
        printf("%d, ", array[i]);
}