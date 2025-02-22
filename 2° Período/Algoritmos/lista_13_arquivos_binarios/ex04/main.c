#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[51];
} Movie;

int count_movies(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        return -1;
    }

    fseek(file, 0, SEEK_END);

    int file_size = ftell(file);

    fclose(file);

    return file_size /
           sizeof(Movie);
}

int main()
{

    int size = count_movies("../ex03/movies.bin");
    printf("%d\n", size);
    return 0;
}