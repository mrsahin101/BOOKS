#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN        1000

enum
{
    NAME,
    PARENS,
    BRACKETS
};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc...*/
char out[1000];             /* output string */

main()                      /* convert declaration to words*/
{
    while(gettoken() != EOF)            /* 1st token on line */
    {
        strcpy(datatype, token);        /* is the datatype */
        out[0] = '\0';
        dcl();                          /* parse rest of line */
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
int gettoken(void)              /* return next token */
{
    int c, mygetch(void);
    void myungetch(int);
    char *p = token;

    while((c = mygetch()) == ' ' || c == '\t')
        putchar(c);

    if(c == '(')
    {
        if((c = mygetch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            myungetch(c);
            return tokentype = '(';
        }
    }
    else if(c == '[')
    {
        for(*p++ = c; (*p++ = mygetch()) != ']';);
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if(isalpha(c))
    {
        for(*p++ = c; isalnum(c = mygetch());)
            *p++ = c;
        *p = '\0';
        myungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}
/* dirdcl : parse a direct declarator */
void dirdcl(void)
{
    int type; 

    if(tokentype == '(')    /* ( dcl ) */
    {
        dcl();
        if(tokentype != ')')
            printf("error: missing )\n");
    }
    else if(tokentype == NAME)      /* variable name*/
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while((type = gettoken()) == PARENS || type == BRACKETS)
        if(type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}
#define BUFSIZE (1 << 10)
int buf[BUFSIZE];
int bufp = 0;
int mygetch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void myungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
/* dcl : parse a declarator */
void dcl(void)
{
    int ns;

    for(ns = 0; gettoken() == '*';)     /* count *'s */
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out, " pointer to");
}