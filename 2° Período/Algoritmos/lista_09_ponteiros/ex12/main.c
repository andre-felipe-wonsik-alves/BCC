#include <stdio.h>

struct point
{
    int x, y;
    char symbol;
};
typedef struct point Point;

struct rect
{
    int x, y, width, height;
};
typedef struct rect Rect;

void print_board_with_coordinates(Rect *board, Point *points)
{
    if (points->x > board->width || points->x < 0)
    {
        return;
    }
    if (points->y > board->height || points->y < 0)
    {
        return;
    }

    for (int i = 0; i < board->y; i++)
    {
        printf("\n");
    }

    for (int i = 0; i < board->y; i++)
        for (int j = 0; j < (board->x + board->width); j++)
        {
            if (i == points->y && (j - board->x) - 1 == points->x)
            {
                printf("%c", points->symbol);
                points++;
            }
            else if (j > board->x)
            {
                printf("*");
                if (j == (board->x + board->width) - 1)
                {
                    printf("\n");
                }
            }
            else
            {
                printf(" ");
            }
        }
    printf("\n");
    {
    }
}

int main()
{
    Rect rect = {5, 5, 10, 10};
    Point points[] = {{0, 0, 'A'}, {2, 7, 'B'}, {9, 9, 'C'}};

    print_board_with_coordinates(&rect, points);
    return 0;
}