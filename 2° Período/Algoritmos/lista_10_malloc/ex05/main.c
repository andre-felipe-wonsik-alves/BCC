#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *str1, const char *str2)
{
    char *pointer = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));

    for (int i = 0; str1[i] != '\0'; i++)
    {
        pointer[i] = str1[i];
    }

    int j = strlen(str1);

    for (int i = 0; str2[i] != '\0'; i++)
    {
        pointer[j] = str2[i];
        j++;
    }

    return pointer;
}

int main()
{
    char str1[] = "abcd";
    char str2[] = "efg";

    char *p = concat(str1, str2);

    printf("Concat: %s\n", p);
    free(p);

    return 0;
}