#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} Point;

float distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void nearest_points(int n, Point v[])
{
    if (n < 2)
    {
        return;
    }

    int p1 = 0, p2 = 1;
    float min_dist = distance(v[0], v[1]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float dist = distance(v[i], v[j]);
            if (dist < min_dist)
            {
                min_dist = dist;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("Os pontos mais próximos são (%f, %f) e (%f, %f) com uma distância de %f\n", v[p1].x, v[p1].y, v[p2].x, v[p2].y, min_dist);
}

int main()
{
    Point points[] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    nearest_points(n, points);

    return 0;
}