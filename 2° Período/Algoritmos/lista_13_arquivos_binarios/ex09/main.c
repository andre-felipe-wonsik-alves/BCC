#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[51];
} Movie;

int delete_movie(const char *filepath, long id)
{
    Movie movie;
    Movie movieApagado = {-1, "apagado"};

    FILE *file = fopen(filepath, "r+b");
    if (!file)
        return 0;

    while (fread(&movie, sizeof(Movie), 1, file))
    {
        if (movie.id == id)
        {
            fseek(file, sizeof(Movie), SEEK_CUR); // garante que o ponteiro está no início do próximo registro
            fwrite(&movie, sizeof(Movie), 1, file);
            fclose(file);
            return 1;
        }
    }
    return 0;
}

int main()
{
    if (delete_movie("../ex03/movies.bin", 1))
    {
        printf("Movie deleted successfully.\n");
    }
    else
    {
        printf("Failed to delete movie.\n");
    }
    return 0;
}