#include <stdio.h>
#include <stdlib.h>

int save_lines(const char *filepath, int n, const char text_lines[n][51])
{
    FILE *file = fopen(filepath, "w");
    if (!file)
        return 0;

    for (int i = 0; i < n; i++)
    {
        fputs(text_lines[i], file);
        fputc('\n', file);
    }

    return 1;
}

int main()
{
    const char *filepath = "output.txt";
    int n = 3;

    const char text_lines[3][51] = {
        "Primeira linha",
        "Segunda linha",
        "Terceira linha"};

    if (save_lines(filepath, n, text_lines))
    {
        printf("As linhas foram salvas com sucesso em %s.\n", filepath);
    }
    else
    {
        printf("Erro ao salvar as linhas em %s.\n", filepath);
    }

    return 0;
}