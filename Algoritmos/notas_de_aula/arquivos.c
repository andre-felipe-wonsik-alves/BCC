#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file_string()
{
    FILE *file = fopen("arquivo.txt", "r"); // read
    if (file == NULL)
    {
        printf("ERRO: Arquivo nao existe.\n");
        return;
    }
    int n = 4; // 199 chars + '\0'
    char buffer[n];
    while (fgets(buffer, n, file) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(file);
}

void write_read_file_formatted()
{
    FILE *file = fopen("arquivo.txt", "w+"); // write-read trucate/create
    // Escreve com formato: deve iniciar com char
    for (int i = 0; i < 10; i++)
    {
        fprintf(file, " %d - %s - %f", i + 1, "TextoTeste", (i + 1) / 2.0f);
    }
    rewind(file); // mesmo que fseek(file, 0, SEEK_SET);
    // Leitura com o mesmo formato usado para escrita
    int a;
    float b;
    char str[20];
    while (fscanf(file, " %d - %s - %f", &a, str, &b) != EOF)
    {
        printf("%2d, %s, %.2f\n", a, str, b);
    }
    fclose(file);
}

int main()
{
    // read_file_string();
    write_read_file_formatted();
    return 0;
}
