#include <stdio.h>

int get_hamming_distance(const char *str1, const char *str2)
{
    int hamming = 0;

    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            hamming++;
        }
        str1++;
        str2++;
    }
    return hamming;
}

char *find_most_similar(const char *str, int n, char list[n][50])
{
    int menorHamming = -1, hamming;
    char *similar;

    for (int i = 0; i < n; i++)
    {
        hamming = get_hamming_distance(str, list[i]);
        if (menorHamming == -1 || hamming < menorHamming)
        {
            menorHamming = hamming;
            similar = list[i];
        }
    }
    return similar;
}

int main()
{
    char words[][50] = {"canana", "savana", "dacana", "halana"};
    char *most_similar = find_most_similar("banana", 4, words);
    printf("%s\n", most_similar);

    return 0;
}