#include <stdio.h>
#include <string.h>

#define SPACE_PER_WORD      15
#define MAXLINE             10


int columnIndex = 0;
char line[MAXLINE];    

void printWord(void);
int getline(void);
void spaceit(int sizeOfSpace);
/* Tab space are 4 and single space is 1*/
main()
{
    int len;

    while((len = getline()) > 0){
        printWord();
        spaceit(SPACE_PER_WORD - len);
        if(columnIndex > 80)
        {
            printf("\n");
            columnIndex = 0;
        }
    }
        
    return 0;
   //printf("a\tb");
}
void cleanLine(void)
{
    for(int i = 0; i < MAXLINE; i++)
        line[i] = '\0';
}
void printWord(void)
{
    for(int i = 0; i < strlen(line); i++)
    {
        putchar(line[i]);
        columnIndex++;
    }
    putchar('\0');
    columnIndex++;
}
void spaceit(int sizeOfSpace)
{
    while(sizeOfSpace > 0)
    {
        if(sizeOfSpace >= 8)
        {
            printf("\t");
            sizeOfSpace -= 8;
            columnIndex += 8;
        }
        else
        {
            columnIndex++;
            printf(" ");
            sizeOfSpace--;
        }/* 
        columnIndex++;
        printf(" ");
        sizeOfSpace--; */
    }
}
int getline(void)
{
    extern char line[];

    char word[20];
    scanf("%s", &word);
    
    for(int i = 0; i < strlen(word); i++)
    {
        line[i] = word[i];
        columnIndex++;
    }
    line[strlen(word)] = '\0';
    columnIndex++;
    return strlen(word);
}