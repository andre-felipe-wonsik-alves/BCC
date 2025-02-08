#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reversed(const char *str)
{
    char *pointer = malloc((strlen(str) + 1) * sizeof(char));
    int j = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        pointer[j] = str[i];
        j++;
    }

    pointer[strlen(str)] = '\0';

    return pointer;
}

int main()
{
    char str[] = "abcd";

    char *p = reversed(str);

    printf("String: %s\n", p);
    free(p);

    return 0;
}