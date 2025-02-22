#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[51];
} Movie;

void write_all_movies(const char *filepath, const Movie *list, int size)
{
    FILE *file = fopen(filepath, "wb");
    if (file == NULL)
    {
        return;
    }

    fwrite(list, sizeof(Movie), size, file);
}

int main()
{
    Movie list[] = {
        {6, "They Live"},
        {11, "Big Trouble in Little China"},
        {10, "The Thing"},
        {1, "In the Mouth of Madness"},
        {8, "Ghosts of Mars"},
        {23, "Halloween"},
        {7, "Village of the Damned"}};

    write_all_movies("movies.bin", list, 7);

    return 0;
}