#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[51];
} Movie;

Movie read_movie(const char *filepath, int pos)
{
    FILE *file = fopen(filepath, "rb");
    Movie movie = {0, "0"};

    if (!file)
        return movie;

    if (fseek(file, pos * sizeof(Movie), SEEK_SET) != 0)
    {
        return movie;
    }

    fread(&movie, sizeof(Movie), 1, file);

    return movie;
}

int main()
{
    Movie movie = read_movie("../ex03/movies.bin", 4); // movie = {8,"Ghosts of Mars "}

    printf("%s\n", movie.name);

    return 0;
}