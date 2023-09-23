#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD             100
#define HASH_MAP_LENGTH     128
void insertHashMap(char *string);
bool isPunctuation(char c);
enum err
{
    NOT_ENOUGH_ARGUMENTS = 1,
    TOO_MANY_ARGUMENTS = 2,
    ARGUMENT_IS_NOT_NUMERICAL = 3,
    FILE_DOESNT_EXIST = 4,
};
bool isInteger(char *string)
{
    for(int i = 0; i < strlen(string); i++)
    {
        if(!isdigit(string[i]))
            return false;
    }
    return true;
}
struct _glb
{
    int number_of_Characters;
    FILE *f_pointer;
}globals;
typedef struct mynode
{
    char word[256];
    struct mynode *next;
}node;
struct _vars
{
    node *hashMap[HASH_MAP_LENGTH];
    int hash_length;
}vars;
void hash_init(void)
{
    for(int i = 0; i < HASH_MAP_LENGTH; i++)
        vars.hashMap[i] = NULL;
    vars.hash_length = 0;
}
int main(int argc, char *argv[])
{
    /* INPUT ARGS HANDLING BEGIN */
    if(argc < 3)
    {
        printf("Please provide character count or filename!\n");
        printf("Usage : alphaorder.exe [CHARACTER COUNT] [FILENAME]\n");
        return NOT_ENOUGH_ARGUMENTS;
    }
    else if(argc == 3)
    {
        if(isInteger(argv[1]))
            globals.number_of_Characters = atoi(argv[1]);
        else
        {
            printf("Please enter positive integer number\n");
            printf("Usage : alphaorder.exe [CHARACTER COUNT] [FILENAME]\n");
            return(ARGUMENT_IS_NOT_NUMERICAL);
        }
        if(!(globals.f_pointer = fopen(argv[2], "r")))
        {
            printf("ERROR! File Doesn't exist\n");
            return FILE_DOESNT_EXIST;
        }
    }
    else
    {
        printf("Too many arguments\n");
        printf("Usage : alphaorder.exe [CHARACTER COUNT] [FILENAME]\n");
        return TOO_MANY_ARGUMENTS;
    }
    /* INPUT ARGS HANDLING END */
    char c;
    bool single_comment_on = 0;
    bool long_comment_on = 0;
    bool string_on = 0;
    bool word_on = 0;
    char c_prev;
    char wordBuffer[128];
    int wordIndex = 0;

    while((c = fgetc(globals.f_pointer)) != EOF)
    {
        if(c_prev == '\\' && c == '\\')
        {
            single_comment_on = true;
            c_prev = c;
            printf("Single comment found\n");
            continue;
        }
        if((c_prev == '/' & c == '*'))
        {
            long_comment_on = true;
            c_prev = c;
            printf("Long comment found\n");
            continue;
        }
        if(single_comment_on == true && c != '\n')
        {
            c_prev = c;
            printf("Single comment on\n");
            continue;
        }
        else if(single_comment_on == true && c == '\n')
        {
            c_prev = c;
            single_comment_on = false;
            printf("Single comment done\n");
            continue;
        }
        if(long_comment_on == true && c_prev == '*' && c == '/')
        {
            c_prev = c;
            long_comment_on = false;
            printf("long comment found\n");
            continue;
        }
        else if(long_comment_on == true && !(c_prev == '*' && c == '/'))
        {
            c_prev = c;
            printf("long comment on\n");
            continue;
        }  
        if(string_on == false && c == '\"')
        {
            c_prev = c;
            string_on = true;
            //printf("String found\n");
            continue;
        }
        else if(string_on == true && c != '\"')
        {
            c_prev = c;
            //printf("String on\n");
            continue;
        }
        else if(string_on == true && c ==  '\"')
        {
            c_prev = c;
            string_on = false;
            //printf("String done\n");
            continue;
        }
        if(word_on == false && (c == ' ' || isPunctuation(c)))
        {
            c_prev = c;
            continue;
        }
        if(word_on == false && (c != ' ' && !isPunctuation(c)))
        {
            c_prev = c;
            word_on = true;
            wordBuffer[wordIndex] = c;
            wordIndex++;
            //printf("Word found\n");
            continue;
        }
        if(word_on == true && (c != ' ' && !isPunctuation(c)))
        {
            wordBuffer[wordIndex] = c;
            wordIndex++;
            c_prev = c;
            continue;
        }
        if(word_on == true && (c == ' ' || isPunctuation(c)))
        {
            word_on = false;
            wordBuffer[wordIndex] = '\0';
            wordIndex = 0;
            //printf("Word done\n");
            insertHashMap(wordBuffer);
            //printf("%s\n", wordBuffer);
            c_prev = c;
            continue;
        }
        
    }
    for(int i = 0; i < 128; i++)
    {
        if(vars.hashMap[i]->next != NULL)
        {
            node *temp = vars.hashMap[i];
            printf("%s", temp->word);
            
            while(temp->next != NULL)
            {
                temp = temp->next;
                printf(",%s", temp->word);
            }
            printf("\n");
        }
    }
}
char punctuation[] = {'(', ')', '{', '}', ',', ';', '=', '+', '-', '\n', '!'};
bool isPunctuation(char c)
{
    for(int i = 0; i < 11; i++)
    {
        if(c == punctuation[i])
            return true;
    }
    return false;
}
void insertHashMap2(char *string)
{
    int low = 0;
    int high = vars.hash_length;
    while(0 <= high)
    {
        int mid = low + (high - low) / 2;

        if(strncmp(string, vars.hashMap[mid]->word, globals.number_of_Characters) == 0)
        {
            node *nodetemp = (node *)malloc(sizeof(node));
            strcpy(vars.hashMap[mid]->word, string);
            vars.hashMap[mid]->next = NULL;
        }
        else if(strncmp(string, vars.hashMap[mid]->word, globals.number_of_Characters) < 0)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    
}
bool searchHashMap(int index, char *string)
{
    node *temp = vars.hashMap[index];
    if(strcmp(temp->word, string) == 0)
        return true;
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(strcmp(temp->word, string) == 0)
            return true;
    }
    return false;
}
void insertHashMap(char *string)
{
    bool matchFound = false;
    for(int i = 0; i < HASH_MAP_LENGTH; i++)
    {
        if(vars.hashMap[i] != NULL)
        {
            if(strncmp(vars.hashMap[i]->word, string, globals.number_of_Characters) == 0)
            {
                if(searchHashMap(i, string) == true)
                    break;;
                node *temp = (node *)malloc(sizeof(node));
                strcpy(temp->word, string);
                temp->next = NULL;
                node *temp2 = vars.hashMap[i];
                while(temp2->next != NULL)
                    temp2 = temp2->next;
                temp2->next = temp;
                matchFound = true;
                break;
            }    
        }
        else
        {
            if(matchFound == false)
            {
                node *temp = (node *)malloc(sizeof(node));
                strcpy(temp->word, string);
                temp->next = NULL;
                vars.hashMap[i] = temp;
                break;
            }
        }
    }
}