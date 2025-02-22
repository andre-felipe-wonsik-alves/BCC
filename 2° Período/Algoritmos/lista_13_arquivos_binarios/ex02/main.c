#include <stdio.h>
#include <stdlib.h>

void print_array(int* v, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d ", v[i]);
    }
}

int *read_array(const char *filepath, int *n)
{
    FILE *file = fopen(filepath, "wb");
    if (file == NULL)
        return NULL;

    fseek(file, 0, SEEK_END); // indo até o final do arquivo
    int file_size = ftell(file);
    rewind(file);

    *n = file_size / sizeof(int);
    int *heap = malloc(*n * sizeof(int));

    int read = fread(heap, sizeof(int), *n, file);
}
int main()
{
    int n;
    int* v_lido = read_array("dados.bin", &n);
    if (v_lido != NULL) {
        for (int i = 0; i < n; i++) {
            printf("%d ", v_lido[i]);
        }
        printf("\n");
        free(v_lido);
    }
    return 0;
}