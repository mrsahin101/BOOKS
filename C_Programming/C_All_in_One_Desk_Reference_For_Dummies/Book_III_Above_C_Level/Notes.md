# NOTES

## Arrays
- Arrays start with index 0. Each element could be threated like just normal variable.

- Since arrays declared like int array[5]; their size is constant. Doesn't change dynamically. So we can use constant with define directive to control array size.

#### Bubble sort in pseudocode
-   begin BubbleSort(list)
        for all elements of list
            if list[i] > list[i + 1]
                swap(list[i], list[i + 1])
            end if
        end for
        return list
    end BubbleSort

- In two-dimensional arrays, both dimension is same data type. 

- In fact there is no such a thing **two-dimensional** array. All arrays in memory are single dimenson but multi-dimensional arrays are shortcut notation.