#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_words(const char *path, int *words_count)
{
    FILE *file = fopen(path, "r");
    if (!file)
    {
        return NULL;
    }

    char **words = NULL;
    char buffer[1024];
    *words_count = 0;

    while (fscanf(file, "%1023s", buffer) == 1)
    {
        char **temp = realloc(words, (*words_count + 1) * sizeof(char *));
        if (!temp)
        {
            for (int i = 0; i < *words_count; i++)
            {
                free(words[i]);
            }
            free(words);
            fclose(file);
            return NULL;
        }
        words = temp;
        words[*words_count] = strdup(buffer);
        if (!words[*words_count])
        {
            for (int i = 0; i < *words_count; i++)
            {
                free(words[i]);
            }
            free(words);
            fclose(file);
            return NULL;
        }
        (*words_count)++;
    }

    fclose(file);
    return words;
}

int main()
{
    int words_count;
    char **words = get_words("texto.txt", &words_count);

    if (words)
    {
        for (int i = 0; i < words_count; i++)
        {
            printf("%s\n", words[i]);
            free(words[i]);
        }
        free(words);
    }
    else
    {
        printf("erro.\n");
    }

    return 0;
}