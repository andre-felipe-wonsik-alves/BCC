#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char title[100];
    char director[100];
    int year;
} Movie;

int defrag(const char *filepath)
{
    FILE *file = fopen(filepath, "rb+");
    if (!file)
    {
        return 0;
    }

    FILE *temp = tmpfile();
    if (!temp)
    {
        fclose(file);
        return 0;
    }

    Movie movie;
    while (fread(&movie, sizeof(Movie), 1, file))
    {
        if (movie.id != -1)
        {
            fwrite(&movie, sizeof(Movie), 1, temp);
        }
    }

    rewind(file);
    rewind(temp);

    while (fread(&movie, sizeof(Movie), 1, temp))
    {
        fwrite(&movie, sizeof(Movie), 1, file);
    }

    fclose(file);
    fclose(temp);
    return 1;
}