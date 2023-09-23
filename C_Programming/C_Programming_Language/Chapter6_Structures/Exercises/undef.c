#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist                    /* table entry */
{
    struct nlist *next;         /* next entry in chain */
    char *name;                 /* defined name */
    char *defn;                 /* replacement text */
};

#define HASH_SIZE           101

static struct nlist *hastab[HASH_SIZE];             /* pointer table */

char *mystrdup(char *s);
void print_hashmap();
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
/* hash : from  hash value for string s*/
unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval & HASH_SIZE;
}
/* look up for s in hastab*/
struct nlist *lookup(char *s)
{
    struct nlist *np;
    
    
    for(np = hastab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s, np->name) == 0)
            return np;          /* found */
    return NULL;                /* not found */
}
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL)                     /* not found*/
    {
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = mystrdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hastab[hashval];
        hastab[hashval] = np;
    }
    else                                /* already there*/
        free((void *) np->defn);        /* free previous defn */
    if((np->defn = mystrdup(defn)) == NULL)
        return NULL;
    return np; 
}
char *mystrdup(char *s)           /* make a duplicate of s*/
{
    char *p;
    p = (char *)malloc(strlen(s) + 1);       /* +1 for '\0' */
    if(p != NULL)
        strcpy(p, s);
    return p;
}
void undef(char *name)
{
    struct nlist *temp = lookup(name);
    if(temp == NULL)
    {
        printf("Given name \"%s\" doesnt exist in hash map\n", name);
        return;
    }
    else
    {
        struct nlist *np, *previous = NULL;
        for(np = hastab[hash(name)]; np != NULL; previous = np, np = np->next)
        {
            if(strcmp(name, np->name) == 0)
                break;    
        }
        if(np->next == NULL && hastab[hash(name)] != np)                // Is last element in Link-List
        {
            previous->next = NULL;
            free(np);
        }
        else if(previous == NULL)           // is this first element in Link-List
        {
            if(np->next == NULL)
            {
                hastab[hash(name)] = NULL;
                free(np);
            }
            else
            {
                hastab[hash(name)]->next = np->next;
                free(np);
            }
        }
        else
        {
            previous->next = np->next;
            free(np);
        }
    }
}
int main()
{
    install("TRUE", "1");
    install("FALSE", "0");
    install("Embedded", "LOVE");
    install("FATMAN", "Big Eater");
    install("Fenerbahce", "True Love");
    install("Future", "AI");
    install("C language", "All Hail");
    printf("------------------------------\n");
    print_hashmap();
    undef("TRUE");
    printf("------------------------------\n");
    print_hashmap();
    
}
void print_hashmap()
{
    for(int i = 0; i < HASH_SIZE; i++)
    {
        if(hastab[i] != NULL)
        {
            printf("%02dth item name : %-30s Replacement text : %s\n", i + 1, hastab[i]->name, hastab[i]->defn);
            struct nlist *temp = hastab[i];
            while(temp->next != NULL)
            {
                temp = temp->next;
                printf("%02dth item name : %-30s Replacement text : %s\n", i + 1, hastab[i]->name, hastab[i]->defn);
            }   
        }

    }
}