# CONTROL FLOW

### Statements and Blocks
- In C, **;** is statement terminator. Braces(**{**, **}**) puts statements into **compound statement** or **block**.

### if-else 
- Syntax :
``` C
if(expression)
    statement1;
else
    statement2;
```

### else if
- Syntax :
``` C
    if(expression1)
        statement1;
    else if(expression2)
        statement2;
    else if(expression3)
        statement3;
    else if(expression4)
        statement4;
    else
        statement5;
```

### Switch
- Syntax :
``` C
    switch(expression)
    {
        case constant-expression1 : 
            statements;
        case constant-expression2 : 
            statements;
        case constant-expression3 :
            statements;
        default:
            statements;
    }
```

### Loops - While and For
``` C
    while(expression)
    {
        statements;
    }

    for(expr1; expr2; expr3)
    {
        statements;
    }
```

### Loops - Do-While
``` C
do 
{
    statements;
}
while(expression);
```
### Break and Continue
- **break** and **continue** are used to to braek out of loop or ifs. Continue **only** applies to loops.


### Goto and Labels
- <code>goto</code> is never necessary and in practice it is almost always easy to write code without it.