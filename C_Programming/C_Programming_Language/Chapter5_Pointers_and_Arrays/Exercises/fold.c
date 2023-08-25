#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXLINES        5000        /* max #lines to be sorted*/
char *lineptr[MAXLINES];            /*pointers to text lines*/
#define MAXLEN          200

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int my_getline(char *line, int max);
int cmpWrapper(void *firstString, void *secondString);
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

struct _cmdoptions
{
    bool numeric;       // -n
    bool reverse;       // -r
    bool fold;          // -f
    bool directory;     // -d
    char *options[4];
}cmd_options;
void check_arguments(int argc,char *argv[])
{
    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(strcmp(argv[i], cmd_options.options[j]) == 0)
                {
                    if(j == 0) {cmd_options.numeric = true;} 
                    if(j == 1) {cmd_options.reverse = true;}
                    if(j == 2) {cmd_options.fold = true;}
                    if(j == 3) {cmd_options.directory = true;}
                }
            }
        }
    }
    
}
void options_init()
{
    cmd_options.numeric = false;
    cmd_options.reverse = false;
    cmd_options.fold = false;
    cmd_options.directory = false;
    cmd_options.options[0] = "-n";
    cmd_options.options[1] = "-r";
    cmd_options.options[2] = "-f";
    cmd_options.options[3] = "-d";
}
/* sort input lines */
int main(int argc, char *argv[])
{
    options_init();
    int nlines;             /* number of input lines to read*/
    check_arguments(argc, argv);
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        myqsort((void **)lineptr, 0, nlines - 1, (int(*)(void*, void*)) (cmd_options.numeric ? numcmp : cmpWrapper));
        printf("-------Sorted-------\n");
        if(cmd_options.reverse == true)
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
int cmpWrapper(void *firstString, void *secondString)
{
    if(cmd_options.fold == true)
    {
        char *ptrfString = (char *)firstString;
        char *ptrsString = (char *)secondString;
        char *fString = malloc((strlen(ptrfString) * sizeof(char)) + sizeof(char));
        char *sString = malloc((strlen(ptrsString) * sizeof(char)) + sizeof(char));
        for(int i = 0; i < strlen(ptrfString); i++)
        {
            char ch = ptrfString[i];
            fString[i] = toupper(ch);
        }
        fString[strlen(ptrfString)] = '\0';

        for(int i = 0; i <strlen(ptrsString); i++)
        {
            char ch = ptrsString[i];
            sString[i] = toupper(ch);
        }
        sString[strlen(ptrsString)] = '\0';
        if(strcmp((char *)fString, (char *)sString) == 0)
        {
            free(fString);
            free(sString);
            return 0;
        }
        else if(strcmp((char *)fString, (char *)sString) > 0)
        {
            free(fString);
            free(sString);
            return 1;
        }
        else if (strcmp((char *)fString, (char *)sString) < 0)
        {
            free(fString);
            free(sString);
            return -1;
        }
    }
    else if (cmd_options.directory == true)
    {
        char *ptrfString = (char *)firstString;
        char *ptrsString = (char *)secondString;
        char *fString = malloc((strlen(ptrfString) * sizeof(char)) + sizeof(char));
        char *sString = malloc((strlen(ptrsString) * sizeof(char)) + sizeof(char));
        int i = 0, string_index = 0;
        for(i = 0; i < strlen(ptrfString); i++)
        {
            if(isalpha(ptrfString[i]) || isspace(ptrfString[i] || isdigit(ptrfString[i])))
            {
                fString[string_index] = ptrfString[i];
                string_index++;
            }
        }
        fString[string_index] = '\0';
        string_index = 0;

        for(i = 0; i < strlen(ptrsString); i++)
        {
            if(isalpha(ptrsString[i]) || isspace(ptrsString[i] || isdigit(ptrsString[i])))
            {
                sString[string_index] = ptrsString[i];
                string_index++;
            }
        }
        sString[string_index] = '\0';
        if(strcmp((char *)fString, (char *)sString) == 0)
        {
            free(fString);
            free(sString);
            return 0;
        }
        else if(strcmp((char *)fString, (char *)sString) > 0)
        {
            free(fString);
            free(sString);
            return 1;
        }
        else if (strcmp((char *)fString, (char *)sString) < 0)
        {
            free(fString);
            free(sString);
            return -1;
        }
    }
    else
        return strcmp((char *)firstString, (char *)secondString);
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