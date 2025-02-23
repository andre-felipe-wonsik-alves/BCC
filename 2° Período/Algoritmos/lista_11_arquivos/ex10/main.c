#include <stdio.h>
#include <stdlib.h>

int is_separator(char c, const char *separators)
{
    while (*separators)
    {
        if (c == *separators)
        {
            return 1;
        }
        separators++;
    }
    return 0;
}

void copy_string(char *dest, const char *src, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

char **get_words_sep(const char *path, const char *separators, int *words_count)
{
    FILE *file = fopen(path, "r");
    if (!file)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(file_size + 1);
    if (!content)
    {
        fclose(file);
        return NULL;
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0';
    fclose(file);

    char **words = NULL;
    *words_count = 0;
    char *start = content;
    char *end;

    while (*start)
    {
        while (*start && is_separator(*start, separators))
        {
            start++;
        }
        if (*start == '\0')
            break;

        end = start;
        while (*end && !is_separator(*end, separators))
        {
            end++;
        }
        size_t len = end - start;

        words = (char **)realloc(words, (*words_count + 1) * sizeof(char *));
        if (!words)
        {
            free(content);
            return NULL;
        }

        words[*words_count] = (char *)malloc(len + 1);
        if (!words[*words_count])
        {
            free(content);
            for (int i = 0; i < *words_count; i++)
            {
                free(words[i]);
            }
            free(words);
            return NULL;
        }

        copy_string(words[*words_count], start, len);
        (*words_count)++;

        start = end;
    }

    free(content);
    return words;
}