#include <stdio.h>

void make_mirroed(char v[])
{
    char *p1 = v;
    int size = 1;

    for (int i = 0; *p1 != '\0'; i++)
    {
        size++;
        p1++;
    }

    *p1 = '|';
    p1++;

    for (int i = 2; *p1 != *(p1 - size); i += 2)
    {
        *p1 = *(p1 - i);
        p1++;
    }
}

int main()
{
    char name[40] = "John Doe";
    make_mirroed(name);
    printf("%s\n", name);
    return 0;
}