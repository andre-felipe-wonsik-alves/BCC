#include <stdio.h>
#include <math.h>

struct Point
{
    float x;
    float y;
};
typedef struct Point Point;

float distance(Point p1, Point p2)
{
    float res = (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
    res = sqrt(res);

    return res;
}

int main()
{

    Point p1 = {-2.0f, 7.5f};
    Point p2 = {5.0f, 12.4f};

    float dist = distance(p1, p2);
    printf("Distância: %f\n", dist);

    return 0;
}