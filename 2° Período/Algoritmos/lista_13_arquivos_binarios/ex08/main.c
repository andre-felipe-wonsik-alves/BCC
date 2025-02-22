#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[51];
} Movie;

int update_movie(const char *filepath, const Movie *movie)
{
    FILE *file = fopen(filepath, "r+b");
    Movie movieTemp;
    int pos = 0;
    if (!file)
        return 0;

    while (fread(&movieTemp, sizeof(Movie), 1, file))
    {
        if (movie->id == movieTemp.id)
        {
            fseek(file, pos * sizeof(Movie), SEEK_SET);
            fwrite(movie, sizeof(Movie), 1, file);
            fclose(file);
            return 1;
        }
        pos++;
    }

    fclose(file);
    return 0;
}

int main()
{
    Movie movie;
    movie.id = 1;
    snprintf(movie.name, sizeof(movie.name), "New Movie Name");

    if (update_movie("../ex03/movies.bin", &movie))
    {
        printf("Movie updated successfully.\n");
    }
    else
    {
        printf("Movie not found.\n");
    }
    return 0;
}