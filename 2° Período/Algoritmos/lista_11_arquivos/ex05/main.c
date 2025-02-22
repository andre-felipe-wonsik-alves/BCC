#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int save_string(const char *filepath, const char *text)
{
    FILE *file = fopen(filepath, "w+");

    if (!file)
    {
        return 0;
    }

    fputs(text, file);
    fclose(file);

    return 1;
}

int main()
{
    int res = save_string("teste.txt", "chaaaama");

    printf("\nResponse: %d\n", res);
    return 0;
}