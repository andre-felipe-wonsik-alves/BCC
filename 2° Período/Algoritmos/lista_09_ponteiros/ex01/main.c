#include <stdio.h>

int main()
{
    char a = 'a';
    int b = 1;
    double c = 2;

    printf("char: %d\nint: %d\ndouble: %d\n", &a, &b, &c);

    return 0;
}