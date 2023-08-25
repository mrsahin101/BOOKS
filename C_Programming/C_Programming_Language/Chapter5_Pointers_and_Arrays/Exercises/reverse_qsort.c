#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES        5000        /* max #lines to be sorted*/
char *lineptr[MAXLINES];            /*pointers to text lines*/
#define MAXLEN          200

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int my_getline(char *line, int max);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';  /* remove newline character */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
void reverse_write_lines(char *lineptr[], int nlines)
{
    for(int i = nlines -1 ; i >= 0; i--)
        printf("%s\n", lineptr[i]);
}
/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;             /* number of input lines to read*/
    int numeric = 0;        /* 1 if numeric sort */
    int reverse = 0;
    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if(argc > 1 && strcmp(argv[1],"-r") == 0)
        reverse = 1;
    else if(argc > 2)
        if(strcmp(argv[2], "-r") == 0)
            reverse = 1;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        printf("Entered if");
        myqsort((void **)lineptr, 0, nlines - 1, (int(*)(void*, void*)) (numeric ? numcmp : strcmp));
        printf("-------Sorted-------\n");
        if(reverse)
            reverse_write_lines(lineptr, nlines);
        else
            writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}
/* numcmp : compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}
/* qsort : sort v[left]...v[right] into increasing order*/
void myqsort(void *v[], int left, int right, int (*comp)(void *, void*))
{
    int i, last;
    void swap(void *v[], int, int);

    if(left >= right)               /* do nothing if array contains fewer than two elements*/
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
/* my_getline: read input line */
int my_getline(char *line, int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}