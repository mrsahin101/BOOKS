#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum _types
{
    INT_TYPE = 0,
    FLOAT_TYPE = 1,
    DOUBLE_TYPE = 2,
    STRING_TYPE = 3,
};

typedef struct _node
{
    enum _types utype;
    union{
        int ival;
        float fval;
        double dval;
        char str[10];
    }u;
}node;

void print_node(node *input)
{
    if(input->utype == INT_TYPE)
        printf("%d\n", input->u.ival);
    else if(input->utype == FLOAT_TYPE)
        printf("%f\n", input->u.fval);
    else if(input->utype == DOUBLE_TYPE)
        printf("%lf\n", input->u.dval);
    else if(input->utype == STRING_TYPE)
        printf("%s\n", input->u.str);
    else
        printf("ERROR! UNKNOWN TYPE\n");
}
int main()
{
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->u.str, "Hello\n");
    temp->utype = STRING_TYPE;

    print_node(temp);
}