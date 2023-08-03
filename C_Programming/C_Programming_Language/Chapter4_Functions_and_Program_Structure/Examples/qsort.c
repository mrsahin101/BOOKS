#include <stdio.h>

/* Quick sort algorithm is developed by C.A.R Hoare in 1962.*/

/* qsort : sort v[left] ... v[right] into increasing order*/
void qsort(int v[],int left, int right)
{
    int i, last;

    void swap(int v[], int i, int j);

    if(left >= right)                       /* do nothing if array contains */
        return;                             /* fewer than two elements */
    
    swap(v, left, (left + right) / 2);      /* move partition elem*/
    last = left;                            /* to v[0] */

    for(i = left + 1; i <= right; i++)      /* partition */
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);                    /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
/* swap : interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    int array[9] = {19, 17, 15, 12, 16, 18, 4, 11, 13};

    printf("Unsorted Array : \n");
    printf("-----------------------------\n");
    for(int i = 0; i < 9; i++)
        printf("%d, ",array[i]);

    printf("\n\n");

    qsort(array, 0, 9);

    printf("Sorted Array : \n");
    printf("-----------------------------\n");
    for(int i = 0; i < 9; i++)
        printf("%d, ",array[i]);
    printf("\n\n");
}