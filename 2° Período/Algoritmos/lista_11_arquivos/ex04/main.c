#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_lines(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    int rows = 0;

    if (!file)
        return 0;

    char c = fgetc(file);

    while (c != EOF)
    {
        if (c == '\\' && fgetc(file) == 'n')
        {
            rows++;
        }

        c = fgetc(file);
    }
    return rows;
}

int main()
{
    int res = count_lines("../../notas_de_aula/arquivo.txt");

    printf("\nLinhas do arquivo: %d\n", res);
    return 0;
}