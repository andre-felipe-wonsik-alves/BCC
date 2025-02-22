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

int main()
{
    int dist = get_hamming_distance("banana", "cacaba");
    printf("Hamming: %d\n", dist);
    return 0;
}