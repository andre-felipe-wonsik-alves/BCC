#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[51];
} Movie;

int find_movie(const char *filepath, long id)
{
    FILE *file = fopen(filepath, "rb");
    if (!file)
        return -1;
    Movie movie;
    int index = 0, pos = 0;

    while (fread(&movie, sizeof(Movie), 1, file))
    {
        if (movie.id == id)
        {
            return pos;
        }
        pos++;
    }

    fclose(file);
}

int main()
{
    long pos = find_movie("../ex03/movies.bin", 23);
    printf("%ld\n", pos);
    return 0;
}