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

int main()
{
    install("TRUE", "1");
    install("FALSE", "0");
    install("Embedded", "LOVE");
    install("FATMAN", "Big Eater");
    install("Fenerbahce", "True Love");
    install("Future", "AI");
    install("C language", "All Hail");
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