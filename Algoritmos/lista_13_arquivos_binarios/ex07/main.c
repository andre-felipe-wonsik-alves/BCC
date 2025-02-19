#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[51];
} Movie;

int add_movie(const char *filepath, const Movie *movie)
{
    FILE *file = fopen(filepath, "ab");
    if (!file)
        return 0;

    fwrite(movie, sizeof(Movie), 1, file);

    fclose(file);

    return 1;
}

int main()
{
    Movie movie = {1, "The Shawshank Redemption"};

    if (add_movie("../ex03/movies.bin", &movie))
        printf("Filme adicionado com sucesso!\n");
    else
        printf("Erro ao adicionar filme!\n");

    return 0;
}