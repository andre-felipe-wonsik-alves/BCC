#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_content(const char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (!file)
    {
        return 0;
    }

    char ch = fgetc(file);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(file);
    }
    fclose(file);

    return 1;
}

int main()
{
    int res = print_content("../../notas_de_aula/arquivo.txt");

    printf("\nRetorno da funcao: %d\n", res);
    return 0;
}