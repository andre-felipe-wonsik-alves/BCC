#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_or_create(const char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (!file)
    {
        fopen(filepath, "w");
        return 1;
    }
    return 0;
}

int main()

{
    int res = check_or_create("teste.txt");
    return 0;
}