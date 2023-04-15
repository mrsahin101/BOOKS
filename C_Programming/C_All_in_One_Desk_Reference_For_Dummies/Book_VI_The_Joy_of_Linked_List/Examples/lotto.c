#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define RANGE 52
#define BALLS 6

int getBall(void);

struct lotto
{
    int ball[BALLS];
    struct lotto *previous;
    struct lotto *next;
};

struct lotto *f, *c, *n, *p, *l;

int main()
{
    int x, y;

    srand((unsigned)time(NULL));        /* seed the randomizer */

    /* fill the first record */
    f = (struct lotto *)malloc(sizeof(struct lotto));
    for(x = 0; x < BALLS; x++)
        f->ball[x] = getBall();
    f->previous = NULL;
    f->next = NULL;
    c = f;

    /* fill middle records*/
    for(y = 0; y < 9; y++)
    {
        p = c;
        n = (struct lotto *)malloc(sizeof(struct lotto));
        c->next = n;
        c = n;
        for(x = 0; x < BALLS; x++)
            c->ball[x] = getBall();
        c->previous = p;
    }
    /* fix in the last record */
    c->next = NULL;
    l = c;

    return(0);
}

int getBall(void)
{
    return (rand() % RANGE + 1);
}