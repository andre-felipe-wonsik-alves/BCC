#include <stdio.h>
#include <string.h>

void slice(char str[], int pos)
{
    str[pos] = '\0';
}

int find(char str[], const char sub[])
{
    int check = 0, posFinal;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == sub[0])
        {
            for (int j = 0; sub[j] != '\0'; j++)
            {
                if (str[i + j] == sub[j])
                {
                    check++;
                    posFinal = i + j;
                }
            }
        }
    }

    if (check == strlen(sub))
    {
        slice(str, posFinal);
        return 1;
    }
    return 0;
}

int main()
{
    char string[] = "fala fi";
    int check = find(string, "fi");

    if (check)
    {
        printf("%s\n", string);
        return 0;
    }
    return 0;
}