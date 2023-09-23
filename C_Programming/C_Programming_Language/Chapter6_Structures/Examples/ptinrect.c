#include <stdio.h>

struct point
{
    int x;
    int y;
};
struct rect
{
    struct point pt1;
    struct point pt2;
};
/* makepoint : make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    
    temp.x = x;
    temp.y = y;
    return temp;
}
/* ptinrect : return 1 if p in r, 0 if not*/
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main()
{
    struct point firstPoint = makepoint(1, 2);
    struct point secondPoint = makepoint(3, 4);
    struct rect firstRectangle;
    firstRectangle.pt1 = firstPoint;
    firstRectangle.pt2 = secondPoint;

    struct point searchedPoint = makepoint(2,3);
    if(ptinrect(searchedPoint, firstRectangle) == 1)
        printf("Point is in rectangle\n");
    else
        printf("Point is not in rectangle\n");
    return 0;

}