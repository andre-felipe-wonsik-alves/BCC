#include <stdio.h>

void stringCount(const char str[])
{
    int alfabeto[26] = {0};
    int letrasTotais = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {

            alfabeto[str[i] - 'A']++;
            letrasTotais++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {

            alfabeto[str[i] - 'a']++;
            letrasTotais++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (alfabeto[i] > 0)
        {
            float porcentagem = (alfabeto[i] * 100.0) / letrasTotais;
            printf("%c x%d (%.0f%%)\n", i + 'A', alfabeto[i], porcentagem);
        }
    }
}

int main()
{
    char s[] = "fala fi";

    stringCount(s);

    return 0;
}