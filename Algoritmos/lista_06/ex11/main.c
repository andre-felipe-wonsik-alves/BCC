#include <stdio.h>
#include <string.h>

int find(const char str[], const char sub[])
{
    int check = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == sub[0])
        {
            for (int j = 0; sub[j] != '\0'; j++)
            {
                if (str[i + j] == sub[j])
                {
                    check++;
                }
            }
        }
    }

    if (check == strlen(sub))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char string[] = "Fala fi";
    int res = find(string, "fi");

    printf("%d\n", res);
}