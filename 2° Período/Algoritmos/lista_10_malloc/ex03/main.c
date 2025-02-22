#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy_string(const char *str)
{
    char *pointer = malloc((strlen(str) + 1) * sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
    {
        pointer[i] = str[i];
    }

    pointer[strlen(str)] = '\0';

    return pointer;
}

int main()
{
    char str[] = "andrezones";

    char *p = copy_string(str);

    printf("String: %s\n", p);
    free(p);

    return 0;
}
