#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_ASCII ' '

enum err
{
    ARG_FILENAME_MISSING = 1,
    TOO_MANY_ARGS = 2,
    FILE_DOESNT_EXIST = 3,
};
struct _glb
{
    FILE *fptr;
} globals;

typedef struct _node
{
    char word[256];
    int lineNumbers[128];
    int count;
    struct _node *next;
} node;

void print_node(node *temp);
void node_init(node *temp);
void insertLineNumber(node *myNode, int lineNumber);
bool isPunctuation(char c);
bool isProper(char *string);
void sort_printf(node *head, node *tail);
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide the file\n");
        printf("Usage wordcounter.exe [FILENAME]\n");
        return ARG_FILENAME_MISSING;
    }
    else if (argc > 2)
    {
        printf("Too many arguments\n");
        printf("Usage wordcounter.exe [FILENAME]\n");
        return TOO_MANY_ARGS;
    }
    else
    {
        if (!(globals.fptr = fopen(argv[1], "r")))
        {
            printf("ERROR! File Doesn't exist\n");
            return FILE_DOESNT_EXIST;
        }
    }
    char c;
    node *head;
    node *tail;
    bool word_on = false;
    char wordBuffer[256];
    int wordIndex = 0;
    bool isFirstWord = true;
    int lineCounter = 1;
    while ((c = fgetc(globals.fptr)) != EOF)
    {
        if (c == '\n')
            lineCounter++;
        if (word_on == false && c != SPACE_ASCII && !isPunctuation(c))
        {
            word_on = true;
            wordBuffer[wordIndex++] = c;
            continue;
        }
        if (word_on == true && (c != SPACE_ASCII && !isPunctuation(c)))
        {
            wordBuffer[wordIndex++] = c;
            continue;
        }
        if (word_on == true && (c == SPACE_ASCII || isPunctuation(c)))
        {
            wordBuffer[wordIndex] = '\0';
            wordIndex = 0;
            word_on = false;
            if (isProper(wordBuffer))
            {
                if (isFirstWord == true)
                {
                    isFirstWord = false;
                    head = (node *)malloc(sizeof(node));
                    node_init(head);
                    tail = head;
                    strcpy(head->word, wordBuffer);
                    head->next = NULL;
                    tail->count++;
                    insertLineNumber(head, lineCounter);
                }
                else
                {
                    // Does it exist
                    bool doesExist = false;
                    node *temp = head;
                    node *found;
                    if (strcmp(temp->word, wordBuffer) == 0)
                    {
                        found = temp;
                        doesExist = true;
                    }
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                        if (strcmp(temp->word, wordBuffer) == 0)
                        {
                            found = temp;
                            doesExist = true;
                            break;
                        }
                    }
                    if (doesExist == true)
                    {
                        // BURADA KALDIM
                        for (int i = 0; i < 128; i++)
                        {
                            if (found->lineNumbers[i] != -1)
                                continue;
                            else
                            {
                                found->lineNumbers[i] = lineCounter;
                                found->count++;
                                break;
                            }
                        }
                    }
                    else
                    {
                        tail->next = (node *)malloc(sizeof(node));
                        tail = tail->next;
                        node_init(tail);
                        strcpy(tail->word, wordBuffer);
                        tail->next = NULL;
                        tail->count++;
                        insertLineNumber(tail, lineCounter);
                    }
                }
            }
        }
    }

    printf("Done\n");
    node *temporary;
    temporary = head;
    print_node(head);
    while (temporary->next != NULL)
    {
        temporary = temporary->next;
        print_node(temporary);
    }
    sort_printf(head, tail);

}

void sort_printf(node *head, node *tail)
{
    node *localhead = head;
    node *localtail = tail;
    
    while(localhead != NULL)
    {
        int highest = localhead->count;
        node *temp = localhead;
        node *highNode = localhead;
        node *previous = NULL;
        while(temp->next != NULL)
        {
            if(temp->next->count > highest)
                previous = temp;
            temp = temp->next;
            if(temp->count > highest)
            {
                highest = temp->count;
                highNode = temp;
            }
        }
        if(highNode == localhead)
        {
            printf("Word : %s,Occurence : %d\n", localhead->word, localhead->count);
            node *temp2 = localhead->next;
            free(localhead);
            localhead = temp2;
        }
        else if(highNode == localtail)
        {
            printf("Word : %s, Occurence : %d\n", localtail->word, localhead->count);
            free(localtail);
            localtail = previous;
        }
        else
        {
            printf("Word : %s, Occurence : %d\n", highNode->word, highNode->count);
            previous->next = highNode->next;
            free(highNode);
        }
    }
}
void print_node(node *temp)
{
    printf("Word : %s\n", temp->word);
    printf("Line Numbers : ");
    for (int i = 0; i < 128; i++)
    {
        if (temp->lineNumbers[i] == -1)
            break;
        printf("%d,", temp->lineNumbers[i]);
        printf("count : %d,", temp->count);
    }
    printf("\n");
}
void node_init(node *temp)
{
    for (int i = 0; i < 128; i++)
    {
        temp->lineNumbers[i] = -1;
    }
    temp->count = 0;
    temp->next = NULL;
}
void insertLineNumber(node *myNode, int lineNumber)
{
    for (int i = 0; i < 128; i++)
    {
        if (myNode->lineNumbers[i] == -1)
        {
            myNode->lineNumbers[i] = lineNumber;
            break;
        }
    }
}
bool isPunctuation(char c)
{
    char punc[] = {'\"', '!', ',', ';', '.', '?', ':', '\n', '\t'};
    for (int i = 0; i < 9; i++)
    {
        if (punc[i] == c)
            return true;
    }
    return false;
}
bool isProper(char *string)
{
    char connective[][255] = {"as", "and", "it", "but", "if", "or", "at", "by", "to", "then"};
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(connective[i], string) == 0)
        {
            return false;
        }
    }
    return true;
}