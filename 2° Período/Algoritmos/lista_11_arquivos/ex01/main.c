#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_exists(const char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (!file)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int res = file_exists("../../notas_de_aula/arquivo.txt");
    printf("%d\n", res);
    return 0;
}