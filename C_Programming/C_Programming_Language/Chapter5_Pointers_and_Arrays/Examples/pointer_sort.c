#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES            5000        /* max # lines to be sorted */

char *lineptr[MAXLINES];                /* pointer to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlies);

void myqsort(char *lineptr[], int left, int right);

int lineCounter = 0;
/* sort input lines */
main()
{
    int nlines;         /* number of input lines read*/

    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        myqsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
    }
}

#define MAXLEN          1000    /* max length of any input line*/
int mygetline(char lineptr[], int maxlines);
char *alloc(int);

char *alloc(int count)
{
    char *ptr = malloc(count * sizeof(char));
    return ptr;
}
/* readlines : read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while((len = mygetline(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';        /* delete newline*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
int mygetline(char lineptr[], int maxlines)
{
    int i;
    char ch;
    for (i=0; i<maxlines-1 && (ch=getchar())!=EOF && ch!='\n'; ++i)
    {
        lineptr[i] = ch;
    }
        
    if (ch == '\n') {
        lineptr[i] = ch;
        ++i;
    }
    lineptr[i] = '\0';
    lineCounter++;
}
/* writelines : write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}
/* swap : interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void myqsort(char *v[],int left, int right)
{
    int i, last;

    void swap(char *v[], int i, int j);

    if(left >= right)                       /* do nothing if array contains */
        return;                             /* fewer than two elements */
    
    swap(v, left, (left + right) / 2);      /* move partition elem*/
    last = left;                            /* to v[0] */

    for(i = left + 1; i <= right; i++)      /* partition */
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);                    /* restore partition elem */
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}
