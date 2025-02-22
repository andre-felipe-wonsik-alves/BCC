#include <stdio.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

float print_point(Point p)
{
    printf("( %.2f, %.2f )\n", p.x, p.y);
}

int main()
{
    Point teste;

    teste.x = 1;
    teste.y = 2;

    print_point(teste);

    return 0;
}