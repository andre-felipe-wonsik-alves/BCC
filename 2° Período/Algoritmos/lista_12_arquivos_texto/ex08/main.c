#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char key[101];
    char value[101];
} Pair;

void trim(char *str)
{
    char *end;

    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0)
        return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    *(end + 1) = 0;
}

Pair *load_ini_file(const char *filepath, int *n)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        *n = 0;
        return NULL;
    }

    Pair *pairs = NULL;
    char line[256];
    *n = 0;

    while (fgets(line, sizeof(line), file))
    {
        char *equals = strchr(line, '=');
        if (equals)
        {
            *equals = '\0';
            char *key = line;
            char *value = equals + 1;

            trim(key);
            trim(value);

            pairs = realloc(pairs, (*n + 1) * sizeof(Pair));
            if (!pairs)
            {
                fclose(file);
                *n = 0;
                return NULL;
            }

            strncpy(pairs[*n].key, key, 100);
            pairs[*n].key[100] = '\0';
            strncpy(pairs[*n].value, value, 100);
            pairs[*n].value[100] = '\0';

            (*n)++;
        }
    }

    fclose(file);

    if (*n == 0)
    {
        free(pairs);
        return NULL;
    }

    return pairs;
}