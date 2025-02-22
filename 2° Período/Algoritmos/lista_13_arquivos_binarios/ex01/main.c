#include <stdio.h>

void write_array(const char *filePath, const int *v, int n)
{
    FILE *file = fopen(filePath, "wb");
    if (!file)
        return;
    

    int w = fwrite(v, sizeof(int),n, file);

    fclose(file);
}

int main()
{
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    // cria arquivo 'dados.bin' com conteúdo de 'v'
    write_array("../ex02/dados.bin", v, 10);
    return 0;
}