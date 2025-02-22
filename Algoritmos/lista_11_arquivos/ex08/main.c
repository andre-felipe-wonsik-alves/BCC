#include <stdio.h>
#include <stdlib.h>

char *get_content(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
        return NULL;

    char c;

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    int size = fileSize / sizeof(char);

    char *v = malloc(size * sizeof(char));
    int i = 0;
    rewind(file);

    while ((c = fgetc(file)) != EOF)
    {
        v[i] = c;
        i++;
    }

    fclose(file);
    return v;
}

int main()
{
    const char *filepath = "../ex07/output.txt";
    char *content = get_content(filepath);

    if (content)
    {
        printf("Conteúdo do arquivo:\n%s\n", content);
        free(content);
    }
    else
    {
        printf("Erro ao ler o arquivo %s.\n", filepath);
    }
    return 0;
}