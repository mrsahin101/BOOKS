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

/* addpoint : add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int main()
{
    int x = 1, y = 2;
    struct point firstPoint = makepoint(1, 2);
    printf("x : %d, y : %d\n", firstPoint.x, firstPoint.y);
    
    struct point secondPoint = makepoint(3, 4);

    firstPoint = addpoint(firstPoint, secondPoint);

    printf("x : %d, y : %d\n", firstPoint.x, firstPoint.y);
    return 0;

}