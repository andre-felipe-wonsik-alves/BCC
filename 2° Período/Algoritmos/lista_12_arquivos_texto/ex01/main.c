#include <stdio.h>
#include <stdlib.h>
int count_word(const char *filepath, const char *word)
{
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    int word_len = strlen(word);
    int index = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == word[index])
        {
            index++;
            if (index == word_len)
            {
                if ((ch = fgetc(file)) == ' ' || ch == '\n' || ch == '\t' || ch == EOF)
                {
                    count++;
                }
                ungetc(ch, file);
                index = 0;
            }
        }
        else
        {
            index = 0;
        }
    }

    fclose(file);
    return count;
}

int main()
{
    return 0;
}