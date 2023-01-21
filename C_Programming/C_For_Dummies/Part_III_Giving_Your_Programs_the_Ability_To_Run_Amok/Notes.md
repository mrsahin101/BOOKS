# NOTES

- Arithmetic operators
    ![Arithmetic Operators](https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_III_Giving_Your_Programs_the_Ability_To_Run_Amok/Images/Aritmethic_Operators.PNG) 

### Precedence of Operation :
1. Multiplication
2. Division
3. Addition
4. Substraction

- if statement Syntax
    if(comparison)
    {
        statement;
        [statement;..]
    }
    else
    {
        statement;
        [statement;..]
    }

#### Comparison Table 
-    ![ Comparison Table](https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_III_Giving_Your_Programs_the_Ability_To_Run_Amok/Images/If_Statements_1.PNG) 
     ![ Comparison Table](https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_III_Giving_Your_Programs_the_Ability_To_Run_Amok/Images/If_Statements_2.PNG)

- If and else statements
    ![ Comparison Table](https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_III_Giving_Your_Programs_the_Ability_To_Run_Amok/Images/If_else.PNG)
 

 - Since getchar reads from standart IO, for sequantial use; must flush stdin first to get input properly from prompt.

 - Comparing single character variable is viable with if, but when comparing whole string; result is unpredictable. 


 #### Logical Operators in if Statements
 
 ![ Comparison Table]( https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_III_Giving_Your_Programs_the_Ability_To_Run_Amok/Images/Logical_Operators.PNG)

#### For Loop Syntax
- for(starting; while_true; do_this)
    {
        statements;
    }
- Syntax for infinite for loop
    for(;;)
    {
        statements;
    }

- break keyword breaks out of the loop. This keyword only break out of the loop its in. Doesn't break out of nested loop. Just the loop its in!

#### Some syntactic sugar of C
- i++, i--, i += 5, i -= 5, i /= 2;
    ![ Comparison Table]( https://github.com/mrsahin101/C_for_Dummies/blob/master/Part_III_Giving_Your_Programs_the_Ability_To_Run_Amok/Images/Pre_Post_Increment_Decrement.PNG)

#### While loop Syntax
-   starting;
    while(while_true)
    {
        statement(s);
        do_this;
    }

#### Do-While loop Syntax
-   do
    {
        statement(s);
    }
    while(condition);

- When we taking input from user always its good practice to **check input bounds!**. This is also called making it bulletprof. Its used in professional programs.

- C language has sleep(seconds) functions for generating delay. it could be usefull sometimes. In some implementation of GCC sleep function takes input in order of milliseconds.

- **continue** keyword is very usefull. we can basically ignore that step with continue keyword.

#### Switch-Case syntax
-   switch(choice)
    {
        case item1:
            statement(s);
            break;
        case item2:
        case item3:
            statement(s);
            break;
        default:
            statement(s);
    }
- Using **break** keyword is important. If not program keep going through other case statements.

- We can skip default when using switch-case. In this situation when no match found nothing happens.