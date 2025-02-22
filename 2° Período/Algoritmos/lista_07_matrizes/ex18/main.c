#include <stdio.h>
#include <string.h>

void print_strings_minmax(int n, int len, char list[n][len])
{
    if (n == 0)
    {
        return;
    }

    int min_index = 0, max_index = 0;
    int min_length = strlen(list[0]), max_length = strlen(list[0]);

    for (int i = 1; i < n; i++)
    {
        int current_length = strlen(list[i]);
        if (current_length < min_length)
        {
            min_length = current_length;
            min_index = i;
        }
        if (current_length > max_length)
        {
            max_length = current_length;
            max_index = i;
        }
    }

    printf("menor string: %s\n", list[min_index]);
    printf("maior string: %s\n", list[max_index]);
}

int main()
{
    int n = 5;
    int len = 20;
    char list[5][20] = {
        "maçã",
        "banana",
        "cereja",
        "tâmara",
        "abacaxi"};

    print_strings_minmax(n, len, list);

    return 0;
}