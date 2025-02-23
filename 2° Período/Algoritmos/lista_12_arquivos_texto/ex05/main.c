#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **get_words(const char *filepath, int letters, int *count)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        return NULL;
    }

    char **words = NULL;
    char word[100];
    *count = 0;

    while (fscanf(file, "%99s", word) == 1)
    {
        int len = strlen(word);
        while (len > 0 && ispunct(word[len - 1]))
        {
            word[--len] = '\0';
        }
        if (len == letters)
        {
            words = realloc(words, (*count + 1) * sizeof(char *));
            words[*count] = malloc((len + 1) * sizeof(char));
            strcpy(words[*count], word);
            (*count)++;
        }
    }

    fclose(file);
    return words;
}

int main()
{
    const char *filepath = "example.txt";
    int letters = 5;
    int count = 0;
    char **words = get_words(filepath, letters, &count);

    if (words)
    {
        for (int i = 0; i < count; i++)
        {
            printf("%s\n", words[i]);
            free(words[i]);
        }
        free(words);
    }

    return 0;
}