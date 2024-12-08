#include <stdio.h>

void sum(int *p1, int *p2)
{
    *p1 = *p1 + *p2;
    printf("%d\n", *p1);
}

int main()
{
    int a = 1;
    int b = 2;

    int *p1 = &a;
    int *p2 = &b;

    sum(p1, p2);

    return 0;
}