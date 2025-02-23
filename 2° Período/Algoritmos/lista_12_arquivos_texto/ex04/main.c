#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct
{
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void count_all_words(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        return;
    }

    WordCount words[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%99s", buffer) == 1)
    {
        for (int i = 0; buffer[i]; i++)
        {
            buffer[i] = tolower(buffer[i]);
        }
        int len = strlen(buffer);
        if (ispunct(buffer[len - 1]))
        {
            buffer[len - 1] = '\0';
        }

        int found = 0;
        for (int i = 0; i < word_count; i++)
        {
            if (strcmp(words[i].word, buffer) == 0)
            {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && word_count < MAX_WORDS)
        {
            strcpy(words[word_count].word, buffer);
            words[word_count].count = 1;
            word_count++;
        }
    }

    fclose(file);

    for (int i = 0; i < word_count; i++)
    {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}