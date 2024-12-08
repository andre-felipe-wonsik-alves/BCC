#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

float distance_vector(int n, Point v[])
{
    float res;

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            return 0;
        }
        res = (v[i + 1].x - v[i].x) * (v[i + 1].x - v[i].x) + (v[i + 1].y - v[i].y) * (v[i + 1].y - v[i].y);
        res = sqrt(res);

        printf("%f\n", res);
    }
}

int main()
{
    Point v[3] = {{-2.0f, 7.5f}, {-1.0f, 8.5f}, {-2.0f, 7.5f}};

    distance_vector(3, v);
    return 0;
}