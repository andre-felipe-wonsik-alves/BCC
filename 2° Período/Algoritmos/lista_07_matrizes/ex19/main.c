#include <stdio.h>
#include <ctype.h>

int count_words(int n, int len, char lines[n][len])
{
    int word_count = 0;
    for (int i = 0; i < n; i++)
    {
        int in_word = 0;
        for (int j = 0; j < len; j++)
        {
            if (isspace(lines[i][j]) || lines[i][j] == '\0')
            {
                if (in_word)
                {
                    word_count++;
                    in_word = 0;
                }
                if (lines[i][j] == '\0')
                {
                    break;
                }
            }
            else
            {
                in_word = 1;
            }
        }
    }
    return word_count;
}

int main()
{
    int n = 3;
    int len = 100;
    char lines[3][100] = {
        "  Olá mundo  ",
        "Isto é um teste",
        "  Outro   exemplo  "};

    int result = count_words(n, len, lines);
    printf("Total: %d\n", result);

    return 0;
}