#include <stdio.h>
#include <stdlib.h>

#define FALSE       0
#define TRUE        !FALSE

#define PASS        TRUE
#define FAIL        FALSE

typedef int bool;

FILE* ptr;

int syntax_checker();
bool parentheses_checker();
bool brackets_checker();
bool braces_checker();

/* I could write more detailed version(Real world example), but since my point is to go through this book, i wont go into details */
int main()
{
    
    ptr = fopen("example.c", "r+");
    
    syntax_checker();
    
    fclose(ptr);
}

bool syntax_checker()
{
    if(parentheses_checker() == PASS)
        printf("Parentheses check passed!\n");
    else
        printf("Parentheses check failed!\n");

    if(brackets_checker() == PASS)
        printf("Brackets check passed!\n");
    else
        printf("Brackets check failed!\n");

    if(braces_checker() == PASS)
        printf("Braces check passed!\n");
    else
        printf("Braces check failed!\n");
}
bool braces_checker()
{
    int left_braces = 0, right_braces = 0;
    char ch;

    while((ch = fgetc(ptr)) != EOF)
    {
        if(ch == '{')
            left_braces++;
        if(ch == '}')
            right_braces++;
    }
    if(left_braces == right_braces)
        return PASS;
    else
        return FALSE;
}
bool brackets_checker()
{
    int left_bracket = 0, right_bracket = 0;
    char ch;

    while((ch = fgetc(ptr)) != EOF)
    {
        if(ch == '[')
            left_bracket++;
        if(ch == ']')
            right_bracket++;
    }
    if(right_bracket == left_bracket)
        return PASS;
    else
        return FAIL;
}
bool parentheses_checker()
{
    int left_parentheses = 0, right_parentheses = 0;
    char ch;
    while((ch = fgetc(ptr)) != EOF)
    {
        if(ch == '(')
            left_parentheses++;
        if(ch == ')')
            right_parentheses++;
    }  
    if(right_parentheses == left_parentheses)
        return PASS;
    else
        return FAIL;
}