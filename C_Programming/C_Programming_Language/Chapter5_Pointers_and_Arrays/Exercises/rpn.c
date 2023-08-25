#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* get */
#define RPN_STACK_LENGTH    20

struct __rpn
{
    int operandStack[RPN_STACK_LENGTH];
    int operandHeadIndex;
}rpn;
char operators[4] = {'+', '-', '/', 'x'};

void rpn_init()
{
    rpn.operandHeadIndex = -1;
    for(int i = 0; i < RPN_STACK_LENGTH; i++)
        rpn.operandStack[i] = 0;
}

bool isOperator(char c)
{
    bool status = false;
    for(int i = 0; i < 4; i++)
    {
        if(c == operators[i])
            status = true;
    }
    return status;
}
void push_to_Stack(int x)
{
    rpn.operandHeadIndex++;
    rpn.operandStack[rpn.operandHeadIndex] = x;
}
int pop_from_stack()
{
    int temp = rpn.operandStack[rpn.operandHeadIndex];
    rpn.operandHeadIndex--;
    return temp;
}
void print_Stack_content(void)
{
    printf("Stack Content\n");
    for(int i = 0; i < rpn.operandHeadIndex + 1; i++)
    {
        printf("%d\n", rpn.operandStack[i]);
    }
    printf("-------------------");
}
int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("Write expression in postfix notation\n");
        printf("Usage : .\rpn.exe expression\n");
    }
    else
    {
        rpn_init();
        for(int i = 1; i < argc; i++)
        {
            if(!isOperator(argv[i][0]))
            {
                int temp = atoi(argv[i]);
                push_to_Stack(temp);
                
            }
            else
            {
                for(int j = 0; j < 4; j++)
                {
                    if(argv[i][0] == operators[j])
                    {
                        int op2 = pop_from_stack();
                        int op1 = pop_from_stack();
                        switch(j)
                        {
                            case 0:
                                push_to_Stack(op1 + op2);
                                break;
                            case 1:
                                push_to_Stack(op1 - op2);
                                break;
                            case 2: 
                                push_to_Stack(op1 / op2);
                                break;
                            case 3:
                                push_to_Stack(op1 * op2);
                                break;
                            default:
                                printf("Unknown error occured\n");
                        }
                    }
                }

            }

        }
        int result = pop_from_stack();
        printf("Result : %d\n", result);
    }
}