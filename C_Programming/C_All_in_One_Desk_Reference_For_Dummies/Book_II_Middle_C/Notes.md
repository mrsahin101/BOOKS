# NOTES

- When using declaring **unsigned long int** order or predence doesnt matter. We can also do this **long unsigned int** : Both are same for the compiler

- Type-Casting syntax : (type) variable;

- If we want to divide 2 integer and get result as floating point, Atleast one of integer has to be casted as floating point number!

#### C Language Variable Types 
![C Variable Types](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_II_Middle_C/Images/C_Variable_Types.PNG) 

#### Number Systems
- Base 2 -> Binary          -> 0,1;
- Base 8 -> Octal           -> 0,1,2,3,4,5,6,7;
- Base 10 -> Decimal        -> 0,1,2,3,4,5,6,7,8,9;
- Base 16 -> Hexadecimal    -> 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F;

- Hexadecimal numbers are prefixed with 0x front of them. E.g : 0xC8FE

- Another way to write hexadeciamls is : C800h 
- Another way to write hexadecimals is : $C800

- Scientific Notation is short hand notation to represent big or small numbers: 6,000,000 -> 6E+09
    or .000000000097531 -> 9.7531E-11

- Scientific notation syntax : n.nnnnnE+-mm

- Scientific notation placeholders -> %e %E %g %G works only with float point numbers. If you gonna use integer make sure cast it to float first.

- We can assign variables with scientific notation such as : float var = 6.27E-4; or #define DELTA_V 6.27E-4

- '#' is prefix character for hexdecimals and octals. For placeholders such as %x, %X, %o, prefixes expresssion with 0X or 0x or 0

- Computers measures angles in **radians** not degrees.
    pi radians = 180 degrees
    1 radian = 180 / pi degrees or 180/ 3.14159265
    1 radian = 57.2957795 degrees
    1 degree = 0.0174532925 radians

- In computers it's hard to generate trully random numbers. Thats why we are using pseudorandom numbers.

- Modulo syntaax : result = divided % divider; -> result is basically remiander of divided / divider;
 
#### Order of Precedence
   1. Multiplication
   2. Division
   3. Modulo
   4. Addition
   5. Subtraction

#### LOOPS
- All loops have three parts
    1. A setup, or initialization
    2. The part that loops - the statements that repeat
    3. The condition on which the loop finishes

- While loop syntax body :
    some sort of setup;
    while(condition == true)
    {
        statement;
        statement;
        /* more statements... */
        something to modify the condition and end the loop;
    }

- Generally speaking, compilers see **non-zero** values as TRUE and !0 works out to a non-zero value for the compiler.
    1. FALSE -> 0
    2. TRUE  -> ALL non zero values.


##### Do while syntax :
    do 
    {
        statement;
        statement;
        /* more statements */
    }
    while(condition == true);

- Difference with generic while loop is : even if loop condition is false, body part of the loop executed at least once.

- **continue** keyword is used in loops. When continue keywords is executed, it basically ignores loop body and goes back to head of the loop.