#include <stdio.h>
#include <string.h>

int count_occurrences(int n, int len, char lines[n][len], char word[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        char *pos = lines[i];
        while ((pos = strstr(pos, word)) != NULL)
        {
            count++;
            pos += strlen(word);
        }
    }
    return count;
}

int main()
{
    int n = 3;
    int len = 100;
    char lines[3][100] = {
        "isto é um teste",
        "este teste é um teste",
        "teste isto é"};
    char word[] = "test";

    int result = count_occurrences(n, len, lines, word);
    printf("A palavra '%s' aparece %d vezes.\n", word, result);

    return 0;
}