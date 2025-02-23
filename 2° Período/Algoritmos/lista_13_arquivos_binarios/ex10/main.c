#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char title[100];
    int year;
} Movie;

int insert_sorted(const char *filepath, const Movie *movie)
{
    FILE *file = fopen(filepath, "rb+");
    if (!file)
    {
        file = fopen(filepath, "wb+");
        if (!file)
            return 0;
    }

    Movie current;
    long pos = 0;
    while (fread(&current, sizeof(Movie), 1, file))
    {
        if (current.id > movie->id)
        {
            break;
        }
        pos = ftell(file);
    }

    fseek(file, pos, SEEK_SET);

    FILE *tempFile = tmpfile();
    if (!tempFile)
    {
        fclose(file);
        return 0;
    }

    fseek(file, pos, SEEK_SET);
    while (fread(&current, sizeof(Movie), 1, file))
    {
        fwrite(&current, sizeof(Movie), 1, tempFile);
    }

    fseek(file, pos, SEEK_SET);
    fwrite(movie, sizeof(Movie), 1, file);

    fseek(tempFile, 0, SEEK_SET);
    while (fread(&current, sizeof(Movie), 1, tempFile))
    {
        fwrite(&current, sizeof(Movie), 1, file);
    }

    fclose(tempFile);
    fclose(file);
    return 1;
}