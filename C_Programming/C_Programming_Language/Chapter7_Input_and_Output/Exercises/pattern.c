#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH     255
#define KNRM            "\x1B[0m"
#define KRED            "\x1B[31m"
#define KGRN            "\x1B[32m"
#define KYEL            "\x1B[33m"
#define KBLU            "\x1B[34m"
#define KWHT            "\x1B[37m"
typedef struct _myfilet
{
    FILE *fp;
    char name[255];
    struct _myfilet *next;
}myfile_t;
void print_line(char *line, char *pattern)
{
    char *substring = strstr(line, pattern);
    int position = substring - line;
    for(int i = 0; i < strlen(line); i++)
    {
        if(i == position)
            printf("%s", KGRN);
        if(i == (position + strlen(pattern)))
            printf("%s", KWHT);
        printf("%c", line[i]);
        
    }
}
// Assumes file already opened and has no issues
void searchForPattern(myfile_t *fp, char *pattern)
{   
    char line[LINE_LENGTH];
    int lineIndexer = 1;
    char *substring;
    printf("Searching %s file for %s%s%s string pattern\n",fp->name, KRED, pattern, KWHT);
    while(fgets(line, sizeof(line), fp->fp) != NULL)
    {
        if((substring = strstr(line, pattern)) != NULL)
        {
            printf("Pattern found at line : %d->\t", lineIndexer);
            print_line(line, pattern);
            //printf("Line : %s%s%s\n", KGRN, line, KWHT);
        }
        lineIndexer++;
    }
    printf("Finished searching %s file\n\n", fp->name);
}
int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        fprintf(stderr, "ERROR! Atleast you should provide the pattern to be searched\n");
        fprintf(stderr,"Usage : pattern.exe [PATTERN_TO_SEARCH] [FILENAMES...]\n");
        exit(1);
    }
    else if(argc == 2)
    {
        myfile_t *object = (myfile_t *)malloc(sizeof(myfile_t));
        object->fp = stdin;
        memcpy(object->name, "stdin", 6);
        object->next = NULL;
        searchForPattern(object, argv[1]);
    }
    else
    {

        myfile_t *head = NULL;
        myfile_t *current;

        for(int i = 2; i < argc; i++)
        {
            if(head == NULL)
            {
                head = (myfile_t *)malloc(sizeof(myfile_t));
                if((head->fp = fopen(argv[2], "r")) == NULL)
                {
                    fprintf(stderr, "ERROR! Unable to open %s file\n", argv[2]);
                    exit(1);
                }
                else
                {
                    memcpy(head->name, argv[2], strlen(argv[2]) + 1);
                    head->next = NULL;
                    current = head;
                }
            }
            else
            {
                current->next = (myfile_t *)malloc(sizeof(myfile_t));
                current = current->next;
                if((current->fp = fopen(argv[i], "r")) == NULL)
                {
                    fprintf(stderr, "ERROR! Unable to open %s file\n", argv[i]);
                    exit(1);
                }
                else
                {
                    memcpy(current->name, argv[i], strlen(argv[i]) + 1);
                    current->next = NULL;
                }
            }
        }
        myfile_t *temp = head;
        while(temp != NULL)
        {
            searchForPattern(temp, argv[1]);
            temp = temp->next;
        }
    }
}