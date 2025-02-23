#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

void report_by_chars(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        return;
    }

    int word_count[MAX_WORD_LENGTH] = {0};
    char word[MAX_WORD_LENGTH];
    int c, length = 0;

    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
        {
            word[length++] = c;
        }
        else if (length > 0)
        {
            word[length] = '\0';
            word_count[length]++;
            length = 0;
        }
    }

    if (length > 0)
    {
        word[length] = '\0';
        word_count[length]++;
    }

    fclose(file);

    printf("res:\n");
    for (int i = 1; i < MAX_WORD_LENGTH; i++)
    {
        if (word_count[i] > 0)
        {
            printf("%d letters: %d words\n", i, word_count[i]);
        }
    }
}