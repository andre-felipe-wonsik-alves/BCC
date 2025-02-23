#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(const char *str, int *n)
{
    int count = 0;
    const char *temp = str;
    while (*temp)
    {
        while (*temp && *temp == ' ')
            temp++;
        if (*temp)
            count++;
        while (*temp && *temp != ' ')
            temp++;
    }

    char **result = (char **)malloc(count * sizeof(char *));
    if (!result)
        return NULL;

    temp = str;
    int index = 0;
    while (*temp)
    {
        while (*temp && *temp == ' ')
            temp++;
        if (*temp)
        {
            const char *start = temp;
            while (*temp && *temp != ' ')
                temp++;
            int length = temp - start;
            result[index] = (char *)malloc((length + 1) * sizeof(char));
            if (!result[index])
                return NULL;
            strncpy(result[index], start, length);
            result[index][length] = '\0';
            index++;
        }
    }

    *n = count;
    return result;
}

int main()
{
    const char *str = "teste";
    int n;
    char **words = split(str, &n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}