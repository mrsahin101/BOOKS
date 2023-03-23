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

- CTYPE functions are introduced in ctype.h header file. There are functions like isalpha(), tolower()... This functions does operations on strings. There are 2 type functions
    1. Examine the given individual character.
    2. Do operation on given individual character.

- ![CTYPE Examination Functions](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_III_Above_C_Level/Images/C_Type_Test_Functions.PNG)

- ![CTYPE Character Changing Functions ](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_III_Above_C_Level/Images/C_Type_Character_Changing_Functions.PNG)

- Purpose of CTYPE functions is to examine given input and do desired work on them quickly.

## Structures
- Structures are basically multivariable. They make accesing data easier and helping us to keep data organized. They are like fill in the blank cards. 

- They keep related information together and easily accessed.

- Structures are basically collection of variable types all stored in one compact unit.

- Structure syntax: 
    struct name
    {
        type name;
        type name;
    };
After creating structure we should create variable from it : struct name variable;

- Also we can create structure and variable on the fly :
    struct name
    {
        type name;
        type name;
    }variable;
or
    struct name
    {
        type name;
        type name;
    }var1,var2,var3;

- Creating array of structures : struct name variable[20]; accessing each element of array : variable[x].name;

- We can also nesting structures in other structure. For example :
    struct date
    {
        int month;
        int day;
        int year;
    };

    struct family
    {
        char name[20];
        struct date birthday;
    };

- To access nested structure items, lets say we define it like this :
    struct family people;
    people.birtday.month is the way we access nested structure items.

## Functions
- Syntax :
    type name(type)
    {
        statement(s);
    }
- type variables :
    1. char (signed, unsigned)
    2. double
    3. float
    4. int(long, short, signed, unsigned)
    5. void

- Suggestions for functions : keep names short and descriptive.

- Global variables can only be declared or assigned immediate values.

- Passing values to function.
    1. Know what kind of value you will send to the function
    2. Define the variable in the function's parantheses.
    3. Somwhow use the variable in your function.
    4. Properly prototype the function.
    5. Remember to send the proper values when you're calling the function.

- Returning value with **return** keyword
    1. Function has to be defined as certain type.
    2. The function has to return a value.
    3. Void doesn't return any value.
    4. Functions can return only a single value. There is a way working around this with pointer.

- In case of error, **exit()** is best way to quit a program,  because it makes sure any open file are properly closed then quit.
- **abort()** is used for quittingg when something gone wrong.
- **atexit()** function does call what ever you specified when exit condition happen. Basically this work when exiting. 