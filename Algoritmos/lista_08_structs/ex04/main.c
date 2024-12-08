#include <stdio.h>
#include <stdlib.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

void random_points(int n, Point v[])
{
    float rand_number;
    int size = n - 1;

    for (int i = 0; i < n; i++)
    {
        rand_number = rand() / ((float)RAND_MAX * ((n - 1) - v[0]));
    }
}

int main()
{

    return 0;
}