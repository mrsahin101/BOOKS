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

- NULL -> **'\0'** used terminate strings in C. It corresponds to ASCII code 0.


#### C Language String Functions 
- ![C String Functions](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_III_Above_C_Level/Images/C_String_Functions.PNG) 


- strcpy syntax -> result = strcpy(gumby, pokey); -> returns 0 when they are exact same strings.

- In 3-dimensional char arrays syntax : names[x][y][z] -> x is row, y is columns, and z is each string size(how many character can string contain). 